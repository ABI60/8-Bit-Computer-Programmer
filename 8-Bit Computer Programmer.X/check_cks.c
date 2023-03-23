#include "config.h"
#include "UART.h"

/**
 * Performs a checksum calculation on the UART buffer and returns the result
 * @return 1-> Correct checksum, 0-> Wrong checksum
 */
uint8_t check_cks(){
    
    //Calculate the sum of all bytes
    uint16_t result = 0;    
    for(uint8_t i = 0; i < UART_MAX_RECEIVE_BYTES; i++){
        result += UART_receive_buffer[i];
    }
    
    //Perform the 1's complement addition
    result = (result>>8) + (result & 0xFF);
    
    //Chech the result(all 1's means checksum is correct)
    if(result == 255) return 1;
    return 0;
}
