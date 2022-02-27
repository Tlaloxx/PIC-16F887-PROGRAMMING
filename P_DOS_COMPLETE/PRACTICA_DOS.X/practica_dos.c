// PIC16F887 Configuration Bit Settings
// SAUCEDA ALVAREZ JOSE LUIS TLALOC

// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#include <xc.h>
#define _XTAL_FREQ 4000000 

void main(void) {
    TRISD = 0xFF;           // DECLARACION DE TODO EL PUERTO D COMO ESTRADA
    TRISB = 0x00;           // DECLARACION DE TODO EL PUERTO B COMO SALIDA
    
   PORTD = 0x00;          // DECLARAR UN ESTADO INICIAL EN CERO EN PORT D
   PORTB = 0xFF;          // DECLARAR UN ESTADO INICIAL EN CERO EN PORT B
    
    ANSEL = 0x00;           // DEFINIR ENTRADA COMO DIGITALES (ANALOGICO = 1)
    ANSELH = 0x00;         // DEFINIR ENTRADAS DIGITALES
    
    while(1){
        PORTB = PORTD;
    }
}


