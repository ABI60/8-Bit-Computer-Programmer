#include "config.h"
#include "UART.h"


/**
 * Sends a single 8-bit data through UART
 * @param data: 8-bit data to be sent
 */
void UART_send(uint8_t data) {
    
    // Wait for the TSR to empty
    while(TXSTAbits.TRMT == 0);
    
    // Send the data
    TXREG = data;
}
