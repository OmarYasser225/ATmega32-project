/*
 * password.c
 *
 * Created: 1/25/2024 9:58:25 PM
 *  Author: omarn
 */ 

/*********************************************** Include Section ****************************************/
#include "password.h"
#include "NVM_Interface.h"
#include "KEYPAD_Interface.h"
#include "NVM_Interface.h"
#include "LCD_Interface.h"

/********************************************** Variable Section ****************************************/
// First bit to check
static u8 password[5] ={'1','0','0','0','0'};
extern u8 first;

/****************************************** Function Implementaion **************************************/
void password_set(void)
{
	u8 check = NVM_READ(0);
	if(check != 1)
	{
		for (u8 i = 1 ; i < 5 ; i++)
		{
			NVM_WRITE(i,password[i]);
		}
		NVM_WRITE(5,1);
	}
	else
	{
		for (u8 i = 1 ; i < 5 ; i++)
		{
			password[i] = NVM_READ(i);
		}
		return;
	}
}

password_check_return password_check(void)
{
	u8 key = KEYPAD_GET_KEY();
	u8 index = 1;
	while(1)
	{
		key = KEYPAD_GET_KEY();
		if(key >= '0' && key <= '9')
		{
			LCD_WRITE_CHAR('*');
			if(key == password[index])
			{
				index++;
			}
			else
			{
				return non_valid;	
			}
		}
		if (index == 5)
		{
			NVM_WRITE(5,1);
			first = 0;
			return valid;
		}
	}
	
	
}

password_check_return password_change(void)
{
	u8 key = KEYPAD_GET_KEY();
	u8 index = 1;
	
	while(1)
	{
		key = KEYPAD_GET_KEY();
		if(key >= '0' && key <= '9')
		{
			LCD_WRITE_CHAR('*');
			NVM_WRITE(index,key);
			password[index] = key;
			index++;	
		}
		
		if (index == 5)
		{
			return Change_Done;
		}
	}
	
}
