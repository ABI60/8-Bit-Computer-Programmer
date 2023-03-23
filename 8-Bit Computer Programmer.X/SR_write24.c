#include "config.h"
#include "project_definitions.h"
#include "SR.h"

/**
 * Writes the command, data and addresses to the shift registers
 * and latches them to the output(24-Bit Mode)
 * @param command: 8-bit command
 * @param data: 8-bit data
 * @param address: 8-bit address
 */
void SR_write24(uint8_t command, uint8_t data, uint8_t address){
    
    //Write the address value
    for(uint8_t i = 0; i<8; i++){
        LAT_DAT = address;
        SR_clk();
        address = address >> 1;
    }

    //Write the data value
    for(uint8_t i = 0; i<8; i++){
        LAT_DAT = data;
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