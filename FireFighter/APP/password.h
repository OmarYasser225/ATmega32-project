/*
 * password.h
 *
 * Created: 1/25/2024 9:58:37 PM
 *  Author: omarn
 */ 


#ifndef PASSWORD_H_
#define PASSWORD_H_


/********************************************* Typedef Section *********************************************/
typedef enum
{
	non_valid = 0 ,
	valid = 1,
	Change_Done = 2,
	
}password_check_return;


/******************************************* Function Declaration ******************************************/
void password_set(void);
password_check_return password_check(void);
password_check_return password_change(void);


#endif /* PASSWORD_H_ */