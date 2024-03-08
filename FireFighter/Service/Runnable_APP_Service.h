/*
 * Runnable_APP_Service.h
 *
 * Created: 3/8/2024 10:08:44 PM
 *  Author: omarn
 */ 


#ifndef RUNNABLE_APP_SERVICE_H_
#define RUNNABLE_APP_SERVICE_H_

/**************************************************** Include Section ****************************************************/
#include "DIO_Interface.h"
#include "StdTypes.h"

/***************************************************** Macros Section ****************************************************/
#define yellow_led	PINC0
#define orange_led	PINC1
#define red_led		PINC2
#define motor		PINB0

// LCD write
#define temp_value  6
#define press_c     9

// CPU Clock
#define F_CPU 8E6

/************************************************** Function Declaration *************************************************/
void RunnableApp(void);


#endif /* RUNNABLE_APP_SERVICE_H_ */