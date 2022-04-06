/**
 * @file communications.h
 * @brief Communication functionality.
 *
 */


#ifndef _OSCC_SELECTOR_COMMUNICATIONS_H_
#define _OSCC_SELECTOR_COMMUNICATIONS_H_


// ****************************************************************************
// Function:    publish_selector_report
//
// Purpose:     Publish selector report to CAN bus.
//
// Returns:     void
//
// Parameters:  void
//
// ****************************************************************************
void publish_selector_report( void );


// ****************************************************************************
// Function:    publish_fault_report
//
// Purpose:     Publish a fault report message to the CAN bus.
//
// Returns:     void
//
// Parameters:  void
//
// ****************************************************************************
void publish_fault_report( void );


// ****************************************************************************
// Function:    check_for_incoming_message
//
// Purpose:     Check CAN bus for incoming frames and process any present.
//
// Returns:     void
//
// Parameters:  void
//
// ****************************************************************************
void check_for_incoming_message( void );


#endif /* _OSCC_SELECTOR_COMMUNICATIONS_H_ */
