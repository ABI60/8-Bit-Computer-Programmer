#ifndef UART_H
    #define	UART_H


    //-------------------------- General Definitions --------------------------
    #define UART_MAX_RECEIVE_BYTES 4


    //---------------------- Functions & Macro functions ----------------------
    /**
     * Enables UART receive circuitry after clearing the FIFO
     */
    #define UART_enable_receive() {\
                                   RCREG;\
                                   RCREG;\
                                   RCSTAbits.CREN = 1;\
                                  }

    /**
     * Disables UART receive circuitry and clears the FIFO
     */
    #define UART_disable_receive() {\
                                   RCSTAbits.CREN = 0;\
                                   RCREG;\
                                   RCREG;\
                                  }

    /**
     * Reads and returns a single 8-bit data from FIFO through UART
     * @return Read 8-bit data
     */
    #define UART_read() (RCREG)

       void UART_init(void);
       void UART_send(uint8_t);
    uint8_t UART_receive_error_check(void);
    
    //--------------------------- Global Variables ---------------------------
    extern volatile char UART_receive_buffer[];
    extern uint8_t UART_receive_pointer;
    
    
#endif	/* UART_H */

