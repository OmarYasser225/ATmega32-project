/*
 * converter_private.h
 *
 * Created: 1/23/2024 5:26:59 PM
 *  Author: Omar Yasser
 */ 


#ifndef CONVERTER_PRIVATE_H_
#define CONVERTER_PRIVATE_H_

/******************************************** Include Section ****************************************/
#include "StdTypes.h"
#include "converter.h"

/****************************************** Function Declaration ***********************************/
 void convert_to_menu(MODE_type select);
 u32 power(u8 num1 , u8 exp);
 void convert_from_menu(void);
 MODE_type check_select(u8 check);
 void result_menu(void);
 u32 binary_to_dec(u32 bin_num);
 u32 get_num(u8 start , u8 end);
 u32 get_num_hex(void);

#endif /* CONVERTER_PRIVATE_H_ */