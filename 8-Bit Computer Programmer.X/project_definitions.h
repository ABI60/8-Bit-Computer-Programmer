#ifndef PROJECT_DEFINITIONS_H
    #define	PROJECT_DEFINITIONS_H


    //------------ Programming pins definitions ------------
    #define TRIS_5V  TRISAbits.TRISA4
    #define LAT_5V   LATAbits.LATA4
    #define PORT_5V  PORTAbits.RA4
    #define ANSEL_5V  ANSELAbits.ANSA4

    #define TRIS_DAT TRISAbits.TRISA3
    #define LAT_DAT  LATAbits.LATA3
    #define PORT_DAT PORTAbits.RA3
    #define ANSEL_DAT ANSELAbits.ANSA3

    #define TRIS_OE  TRISAbits.TRISA2
    #define LAT_OE   LATAbits.LATA2
    #define PORT_OE  PORTAbits.RA2
    #define ANSEL_OE  ANSELAbits.ANSA2

    #define TRIS_LAT TRISAbits.TRISA1
    #define LAT_LAT  LATAbits.LATA1
    #define PORT_LAT PORTAbits.RA1
    #define ANSEL_LAT ANSELAbits.ANSA1

    #define TRIS_CLK TRISAbits.TRISA0
    #define LAT_CLK  LATAbits.LATA0
    #define PORT_CLK PORTAbits.RA0
    #define ANSEL_CLK ANSELAbits.ANSA0

    //------------ Other pin definitions ------------
    #define TRIS_LED_RED     TRISBbits.TRISB3
    #define LAT_LED_RED      LATBbits.LATB3
    #define PORT_LED_RED     PORTBbits.RB3
    #define ANSEL_LED_RED    ANSELBbits.ANSB3

    #define TRIS_LED_ORANGE  TRISBbits.TRISB4
    #define LAT_LED_ORANGE   LATBbits.LATB4
    #define PORT_LED_ORANGE  PORTBbits.RB4
    #define ANSEL_LED_ORANGE ANSELBbits.ANSB4

    #define TRIS_LED_GREEN   TRISBbits.TRISB5
    #define LAT_LED_GREEN    LATBbits.LATB5
    #define PORT_LED_GREEN   PORTBbits.RB5
    #define ANSEL_LED_GREEN  ANSELBbits.ANSB5

    #define TRIS_INT         TRISBbits.TRISB0
    #define LAT_INT          LATBbits.LATB0
    #define PORT_INT         PORTBbits.RB0

    #define TRIS_PGD         TRISBbits.TRISB7
    #define LAT_PGD          LATBbits.LATB7
    #define PORT_PGD         PORTBbits.RB7
    #define ANSEL_PGD        ANSELBbits.ANSB7

    #define TRIS_PGC         TRISBbits.TRISB6
    #define LAT_PGC          LATBbits.LATB6
    #define PORT_PGC         PORTBbits.RB6
    #define ANSEL_PGC        ANSELBbits.ANSB6

    //------------ General Definitions ------------
    #define MODE_STANDBY     0
    #define MODE_CONNECTED24 1
    #define MODE_CONNECTED40 2
    #define MODE_PROGRAM     3


    #define CMD_PING         0x01
    #define CMD_RESTART      0x02
    #define CMD_MODE_24      0x03
    #define CMD_MODE_40      0x04
    #define CMD_MODE         0x05
    #define CMD_MODE_PROGRAM 0x06


    #define CMD_RESET       0x07
    #define CMD_RESET_HOLD  0x08
    #define CMD_HALT        0x09
    #define CMD_RELEASE     0x0A
    #define CMD_CLOCK       0x0B
    #define CMD_CLOCK_RAISE 0x0C
    #define CMD_CLOCK_FALL  0x0D
    #define CMD_PC_ENABLE   0x0E
    #define CMD_PC_DISABLE  0x0F


    #define STATUS_ACK          0xFF
    #define STATUS_NACK         0x00
    #define STATUS_MODE_24      0x0F
    #define STATUS_MODE_40      0xF0
    #define STATUS_MODE_STANDBY 0xCC
    #define STATUS_MODE_PROGRAM 0x33












    //Mask for command shift register(7-bits)
    #define MASK_PC_EN          0b1000000
    #define MASK_HALT           0b0100000
    #define MASK_RESET          0b0010000
    #define MASK_CLOCK          0b0001000
    #define MASK_EEPROM_WE      0b0000100
    #define MASK_ASSERT_ADDRESS 0b0000010
    #define MASK_ASSERT_DATA    0b0000001

    //Set & clear macros for the command shift register
    #define set_mask(value, mask)   (value |= mask)
    #define clear_mask(value, mask) (value &= ~mask)

    //------------ Functions & Macro functions ------------
       void programmer_init(void);    
    uint8_t check_cks(void);
    
#endif

