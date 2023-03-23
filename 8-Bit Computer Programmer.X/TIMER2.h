#ifndef TIMER2_H

#include "project_definitions.h"

    #define	TIMER2_H


    //------------ Functions & Macro functions ------------

    /**
     * Resets the TIMER1 registers and starts the TIMER1
     */
    #define blink_enable()  TMR2_enable()
    #define TMR2_enable() {\
                           T2CONbits.TMR2ON = 1;\
                          }

    /**
     * Stops the timer and clears the TIMER1 flag\n
     * - Turns all status LEDs off
     */
    #define blink_disable() TMR2_disable()
    #define TMR2_disable() {\
                            LAT_LED_RED    = 0;\
                            LAT_LED_ORANGE = 0;\
                            LAT_LED_GREEN  = 0;\
                            T2CONbits.TMR2ON = 0;\
                           }

    void TMR2_init(void);
    
    //------------ Global Variables ------------
    extern uint8_t TMR2_counter;


#endif	/* TIMER2_H */

