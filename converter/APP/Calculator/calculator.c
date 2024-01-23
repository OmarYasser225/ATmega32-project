/*
 * calculator.c
 *
 * Created: 1/22/2024 6:47:00 PM
 *  Author: Omar Yasser
 */ 


/********************************* Include Section ******************************/
#include "LCD_Interface.h"
#include "KEYPAD_Interface.h"
#include "calculator.h"

/********************************* Variable Section *****************************/
static u32 expression[array_size]={0};

/***************************** Function Implementation **************************/
static void get_expression(void)
{
	u8 temp = KEYPAD_GET_KEY_CAL();
	u8 i = 0;
	while(temp!='=')
	{
		temp = KEYPAD_GET_KEY_CAL();
		if( temp >= '0' && temp <='9'  )
		{
			LCD_WRITE_CHAR(temp);
			if(i==0)
			{
				expression[i] = (temp-'0');
				i++;
			}
			else if((expression[i-1] == '+' || expression[i-1] == '-' || expression[i-1] == '*' || expression[i-1] == '/'))
			{
				expression[i] = (temp-'0');
				i++;
			}
			else
			{
				expression[i-1] *=10;
				expression[i-1] += (temp-'0');
			}
		}
		else if((temp == '+' || temp == '-' || temp == '*' || temp == '/'))
		{
			LCD_WRITE_CHAR(temp);
			expression[i] = temp;
			i++;
		}
		if(i>=array_size)
		{
			return;
		}
	}
}

static void shift_array(u8 index)
{
	for (u8 i =index ; i < (array_size-2) ; i++)
	{
		expression[i] = expression[i+2];
	}
}

static u32 result_calculation()
{	
	for (u8 i = 0 ; i < array_size ; i++)
	{
		if(expression[i]=='*')
		{
			expression[i-1] *= expression[i+1];
			shift_array(i);
			i=0;
		}
		else if(expression[i] == '/')
		{
			expression[i-1] /= expression[i+1];
			shift_array(i);
			i=0;
		}
	}
	
	for (u8 i = 0 ; i < array_size ; i++)
	{
		if(expression[i] =='+')
		{
			expression[i-1] += expression[i+1];
			shift_array(i);
			i=0;
		}
		else if(expression[i] == '-')
		{
			expression[i-1] -= expression[i+1];
			shift_array(i);
			i=0;
		}
	}
	
	return expression[0];
}

void calculator_menu(void)
{
	u32 result;
	
	// menu to show the i/p and the position of writing the expression
	LCD_CLR();
	LCD_SET_CURSOR(1,1);
	LCD_WRITE_STRING("I/P:");
	
	// function to get the expression from the user
	get_expression();
	
	// calculator of the expression
	result = result_calculation();
	
	// fall down to the second line to write the result
	LCD_SET_CURSOR(2,1);
	LCD_WRITE_STRING("Result:");
	LCD_WRITE_NUM(result);
	while(KEYPAD_GET_KEY_CAL() == NO_KEY);
}