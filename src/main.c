/**************************************************************************//**
 * @file
 * @brief RTCC Demo
 * @version 1.00.0
 ******************************************************************************
 * @section License
 * <b>(C) Copyright 2015 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 *
 ******************************************************************************/

#include <stdio.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_rtcc.h"
#include "em_cryotimer.h"
#include "retargetserial.h"
#include "HardwareProfile.h"

#define START_TIME      0x00235945      /* 23:59:45 */
#define START_DATE      0x06160228      /* 2016/2/28 */

uint32_t rtccFlag;
uint32_t gpioFlag;
uint32_t cryotimerFlag;

KBDRIVINGSTATE Keyboard_State;
KEYBOARDKEYS PressedKey;


/**************************************************************************//**
* @brief Setup GPIO interrupt for pushbuttons.
*****************************************************************************/
static void gpioSetup(void)
{
  /* Enable GPIO clock */
  CMU_ClockEnable(cmuClock_GPIO, true);


  /*Keyboard Related GPIOs*/

  Init_KeyboardR1();
  Init_IntKeyboardR1();
  Init_KeyboardR2();
  Init_IntKeyboardR2();
  Init_KeyboardR3();
  Init_IntKeyboardR3();
  Init_KeyboardR4();
  Init_IntKeyboardR4();


  Init_KeyboardC1();
  Init_KeyboardC2();
  Init_KeyboardC3();


#if 0
 /*Keyboard - Row 1 - PD9 - Input with Filter Enabled*/
  GPIO_PinModeSet(gpioPortD, 9, gpioModeInputPullFilter, 1);
  GPIO_IntConfig(gpioPortD, 9, false, true,  true);
  /*Keyboard - Row 2 - PC7 - Input with Filter Enabled*/
  GPIO_PinModeSet(gpioPortC, 7, gpioModeInputPullFilter, 1);
  GPIO_IntConfig(gpioPortC, 7, false, true,  true);
  /*Keyboard - Row 3 - PA3 - Input with Filter Enabled*/
  GPIO_PinModeSet(gpioPortA, 3, gpioModeInputPullFilter, 1);
  GPIO_IntConfig(gpioPortA, 3, false, true,  true);
  /*Keyboard - Row 4 - PB13 - Input with Filter Enabled*/
  GPIO_PinModeSet(gpioPortB, 13, gpioModeInputPullFilter, 1);
  GPIO_IntConfig(gpioPortB, 13, false, true,  true);

  /*Keyboard - Column 1 - PA4 - Output- Push-pull*/
  GPIO_PinModeSet(gpioPortA, 4, gpioModeWiredOr, 0);
  /*Keyboard - Column 2 - PD10 - Output- Push-pull*/
  GPIO_PinModeSet(gpioPortD, 10, gpioModeWiredOr, 0);
  /*Keyboard - Column 3 - PD11 - Output- Push-pull*/
  GPIO_PinModeSet(gpioPortD, 11, gpioModeWiredOr, 0);


  /*Buzzer - PC6*/
  GPIO_PinModeSet(gpioPortC, 6, gpioModePushPull, 0);
#endif





  /* Configure PB0 as input and enable interrupt  */
  GPIO_PinModeSet(gpioPortF, 6, gpioModeInputPull, 1);
  GPIO_IntConfig(gpioPortF, 6, false, true, true);

  NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);
  NVIC_ClearPendingIRQ(GPIO_ODD_IRQn);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);

}

/**************************************************************************//**
* @brief Setup RTCC for calendar.
*****************************************************************************/
void rtccSetup(void)
{
  RTCC_Init_TypeDef rtccInit = RTCC_INIT_DEFAULT;

  /* Enable RTC clock */
  CMU_ClockEnable(cmuClock_RTCC, true);

  /* In calendar mode, the pre-counter should be configured to give ticks with a period of   */
  /* one second, i.e. RTCC_CTRL_CNTTICK should be set to PRESC, and the CNTPRESC bitfield    */
  /* of the RTCC_CTRL register should be set to DIV32768 if a 32768 Hz clock source is used. */
  rtccInit.enable   = false;
  rtccInit.presc = rtccCntPresc_32768;
  rtccInit.cntMode = rtccCntModeCalendar;
  RTCC_Init(&rtccInit);

  /* Initialize date and time */
  RTCC_DateSet(START_DATE);
  RTCC_TimeSet(START_TIME);
    
  /* Enable required interrupt */
  RTCC_IntEnable(RTCC_IEN_CNTTICK);
  /* Enable RTCC interrupt */
  NVIC_ClearPendingIRQ(RTCC_IRQn);
  NVIC_EnableIRQ(RTCC_IRQn);

  /* Start Counter */
  RTCC_Enable(true);
}

