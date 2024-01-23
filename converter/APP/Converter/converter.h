/*
 * converter.h
 *
 * Created: 1/22/2024 6:46:38 PM
 *  Author: Omar Yasser
 */ 


#ifndef CONVERTER_H_
#define CONVERTER_H_

/**************************** Macros Section *************************************/
#define from 3
#define to   2

/**************************** Typedef Section ************************************/
typedef enum
{
	DEC=1,
	HEX=2,
	BIN=3
}MODE_type;

/************************** Function Declaration *********************************/
void converter_menu(void);



#endif /* CONVERTER_H_ */