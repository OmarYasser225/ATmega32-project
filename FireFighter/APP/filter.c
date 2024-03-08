/*
 * filter.c
 *
 * Created: 1/25/2024 10:40:15 PM
 *  Author: Omar Yasser
 */ 


/********************************************** Include Section ***********************************************/
#include "filter.h"
#include "Temp_interface.h"
#include "Pressure_Interface.h"

/********************************************** Variable Section ***********************************************/

static u8 temp_filterd_value[10]  = {30};
static u8 press_filterd_value[10] = {30};

static u8 temp_filtered  = 0 ;
static u8 press_filterd  = 0 ;

/******************************************* Function Implementation *******************************************/
void Filter_INIT(void)
{
	temp_filtered  = 30 ;
	press_filterd  = 30 ;
}

void RUNNABLE_TEMP_VALUE(void)
{
	static u8 index = 0; 
	u8 temp = TEMP_GETTER();
	temp_filterd_value[index] = temp;
	index = index==9? 0:index+1;
	u16 result = 0;
	for (u8 i = 0 ; i < 10 ; i++)
	{
		result += temp_filterd_value[i];
	}
	temp_filtered = result/10;
}

void RUNNABLE_PRESS_VALUE(void)
{
	static u8 index = 0;
	u8 press = PRESSURE_GETTER();
	press_filterd_value[index] = press;
	index = index==9? 0:index+1;
	u16 result = 0;
	for (u8 i = 0 ; i < 10 ; i++)
	{
		result += press_filterd_value[i];
	}
	press_filterd = result/10;
}

u8 temp_filter_get(void)
{
	return temp_filtered;
}

u8 press_filter_get(void)
{
	return press_filterd;
}