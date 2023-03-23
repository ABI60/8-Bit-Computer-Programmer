#include "config.h"
#include "TIMER2.h"


//Define gloabal variables
uint8_t TMR2_counter = 0;


/**
 * Initializes everything related to TIMER2(including interrupts)\n
 * - Not enabled by default\n
 * - Doesn't enable global interrupts\n
 * - 1 interrrupt period[s] = 4*16*64*255/Fosc
 */
void TMR2_init(){
    
    /*
     * X
     * TOUTPS = 1111
     * TMR2ON = 0
     * T2CKPS = 11
     */
    T2CON = 0b01111011;
    
    //Interrupt setup for TIMER2
    INTCONbits.PEIE = 1;
    PIR1bits.TMR2IF = 0;
    PIE1bits.TMR2IE = 1;
}