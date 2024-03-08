/*
 * Temp.c
 *
 * Created: 1/25/2024 8:05:43 PM
 *  Author: omarn
 */ 


/**************************************************** Include Section *****************************************************/
#include "ADC_Interface.h"
#include "Temp_cfg.h"
#include "Temp_interface.h"

/************************************************ Function Implementation *************************************************/
void TEMP_INIT(void)
{
	
}
u8 TEMP_GETTER(void)
{
	// get the volt from ADC
	u16 volt = ADC_READ(TEMP_PIN);
	
	// convert the volt into volt
	u8 temp = ((u32)50*(u32)volt/103);
	
	return temp;
	
}