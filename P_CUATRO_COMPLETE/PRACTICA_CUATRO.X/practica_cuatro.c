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

//LIBRARIES
#include <xc.h>
#define _XTAL_FREQ 4000000 

void main()
{

    TRISB = 0x00;           // CONFIGURANDO PUERTO B COMO SALIDA
    ANSELH = 0x00;         // CONFIGURANDO ENTRADAS COMO DIGITALES
    PORTD = 0xFF;           // CONFIGURANDO PUERTO D COMO ENTRADA
    
    while(1)
    {
        if(PORTDbits.RD0)
        {
            PORTB = PORTD; //&0x77;     AÑADIR ESTA LIINEA PARA ELIMINAR RB3 7 RB7 QUE NO SON UTILIZADOS
            __delay_ms(250);
            PORTB = 0x01;
            __delay_ms(250);
        }
        else
        {
            PORTB = 0; 
        }
    }
}



