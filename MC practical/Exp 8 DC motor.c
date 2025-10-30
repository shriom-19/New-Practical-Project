#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF

void main()
{
	unsigned char dc;
	TRISC = 0;
	PORTC = 0;

	PR2 = 0b01111100;
	T2CON = 0b00000101;
	CCP1CON = 0b00001100;
	CCP2CON = 0b00111100;

	for (;;)
	{
		for (dc = 0; dc < 128; dc++)
		{
			CCPR1L = dc;
			CCPR2L = 128 - dc;
			Delay10KTCYx(50);
		}
		for (dc = 127; dc > 0; dc--)
		{
			CCPR1L = dc;
			CCPR2L = 128 - dc;
			Delay10KTCYx(50);
		}
	}
}

