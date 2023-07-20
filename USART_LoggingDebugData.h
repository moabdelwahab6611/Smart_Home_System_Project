/* 
 * File     : USART_LoggingDebugData.h
 * Author   : Mohamed Ahmed Abdel Wahab
 * LinkedIn : https://www.linkedin.com/in/mohamed-abdel-wahab-162413253/
 * Github   : https://github.com/moabdelwahab6611
 * Created on June 19, 2023, 8:03 PM
 */

#ifndef USART_LOGGINGDEBUGDATA_H
#define	USART_LOGGINGDEBUGDATA_H

/**************************Includes-Section*****************************/
#include "../../mcc_generated_files/eusart.h"
/***********************************************************************/

/**********************Macro Declarations-Section***********************/

/***********************************************************************/

/******************Macro Function Declarations-Section******************/

/***********************************************************************/

/********************Data Types Declarations-Section********************/

/***********************************************************************/

/**********Software Interfaces Functions Declarations-Section***********/
/*
 * @Brief : To write string.
 * @Param String
 * @Param String_Length
 */
void USART_LoggingDebugData_Send_String(uint8_t *_String, uint16_t String_Length);
/***********************************************************************/
#endif	/* USART_LOGGINGDEBUGDATA_H */

