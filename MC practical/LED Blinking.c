#include <p18f4520.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF

unsigned char g_ui8TimerOnflag = 0;

void Timer0Init()
{
	T0CONbits.T0PS0 = 1;
	T0CONbits.T0PS1 = 1;
	T0CONbits.T0PS2 = 1;
	T0CONbits.PSA = 0;
	T0CONbits.T0SE = 0;
	T0CONbits.T0CS = 0;
	T0CONbits.T08BIT = 0;
	T0CONbits.TMR0ON = 1;
	TMR0H = 0xB3;
	TMR0L = 0xB4;

	RCONbits.IPEN = 1;
	INTCONbits.GIE = 1;
	INTCONbits.PEIE = 1;
	INTCONbits.TMR0IE = 1;
	INTCONbits.TMR0IF = 0;
	INTCON2bits.TMR0IP = 1;
}

void TMRISR(void);
#pragma code InterruptVectorHigh = 0x08
void InterruptVectorHigh(void)
{
	_asm
		goto TMRISR
	_endasm
}
#pragma code
#pragma interrupt TMRISR
void TMRISR(void)
{
	if (INTCONbits.TMR0IF == 1)
	{
		INTCONbits.TMR0IF = 0;
		TMR0H = 0xB3;
		TMR0L = 0xB4;

		if (g_ui8TimerOnflag)
		{
			PORTD = 0x00;
			g_ui8TimerOnflag = 0;
		}
		else
		{
			PORTD = 0xFF;
			g_ui8TimerOnflag = 1;
		}
	}
}

void main(void)
{
	Timer0Init();
	g_ui8TimerOnflag = 0;
	TRISD = 0x00;
	PORTD = 0x00;

	while (1) {}
}

