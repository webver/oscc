/**
 * @file selector_control.h
 * @brief Control of the selector system.
 *
 */


#ifndef _OSCC_SELECTOR_CONTROL_H_
#define _OSCC_SELECTOR_CONTROL_H_


#include <stdint.h>


/**
 * @brief Current selector control state.
 *
 * Current state of the throttle module control system.
 *
 */
typedef struct {
    bool enabled; /* Flag indicating control is currently enabled. */

    bool operator_override; /* Flag indicating whether selector wheel was
                               manually turned by operator. */

    char current_position; /*Current selector position char P-R-N-D-1-2-3-4*/

    char last_set_position;  /*Last selector position set by controller char P-R-N-D-1-2-3-4*/

    bool is_brake_enabled; /*Is brake pedal pressed*/

    int speed; /*Current car speed*/

    uint8_t dtcs; /* Bitfield of faults present in the module. */
} selector_control_state_s;


// ****************************************************************************
// Function:    check_for_sensor_faults
//
// Purpose:     Checks to see if valid values are being read from the sensors.
//              If operator override for selector is turned on detection of the
//              selector wheel being manually turned is also detected.
//
// Returns:     void
//
// Parameters:  void
//
// ****************************************************************************
void check_for_faults(void);


// ****************************************************************************
// Function:    update_selector_position
//
// Purpose:     Rotate step motor until requested position.
//
// Returns:     void
//
// Parameters:  position - value of selector command
//
// ****************************************************************************
void update_selector_position(const char position);


// *****************************************************
// Function:    enable_control
//
// Purpose:     Enable control of the selector system.
//
// Returns:     void
//
// Parameters:  void
//
// *****************************************************
void enable_control(void);


// *****************************************************
// Function:    disable_control
//
// Purpose:     Disable control of the selector system.
//
// Returns:     void
//
// Parameters:  void
//
// *****************************************************
void disable_control(void);


#endif /* _OSCC_SELECTOR_CONTROL_H_ */
