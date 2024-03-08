/*
 * FireFighter.c
 *
 * Created: 1/25/2024 6:52:55 PM
 * Author : Omar Yasser
 */ 

/*************************************************** Include Section ****************************************************/
#define F_CPU 8E6
#include <util/delay.h>
#include "StdTypes.h"
#include "Temp_interface.h"
#include "Pressure_Interface.h"
#include "LCD_Interface.h"
#include "ADC_Interface.h"
#include "NVM_Interface.h"
#include "password.h"
#include "filter.h"
#include "start_window.h"
#include "Runnable_APP_Service.h"
#include "Interrupt_Interface.h"

/***************************************************** Variable Section **************************************************/
volatile u8 first = 0;

/***************************************************** CallBack Function *************************************************/
void EXINT2_FN(void)
{
	LCD_CLR();
	LCD_SET_CURSOR(1,1);
	LCD_WRITE_STRING("Old:");
	
	if( password_check() == valid )
	{
		LCD_SET_CURSOR(2,1);
		LCD_WRITE_STRING("New:");
		password_change();
		LCD_CLR();
		LCD_WRITE_STRING("Password change");
		_delay_ms(150);
		LCD_CLR();
	}
	else
	{
		return;
	}
}
 
/********************************************************** Main *********************************************************/
int main(void)
{
	/* Enable the global interrupt */
	ENABLE_GI();
	
    /* Initialization */
	DIO_INIT();
	LCD_INIT();
	NVM_INIT();
	ADC_INIT(VREF_VCC,PRESCALAR_64);
	PRESSURE_INIT();
	TEMP_INIT();
	Filter_INIT();
	password_set();
	EXI_INIT(INT2);
	EXI_CONTROL(INT2,ENABLE);
	EXI_TRIG_EDGE(INT2,RISING_EDGE);
	EXI_CALLBACK(INT2,EXINT2_FN);
	
	// Custom shape
	u8 shape[8]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	LCD_DRAW(0,shape);
	
	// start shape
	start();
		
    while (1) 
    {
		
		first_window (first);
		
		RunnableApp();
    }
	
}

