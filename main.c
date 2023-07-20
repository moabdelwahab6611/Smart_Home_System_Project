/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Author   : Mohamed Ahmed Abdel Wahab
  LinkedIn : https://www.linkedin.com/in/mohamed-abdel-wahab-162413253/
  Github   : https://github.com/moabdelwahab6611
  
  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K20
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**************************Includes-Section*****************************/
#include "mcc_generated_files/mcc.h"
#include "AECUL_Modules/RealTimeClockDS1307/RealTimeClockDS1307.h"
#include "AECUL_Modules/EEPROM_24C02C/EEPROM_24C02C.h"
#include "AECUL_Modules/TemperatureSensor_TC74/TemperatureSensor_TC74.h"
/***********************************************************************/

/***********************************************************************/
RealTimeClockDS1307_T RealTimeClockDS1307;

uint8_t U4Received_Value;
uint8_t U5Received_Value;
uint8_t TC74_A7_Temperature_Degree;
/***********************************************************************/
/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
   
    USART_LoggingDebugData_Send_String("System Started\r", 15);
    
    EEPROM_24C02C_Write_Byte(0xA2, 0x08, 5);
    __delay_us(100);
    EEPROM_24C02C_Write_Byte(0xA6, 0x08, 6);
    __delay_us(100);
    
    U4Received_Value = EEPROM_24C02C_Read_Byte(0xA2, 0x08);
    U5Received_Value = EEPROM_24C02C_Read_Byte(0xA6, 0x08);
    
    while (1)
    {
        RealTimeClockDS1307 = RealTimeClockDS1307_Get_Date_And_Time();
        Print_RealTimeClockDS1307_full_Date();
        
        TC74_A7_Temperature_Degree = TemperatureSensor_TC74_Read_Temperature_Degree(0x9E);
        
        I2C_Write1ByteRegister(0x70, 0x00, TC74_A7_Temperature_Degree);
    }
}
/**
 End of File
*/