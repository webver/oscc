/**
 * @file selector_can_protocol.h
 * @brief Selector CAN Protocol.
 *
 */


#ifndef _OSCC_SELECTOR_CAN_PROTOCOL_H_
#define _OSCC_SELECTOR_CAN_PROTOCOL_H_


#include <stdint.h>
#include "magic.h"


/*
 * @brief CAN ID representing the range of selector messages.
 *
 */
#define OSCC_SELECTOR_CAN_ID_INDEX (0xB0)


/*
 * @brief Selector enable message (CAN frame) ID.
 *
 */
#define OSCC_SELECTOR_ENABLE_CAN_ID (0xB0)

/*
 * @brief Selector disable message (CAN frame) ID.
 *
 */
#define OSCC_SELECTOR_DISABLE_CAN_ID (0xB1)

/*
 * @brief Selector command message (CAN frame) ID.
 *
 */
#define OSCC_SELECTOR_COMMAND_CAN_ID (0xB2)

/*
 * @brief Selector report message (CAN frame) ID.
 *
 */
#define OSCC_SELECTOR_REPORT_CAN_ID (0xB3)

/*
 * @brief Selector report message (CAN frame) length.
 *
 */
#define OSCC_SELECTOR_REPORT_CAN_DLC (8)

/*
 * @brief Selector report message publishing frequency. [Hz]
 *
 */
#define OSCC_REPORT_SELECTOR_PUBLISH_FREQ_IN_HZ (50)

/*
 * @brief Enumeration of all possible selector DTCs.
 *
 */
enum {
    /* DTC bitfield position indicating an invalid sensor value. */
    OSCC_SELECTOR_DTC_INVALID_SENSOR_VAL = 0,

    /* DTC bitfield position indicating an operator override. */
    OSCC_SELECTOR_DTC_OPERATOR_OVERRIDE,

    /* Number of possible selector DTCs. */
    OSCC_SELECTOR_DTC_COUNT
};


#pragma pack(push)
#pragma pack(1)

/**
 * @brief Selector enable message.
 *
 * CAN frame ID: \ref OSCC_SELECTOR_ENABLE_CAN_ID
 *
 */
typedef struct {
    uint8_t magic[2]; /*!< Magic number identifying CAN frame as from OSCC.
                       *   Byte 0 should be \ref OSCC_MAGIC_BYTE_0.
                       *   Byte 1 should be \ref OSCC_MAGIC_BYTE_1. */

    uint8_t reserved[6]; /*!< Reserved. */
} oscc_selector_enable_s;


/**
 * @brief Selector disable message.
 *
 * CAN frame ID: \ref OSCC_SELECTOR_DISABLE_CAN_ID
 *
 */
typedef struct {
    uint8_t magic[2]; /*!< Magic number identifying CAN frame as from OSCC.
                       *   Byte 0 should be \ref OSCC_MAGIC_BYTE_0.
                       *   Byte 1 should be \ref OSCC_MAGIC_BYTE_1. */

    uint8_t reserved[6]; /*!< Reserved. */
} oscc_selector_disable_s;


/**
 * @brief Selector command message data.
 *
 * CAN frame ID: \ref OSCC_SELECTOR_COMMAND_CAN_ID
 *
 */
typedef struct {
    uint8_t magic[2]; /*!< Magic number identifying CAN frame as from OSCC.
                       *   Byte 0 should be \ref OSCC_MAGIC_BYTE_0.
                       *   Byte 1 should be \ref OSCC_MAGIC_BYTE_1. */

    uint8_t selector_command; /* Selector request P,R,N,D ASCII values*/

    uint8_t reserved[5]; /*!< Reserved. */
} oscc_selector_command_s;


/**
 * @brief Selector report message data.
 *
 * CAN frame ID: \ref OSCC_SELECTOR_REPORT_CAN_ID
 *
 */
typedef struct {
    uint8_t magic[2]; /*!< Magic number identifying CAN frame as from OSCC.
                       *   Byte 0 should be \ref OSCC_MAGIC_BYTE_0.
                       *   Byte 1 should be \ref OSCC_MAGIC_BYTE_1. */

    uint8_t enabled; /*!< Selector controls enabled state.
                      * Zero value means disabled (commands are ignored).
                      * Non-zero value means enabled (no timeouts or overrides have occured). */

    uint8_t operator_override; /*!< Driver override state.
                                * Zero value means there has been no operator override.
                                * Non-zero value means an operator has physically overridden
                                * the system. */

    uint8_t dtcs; /*!< Bitfield of DTCs present in the module. */

    uint8_t reserved[3]; /*!< Reserved. */
} oscc_selector_report_s;


/**
 * @brief Selector position report data.
 *
 * CAN frame ID: \ref OBD_SELECTOR_POSITION_REPORT_ID
 *
 */
typedef struct {
    uint8_t selector_position_byte;
    uint8_t brake_status_byte;
    uint8_t reserved[6]; /*!< Reserved. */
} obd_selector_position_report_s;

/**
 * @brief Selector position report data.
 *
 * CAN frame ID: \ref OBD_SPEED_REPORT_ID
 *
 */
typedef struct {
    uint8_t speed;
    uint8_t reserved[7]; /*!< Reserved. */
} obd_speed_report_s;

#pragma pack(pop)


#endif /* _OSCC_SELECTOR_CAN_PROTOCOL_H_ */
