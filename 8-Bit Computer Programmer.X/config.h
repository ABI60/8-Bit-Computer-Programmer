#ifndef CONFIG_H
    #define	CONFIG_H

    // PIC16F1826 Configuration Bit Settings

    // 'C' source line config statements

    // CONFIG1
    #pragma config FOSC = HS        // Oscillator Selection (HS Oscillator, High-speed crystal/resonator connected between OSC1 and OSC2 pins)
    #pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
    #pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT enabled)   !!!!!!!!!!!!!!!!!!!!!!!!!!!!SHOULD BE "ON"
    #pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
    #pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
    #pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
    #pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
    #pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
    #pragma config IESO = ON        // Internal/External Switchover (Internal/External Switchover mode is enabled)
    #pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

    // CONFIG2
    #pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
    #pragma config PLLEN = ON       // PLL Enable (4x PLL enabled)
    #pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
    #pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
    #pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

    //System clock frequency
    #define _XTAL_FREQ 24000000

    //Project includes
    #include <xc.h>
    #include <stdint.h>
    #include "bool.h"

#endif	/* CONFIG_H */

