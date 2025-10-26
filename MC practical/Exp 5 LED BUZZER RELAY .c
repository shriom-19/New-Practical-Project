#include <p18f4520.h>
#include <delays.h>

#define BUZZER  LATAbits.LATA3
#define SWITCH0 PORTBbits.RB0
#define SWITCH1 PORTBbits.RB1

void main(void)
{
    TRISA = 0x00;
    TRISB = 0xFF;
    TRISD = 0x00;
    LATD = 0x00;

    while (1)
    {
        if (!SWITCH1)
        {
            while (1)
            {
                BUZZER = 1;
                LATD = 0x30 | 0x01; Delay10KTCYx(100);
                LATD = 0x30 | 0x02; Delay10KTCYx(100);
                LATD = 0x30 | 0x04; Delay10KTCYx(100);
                LATD = 0x30 | 0x08; Delay10KTCYx(100);

                if (!SWITCH0) break;
            }
        }
        else if (!SWITCH0)
        {
            while (1)
            {
                BUZZER = 0;
                LATD = 0x00 | 0x08; Delay10KTCYx(100);
                LATD = 0x00 | 0x04; Delay10KTCYx(100);
                LATD = 0x00 | 0x02; Delay10KTCYx(100);
                LATD = 0x00 | 0x01; Delay10KTCYx(100);

                if (!SWITCH1) break;
            }
        }
    }
}

