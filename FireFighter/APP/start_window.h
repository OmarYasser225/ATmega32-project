/*
 * start_window.h
 *
 * Created: 3/8/2024 9:48:50 PM
 *  Author: omarn
 */ 


#ifndef START_WINDOW_H_
#define START_WINDOW_H_

/**************************************************** Include Section **************************************************/
#include "DIO_Interface.h"

/**************************************************** Macros Section **************************************************/
#define motor		PINB0 

/************************************************ Function Declaration ************************************************/
void start(void);
void first_window (u8 first);



#endif /* START_WINDOW_H_ */