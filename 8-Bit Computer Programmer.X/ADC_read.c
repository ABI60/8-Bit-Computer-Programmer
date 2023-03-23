#include "config.h"
#include "ADC.h"


/**
 * Reads the selected ADC channel and returns an 8-bit left justified result
 */
uint8_t ADC_read(){
    
    //Acquisition delay(chosen arbitrarily)
    __delay_us(10);
    
    //Read the ADC and returns the 8-bit left justified result
    ADCON0bits.GO_nDONE = 1;    
    while(ADCON0bits.GO_nDONE == 1);    
    return ADRESH;
}
