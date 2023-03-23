#include "config.h"
#include "UART.h"


//Define global variables
volatile char UART_receive_buffer[UART_MAX_RECEIVE_BYTES];
uint8_t UART_receive_pointer = 0;

/**
 * Initializes everything related to UART(including interrupts)\n
 * (Doesn't enable global interrupts)
 */
void UART_init() {
    
    //Configure I/Os
    ANSELBbits.ANSB1 = 0;  //RX pin as digital
    TRISBbits.TRISB1 = 1;  //RX pin as input
    TRISBbits.TRISB2 = 0;  //TX pin as output
    
    /*
     * CSRC  = x(0)
     * TX9   = 0
     * TXEN  = 1
     * SYNC  = 0
     * SENDB = 0
     * BRGH  = 1
     * TRMT  = x(1)
     * TX9D  = x(0)
     */
    TXSTA = 0b00100110;
    
    /*
     * SPEN  = 1
     * RX9   = 0
     * SREN  = x(0)
     * CREN  = 1
     * ADDEN = 0
     * FERR  = x(0)
     * OERR  = x(0)
     * RX9D  = x(0)
     */
    RCSTA = 0b10010000;
    
    //Select 16-bit baud rate counter
    BAUDCONbits.BRG16 = 1;
    
    /* 
     * Baud rate: (Fosc/[4*(SPBRG+1)) 
     * BD = 115200 -> SPBRG = 51.08
     */
    SPBRG = 51;
    
    //Interrupt setup
    RCREG;
    RCREG;
    INTCONbits.PEIE = 1;
    PIE1bits.RCIE = 1;
}