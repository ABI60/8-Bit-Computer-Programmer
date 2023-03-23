#include "config.h"
#include "TIMER1.h"


//Define gloabal variables
uint8_t TMR1_counter = 0;


/**
 * Initializes everything related to TIMER1(including interrupts)\n
 * - Not enabled by default\n
 * - Doesn't enable global interrupts\n
 * - 1 interrrupt period[s] = 4*8*65536/Fosc
 */
void TMR1_init(){
    
    //Initialize the TIMER1 registers
    TMR1H = 0;
    TMR1L = 0;
    
    /*
     * TMR1CS = 00
     * T1CKPS = 11
     * T1OSCEN = 0
     * T1SYNC = x(0)
     * X
     * TMR1ON = 1
     */
    T1CON = 0b00110000;
    
    //Interrupt setup for TIMER1
    INTCONbits.PEIE = 1;
    PIR1bits.TMR1IF = 0;
    PIE1bits.TMR1IE = 1;
}
