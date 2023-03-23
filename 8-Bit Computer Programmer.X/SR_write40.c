#include "config.h"
#include "project_definitions.h"
#include "SR.h"

/**
 * Writes the command, data and addresses to the shift registers
 * and latches them to the output(40-Bit Mode)
 * @param command: 8-bit command
 * @param data: 16-bit data
 * @param address: 16-bit address
 */
void SR_write40(uint8_t command, uint16_t data, uint16_t address){

    //Write the address value
    for(uint8_t i = 0; i<16; i++){
        LAT_DAT = (uint8_t)address;
        SR_clk();
        address = address >> 1;
    }

    //Write the data value
    for(uint8_t i = 0; i<16; i++){
        LAT_DAT = (uint8_t)data;
        SR_clk();
        data = data >> 1;
    }

    //Write the command value
    for(uint8_t i = 0; i<8; i++){
        LAT_DAT = command;
        SR_clk();
        command = command >> 1;
    }
    
    //Latch the output
    SR_latch();
}