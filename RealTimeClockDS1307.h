/* 
 * File     : RealTimeClockDS1307.h
 * Author   : Mohamed Ahmed Abdel Wahab
 * LinkedIn : https://www.linkedin.com/in/mohamed-abdel-wahab-162413253/
 * Github   : https://github.com/moabdelwahab6611
 * Created on June 19, 2023, 3:57 PM
 */

#ifndef REALTIMECLOCKDS1307_H
#define	REALTIMECLOCKDS1307_H

/**************************Includes-Section*****************************/
#include "../../mcc_generated_files/mcc.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"
#include "../USART_LoggingDebugData/USART_LoggingDebugData.h"
/***********************************************************************/

/**********************Macro Declarations-Section***********************/

/***********************************************************************/

/******************Macro Function Declarations-Section******************/

/***********************************************************************/

/********************Data Types Declarations-Section********************/
/* @Brief : Real Time Clock DS1307 date and time configurations. */
typedef struct
{
    uint8_t _Hours;
    uint8_t _Minutes;
    uint8_t _Seconds;
    uint8_t _Year;
    uint8_t _Month;
    uint8_t _Day;
}RealTimeClockDS1307_T;
/***********************************************************************/

/**********Software Interfaces Functions Declarations-Section***********/
/*
 * @Brief : To write full date and time.
 * @Return RealTimeClockDS1307
 */
RealTimeClockDS1307_T RealTimeClockDS1307_Get_Date_And_Time(void);

/*
 * @Brief : To show full date and time.
 */
void Print_RealTimeClockDS1307_full_Date(void);
/***********************************************************************/
#endif	/* REALTIMECLOCKDS1307_H */

