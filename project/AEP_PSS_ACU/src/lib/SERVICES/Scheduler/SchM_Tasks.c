/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: SchM_Tasks.c $
 * $Revision: version 4 $
 * $Author: Habib Apez $
 * $Date: 2017-12- 18 $
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
/* Habib Apez          |          4         |   Reminder State Machine added  */
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
#include "APP\remindersm.h"
#include "HAL\leds.h"

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/
T_UBYTE rub_EngineStatus;
T_UWORD ruw_EngineRPM;
T_ULONG rul_RxMessageData[2] = {0, 0};
T_ULONG rul_TxMessageData[2] = {0, 0};

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
	remindersm_ReminderStateMachine();
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
