/*
 * Runnable_APP_Service.c
 *
 * Created: 3/8/2024 10:08:56 PM
 *  Author: Omar Yasser
 */ 

/****************************************************** Include Section *****************************************************/
#include "Runnable_APP_Service.h"
#include "LCD_Interface.h"
#include "filter.h"
#include "password.h"
#include "NVM_Interface.h"
#include "Interrupt_Interface.h"
#include <util/delay.h>

/****************************************************** Variable Section ****************************************************/
static u8 temp;
static u8 press;
extern u8 first;

/************************************************** Function Implementation *************************************************/

void RunnableApp(void)
{
	// Runnable mode
	u8 lock = NVM_READ(5);
	
	if(lock == 1)
	{
		CLOSE_GI();		
		first = 1;
		
		RUNNABLE_PRESS_VALUE();
		RUNNABLE_TEMP_VALUE();
		
		temp  = temp_filter_get();
		
		if(temp <= 48 )
		{
			
			LCD_SET_CURSOR(1,press_c);
			LCD_WRITE_STRING("        ");
			
			
			DIO_WritePin(yellow_led,HIGH);
			DIO_WritePin(red_led,LOW);
			DIO_WritePin(orange_led,LOW);
			
			LCD_SET_CURSOR(1,temp_value);
			LCD_WRITE_NUM(temp);
			LCD_SET_CURSOR(2,7);
			LCD_WRITE_STRING("Good");
			
			ENABLE_GI();
		}
		
		else if (temp > 50)
		{
			
			DIO_WritePin(yellow_led,LOW);
			DIO_WritePin(red_led,LOW);
			DIO_WritePin(orange_led,HIGH);
			
			LCD_SET_CURSOR(1,temp_value);
			LCD_WRITE_NUM(temp);
			
			press = press_filter_get();
			
			LCD_SET_CURSOR(1,press_c);
			LCD_WRITE_STRING("press:");
			LCD_WRITE_NUM(press);
			LCD_SET_CURSOR(2,7);
			LCD_WRITE_STRING("Fine");
			
			if(press > 50)
			{
				NVM_WRITE(5,0);
				LCD_CLR();
			}
			
			ENABLE_GI();
		}
	}
	
	// Lock case
	else
	{
		CLOSE_GI();	
		
		DIO_WritePin(yellow_led,LOW);
		DIO_WritePin(red_led,HIGH);
		DIO_WritePin(orange_led,LOW);
		
		DIO_WritePin(motor,HIGH);
		
		LCD_SET_CURSOR(1,1);
		LCD_WRITE_STRING("Password:");
		
		if( password_check() == non_valid)
		{
			LCD_SET_CURSOR(2,1);
			LCD_WRITE_STRING("NON VAILD");
			_delay_ms(1000);
			LCD_CLR();
		}
		else
		{
			LCD_SET_CURSOR(2,1);
			LCD_WRITE_STRING("VALID");
			_delay_ms(1500);
		}
		
		ENABLE_GI();
	}
}
