/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: main.c $
 * $Revision: version 2$
 * $Author: Habib Apez $
 * $Date: 2017-12 -10 $
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
/* Habib Apez          |          2         |   Sensor Manager added to the   */
/* Habib Apez          |          2         |   scheduler                     */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: main.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "HAL\clock.h"                         // OK
#include "HAL\leds.h"                          // OK
#include "HAL\sensors.h"                       // OK
#include "SERVICES\Interrupts\interrupts.h"    // OK
#include "SERVICES\Scheduler\SchM.h"           // OK
#include "SERVICES\Scheduler\SchM_Cfg.h"       // OK

#include "HAL\can.h"                       // OK


/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/

/* Private functions prototypes */
/*============================================================================*/
void SysTick_Handler(void);

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : SystTick interruption
 *  Description          : Moves the Window upwards
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SysTick_Handler(void){
  if (NULL!= GlbSysTickCallback)
	  GlbSysTickCallback();
  // leds_ToggleBlueBoardLED();
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
  sensor_InitSensors();

  T_ULONG rul_RxMessageData[2];
  T_ULONG rul_TxMessageData[2];

  can_InitCAN0();

  for(;;){
	leds_TurnOffDownLED();
	leds_TurnOffAntipinchLED();
	if(1 == can_CheckMessageArrivalCAN0(RX_MESSAGE1_MESSAGEBUFFER)){
	  leds_TurnOnDownLED();
	  leds_TurnOffAntipinchLED();
      can_ReceiveMessageCAN0(RX_MESSAGE1_MESSAGEBUFFER, rul_RxMessageData);
      rul_TxMessageData[0] = rul_RxMessageData[0];
      rul_TxMessageData[1] = rul_RxMessageData[1];
	  can_TransmitMessageCAN0(0, TX_MESSAGE1_ID, rul_TxMessageData);
	}
	if(1 == can_CheckMessageArrivalCAN0(RX_MESSAGE2_MESSAGEBUFFER)){
	  leds_TurnOffDownLED();
      leds_TurnOnAntipinchLED();
      can_ReceiveMessageCAN0(RX_MESSAGE2_MESSAGEBUFFER, rul_RxMessageData);
      rul_TxMessageData[0] = rul_RxMessageData[0];
      rul_TxMessageData[1] = rul_RxMessageData[1];
      can_TransmitMessageCAN0(2, TX_MESSAGE2_ID, rul_TxMessageData);
	}
  }

  SchM_Init(&SchM_Config);	/* Scheduler Services Initialization */
  SchM_Start();		        /* Start Scheduler Services */

  for(;;){
    // Do nothing
  }

  return 0;
}

/* Exported functions */
/*============================================================================*/

 /* Notice: the file ends with a blank new line to avoid compiler warnings */

