

#include <p18f4520.h>
#include <stdio.h>
#include <delays.h>


#define rs LATCbits.LATC0
#define en LATCbits.LATC1

void lcd_nibble(unsigned char data, unsigned char isData)
{
    LATCbits.LATC2 = (data) & 0x1;
    LATEbits.LATE0 = (data >> 1) & 0x1;
    LATEbits.LATE1 = (data >> 2) & 0x1;
    LATEbits.LATE2 = (data >> 3) & 0x1;
    rs = isData;
    en = 1;
    Delay10KTCYx(1);
    en = 0;
    Delay10KTCYx(1);
}

void lcd_send(unsigned char value, unsigned char isData)
{
    unsigned char high = (value >> 4) & 0x0F;
    unsigned char low  = value & 0x0F;
    lcd_nibble(high, isData);
    lcd_nibble(low, isData);
    Delay10KTCYx(2);
}

void lcdcmd(unsigned char cmd)
{
    lcd_send(cmd, 0);
}

void lcddata(unsigned char data)
{
    lcd_send(data, 1);
}

void lcdinit(void)
{
    TRISEbits.RE0 = 0;
    TRISEbits.RE1 = 0;
    TRISEbits.RE2 = 0;
    TRISCbits.RC0 = 0;
    TRISCbits.RC1 = 0;
    TRISCbits.RC2 = 0;

    LATE = 0;
    LATC = 0;

    Delay10KTCYx(2);
    lcdcmd(0x03);
    lcdcmd(0x03);
    lcdcmd(0x03);
    lcdcmd(0x02);
    lcdcmd(0x28);
    lcdcmd(0x0C);
    lcdcmd(0x06);
}

void DisplayRow(int row, char *str)
{
    int k = 0;
    lcdcmd(row == 1 ? 0x80 : 0xC0);

    while (str[k] && k < 16)
    {
        lcddata(str[k]);
        k++;
    }
    while (k < 16)
    {
        lcddata(' ');
        k++;
    }
}

