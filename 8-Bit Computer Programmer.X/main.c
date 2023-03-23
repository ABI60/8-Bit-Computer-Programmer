#include "config.h"
#include "project_definitions.h"
#include "SR.h"
#include "UART.h"
#include "ADC.h"
#include "TIMER1.h"
#include "TIMER2.h"

#pragma warning disable 520

// <editor-fold defaultstate="collapsed" desc="Project Flags & Modes">
static volatile uint8_t MENU_programmer_mode  = MODE_STANDBY;
static volatile bool    MENU_f_first_entrance = true;

static volatile bool f_packet_complete = false;
static volatile bool f_receive_problem = false;

static volatile bool f_blink_red    = false;
static volatile bool f_blink_orange = false;
static volatile bool f_blink_green  = false;

static uint8_t command  = SR_RESET;
static uint16_t data     = 0;
static uint16_t address  = 0;
// </editor-fold>


void main(void){
    
    
    programmer_init();
    ei();
    while(1){
        
        
        //--------------------------- HANDLING INFO ---------------------------
        
    
        // <editor-fold defaultstate="collapsed" desc="Problem Handling">
        if(f_receive_problem == true){
            f_receive_problem = false;
            MENU_programmer_mode = MODE_STANDBY;
            MENU_f_first_entrance = true;
            __delay_ms(100);
            UART_enable_receive();
        }        
        // </editor-fold>
        
    
        //------------------------------- MODES -------------------------------        
        switch(MENU_programmer_mode){
            
            case MODE_STANDBY:
                if(MENU_f_first_entrance == true){
                    MENU_f_first_entrance = false;
                    SR_output_disable();
                    SR_clear();
                    LAT_LED_ORANGE = 0;
                    LAT_LED_GREEN  = 0;
                    f_blink_red    = true;
                    f_blink_orange = false;
                    f_blink_green  = false;
                    blink_enable();
                }
                
                if(f_packet_complete == true){
                    f_packet_complete = false;
                    
                    UART_enable_receive();
                    switch(UART_receive_buffer[0]){
                        case CMD_PING:
                            UART_send(STATUS_ACK);
                            MENU_programmer_mode = MODE_CONNECTED24;
                            MENU_f_first_entrance = true;
                            break;
                        case CMD_RESTART:
                            UART_send(STATUS_ACK);
                            break;
                        case CMD_MODE_24:
                            break;
                        case CMD_MODE:
                            UART_send(STATUS_MODE_STANDBY);
                            break;
                        default:
                            UART_send(STATUS_NACK);
                    }
                }
                break;
                
            case MODE_CONNECTED24:
                if(MENU_f_first_entrance == true){
                    MENU_f_first_entrance = false;
                    blink_disable();
                    LAT_LED_RED    = 0;
                    LAT_LED_ORANGE = 0;
                    LAT_LED_GREEN  = 1;
                }
                
                if(f_packet_complete == true){
                    f_packet_complete = false;
                    
                    switch(UART_receive_buffer[0]){
                        case CMD_PING:
                            UART_send(STATUS_ACK);
                            break;
                        case CMD_MODE:
                            UART_send(STATUS_MODE_24);
                            break;
                        case CMD_RESTART:
                            MENU_programmer_mode = MODE_STANDBY;
                            MENU_f_first_entrance = true;
                            UART_send(STATUS_ACK);
                            break;
                        default:
                            UART_send(STATUS_NACK);
                    }
                    UART_enable_receive();
                }
                break;
        }
    }
    
return;}


void __interrupt() ISR(){
    
    // <editor-fold defaultstate="collapsed" desc="INT INTERRUPT (PROGRAMMER BUTTON)">
    if(INTCONbits.INTF == 1){
        
        LAT_LED_RED    = 1;
        LAT_LED_ORANGE = 1;
        LAT_LED_GREEN  = 1;
        __delay_ms(1000);
        //Clear the interrupt flag
        INTCONbits.INTF = 0;
    }
    // </editor-fold>
    
    // <editor-fold defaultstate="collapsed" desc="TIMER1 INTERRUPT (CONNECTION TIMEOUT)">
    if(PIR1bits.TMR1IF == 1){
        
        //Increment the global counter
        TMR1_counter++;
        
        //If the below delay is reached, set the error flag
        //1.048s delay [1 interrupt period[s] = 4*8*65536/Fosc]
        if(TMR1_counter == 12){
            TMR1_counter = 0;
            f_receive_problem = true;
        }
        
        //Clear the interrupt flag
        PIR1bits.TMR1IF = 0;
    }
    // </editor-fold>
    
    // <editor-fold defaultstate="collapsed" desc="TIMER2 INTERRUPT (LED BLINK)">
    if(PIR1bits.TMR2IF == 1){
        
        //Increment the global counter
        TMR2_counter++;
        
        //Blink LEDs accordingly
        //0.217 delay [1 interrrupt period[s] = 4*16*64*255/Fosc]
        if(TMR2_counter == 5){
            TMR2_counter = 0;            
            if(f_blink_red    == true) LAT_LED_RED    = ~LAT_LED_RED;
            if(f_blink_orange == true) LAT_LED_ORANGE = ~LAT_LED_ORANGE;
            if(f_blink_green  == true) LAT_LED_GREEN  = ~LAT_LED_GREEN;
        }
        
        //Clear the interrupt flag
        PIR1bits.TMR2IF = 0;
    }
    // </editor-fold>
    
    // <editor-fold defaultstate="collapsed" desc="UART RX INTERRUPT">
    if(PIR1bits.RCIF == 1){
        

        //If there is no error, read the byte into buffer...
        if(UART_receive_error_check() == true){
            UART_disable_receive();
            UART_receive_pointer = 0;
            f_receive_problem = true;
        }
        else{
            UART_receive_buffer[UART_receive_pointer] = UART_read();
            UART_receive_pointer++;
        }
        
        //If a whole packet is received...
        if(UART_receive_pointer == UART_MAX_RECEIVE_BYTES){
            UART_disable_receive();
            UART_receive_pointer = 0;
            TMR1_counter = 0;
            if(check_cks() == 1) f_packet_complete = true;
            else f_receive_problem = true;
        }
    }
    // </editor-fold>
    
}