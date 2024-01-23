/*
 * converter_private.c
 *
 * Created: 1/23/2024 5:27:29 PM
 *  Author: Omar Yasser
 */ 


/********************************************* Include Section *************************************************/
#define F_CPU 8E6
#include <util/delay.h>
#include "converter_private.h"

/********************************************* Variable section *****************************/
u8 convert_to[3][13]=
{						"HEX      BIN",
	"DEC      BIN",
	"DEC      HEX"
};

/****************************************** Function Implemention **********************************************/

static void convert_to_menu(MODE_type select)
{
	LCD_CLR();
	LCD_SET_CURSOR(1,1);
	LCD_WRITE_STRING("Convert to:");
	LCD_SET_CURSOR(2,1);
	LCD_WRITE_STRING(convert_to[select-1]);
	LCD_SET_CURSOR(1,12);
}

static u32 power(u8 num1 , u8 exp)
{
	u32 num=1;
	if(exp == 0)
	{
		return 1;
	}
	for(u8 i = 0 ; i < exp ; i++)
	{
		num *= num1;
	}
	return num;
}

static void convert_from_menu(void)
{
	LCD_CLR();
	LCD_SET_CURSOR(1,1);
	LCD_WRITE_STRING("Convert from:");
	LCD_SET_CURSOR(2,1);
	LCD_WRITE_STRING("DEC   HEX   BIN");
	LCD_SET_CURSOR(1,14);
}

static MODE_type check_select(u8 check)
{
	u8 select = KEYPAD_GET_KEY();
	while(select == NO_KEY || select < check)
	{
		select = KEYPAD_GET_KEY();
	}
	select = select-'0';
	LCD_WRITE_NUM(select);
	_delay_ms(1000);
	return select;
}

static void result_menu(void)
{
	LCD_SET_CURSOR(1,1);
	LCD_WRITE_STRING("I/P:");
	LCD_SET_CURSOR(2,1);
	LCD_WRITE_STRING("O/P:");
	LCD_SET_CURSOR(1,5);
}

static u32 binary_to_dec(u32 bin_num)
{
	u32 dec_num = 0;
	u8 temp = 0 , i = 0;
	while(bin_num!=0)
	{
		temp = bin_num%10;
		bin_num /= 10;
		dec_num += temp*power(2,i);
		i++;
	}
	return dec_num;
}

static u32 get_num(u8 start , u8 end)
{
	u32 num = 0;
	u8 temp = KEYPAD_GET_KEY() ;
	while(temp != '=')
	{
		temp = KEYPAD_GET_KEY();
		if(temp >= start && temp <= end)
		{
			LCD_WRITE_CHAR(temp);
			num = (num*10) + (temp-'0');
		}
	}
	return num;
}

static u32 get_num_hex(void)
{
	u32 num = 0;
	u8 hex[8] ;
	u8 temp = KEYPAD_GET_KEY() ;
	while(temp != '=' )
	{
		temp = KEYPAD_GET_KEY();
		if(temp != '=' && temp != NO_KEY)
		{
			LCD_WRITE_CHAR(temp);
			hex[num]=temp;
			num++;
			if(num>8)
			{
				break;
			}
		}
	}
	temp = num-1;
	num = 0;
	
	for(u8 i = temp ; i != 255 ; --i)
	{
		if(hex[i]>='A' && hex[i] <='F')
		{
			num += ((hex[i]-'A'+10)*power(16,(temp-i)));
		}
		else
		{
			num += ((hex[i]-'0')*power(16,(temp-i)));
		}
	}
	return num;
}