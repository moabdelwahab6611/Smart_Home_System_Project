/* 
 * File     : RealTimeClockDS1307.c
 * Author   : Mohamed Ahmed Abdel Wahab
 * LinkedIn : https://www.linkedin.com/in/mohamed-abdel-wahab-162413253/
 * Github   : https://github.com/moabdelwahab6611
 * Created on June 19, 2023, 3:57 PM
 */

/**************************Includes-Section*****************************/
#include "RealTimeClockDS1307.h"
/***********************************************************************/

/*****************Helper Functions Declarations-Section*****************/
static RealTimeClockDS1307_T RealTimeClockDS1307;
/* "_Year" : "_Month" : "_Day" * "_Hours" : "_Minutes" : "_Seconds" */
static uint8_t RealTimeClockDS1307_RB_Date[17]; 
/***********************************************************************/

/*****************Software Interfaces Functions-Section*****************/
/*
 * @Brief : To write full date and time.
 * @Return RealTimeClockDS1307
 */
RealTimeClockDS1307_T RealTimeClockDS1307_Get_Date_And_Time(void)
{
    RealTimeClockDS1307._Seconds = I2C_Read1ByteRegister(0xD0, 0x00);
    RealTimeClockDS1307._Minutes = I2C_Read1ByteRegister(0xD0, 0x01);
    RealTimeClockDS1307._Hours   = I2C_Read1ByteRegister(0xD0, 0x02);
    RealTimeClockDS1307._Day     = I2C_Read1ByteRegister(0xD0, 0x04);
    RealTimeClockDS1307._Month   = I2C_Read1ByteRegister(0xD0, 0x05);
    RealTimeClockDS1307._Year    = I2C_Read1ByteRegister(0xD0, 0x06);
    return RealTimeClockDS1307;
}

/*
 * @Brief : To show full date and time.
 */
void Print_RealTimeClockDS1307_full_Date(void)
{
    RealTimeClockDS1307_RB_Date[0]   = ((RealTimeClockDS1307._Day >> 4) + 0x30);
    RealTimeClockDS1307_RB_Date[1]   = ((RealTimeClockDS1307._Day & 0x0F) + 0x30);
    RealTimeClockDS1307_RB_Date[2]   = '-';
    RealTimeClockDS1307_RB_Date[3]   = ((RealTimeClockDS1307._Month >> 4) + 0x30);
    RealTimeClockDS1307_RB_Date[4]   = ((RealTimeClockDS1307._Month & 0x0F) + 0x30);
    RealTimeClockDS1307_RB_Date[5]   = '-';
    RealTimeClockDS1307_RB_Date[6]   = ((RealTimeClockDS1307._Year >> 4) + 0x30);
    RealTimeClockDS1307_RB_Date[7]   = ((RealTimeClockDS1307._Year & 0x0F) + 0x30);
    
    RealTimeClockDS1307_RB_Date[8]   = '/';
    
    RealTimeClockDS1307_RB_Date[9]   = ((RealTimeClockDS1307._Hours >> 4) + 0x30);
    RealTimeClockDS1307_RB_Date[10]  = ((RealTimeClockDS1307._Hours & 0x0F) + 0x30);
    RealTimeClockDS1307_RB_Date[11]  = '-';
    RealTimeClockDS1307_RB_Date[12]  = ((RealTimeClockDS1307._Minutes >> 4) + 0x30);
    RealTimeClockDS1307_RB_Date[13]  = ((RealTimeClockDS1307._Minutes & 0x0F) + 0x30);
    RealTimeClockDS1307_RB_Date[14]  = '-';
    RealTimeClockDS1307_RB_Date[15]  = ((RealTimeClockDS1307._Seconds >> 4) + 0x30);
    RealTimeClockDS1307_RB_Date[16]  = ((RealTimeClockDS1307._Seconds & 0x0F) + 0x30);
    
            
    USART_LoggingDebugData_Send_String("Date : \r", 8);
    USART_LoggingDebugData_Send_String(RealTimeClockDS1307_RB_Date, 17);
}
/***********************************************************************/