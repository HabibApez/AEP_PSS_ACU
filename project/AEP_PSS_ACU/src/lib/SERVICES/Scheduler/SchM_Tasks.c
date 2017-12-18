/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: SchM_Tasks.c $
 * $Revision: version 2$
 * $Author: Habib Apez $
 * $Date: 2017-12- 17 $
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
/* Habib Apez          |          2         |   Read and send CAN messages added */
/* Habib Apez          |          3         |   Modified for its use with     */
/*                     |                    |   Communications layer          */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: SchM_Tasks.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "SERVICES\Scheduler\SchM_Tasks.h"
#include "SERVICES\Communications\canbus.h"
#include "APP\sensorsm.h"
#include "APP\driverremsm.h"
#include "APP\passengerremsm.h"
#include "HAL\leds.h"

/* Constants and types  */
/*============================================================================*/
#define ONE_SECOND_TASK 		25

/* Variables */
/*============================================================================*/
T_UBYTE rub_EngineStatus;
T_UWORD ruw_EngineRPM;
T_ULONG rul_RxMessageData[2] = {0, 0};
T_ULONG rul_TxMessageData[2] = {0, 0};

/* Private functions prototypes */
/*============================================================================*/
void SchM_RunDriverAndPassengerReminderSM(void);

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : SchM_DriverAndPassengerReminderSM
 *  Description          : Run Driver an Passenger Reminders state machines
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_RunDriverAndPassengerReminderSM(void){
  leds_TurnOnAntipinchLED();
  //
  static T_UBYTE lub_OneSecondCounter = ZERO_SECONDS_TASK;
  lub_OneSecondCounter++;
  if(lub_OneSecondCounter >= ONE_SECOND_TASK){
	  leds_TurnOnUpLED();
	  lub_OneSecondCounter = ZERO_SECONDS_TASK;

	  rub_PowerUpCounter++;
	  if(rub_PowerUpCounter >= 2){
		  leds_ToggleDownLED();
		  driverremsm_ModingStateMachine();
		  passengerremsm_ModingStateMachine();

	  }

	  leds_TurnOffUpLED();
  }
  else{
	  // Do nothing
  }
  leds_TurnOffAntipinchLED();
}

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
  canbus_ReadEngRPMMessage();
}

/**************************************************************
 *  Name                 : SchM_10ms_Task
 *  Description          : Executes a task each 10ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_10ms_Task(void){  /* Code Task1*/
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
  canbus_SendCANMessages();
}

/**************************************************************
 *  Name                 : SchM_40ms_Task
 *  Description          : Executes a task each 8ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_40ms_Task(void){  /* Code Task3*/
  SchM_RunDriverAndPassengerReminderSM();
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
