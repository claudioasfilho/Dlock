/*
 * HardwareProfile.h
 *
 *  Created on: Mar 31, 2016
 *      Author: clfilho
 */

#ifndef HARDWAREPROFILE_H_
#define HARDWAREPROFILE_H_
#include <stdio.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_rtcc.h"
#include "retargetserial.h"

#define DebounceCounter 15

typedef enum
			{
				KEY_0=0x30,
				KEY_1,
				KEY_2,
				KEY_3,
				KEY_4,
				KEY_5,
				KEY_6,
				KEY_7,
				KEY_8,
				KEY_9,
				KEY_C=0x43,
				KEY_LOCK=0x4C,
				END_OF_KEYS
			} KEYBOARDKEYS;

typedef enum
			{
				DRIVING_C1=0,
				DRIVING_C2,
				DRIVING_C3,
			} KBDRIVINGSTATE;

/**************************************************************************//**
		 * @brief  Keyboard Definitions
 *****************************************************************************/

#define Init_KeyboardR1()		GPIO_PinModeSet(gpioPortD, 9, gpioModeInputPullFilter, 1);
#define Init_IntKeyboardR1()	GPIO_IntConfig(gpioPortD, 9, false, true,  true);
#define Get_KeyboardR1() 		GPIO_PinInGet(gpioPortD, 9)

#define Init_KeyboardR2()		GPIO_PinModeSet(gpioPortC, 7, gpioModeInputPullFilter, 1);
#define Init_IntKeyboardR2()	GPIO_IntConfig(gpioPortC, 7, false, true,  true);
#define Get_KeyboardR2() 		GPIO_PinInGet(gpioPortC, 7)

#define Init_KeyboardR3()		GPIO_PinModeSet(gpioPortA, 3, gpioModeInputPullFilter, 1);
#define Init_IntKeyboardR3()	GPIO_IntConfig(gpioPortA, 3, false, true,  true);
#define Get_KeyboardR3() 		GPIO_PinInGet(gpioPortA,3)

#define Init_KeyboardR4()		GPIO_PinModeSet(gpioPortB, 13, gpioModeInputPullFilter, 1);
#define Init_IntKeyboardR4()	GPIO_IntConfig(gpioPortB, 13, false, true,  true);
#define Get_KeyboardR4() 		GPIO_PinInGet(gpioPortB, 13)

#define Init_KeyboardC1()		GPIO_PinModeSet(gpioPortA, 4, gpioModeWiredOr, 0);
#define Set_KeyboardC1()  		{GPIO_PinModeSet(gpioPortA,4, gpioModePushPull, 0); GPIO_PinOutClear(gpioPortA, 4);}
#define Clear_KeyboardC1()  	GPIO_PinModeSet(gpioPortA, 4, gpioModeWiredOr, 0);
#define Get_KeyboardC1() 		GPIO_PinInGet(gpioPortA, 4)

#define Init_KeyboardC2()		GPIO_PinModeSet(gpioPortD, 10, gpioModeWiredOr, 0);
#define Set_KeyboardC2()  		{GPIO_PinModeSet(gpioPortD, 10, gpioModePushPull, 0); GPIO_PinOutClear(gpioPortD, 10);}
#define Clear_KeyboardC2()  	GPIO_PinModeSet(gpioPortD, 10, gpioModeWiredOr, 0);
#define Get_KeyboardC2() 		GPIO_PinInGet(gpioPortD, 10)

#define Init_KeyboardC3()		GPIO_PinModeSet(gpioPortD, 11, gpioModeWiredOr, 0);
#define Set_KeyboardC3()  		{GPIO_PinModeSet(gpioPortD, 11, gpioModePushPull, 0); GPIO_PinOutClear(gpioPortD, 11);}
#define Clear_KeyboardC3()  	GPIO_PinModeSet(gpioPortD, 11, gpioModeWiredOr, 0);
#define Get_KeyboardC3() 		GPIO_PinInGet(gpioPortD, 11)

/**************************************************************************//**
		 * @brief  Outputs Definitions
 *****************************************************************************/

#define Init_MotorIN1()			GPIO_PinModeSet(gpioPortC, 8, gpioModePushPull, 0);
#define Set_MotorIN1()  		GPIO_PinOutSet(gpioPortC, 8);
#define Clear_MotorIN1()  		GPIO_PinOutClear(gpioPortC, 8);
#define Get_MotorIN1() 			GPIO_PinInGet(gpioPortC, 8)

#define Init_MotorIN2()			GPIO_PinModeSet(gpioPortC, 9, gpioModePushPull, 0);
#define Set_MotorIN2()  		GPIO_PinOutSet(gpioPortC, 9);
#define Clear_MotorIN2()  		GPIO_PinOutClear(gpioPortC, 9);
#define Get_MotorIN2() 			GPIO_PinInGet(gpioPortC, 9)

//Inverted Logic
#define Init_MotornSleep()		GPIO_PinModeSet(gpioPortC, 6, gpioModePushPull, 0);
#define Set_MotornSleep()  		GPIO_PinOutClear(gpioPortC, 6);
#define Clear_MotornSleep()  	GPIO_PinOutSet(gpioPortC, 6);
#define Get_MotornSleep() 		GPIO_PinInGet(gpioPortC, 6)

#define Init_Buzzer()			GPIO_PinModeSet(gpioPortF, 4, gpioModePushPull, 0);
#define Set_Buzzer()  			GPIO_PinOutSet(gpioPortF, 4);
#define Clear_Buzzer()  		GPIO_PinOutClear(gpioPortF, 4);
#define Get_Buzzer() 			GPIO_PinInGet(gpioPortF, 4)

#define Init_GreenLed()			GPIO_PinModeSet(gpioPortB, 11, gpioModePushPull, 0);
#define Set_GreenLed()  		GPIO_PinOutSet(gpioPortB, 12); GPIO_PinOutClear(gpioPortB, 11);
#define Clear_GreenLed()  		GPIO_PinOutSet(gpioPortB, 12); GPIO_PinOutSet(gpioPortB, 11);
#define Get_GreenLed() 			GPIO_PinInGet(gpioPortB, 11)

#define Init_RedLed()			GPIO_PinModeSet(gpioPortB, 12, gpioModePushPull, 0);
#define Set_RedLed()  			GPIO_PinOutSet(gpioPortB, 11); GPIO_PinOutClear(gpioPortB, 12);
#define Clear_RedLed()  		GPIO_PinOutSet(gpioPortB, 12); GPIO_PinOutSet(gpioPortB, 11);
#define Get_RedLed() 			GPIO_PinInGet(gpioPortB, 12)

typedef union
			{
			struct
					{
						uint8_t MotorDrive:2;
						bool Buzzer;
						bool GreenLed;
						bool RedLed;
						bool n_SleepMotor;
						bool NA1;
						bool NA2;
					}Flags;
					uint8_t word;
			}OUTFLAGS;


KEYBOARDKEYS Get_KeyboardKey();
void PrintKey(KEYBOARDKEYS Key);
void DriveKeyboardColumns();

#endif /* HARDWAREPROFILE_H_ */
