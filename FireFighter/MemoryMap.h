/*
 * MemoryMap.h
 *
 * Created: 12/5/2023 9:32:04 PM
 *  Author: Omar Yasser
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_


/*********************************** DIO Register ************************************/
// address of PORTA
#define DDRC (*((volatile unsigned char*) 0x34) )
#define PORTC (*((volatile unsigned char*) 0x35) )
#define PINC (*((volatile unsigned char*)0X33))

// address of PORTA
#define DDRB (*((volatile unsigned char*) 0x37) )
#define PORTB (*((volatile unsigned char*) 0x38) )
#define PINB (*((volatile unsigned char*)0X36))

// address of PORTA
#define DDRA (*((volatile unsigned char*) 0x3A) )
#define PORTA (*((volatile unsigned char*) 0x3B) )
#define PINA (*((volatile unsigned char*)0X39))

// address of PORTD
#define DDRD (*((volatile unsigned char*) 0x31) )
#define PORTD (*((volatile unsigned char*) 0x32) )
#define PIND (*((volatile unsigned char*)0X30))

/*********************************** ADC Register **********************************/

// ADMUX Register
#define ADMUX  (*((volatile unsigned char*)0X27))

// ADCSRA Register
#define ADCSRA (*((volatile unsigned char*)0X26))

// ADDATA Register
#define ADCH   (*((volatile unsigned char*)0X25))
#define ADCL   (*((volatile unsigned char*)0X24))

/************************************ NVM Register ***********************************/

/* Address Register */
#define EEAR (*((volatile unsigned short*)0X3E))

/* Data Register */
#define EEDR (*((volatile unsigned char*)0X3D))

/* Control Register */
#define EECR (*((volatile unsigned char*)0X3C))

/***************************** External Interrupt Register ***************************/

#define MCUCSR (*((volatile unsigned char*)0X54))
#define MCUCR  (*((volatile unsigned char*)0X55))
#define GICR   (*((volatile unsigned char*)0X5B))


/********************************** ISR defination *********************************/

// Interrupt services routine function
#define ISR(vector) void vector (void)__attribute__((signal));\
void vector (void)

// vector table

/* External Interrupt */
#define INT0_vect			__vector_1
#define INT1_vect			__vector_2
#define INT2_vect			__vector_3



#endif