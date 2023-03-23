#ifndef SR_H
    #define	SR_H


    //-------------------------- General Definitions --------------------------
    #define SR_RESET 0b01000000

    //---------------------- Functions & Macro functions ----------------------
    /**
     * Enables power on the 5v output
     */
    #define SR_power_enable() {LAT_PGD = 1;}

    /**
     * Disables power on the 5v output
     */
    #define SR_power_disable() {LAT_PGD = 0;}

    /**
     * Enables the output of the command shift register
     */
    #define SR_output_enable() {LAT_OE = 1;}

    /**
     * Disables the output of the command shift register
     */
    #define SR_output_disable() {LAT_OE = 0;}

    /**
     * Sends a clock signal to the shift register clock pin
     */
    #define SR_clk() {LAT_CLK = 1; NOP(); LAT_CLK = 0;}

    /**
     * Sends a clock signal to the shift register latch pin
     */
    #define SR_latch() {LAT_LAT = 1; NOP(); LAT_LAT = 0;}

    /**
     * Writes the reset value to the shift registers
     */
    #define SR_clear() {SR_write40(SR_RESET, 0, 0);}

    void SR_write24(uint8_t, uint8_t, uint8_t);
    void SR_write40(uint8_t, uint16_t, uint16_t);
    
    

#endif	/* SR_H */

