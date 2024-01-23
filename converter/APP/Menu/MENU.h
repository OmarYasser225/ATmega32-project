/*
 * MENU.h
 *
 * Created: 1/22/2024 6:47:51 PM
 *  Author: omarn
 */ 


#ifndef MENU_H_
#define MENU_H_

/***************************** Macros Section ************************************/
typedef enum
{
	converter_mode  = 1,
	calculator_mode = 2
}MODE_RET;


/******************************** Function Declaration *******************************/
void start(void);
MODE_RET menu(void);



#endif /* MENU_H_ */