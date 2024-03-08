/*
 * ADC_Cfg.h
 *
 * Created: 12/18/2023 10:14:08 PM
 *  Author: omarn
 */ 


#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/**************************************** Macros Section ***********************************/

/* 
   ADC_EN:           FUNCTION                                      VALUE
			 - enable the  ADC in initialization to save 25 cycle  (1)
			 - Close the  ADC in initialization                    (0)
*/
#define ADC_EN         1

/* 
   ADC_DATA_POS:           FUNCTION                                      VALUE
				 - make the most of data in high part of register        (1)
				 - make the most of data in low part of register         (0)
*/
#define ADC_DATA_POS   0

#define ADC_VREF_VALUE 5 



#endif /* ADC_CFG_H_ */