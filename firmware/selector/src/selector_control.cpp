/**
 * @file steering_control.cpp
 *
 */


#include <Arduino.h>
#include <stdint.h>
#include <stdlib.h>

#include "can_protocols/selector_can_protocol.h"
#include "communications.h"
#include "debug.h"
#include "dtc.h"
#include "globals.h"
#include "oscc_dac.h"
#include "oscc_check.h"
#include "selector_control.h"
#include "vehicles.h"


static void motor_set_enabled(bool is_enable);

static void motor_set_direction(bool is_clock_wise);

static void motor_make_step(void);

static uint8_t positionToIndex(const char position);

static float exponential_moving_average(
        const float alpha,
        const float input,
        const float average);

#ifdef STEERING_OVERRIDE
static uint16_t filtered_diff = 0;
#endif

void check_for_faults(void) {
    if ((g_selector_control_state.enabled == true)
        || (g_selector_control_state.dtcs > 0)) {

        static condition_state_s operator_override_state = CONDITION_STATE_INIT;

        bool operator_overridden = false;

        //Check only in idle state
        if (g_selector_control_state.last_set_position != 0x00 && g_selector_control_state.request_position == 0x00) {
            operator_overridden = condition_exceeded_duration(
                    g_selector_control_state.last_set_position != g_selector_control_state.current_position,
                    FAULT_HYSTERESIS,
                    &operator_override_state);
        }

        if (operator_overridden == true) {
            disable_control();

            DTC_SET(
                    g_selector_control_state.dtcs,
                    OSCC_SELECTOR_DTC_OPERATOR_OVERRIDE);

            publish_fault_report();

            g_selector_control_state.operator_override = true;

            DEBUG_PRINTLN("Operator override");
        } else {
            g_selector_control_state.dtcs = 0;

            if (g_selector_control_state.operator_override == true) {
                g_selector_control_state.operator_override = false;
            }
        }
    }
}


static void motor_set_enabled(bool is_enable) {
    if (is_enable == true) {
        digitalWrite(PIN_STEP_MOTOR_ENABLE, LOW);
    } else {
        digitalWrite(PIN_STEP_MOTOR_DIRECTION, HIGH);
    }
}

static void motor_set_direction(bool is_clock_wise) {
    cli();

    bool current_direction = digitalRead(PIN_STEP_MOTOR_DIRECTION);
    bool is_enabled = digitalRead(PIN_STEP_MOTOR_ENABLE);

    if (current_direction != is_clock_wise) {
        if (is_enabled == true) {
            motor_set_enabled(false);
        }

        if (is_clock_wise == true) {
            digitalWrite(PIN_STEP_MOTOR_DIRECTION, HIGH);
        } else {
            digitalWrite(PIN_STEP_MOTOR_DIRECTION, LOW);
        }

        if (is_enabled == true) {
            motor_set_enabled(true);
        }
    }

    sei();
}

static void motor_make_step(void) {
    cli();
    digitalWrite(PIN_STEP_MOTOR_PUL, HIGH);
    delayMicroseconds(500);
    digitalWrite(PIN_STEP_MOTOR_PUL, LOW);
    delayMicroseconds(500);
    sei();
}

static uint8_t positionToIndex(const char position) {
    uint8_t position_index = 0;

    switch (position) {
        case 'P':
            position_index = 1;
            break;
        case 'R':
            position_index = 2;
            break;
        case 'N':
            position_index = 3;
            break;
        case 'D':
            position_index = 4;
            break;
        default:
            position_index = 0;
    }

    return position_index;
}

void update_selector_position(const char request_position) {
    if (g_selector_control_state.enabled == true) {

        if (g_selector_control_state.is_brake_enabled && g_selector_control_state.speed == 0) {

            g_selector_control_state.request_position = request_position;

        } else {
            DEBUG_PRINTLN("Brake not pressed or speed != 0");
        }

    }
}

void move_selector(void) {
    if (g_selector_control_state.enabled == true) {

        if (g_selector_control_state.request_position != 0x00) {

            if (g_selector_control_state.is_brake_enabled &&
                g_selector_control_state.speed == 0) {

                if (g_selector_control_state.current_position != g_selector_control_state.request_position) {

                    motor_set_enabled(true);

                    bool isClockWise = false;

                    const uint8_t request_index = positionToIndex(g_selector_control_state.request_position);
                    const uint8_t current_index = positionToIndex(g_selector_control_state.current_position);

                    if (current_index != 0 && request_index != 0) {
                        isClockWise = (request_index > current_index) ? true : false;

                        motor_set_direction(isClockWise);

                        motor_make_step();
                    }

                } else {
                    cli();
                    motor_set_enabled(false);

                    g_selector_control_state.request_position = 0x00;
                    g_selector_control_state.last_set_position = g_selector_control_state.request_position;
                    sei();
                }

            } else {
                cli();
                motor_set_enabled(false);

                g_selector_control_state.request_position = 0x00;
                sei();
            }
        }
    }
}


void enable_control(void) {
    if (g_selector_control_state.enabled == false
        && g_selector_control_state.operator_override == false) {
        const uint16_t num_samples = 20;
        prevent_signal_discontinuity(
                g_dac,
                num_samples,
                PIN_TORQUE_SENSOR_HIGH,
                PIN_TORQUE_SENSOR_LOW);

        cli();
        digitalWrite(PIN_SPOOF_ENABLE, HIGH);
        sei();

        g_selector_control_state.enabled = true;

        DEBUG_PRINTLN("Control enabled");
    }
}


void disable_control(void) {
    if (g_selector_control_state.enabled == true) {
        const uint16_t num_samples = 20;
        prevent_signal_discontinuity(
                g_dac,
                num_samples,
                PIN_TORQUE_SENSOR_HIGH,
                PIN_TORQUE_SENSOR_LOW);

        cli();
        digitalWrite(PIN_SPOOF_ENABLE, LOW);

        digitalWrite(PIN_STEP_MOTOR_ENABLE, HIGH);
        digitalWrite(PIN_STEP_MOTOR_DIRECTION, LOW);
        digitalWrite(PIN_STEP_MOTOR_PUL, LOW);
        sei();

        g_selector_control_state.enabled = false;

#ifdef STEERING_OVERRIDE
        filtered_diff = 0;
#endif

        DEBUG_PRINTLN("Control disabled");
    }
}

//static float exponential_moving_average(
//    const float alpha,
//    const float input,
//    const float average )
//{
//    return ( (alpha * input) + ((1.0 - alpha) * average) );
//}

//static void read_torque_sensor(
//    steering_torque_s * value )
//{
//    cli();
//    value->high = analogRead( PIN_TORQUE_SENSOR_HIGH ) << 2;
//    value->low = analogRead( PIN_TORQUE_SENSOR_LOW ) << 2;
//    sei();
//}
