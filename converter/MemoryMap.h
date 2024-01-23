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

#endif