/*
 * KEYPAD_cfg.c
 *
 * Created: 12/16/2023 9:30:10 PM
 *  Author: Omar Yasser
 */ 

#include "KEYPAD_cfg.h"
#include "StdTypes.h"
#include "DIO_Interface.h"

const u8 KEYPAD_KEYS[ROW][COL]=
{
							{'7','8','9','F'},
							{'4','5','6','E'},
							{'1','2','3','A'},
							{'C','0','=','B'} 			
};

const u8 KEYPAD_KEYS_CAL[ROW][COL]=
{
							{'7','8','9','+'},
							{'4','5','6','-'},
							{'1','2','3','*'},
							{'C','0','=','/'}
};

 const DIO_Pin_type KEYPAD_OUTPUT [ROW] = 
{
									    PINB4,
									    PINB5,
									    PINB6,
									    PINB7
};

const DIO_Pin_type KEYPAD_INPUT [COL] =
{
										PIND2,
										PIND3,
										PIND4,
										PIND5
};