/*
 * MENU.c
 *
 * Created: 1/22/2024 6:47:31 PM
 *  Author: Omar Yasser
 */ 

/***************************** Include Section *******************************/
#define F_CPU 8E6
#include <util/delay.h>
#include "StdTypes.h"
#include "LCD_Interface.h"
#include "KEYPAD_Interface.h"
#include "MENU.h"

/**************************** Function Implementation ************************/

void start(void)
{	
	LCD_CLR();
	LCD_WRITE_STRING("  Omar Yasser  ");
	for (u8 i = 1 ; i < 16 ; i++)
	{
		LCD_SET_CURSOR(2,i);
		LCD_WRITE_STRING(0);
		_delay_ms(150);
	}
	LCD_CLR();
	LCD_SET_CURSOR(1,1);
}

MODE_RET menu(void)
{
	u8 mode;
	
	LCD_WRITE_STRING("  Select mode  ");
	_delay_ms(1000);
	LCD_CLR();
	
    LCD_SET_CURSOR(1,1);
	LCD_WRITE_STRING("1-Converter");
	LCD_SET_CURSOR(2,1);
	LCD_WRITE_STRING("2-Calculator");
	
	st:
	mode = KEYPAD_GET_KEY();
	if(mode =='1')
	{
		return converter_mode;
	}
	else if (mode =='2')
	{
		return calculator_mode;
	}
	else
	{
		goto st;
	}
}