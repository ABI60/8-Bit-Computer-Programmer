#include "config.h"
#include "ADC.h"


/**
 * Initializes everything related to ADC
 */
void ADC_init(){
    
    /*
     * X
     * CHS = 00100
     * GO/DONE = 0
     * ADON = 1
     */
    ADCON0 = 0b00010001;
    
    /*
     * ADFM = 0
     * ADCS = 010
     * X
     * ADNREF = 0
     * ADPREF = 00
     */
    ADCON1 = 0b00100000;
}