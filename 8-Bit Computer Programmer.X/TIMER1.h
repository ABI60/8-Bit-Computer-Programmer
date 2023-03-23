#ifndef TIMER1_H
    #define	TIMER1_H


    //------------ Functions & Macro functions ------------
    /**
     * Resets the TIMER1 registers and starts the TIMER1
     */
    #define TMR1_enable() {\
                           TMR1H = 0;\
                           TMR1L = 0;\
                           T1CONbits.TMR1ON = 1;\
                          }

    /**
     * Stops the timer and clears the TIMER1 flag
     */
    #define TMR1_disable() {\
                            PIR1bits.TMR1IF = 0;\
                            T1CONbits.TMR1ON = 0;\
                           }

    void TMR1_init(void);
    
    //------------ Global Variables ------------
    extern uint8_t TMR1_counter;


#endif	/* TIMER1_H */

