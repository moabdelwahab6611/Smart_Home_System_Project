/* 
 * File     : EEPROM_24C02C.c
 * Author   : Mohamed Ahmed Abdel Wahab
 * LinkedIn : https://www.linkedin.com/in/mohamed-abdel-wahab-162413253/
 * Github   : https://github.com/moabdelwahab6611
 * Created on June 19, 2023, 10:18 PM
 */

/**************************Includes-Section*****************************/
#include "EEPROM_24C02C.h"
/***********************************************************************/

/*****************Helper Functions Declarations-Section*****************/

/***********************************************************************/

/*****************Software Interfaces Functions-Section*****************/
/*
 * @Brief : To write byte in EEPROM_24C02C.
 * @Param EEPROM_Address       
 * @Param Byte_Address
 * @Param Data
 */
void EEPROM_24C02C_Write_Byte(i2c_address_t EEPROM_Address, i2c_address_t Byte_Address, uint8_t Data)
{
    I2C_Write1ByteRegister(EEPROM_Address, Byte_Address, Data);
}

/*
 * @Brief : To read byte from EEPROM_24C02C.
 * @Param EEPROM_Address 
 * @Param Byte_Address
 * @Return Received_Value
 */
uint8_t EEPROM_24C02C_Read_Byte(i2c_address_t EEPROM_Address, i2c_address_t Byte_Address)
{
    uint8_t Received_Value = 0;
    Received_Value = I2C_Read1ByteRegister(EEPROM_Address, Byte_Address);
    
    return Received_Value;
}
/***********************************************************************/