/**************************************************************************//**
 * @brief Initialize CRYOTIMER and PRS to trigger ADC
 *****************************************************************************/
void cryotimerSetup(void)
{
  CRYOTIMER_Init_TypeDef cryotimerInit = CRYOTIMER_INIT_DEFAULT;

  /* Trigger period = 64K x 1/32768 */
  CMU_ClockEnable(cmuClock_CRYOTIMER, true);
  cryotimerInit.osc = cryotimerOscLFXO;
  cryotimerInit.period = cryotimerPeriod_512;
  cryotimerInit.enable=true;
  CRYOTIMER_Init(&cryotimerInit);

  /* Enable required interrupt */
  CRYOTIMER_IntEnable(CRYOTIMER_IEN_PERIOD);
  /* Enable CRYOTIMER interrupt */
  NVIC_ClearPendingIRQ(CRYOTIMER_IRQn);
  NVIC_EnableIRQ(CRYOTIMER_IRQn);

  /* Output to PRS channel 0 */
 // CMU_ClockEnable(cmuClock_PRS, true);
 // PRS_SourceSignalSet(0, PRS_CH_CTRL_SOURCESEL_CRYOTIMER, PRS_CH_CTRL_SIGSEL_CRYOTIMERPERIOD, prsEdgePos);
}


/**************************************************************************//**
* @brief Print RTCC date.
*****************************************************************************/
void rtccPrintDate(void)
{
  uint32_t rtccTemp;
  
  rtccTemp = RTCC_DateGet();
  printf ("Date: 20%lx%lx/%lx%lx/%lx%lx\n", 
          (rtccTemp >> _RTCC_DATE_YEART_SHIFT) & 0x0f,
          (rtccTemp >> _RTCC_DATE_YEARU_SHIFT) & 0x0f,
          (rtccTemp >> _RTCC_DATE_MONTHT_SHIFT) & 0x0f,
          (rtccTemp >> _RTCC_DATE_MONTHU_SHIFT) & 0x0f,
          (rtccTemp >> _RTCC_DATE_DAYOMT_SHIFT) & 0x0f,
          (rtccTemp & 0x0f));
}

/**************************************************************************//**
* @brief Print RTCC time.
*****************************************************************************/
void rtccPrintTime(void)
{
  uint32_t rtccTemp;
  
  rtccTemp = RTCC_TimeGet();
  printf ("Time: %lx%lx:%lx%lx:%lx%lx\n", 
          (rtccTemp >> _RTCC_TIME_HOURT_SHIFT),
          (rtccTemp >> _RTCC_TIME_HOURU_SHIFT) & 0x0f,
          (rtccTemp >> _RTCC_TIME_MINT_SHIFT) & 0x0f,
          (rtccTemp >> _RTCC_TIME_MINU_SHIFT) & 0x0f,
          (rtccTemp >> _RTCC_TIME_SECT_SHIFT) & 0x0f,
          (rtccTemp & 0x0f));
}

/**************************************************************************//**
* @brief CRYOTIMER Interrupt handler
*****************************************************************************/
void CRYOTIMER_IRQHandler(void)
{
	cryotimerFlag = CRYOTIMER->IFC;

}


/**************************************************************************//**
* @brief RTCC Interrupt handler
*****************************************************************************/
void RTCC_IRQHandler(void)
{
  /* Read and clear interrupt source */
  rtccFlag = RTCC->IFC;
  GPIO_PinOutToggle(gpioPortC, 6);
}

/**************************************************************************//**
* @brief GPIO Interrupt handler for even pins
*****************************************************************************/
void GPIO_EVEN_IRQHandler(void)
{
  /* Read and clear interrupt source */
  gpioFlag = GPIO->IFC;
}

void GPIO_ODD_IRQHandler(void)
{
  /* Read and clear interrupt source */
  gpioFlag = GPIO->IFC;
  PressedKey = Get_KeyboardKey();
  PrintKey(PressedKey);
}

/**************************************************************************//**
 * @brief  Main function
 *****************************************************************************/
