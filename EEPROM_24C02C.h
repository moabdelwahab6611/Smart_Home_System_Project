/* 
 * File     : EEPROM_24C02C.h
 * Author   : Mohamed Ahmed Abdel Wahab
 * LinkedIn : https://www.linkedin.com/in/mohamed-abdel-wahab-162413253/
 * Github   : https://github.com/moabdelwahab6611
 * Created on June 19, 2023, 10:18 PM
 */

#ifndef EEPROM_24C02C_H
#define	EEPROM_24C02C_H

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
 * @Brief : To write byte in EEPROM_24C02C.
 * @Param EEPROM_Address       
 * @Param Byte_Address
 * @Param Data
 */
void EEPROM_24C02C_Write_Byte(i2c_address_t EEPROM_Address, i2c_address_t Byte_Address, uint8_t Data);

/*
 * @Brief : To read byte from EEPROM_24C02C.
 * @Param EEPROM_Address 
 * @Param Byte_Address
 * @Return Received_Value
 */
uint8_t EEPROM_24C02C_Read_Byte(i2c_address_t EEPROM_Address, i2c_address_t Byte_Address);
/***********************************************************************/
#endif	/* EEPROM_24C02C_H */

