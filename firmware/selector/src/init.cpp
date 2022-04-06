/**
 * @file init.cpp
 *
 */


#include <Arduino.h>

#include "can_protocols/fault_can_protocol.h"
#include "can_protocols/selector_can_protocol.h"
#include "communications.h"
#include "debug.h"
#include "globals.h"
#include "init.h"
#include "oscc_can.h"
#include "oscc_serial.h"
#include "oscc_timer.h"
#include "vehicles.h"

void init_globals(void) {
    g_selector_control_state.enabled = false;
    g_selector_control_state.operator_override = false;
    g_selector_control_state.current_position = 0x00;
    g_selector_control_state.last_set_position = 0x00;
    g_selector_control_state.is_brake_enabled = false;
    g_selector_control_state.speed = 0;
    g_selector_control_state.dtcs = 0;
}


void init_devices(void) {
    pinMode(PIN_DAC_CHIP_SELECT, OUTPUT);
    pinMode(PIN_TORQUE_SENSOR_HIGH, INPUT);
    pinMode(PIN_TORQUE_SENSOR_LOW, INPUT);
    pinMode(PIN_TORQUE_SPOOF_HIGH, INPUT);
    pinMode(PIN_TORQUE_SPOOF_LOW, INPUT);
    pinMode(PIN_SPOOF_ENABLE, OUTPUT);

    pinMode(PIN_STEP_MOTOR_ENABLE, OUTPUT);
    pinMode(PIN_STEP_MOTOR_DIRECTION, OUTPUT);
    pinMode(PIN_STEP_MOTOR_PUL, OUTPUT);

    cli();
    digitalWrite(PIN_DAC_CHIP_SELECT, HIGH);
    digitalWrite(PIN_SPOOF_ENABLE, LOW);
    sei();

//    while (1) {
//        // мотор крутится по часовой стрелки
//        for (int i = 0; i < (200*14); i++) {
//            digitalWrite(PIN_STEP_MOTOR_DIRECTION, HIGH);
//            digitalWrite(PIN_STEP_MOTOR_ENABLE, LOW);
//            cli();
//            digitalWrite(PIN_STEP_MOTOR_PUL, HIGH);
//            delayMicroseconds(500);
//            digitalWrite(PIN_STEP_MOTOR_PUL, LOW);
//            delayMicroseconds(500);
//            sei();
//            digitalWrite(PIN_STEP_MOTOR_ENABLE, HIGH);
//        }
//        // мотор крутится по против часовой стрелки
//        for (int i = 0; i < (200*14); i++) {
//            digitalWrite(PIN_STEP_MOTOR_DIRECTION, LOW);
//            digitalWrite(PIN_STEP_MOTOR_ENABLE, LOW);
//            digitalWrite(PIN_STEP_MOTOR_PUL, HIGH);
//            delayMicroseconds(500);
//            digitalWrite(PIN_STEP_MOTOR_PUL, LOW);
//            delayMicroseconds(500);
//            digitalWrite(PIN_STEP_MOTOR_ENABLE, HIGH);
//        }
//    }
}


void init_communication_interfaces(void) {
#ifdef DEBUG
    init_serial();
#endif

    DEBUG_PRINT("init Control CAN - ");
    init_can(g_control_can);

    // Filter CAN messages - accept if (CAN_ID & mask) == (filter & mask)
    // Set buffer 0 to filter only selector module and global messages
    g_control_can.init_Mask(0, 0, 0x7F0); // Filter for 0x0N0 to 0x0NF
    g_control_can.init_Filt(0, 0, OSCC_SELECTOR_CAN_ID_INDEX);
    g_control_can.init_Filt(1, 0, OSCC_FAULT_CAN_ID_INDEX);
    g_control_can.init_Filt(2, 0, OBD_SELECTOR_POSITION_CAN_ID);
    g_control_can.init_Filt(2, 0, OBD_SELECTOR_POSITION_CAN_ID);
    // Accept only CAN Disable when buffer overflow occurs in buffer 0
    g_control_can.init_Mask(1, 0, 0x7FF); // Filter for one CAN ID
    g_control_can.init_Filt(2, 1, OSCC_SELECTOR_DISABLE_CAN_ID);
}


void start_timers(void) {
    timer1_init(OSCC_REPORT_SELECTOR_PUBLISH_FREQ_IN_HZ, publish_selector_report);
}
