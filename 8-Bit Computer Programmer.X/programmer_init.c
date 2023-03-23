#include "config.h"
#include "project_definitions.h"
#include "SR.h"
#include "UART.h"
#include "TIMER1.h"
#include "TIMER2.h"
#include "ADC.h"


/**
 * Initializes general programmer configurations\n
 * (doesn't enable global interrupts or shift register outputs)
 */
void programmer_init(){
    
    //------------ Programming pins configurations ------------
    LAT_DAT  = 0;
    LAT_OE   = 0;
    LAT_LAT  = 0;
    LAT_CLK  = 0;
    
    TRIS_DAT = 0;
    TRIS_OE  = 0;
    TRIS_LAT = 0;
    TRIS_CLK = 0;
    
    //------------ Other pin configurations ------------
    LAT_LED_RED     = 0;
    LAT_LED_ORANGE  = 0;
    LAT_LED_GREEN   = 0;
    LAT_PGD         = 0;
    
    TRIS_LED_RED    = 0;
    TRIS_LED_ORANGE = 0;
    TRIS_LED_GREEN  = 0;
    TRIS_PGD        = 0;
    TRIS_PGC        = 0;
    
    //------------ General configurations ------------
    
    //Enable the external intertup(rising edge by default)
    INTCONbits.INTF = 0;
    INTCONbits.INTE = 1;
    
    //Call initialization functions
    
    UART_init();
    ADC_init();
    TMR1_init();
    TMR2_init();
    TMR1_enable();
}
