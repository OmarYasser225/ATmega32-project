/*
 * converter.c
 *
 * Created: 1/22/2024 6:18:21 PM
 * Author : Omar Yasser
 */

/****************************************** Include Section ************************************/
#define F_CPU 8E6
#include <util/delay.h> 
#include "MemoryMap.h"
#include "LCD_Interface.h"
#include "KEYPAD_Interface.h"
#include "DIO_Interface.h"
#include "MENU.h"
#include "converter.h"
#include "Calculator.h"

/******************************************** Main Function *************************************/

int main(void)
{
	// Initialization 
	DIO_INIT();
	LCD_INIT();
	KEYPAD_INIT();
	
	// Custom shape
	u8 shape[8]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	LCD_DRAW(0,shape);
	
	// entry
	start();
	
    while (1) 
    {
		// Main program 
		LCD_CLR();
		MODE_RET mode = menu();
		if(mode == converter_mode)
		{
			converter_menu();
		}
		else
		{
			calculator_menu();
		}
    }
}

