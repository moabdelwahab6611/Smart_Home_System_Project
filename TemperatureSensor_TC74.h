/* 
 * File     : TemperatureSensor_TC74.h
 * Author   : Mohamed Ahmed Abdel Wahab
 * LinkedIn : https://www.linkedin.com/in/mohamed-abdel-wahab-162413253/
 * Github   : https://github.com/moabdelwahab6611
 * Created on June 20, 2023, 1:38 AM
 */

#ifndef TEMPERATURESENSOR_TC74_H
#define	TEMPERATURESENSOR_TC74_H

/**************************Includes-Section*****************************/
#include "../../mcc_generated_files/mcc.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"
/***********************************************************************/

/**********************Macro Declarations-Section***********************/

/***********************************************************************/

/******************Macro Function Declarations-Section******************/

/***********************************************************************/

/********************Data Types Declarations-Section********************/

/***********************************************************************/

/**********Software Interfaces Functions Declarations-Section***********/
/*
 * @Brief : To read temperature by Temperature Sensor TC74.
 * @Param TC74_Address
 * @Return TC74_Temperature_Degree
 */
uint8_t TemperatureSensor_TC74_Read_Temperature_Degree(i2c_address_t TC74_Address);
/***********************************************************************/
#endif	/* TEMPERATURESENSOR_TC74_H */

