/*
 * ADC.c
 *
 * Created: 12/18/2023 10:13:50 PM
 *  Author: Omar Yasser
 */ 

/************************************ Include Section ***********************************/
#include "Utilities.h"
#include "ADC_Interface.h"
#include "ADC_Cfg.h"
#include "MemoryMap.h"

/******************************** Function Implementaion *******************************/
void ADC_INIT(ADC_VREF_type vref , ADC_PRESCALAR_type scale)
{
	
// Select the desired clock 
/* clock must be on range of (50KHZ - 200KHZ) for max resolution */
/* if you want less 10 bit resolution enter above that range */
		
		// Clean first 3 bits in ADCSRA
		ADCSRA = ADCSRA & 0xF8;      // DATA in register ( A B C D E 0 0 0 )
		// Write the number of prescaler 
		ADCSRA = ADCSRA | scale;     // DATA in register ( A B C D E g j k )
		
// Select the voltage reference

		// Clean last 2 bits in ADMUX
		ADMUX = ADMUX & 0x3F;        // DATA in register ( 0 0 A B C D E F )
		// Write the number of Voltage reference
		ADMUX = ADMUX | (vref<<6);	 // DATA in register ( g j A B C D E F)
	
// Enable the ADC 

		if(ADC_EN == 1)
		{
			SET_BIT(ADCSRA,ADEN);
		}
		
// DATA position

		// Set Most of data in high part or low part of register
		if(ADC_DATA_POS == 1)
		{
			SET_BIT(ADMUX,ADLAR);
		}
		else if(ADC_DATA_POS == 0)
		{
			CLR_BIT(ADMUX,ADLAR);
		}
		
				 
}

u16 ADC_READ(ADC_CH_type channel)
{
	u16 volt = 0;
	
// Select the input pin
		
		// Clean first 5 bits in ADMUX
		ADMUX = ADMUX & 0xE0;       // DATA in register ( A B C 0 0 0 0 0 )
		// Write Channel number
		ADMUX = ADMUX | channel;    // DATA in register ( A B C d e f g k )
		
		
// Start ADC conversion
		SET_BIT(ADCSRA, ADSC);
		while(READ_PIN(ADCSRA,ADSC));
		
// Get data from register
		
		#if ADC_DATA_POS == 0
			volt = ADCL;
			volt = volt | (ADCH << 8);
		#elif ADC_DATA_POS == 1
			volt = (ADCL >> 6);
			volt = volt | (ADCH << 2);
		#endif
		
// return voltage or type

		return volt;	
}


u16 ADC_READ_VOLTAGE(ADC_CH_type channel , u8 scale )
{
	u16 ADC = ADC_READ(channel);
	u16 volt;
	
	volt = (((ADC*(u32)ADC_VREF_VALUE)*(u32)scale)/1024);
	return volt;
	
	
}
