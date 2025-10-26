/***************************************************************************
 File          : TESTADC.c
 Description   : Displays on-chip ADC output from variable resistor input.
***************************************************************************/
#include <p18f4520.h>
#include <stdio.h>


#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

void InitADC(void)
{
	TRISA0 = 1;
	ADCON0 = 0x01;
	ADCON1 = 0x0E;
	ADCON2 = 0x8E;
}

void main(void)
{
	unsigned int Result;
	unsigned long voltage;
	char adc_read[16];

	lcdinit();
	DisplayRow(1, "ADC POT TEST");
	InitADC();

	while(1)
	{
		ADCON0bits.GO = 1;
		while(ADCON0bits.GO);
		Result = (ADRESH << 8) + ADRESL;
		voltage = (Result * 5000UL) / 1024;
		sprintf(adc_read, "C=0x%X:%lumV", Result, voltage);
		DisplayRow(2, adc_read);
	}
}

