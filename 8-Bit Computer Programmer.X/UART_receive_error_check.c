#include "config.h"
#include "UART.h"


/**
 * Check for errors for the next received byte for UART
 * (should be done before reading the byte)\n
 * Restarts the UART if an overrun or framing error occurs
 * @return 0-> No errors, 1-> Error detected
 */
uint8_t UART_receive_error_check() {
    
    /*
     * If an overrun or framing error occurs:
     * Disable disable UART
     * Wait for 1 instruction(just in case)
     * Re-enable UART
     */
    if(RCSTAbits.OERR == 1 || RCSTAbits.FERR == 1){
        RCSTAbits.SPEN = 0;
        NOP();
        RCSTAbits.SPEN = 1;
        return 1;
    }
    
    // No errors
    return 0;
}