/* 
 * File     : TemperatureSensor_TC74.c
 * Author   : Mohamed Ahmed Abdel Wahab
 * LinkedIn : https://www.linkedin.com/in/mohamed-abdel-wahab-162413253/
 * Github   : https://github.com/moabdelwahab6611
 * Created on June 20, 2023, 1:38 AM
 */

/**************************Includes-Section*****************************/
#include "TemperatureSensor_TC74.h"
/***********************************************************************/

/*****************Helper Functions Declarations-Section*****************/

/***********************************************************************/

/*****************Software Interfaces Functions-Section*****************/
/*
 * @Brief : To read temperature by Temperature Sensor TC74.
 * @Param TC74_Address
 * @Return TC74_Temperature_Degree
 */
uint8_t TemperatureSensor_TC74_Read_Temperature_Degree(i2c_address_t TC74_Address)
{
    uint8_t TC74_Temperature_Degree = 0;
    TC74_Temperature_Degree = I2C_Read1ByteRegister(TC74_Address, 0x00);
    return TC74_Temperature_Degree;
}
/***********************************************************************/