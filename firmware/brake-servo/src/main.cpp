/**
 * @file main.cpp
 *
 */


#include "arduino_init.h"
#include "can_protocols/brake_can_protocol.h"
#include "communications.h"
#include "debug.h"
#include "init.h"
#include "brake_servo_control.h"


int main( void )
{
    init_arduino( );

    init_globals( );

    init_devices( );

    init_communication_interfaces( );

    start_timers( );

    DEBUG_PRINTLN( "init complete" );

    while( true )
    {
#ifdef __AVR_ATmega32U4__
        RXLED1;
#endif
        check_for_incoming_message( );

        check_for_faults( );
    }
}
