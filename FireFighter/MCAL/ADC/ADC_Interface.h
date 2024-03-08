/*
 * ADC_Interface.h
 *
 * Created: 12/18/2023 10:13:40 PM
 *  Author: Omar Yasser
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*************************************** Include Section *******************************/
#include "MemoryMap.h"
#include "StdTypes.h"

/*************************************** Macros Section *******************************/
// ADMUX BITS
#define REFS1   7
#define REFS0   6
#define ADLAR   5

// ADCSRA BITS
#define ADEN    7
#define ADSC    6


/*************************************** Types Section ********************************/
typedef enum 
{
	VREF,
	VREF_VCC,
	VREF_256 = 3

}ADC_VREF_type;

typedef enum
{
	CH0=0,
	CH1=1,
	CH2=2,
	CH3=3,
	CH4=4,
	CH5=5,
	CH6=6,
	CH7=7
}ADC_CH_type;

typedef enum 
{
	PRESCALAR_2 = 1,
	PRESCALAR_4,
	PRESCALAR_8,
	PRESCALAR_16,
	PRESCALAR_32,
	PRESCALAR_64,
	PRESCALAR_128,
	
}ADC_PRESCALAR_type;


/************************************** Function declaration **************************/

/*
Outputs of function:
    - return void
	  
Inputs of function:
	- vref     : control the voltage reference and select [VREF , AVCC(5V) , 2.56V] which of them is vref
	- scale    : control the division factor of the clk to decrease the clock 
*/ 
void ADC_INIT(ADC_VREF_type vref , ADC_PRESCALAR_type scale);

/*
Outputs of function:
     - return the value of ADC 

Inputs of function:
	 - CH      : select the input port of the signal 
*/
u16 ADC_READ(ADC_CH_type channel );

/*
Outputs of function:
	- return voltage value

Inputs of function:
	- unit    : determine the voltage unit(mV , uV)
*/
u16 ADC_READ_VOLTAGE(ADC_CH_type channel , u8 scale );



#endif /* ADC_INTERFACE_H_ */