int main(void)
{
  EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_STK_DEFAULT;

  /* Chip errata */
  CHIP_Init();

  /* Init DCDC regulator and HFXO with kit specific parameters */
  EMU_DCDCInit(&dcdcInit);

  /* Enable LFE domain for RTCC */
  CMU_ClockEnable(cmuClock_CORELE, true);
  CMU_ClockSelectSet(cmuClock_LFE, cmuSelect_LFXO);

  /* Enable LFXO for CRYOTIMER */
  CMU_OscillatorEnable(cmuOsc_LFXO, true, true);

  /* Enable atomic read-clear operation on reading IFC register */
  MSC->CTRL |= MSC_CTRL_IFCREADCLEAR;
  
  /* Initialize and retarget USART. */
  RETARGET_SerialInit();
  RETARGET_SerialCrLf(1);
  RETARGET_UART->IEN = 0;
  
  /* Initialize GPIO and RTCC. */
  gpioSetup();
  rtccSetup();
  cryotimerSetup();
  

  printf ("Display Keys as pressed\n\n");

  
  while (1)
  {

	  	  	DriveKeyboardColumns();
		    //EMU_EnterEM1();
		  	EMU_EnterEM2(true);
		    if ((rtccFlag ) || gpioFlag || cryotimerFlag)
		    {
		      cryotimerFlag=0;
		      rtccFlag = 0;
		      gpioFlag = 0;
		    }



  }
}

void DriveKeyboardColumns()
{
	 for(Keyboard_State=DRIVING_C1;Keyboard_State<=DRIVING_C3;Keyboard_State++)
		  {
			  switch (Keyboard_State)
			  {
			  	  case DRIVING_C1:{
							  Set_KeyboardC1();
							  Clear_KeyboardC2();
							  Clear_KeyboardC3();
							  break;
			  	  	  	  }
			  	  case DRIVING_C2:{
							  Clear_KeyboardC1();
							  Set_KeyboardC2();
							  Clear_KeyboardC3();
							  break;
			  	  	  	  }
			  	  case DRIVING_C3:{
							  Clear_KeyboardC1();
							  Clear_KeyboardC2();
							  Set_KeyboardC3();
							  break;
			  	  	  	  }
			  }
		  }
}

KEYBOARDKEYS Get_KeyboardKey()
{
	static uint8_t counter=0;

	KEYBOARDKEYS KeyboardRead = END_OF_KEYS;
	static KEYBOARDKEYS LastKeyboardRead = END_OF_KEYS;

	switch (Keyboard_State)
			  {
				case DRIVING_C1:
					{
							 if (Get_KeyboardR1()==0) KeyboardRead = KEY_1;
						else if (Get_KeyboardR2()==0) KeyboardRead = KEY_4;
						else if (Get_KeyboardR3()==0) KeyboardRead = KEY_7;
						else if (Get_KeyboardR4()==0) KeyboardRead = KEY_C;
							 break;
					}
				case DRIVING_C2:
					{
							 if (Get_KeyboardR1()==0) KeyboardRead = KEY_2;
						else if (Get_KeyboardR2()==0) KeyboardRead = KEY_5;
						else if (Get_KeyboardR3()==0) KeyboardRead = KEY_8;
						else if (Get_KeyboardR4()==0) KeyboardRead = KEY_0;
							 break;
					}
				case DRIVING_C3:
					{
							 if (Get_KeyboardR1()==0) KeyboardRead = KEY_3;
						else if (Get_KeyboardR2()==0) KeyboardRead = KEY_6;
						else if (Get_KeyboardR3()==0) KeyboardRead = KEY_9;
						else if (Get_KeyboardR4()==0) KeyboardRead = KEY_LOCK;
							 break;
					}
			  }


/*Debouncing*/

	switch (counter)
	{
		case 0: {
					LastKeyboardRead = KeyboardRead;
					counter++;
					return 0;
				}
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
				{
					if (LastKeyboardRead == KeyboardRead)
					{
						LastKeyboardRead = KeyboardRead;
						counter++;
					}
					else counter=0;
					return 0;
				}
		case 8:
						{
							if (LastKeyboardRead == KeyboardRead)
							{
								LastKeyboardRead = KeyboardRead;
								counter=0;
								return KeyboardRead;
							}
							else counter=0;
							return 0;
						}
	}


}


void PrintKey(KEYBOARDKEYS Key)
{

	if ((Key<END_OF_KEYS) && (Key!=0)) printf ("Keyboard Key %c\r\n", Key);

}

