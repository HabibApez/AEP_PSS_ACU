/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: remindersm.c $
 * $Revision: version 2 $
 * $Author: Habib Apez $
 * $Date: 2017-12-18 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \remindersm.c
    state machine for the reminder. Located at APP.
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
/*----------------------------------------------------------------------------*/
/*  Author             |        Version     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/* Habib Apez          |          1         |   Initial version               */
/* Habib Apez          |          2         |   Indicator functions added     */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: remindersm.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "APP\remindersm.h"
#include "APP\driverremsm.h"
#include "APP\passengerremsm.h"
#include "SERVICES\Communications\canbus.h"

/* Constants and types  */
/*============================================================================*/
#define ZERO_SECONDS_TASK		0
#define ONE_SECOND_TASK 		25

/* Variables */
/*============================================================================*/
E_ReminderStateMachine re_ReminderSmState = ECU_OFF_MODE;

/* Private functions prototypes */
/*============================================================================*/
void remindersm_RunDriverAndPassengerReminderSM(void);

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
void remindersm_RunDriverAndPassengerReminderSM(void){
  static T_UBYTE lub_OneSecondCounter = ZERO_SECONDS_TASK;
  lub_OneSecondCounter++;
  if(lub_OneSecondCounter >= ONE_SECOND_TASK){
	  lub_OneSecondCounter = ZERO_SECONDS_TASK;

	  if(1 == canbus_GetEngStatus())
		  rub_PowerUpCounter++;
	  else
		  rub_PowerUpCounter = 0;

	  if(rub_PowerUpCounter >= 1){
		  driverremsm_ModingStateMachine();
		  passengerremsm_ModingStateMachine();
	  }
  }
  else{
	  // Do nothing
  }
}

/******************************************************************************/
/*******************    STATES DEFINITIONS   **********************************/
/******************************************************************************/

/**************************************************************
 *  Name                 : remindersm_NoFunctionalState
 *  Description          : Defines the No Functional state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void remindersm_NoFunctionalState(void){
  if(1 == canbus_GetEngStatus()){
	  re_ReminderSmState = ECU_RUN_MODE;
  }
  else{
	  // Do nothing
  }
}

/**************************************************************
 *  Name                 : remindersm_DriverUnfastenedAndOccupiedState
 *  Description          : Defines the Full Functional state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void remindersm_FullFunctionalState(void){
  if(0 == canbus_GetEngStatus()){
	  re_ReminderSmState = ECU_OFF_MODE;
	  //RESET POWERUP COUNTER AND EVERYHTING ELSE
	  rub_PowerUpCounter = 0;
	  driverremsm_SetResetConfiguration();
	  passengerremsm_SetResetConfiguration();
  }
  else{
	  remindersm_RunDriverAndPassengerReminderSM();
  }
}

/* Exported functions */
/*============================================================================*/
/******************************************************************************/
/************************    STATE MACHINES   **********************************/
/******************************************************************************/
/**************************************************************
 *  Name                 : remindersm_ReminderStateMachine
 *  Description          : State Machine for the reminder
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void remindersm_ReminderStateMachine(void){
  switch(re_ReminderSmState){
    case ECU_OFF_MODE:
    	remindersm_NoFunctionalState();
      break;

    case ECU_RUN_MODE:
    	remindersm_FullFunctionalState();
      break;

    default:
      break;
  }
}

/* Notice: the file ends with a blank new line to avoid compiler warnings */
