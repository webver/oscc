/**
 * @file vehicles.h
 * @brief List of vehicle headers.
 *
 */


#ifndef _OSCC_VEHICLES_H_
#define _OSCC_VEHICLES_H_


#if defined(KIA_SOUL)
#include "vehicles/kia_soul_petrol.h"
#elif defined(KIA_SOUL_EV)
#include "vehicles/kia_soul_ev.h"
#elif defined(KIA_NIRO)
#include "vehicles/kia_niro.h"
#elif defined(LADA_VESTA)
#include "vehicles/lada_vesta.h"
#define OBD_SELECTOR_POSITION_CAN_ID (LADA_VESTA_OBD_SELECTOR_POSITION_CAN_ID)
#define OBD_THROTTLE_POSITION_CAN_ID (LADA_VESTA_OBD_THROTTLE_POSITION_CAN_ID)
#define OBD_BRAKE_PRESSURE_CAN_ID (LADA_VESTA_OBD_BRAKE_PRESSURE_CAN_ID)
#define OBD_STEERING_WHEEL_ANGLE_CAN_ID (LADA_VESTA_OBD_STEERING_WHEEL_ANGLE_CAN_ID)
#define OBD_WHEEL_SPEED_1_CAN_ID (LADA_VESTA_OBD_WHEEL_SPEED_1_CAN_ID)
#define OBD_WHEEL_SPEED_2_CAN_ID (LADA_VESTA_OBD_WHEEL_SPEED_2_CAN_ID)
#define OBD_STEERING_ANGLE_SCALAR (LADA_VESTA_OBD_STEERING_ANGLE_SCALAR)
#define OBD_LAMP_STATUS_CAN_ID (LADA_VESTA_OBD_LAMP_STATUS_CAN_ID)

#endif

#define CONSTRAIN(amt, low, high) ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))


#endif /* _OSCC_VEHICLES_H_ */
