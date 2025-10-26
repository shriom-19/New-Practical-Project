#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF

#define rs LATCbits.LATC0
#define en LATCbits.LATC1

void lcdcmd1(unsigned char command)
{
	LATCbits.LATC2 = (command) & 0x1;
	LATEbits.LATE0 = (command >> 1) & 0x1;
	LATEbits.LATE1 = (command >> 2) & 0x1;
	LATEbits.LATE2 = (command >> 3) & 0x1;
	en = 0;
	rs = 0;
	Delay10KTCYx(1);
	en = 1;
	Delay10KTCYx(1);
	en = 0;
	Delay10KTCYx(1);
}

void lcdcmd(unsigned char value)
{
	char lowernibble = value & 0x0f;
	char highernibble = (value >> 4) & 0x0f;
	lcdcmd1(highernibble);
	lcdcmd1(lowernibble);
	Delay10KTCYx(2);
}

void lcddata1(unsigned char data)
{
	LATCbits.LATC2 = (data) & 0x1;
	LATEbits.LATE0 = (data >> 1) & 0x1;
	LATEbits.LATE1 = (data >> 2) & 0x1;
	LATEbits.LATE2 = (data >> 3) & 0x1;
	rs = 1;
	Delay10KTCYx(1);
	en = 0;
	Delay10KTCYx(1);
	en = 1;
	Delay10KTCYx(1);
	en = 0;
	Delay10KTCYx(1);
}

void lcddata(unsigned char value)
{
	char lowernibble = value & 0x0f;
	char highernibble = (value >> 4) & 0x0f;
	lcddata1(highernibble);
	lcddata1(lowernibble);
	Delay10KTCYx(2);
}

void lcdinit()
{
	TRISEbits.RE0 = 0;
	TRISEbits.RE1 = 0;
	TRISEbits.RE2 = 0;
	TRISCbits.RC0 = 0;
	TRISCbits.RC1 = 0;
	TRISCbits.RC2 = 0;

	PORTEbits.RE0 = 0;
	PORTEbits.RE1 = 0;
	PORTEbits.RE2 = 0;
	PORTCbits.RC0 = 0;
	PORTCbits.RC1 = 0;
	PORTCbits.RC2 = 0;

	Delay10KTCYx(1);
	lcdcmd(0x03);
	Delay10KTCYx(1);
	lcdcmd(0x03);
	Delay10KTCYx(2);
	lcdcmd(0x03);
	Delay10KTCYx(2);
	lcdcmd(0x02);
	Delay10KTCYx(2);
	lcdcmd(0x28);
	lcdcmd(0x08);
	lcdcmd(0x0c);
	lcdcmd(0x06);
}

void main(void)
{
	lcdinit();
	while(1)
	{
		lcdcmd(0x80);
		lcddata('S');
		lcdcmd(0x81);
		lcddata('I');
		lcdcmd(0x82);
		lcddata('T');
		lcdcmd(0x83);
		lcddata('S');
		Delay10KTCYx(1);
	}
}

