/*
 * filter.h
 *
 * Created: 1/25/2024 10:39:55 PM
 *  Author: Omar Yasser
 */ 


#ifndef FILTER_H_
#define FILTER_H_

/********************************************** Include Section *********************************************/
#include "StdTypes.h"

/******************************************* Function Declaration *******************************************/
void Filter_INIT(void);
void RUNNABLE_TEMP_VALUE(void);
void RUNNABLE_PRESS_VALUE(void);
u8 temp_filter_get(void);
u8 press_filter_get(void);


#endif /* FILTER_H_ */