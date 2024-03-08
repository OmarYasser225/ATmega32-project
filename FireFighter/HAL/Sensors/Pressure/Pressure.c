/*
 * Pressure.c
 *
 * Created: 1/25/2024 8:07:03 PM
 *  Author: Omar Yasser
 */ 

/**************************************************** Include Section *****************************************************/
#include "ADC_Interface.h"
#include "Pressure_cfg.h"
#include "Pressure_Interface.h"

/************************************************ Function Implementation *************************************************/
void PRESSURE_INIT(void)
{
	
}

u8 PRESSURE_GETTER(void)
{
	// get the volt from ADC
	u16 volt = ADC_READ(PRESS_PIN)*10;
	
	// convert the volt into pressure
	u8 press = (u32)25*(u32)((u16)volt-540)/944;
	
	return press; 
}