/*
 * app1.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */


#include<avr/delay.h>
#include<avr/io.h>
#include"lcd.h"
#include"uart.h"


int main(void)
{
	uint8_t num = 0;
	DDRB &= ~(1<<PB2);
	DDRC &= ~(1<<PC4);

	LCD_init();
	UART_init();
	LCD_clearScreen();


	while(1)
	{
		LCD_goToRowColumn(0,0);
		if((PINB & (1<<PB2)))
		{
			if(num != 255)
			{
				num++;
			}
			while((PINB & (1<<PB2)));
		}
		else if((PINC & (1<<PC4)))
		{
			if(num != 0)
			{
				num--;
			}
			while((PINC & (1<<PC4)));
		}


		LCD_intgerToString(num);
		LCD_displayString("         ");
		UART_sendByte(num);
	}
}
