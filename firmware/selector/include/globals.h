/**
 * @file globals.h
 * @brief Module globals.
 *
 */


#ifndef _OSCC_SELECTOR_GLOBALS_H_
#define _OSCC_SELECTOR_GLOBALS_H_


#include "DAC_MCP49xx.h"
#include "mcp_can.h"
#include "selector_control.h"


/*
 * @brief Chip select pin of the DAC IC.
 *
 */
#define PIN_DAC_CHIP_SELECT ( 9 )

/*
 * @brief Chip select pin of the CAN IC.
 *
 */
#define PIN_CAN_CHIP_SELECT ( 10 )

/*
 * @brief High signal pin of the torque sensor.
 *
 */
#define PIN_TORQUE_SENSOR_HIGH ( A0 )

/*
 * @brief Low signal pin of the torque sensor.
 *
 */
#define PIN_TORQUE_SENSOR_LOW ( A1 )

/*
 * @brief High signal pin of the torque spoof output.
 *
 */
#define PIN_TORQUE_SPOOF_HIGH ( A2 )

/*
 * @brief Low signal pin of the torque spoof output.
 *
 */
#define PIN_TORQUE_SPOOF_LOW ( A3 )

/*
 * @brief Relay enable pin for the spoof output.
 *
 */
#define PIN_SPOOF_ENABLE ( 6 )

/*
 * @brief Relay enable pin for the spoof output.
 *
 */
#define PIN_STEP_MOTOR_ENABLE ( 2 )

/*
 * @brief Relay enable pin for the spoof output.
 *
 */
#define PIN_STEP_MOTOR_DIRECTION ( 3 )

/*
 * @brief Relay enable pin for the spoof output.
 *
 */
#define PIN_STEP_MOTOR_PUL ( 4 )


#ifdef GLOBAL_DEFINED
    DAC_MCP49xx g_dac( DAC_MCP49xx::MCP4922, PIN_DAC_CHIP_SELECT );
    MCP_CAN g_control_can( PIN_CAN_CHIP_SELECT );

    #define EXTERN
#else
    extern DAC_MCP49xx g_dac;
    extern MCP_CAN g_control_can;

    #define EXTERN extern
#endif


EXTERN volatile selector_control_state_s g_selector_control_state;


#endif
