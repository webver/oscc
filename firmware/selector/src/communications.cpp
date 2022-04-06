/**
 * @file communications.cpp
 *
 */


#include <stdint.h>

#include "can_protocols/fault_can_protocol.h"
#include "can_protocols/selector_can_protocol.h"
#include "communications.h"
#include "debug.h"
#include "globals.h"
#include "mcp_can.h"
#include "selector_control.h"
#include "oscc_can.h"
#include "vehicles.h"


static void process_rx_frame(
        const can_frame_s *const frame);

static void process_selector_command(
        const uint8_t *const data);

static void process_fault_report(
        const uint8_t *const data);

static void process_selector_position_report(
        const uint8_t *const data);

static void process_speed_report(
        const uint8_t *const data);

void publish_selector_report(void) {
    oscc_selector_report_s selector_report;

    selector_report.magic[0] = (uint8_t) OSCC_MAGIC_BYTE_0;
    selector_report.magic[1] = (uint8_t) OSCC_MAGIC_BYTE_1;
    selector_report.enabled = (uint8_t) g_selector_control_state.enabled;
    selector_report.operator_override = (uint8_t) g_selector_control_state.operator_override;
    selector_report.dtcs = g_selector_control_state.dtcs;

    cli();
    g_control_can.sendMsgBuf(
            OSCC_SELECTOR_REPORT_CAN_ID,
            CAN_STANDARD,
            OSCC_SELECTOR_REPORT_CAN_DLC,
            (uint8_t *) &selector_report);
    sei();
}


void publish_fault_report(void) {
    oscc_fault_report_s fault_report;

    fault_report.magic[0] = (uint8_t) OSCC_MAGIC_BYTE_0;
    fault_report.magic[1] = (uint8_t) OSCC_MAGIC_BYTE_1;
    fault_report.fault_origin_id = FAULT_ORIGIN_SELECTOR;
    fault_report.dtcs = g_selector_control_state.dtcs;

    cli();
    g_control_can.sendMsgBuf(
            OSCC_FAULT_REPORT_CAN_ID,
            CAN_STANDARD,
            OSCC_FAULT_REPORT_CAN_DLC,
            (uint8_t *) &fault_report);
    sei();
}


void check_for_incoming_message(void) {
    can_frame_s rx_frame;
    can_status_t ret = check_for_rx_frame(g_control_can, &rx_frame);

    if (ret == CAN_RX_FRAME_AVAILABLE) {
        process_rx_frame(&rx_frame);
    }
}


static void process_rx_frame(
        const can_frame_s *const frame) {
    if (frame != NULL) {
        if ((frame->data[0] == OSCC_MAGIC_BYTE_0)
            && (frame->data[1] == OSCC_MAGIC_BYTE_1)) {
            if (frame->id == OSCC_SELECTOR_ENABLE_CAN_ID) {
                enable_control();
            } else if (frame->id == OSCC_SELECTOR_DISABLE_CAN_ID) {
                disable_control();
            } else if (frame->id == OSCC_SELECTOR_COMMAND_CAN_ID) {
                process_selector_command(frame->data);
            } else if (frame->id == OSCC_FAULT_REPORT_CAN_ID) {
                process_fault_report(frame->data);
            }
        } else if (frame->id == OBD_SELECTOR_POSITION_CAN_ID) {
            process_selector_position_report(frame->data);
        } else if (frame->id == OBD_SPEED_CAN_ID) {
            process_speed_report(frame->data);
        }
    }
}


static void process_selector_command(
        const uint8_t *const data) {
    if (data != NULL) {
        const oscc_selector_command_s *const selector_command =
                (oscc_selector_command_s *) data;

        if (g_selector_control_state.current_position != 0x00) {
            if ((selector_command->selector_command == 'P') || (selector_command->selector_command == 'R') ||
                (selector_command->selector_command == 'N') || (selector_command->selector_command == 'D')) {

                const uint8_t clamped_position = selector_command->selector_command;

                if (clamped_position != g_selector_control_state.current_position) {
                    update_selector_position(clamped_position);
                }
            } else {
                DEBUG_PRINTLN("Wrong argument");
            }
        } else {
            DEBUG_PRINTLN("Unknown selector position");
        }
    }
}


static void process_fault_report(
        const uint8_t *const data) {
    if (data != NULL) {
        const oscc_fault_report_s *const fault_report =
                (oscc_fault_report_s *) data;

        disable_control();

        DEBUG_PRINT("Fault report received from: ");
        DEBUG_PRINT(fault_report->fault_origin_id);
        DEBUG_PRINT("  DTCs: ");
        DEBUG_PRINTLN(fault_report->dtcs);
    }
}

static void process_selector_position_report(
        const uint8_t *const data) {
    if (data != NULL) {
        const obd_selector_position_report_s *const selector_report =
                (obd_selector_position_report_s *) data;

        //Selector status
        const uint8_t position_bits = (selector_report->selector_position_byte >> 3) & 0x07;
        const bool is_manual_enabled = (selector_report->selector_position_byte >> 7) & 0x01;
        if (is_manual_enabled == false) {
            switch (position_bits) {
                case 0x01:
                    g_selector_control_state.current_position = 'P';
                    break;
                case 0x02:
                    g_selector_control_state.current_position = 'R';
                    break;
                case 0x03:
                    g_selector_control_state.current_position = 'N';
                    break;
                case 0x04:
                    g_selector_control_state.current_position = 'D';
                    break;
                default:
                    g_selector_control_state.current_position = 0x00;
                    break;
            }
        } else {
            switch (position_bits) {
                case 0x00:
                    g_selector_control_state.current_position = '1';
                    break;
                case 0x01:
                    g_selector_control_state.current_position = '2';
                    break;
                case 0x02:
                    g_selector_control_state.current_position = '3';
                    break;
                case 0x03:
                    g_selector_control_state.current_position = '4';
                    break;
                default:
                    g_selector_control_state.current_position = 0x00;
                    break;
            }
        }

        //Brake pressed status
        g_selector_control_state.is_brake_enabled = !((selector_report->brake_status_byte >> 4) & 0x01);
    }
}

static void process_speed_report(
        const uint8_t *const data) {
    if (data != NULL) {
        const obd_speed_report_s *const speed_report =
                (obd_speed_report_s *) data;

        //Car speed
        g_selector_control_state.speed = speed_report->speed;
    }
}

