/*
 * app1.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */


#include<avr/delay.h>
#include<avr/io.h>
#include"lcd.h"
#include "uart.h"


int main(void)
{
	uint8_t num = 0;
	LCD_init();
	UART_init();
	LCD_clearScreen();


	while(1)
	{
		num = UART_recieveByte();
		LCD_goToRowColumn(0,0);

		LCD_intgerToString(num);
	}
}
