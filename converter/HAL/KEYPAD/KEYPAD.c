/*
 * KEYPAD.c
 *
 * Created: 12/16/2023 9:28:30 PM
 *  Author: Omar Yasser
 */ 


/****************************************** Include Section ********************************************/
#include "DIO_Interface.h"
#include "KEYPAD_Interface.h"


/****************************************** Variable Section ********************************************/
extern const u8 KEYPAD_KEYS[ROW][COL];
extern const u8 KEYPAD_KEYS_CAL[ROW][COL];
extern const DIO_Pin_type KEYPAD_OUTPUT [ROW];
extern const DIO_Pin_type KEYPAD_INPUT [COL];

/*************************************** Function Declartaion ******************************************/
void KEYPAD_INIT(void)
{
	for(u8 i = 0 ; i < ROW ; ++i)
	{
		DIO_WritePin(KEYPAD_OUTPUT[i] , OUTPUT_VALUE);
	}
}

u8 KEYPAD_GET_KEY(void)
{
	u8 key = NO_KEY;
	for(u8 i = 0 ; i < COL ; ++i)
	{
		DIO_WritePin(KEYPAD_OUTPUT[i] , (!OUTPUT_VALUE));
		for(u8 j = 0 ; j < COL ; ++j)
		{
			if(DIO_ReadPin(KEYPAD_INPUT[j]) == INPUT_VALUE)
			{
				key = KEYPAD_KEYS[i][j];
				while(DIO_ReadPin(KEYPAD_INPUT[j]) == INPUT_VALUE);
			}

		}
		DIO_WritePin(KEYPAD_OUTPUT[i] , OUTPUT_VALUE);
	}
	return key;
}

u8 KEYPAD_GET_KEY_CAL(void)
{
	u8 key = NO_KEY;
	for(u8 i = 0 ; i < COL ; ++i)
	{
		DIO_WritePin(KEYPAD_OUTPUT[i] , (!OUTPUT_VALUE));
		for(u8 j = 0 ; j < COL ; ++j)
		{
			if(DIO_ReadPin(KEYPAD_INPUT[j]) == INPUT_VALUE)
			{
				key = KEYPAD_KEYS_CAL[i][j];
				while(DIO_ReadPin(KEYPAD_INPUT[j]) == INPUT_VALUE);
			}

		}
		DIO_WritePin(KEYPAD_OUTPUT[i] , OUTPUT_VALUE);
	}
	return key;
}



