/*
 * start_window.c
 *
 * Created: 3/8/2024 9:48:34 PM
 *  Author: Omar Yasser
 */ 


/**************************************************** Include Section ****************************************************/
#include "LCD_Interface.h"
#include "start_window.h"

/************************************************ Function Implementation ************************************************/
void start(void)
{
	LCD_SET_CURSOR(1,1);
	LCD_WRITE_STRING("   Welcome   ");
	LCD_SET_CURSOR(2,1);
	for (u8 i = 0 ; i < 16 ; i++)
	{
		LCD_WRITE_STRING(0);
	}
	LCD_SET_CURSOR(1,1);
	LCD_CLR();
	return;
}

void first_window (u8 first)
{
	if(first == 0)
	{
		DIO_WritePin(motor,LOW);
		
		LCD_CLR();
		LCD_SET_CURSOR(1,1);
		LCD_WRITE_STRING("Temp:");
		LCD_SET_CURSOR(2,1);
		LCD_WRITE_STRING("State:");
	}
	
}