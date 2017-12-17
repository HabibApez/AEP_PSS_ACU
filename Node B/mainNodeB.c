/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: main.c $
 * $Revision: version 2$
 * $Author: Habib Apez $
 * $Date: 2017-12 -15 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \main.c
    Main at APP in Scheduler.
    Window Lifter project main with Scheduler and State Machines.
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  Author             |        Version     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/* Habib Apez          |          1         |   Initial version               */
/* Habib Apez          |          2         |   Node B 						  */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: main.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "HAL\clock.h"                         // OK
#include "HAL\button.h"                          // OK
#include "HAL\leds.h"                          // OK
#include "HAL\sensors.h"                       // OK
#include "HAL\can.h"                       	   // OK
#include "SERVICES\Interrupts\interrupts.h"    // OK
#include "SERVICES\Scheduler\SchM.h"           // OK
#include "SERVICES\Scheduler\SchM_Cfg.h"       // OK



#include "HAL\delays.h"                          // OK
#include "MCAL\adc.h"                       	   // OK

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/
T_UWORD ruw_EngineRPM = 0x2328;
T_UBYTE rub_EngineStatus = 0x00;
T_ULONG rul_RxMessageData[2] = {0, 0};
T_ULONG rul_TxMessageData[2] = {0, 0};

/* Private functions prototypes */
/*============================================================================*/
//void SysTick_Handler(void);

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : adc_ReadRPM
 *  Description          : Moves the Window upwards
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UWORD main_ReadRPM(S_ADC *lps_ADC, T_UBYTE lub_ADCH){
  T_UWORD luw_ADCResult = 0;

  adc_StartConversion(lps_ADC, lub_ADCH);
  while(0 == adc_CheckCompConvFlag(lps_ADC)){};
  luw_ADCResult = adc_ReadConversionResult(lps_ADC, lub_ADCH);

  //return (T_ULONG) ((5000*luw_ADCResult)/0xFFF); /* Convert result to mv for 0-5V range */
  return luw_ADCResult; /* Convert result to mv for 0-5V range */
}

/**************************************************************
 *  Name                 : main
 *  Description          : Implements the main function
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
 int main(void){

  clock_InitClock();
  leds_InitBoardLeds();
  leds_InitLeds();
  button_InitBoardButtons();
  sensor_InitSensors();
  delays_InitTimer();

  can_InitCAN0();

  //SchM_Init(&SchM_Config);	/* Scheduler Services Initialization */
  //SchM_Start();		        /* Start Scheduler Services */

  for(;;){
    ruw_EngineRPM = main_ReadRPM(rps_ADC0, 12);
    if(1 == button_ValidRightBoardButtonPress()){
    	if(0x00 == rub_EngineStatus){
    		rub_EngineStatus = 0x01;
    		leds_TurnOnRedBoardLED();
    	}
    	else{
    		if(0x01 == rub_EngineStatus){
    		leds_TurnOffRedBoardLED();
    		rub_EngineStatus = 0x00;
    		}
    	}
  }
   // rub_EngineStatus = button_CheckButtonUp();
    rul_TxMessageData[0] = 0x00000000;
    rul_TxMessageData[0] |= (ruw_EngineRPM & 0x00FF) << 24;
    rul_TxMessageData[0] |= ((ruw_EngineRPM & 0xFF00) >> 8) << 16;
    rul_TxMessageData[0] |= rub_EngineStatus << 8;
    rul_TxMessageData[1] = 0x00000000;
    can_TransmitMessageCAN0(TX_MSG1_BUFF, 0x100, rul_TxMessageData);
    leds_ToggleDownLED();
  //  if(1 == can_CheckMessageArrivalCAN0(RX_MSG1_BUFF)){
			  //leds_TurnOnDownLED();
//		      can_ReceiveMessageCAN0(RX_MSG1_BUFF, rul_RxMessageData);
	//	      rul_TxMessageData[0] = rul_RxMessageData[0];
		///      rul_TxMessageData[1] = rul_RxMessageData[1];
			//  can_TransmitMessageCAN0(TX_MSG1_BUFF, TX_MSG1_ID, rul_TxMessageData);
		      //leds_TurnOffDownLED();
		    //  rub_PowerUpCounter = POWER_UP_CONTER_RESET;
//		}
    // Do nothing
  }

  return 0;
}

/* Exported functions */
/*============================================================================*/

 /* Notice: the file ends with a blank new line to avoid compiler warnings */

