/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: SchM_Tasks.c $
 * $Revision: version 1$
 * $Author: Habib Apez $
 * $Date: 2017-11- 22 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \SchM_Tasks.c
    Source of SchM_Tasks. Located at SERVICES in Scheduler.
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
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: SchM_Tasks.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "SERVICES\Scheduler\SchM_Tasks.h"
#include "HAL\leds.h"
#include "HAL\can.h"
#include "APP\sensorsm.h"
#include "APP\passengerremsm.h"

/* Constants and types  */
/*============================================================================*/
#define ONE_SECOND_TASK 		500
#define ZERO_SECOND_TASK		0
#define POWER_UP_CONTER_RESET	0


/* Variables */
/*============================================================================*/
extern T_UBYTE rub_PowerUpCounter;

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/* Exported functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : SchM_5ms_Task
 *  Description          : Executes a task each 5ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_5ms_Task(void){   /* Code Task0*/
  //leds_ToggleBlueBoardLED();
  // Read CAN bus and collect data from ECU each 10ms*

	leds_TurnOnAntipinchLED();
	if(1 == can_CheckMessageArrivalCAN0(RX_MSG1_BUFF)){
		  leds_TurnOnDownLED();
		  T_ULONG rul_RxMessageData[2] = {0, 0};
		  T_ULONG rul_TxMessageData[2] = {0, 0};
	      can_ReceiveMessageCAN0(RX_MSG1_BUFF, rul_RxMessageData);
	      rul_TxMessageData[0] = rul_RxMessageData[0];
	      rul_TxMessageData[1] = rul_RxMessageData[1];
		  //can_TransmitMessageCAN0(TX_MSG1_BUFF, TX_MSG1_ID, rul_TxMessageData);
	      leds_TurnOffDownLED();
	      rub_PowerUpCounter = POWER_UP_CONTER_RESET;
	}
	leds_TurnOffAntipinchLED();
}

/**************************************************************
 *  Name                 : SchM_10ms_Task
 *  Description          : Executes a task each 10ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_10ms_Task(void){  /* Code Task1*/
  //leds_ToggleRedBoardLED();
  sensorsm_StateMachine();
}

/**************************************************************
 *  Name                 : SchM_20ms_Task
 *  Description          : Executes a task each 20ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_20ms_Task(void){  /* Code Task2*/
  //leds_ToggleGreenBoardLED();
  // Run Driver an Passenger Reminders state machines
  static T_UBYTE lub_OneSecondCounter = ZERO_SECOND_TASK;
  lub_OneSecondCounter++;
  if(lub_OneSecondCounter >= ONE_SECOND_TASK){
	  lub_OneSecondCounter = ZERO_SECOND_TASK;
	  rub_PowerUpCounter++;
	  passengerremsm_ModingStateMachine();
  }
  else{
	  // Do nothing
  }
}

/**************************************************************
 *  Name                 : SchM_40ms_Task
 *  Description          : Executes a task each 8ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_40ms_Task(void){  /* Code Task3*/
  //leds_ToggleAntipinchLED();
  // Send Chrime and Seat Belt data each 200ms
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
