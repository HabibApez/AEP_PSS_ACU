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
#include "SchM_Tasks.h"
#include "C:\My Documents\Continental\IAR\Devs\lib\APP\buttonsm.c"
#include "C:\My Documents\Continental\IAR\Devs\lib\APP\windowlifter.c"

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/* Exported functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : SchM_1ms_Task
 *  Description          : Executes a task each 1ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_1ms_Task(void){   /* Code Task0*/
  buttonsm_StateMachine();
  // leds_ToggleBlueBoardLED();
}

/**************************************************************
 *  Name                 : SchM_2ms_Task
 *  Description          : Executes a task each 2ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_2ms_Task(void){  /* Code Task1*/
  windowlifter_StateMachine();
  // leds_ToggleBlueBoardLED();
}

/**************************************************************
 *  Name                 : SchM_4ms_Task
 *  Description          : Executes a task each 4ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_4ms_Task(void){  /* Code Task2*/
  
}

/**************************************************************
 *  Name                 : SchM_8ms_Task
 *  Description          : Executes a task each 8ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_8ms_Task(void){  /* Code Task3*/
  
}

/**************************************************************
 *  Name                 : SchM_16ms_Task
 *  Description          : Executes a task each 16ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_16ms_Task(void){  /* Code Task4*/
  
}

/**************************************************************
 *  Name                 : SchM_32ms_Task
 *  Description          : Executes a task each 32ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_32ms_Task(void){  /* Code Task5*/
  // leds_ToggleBlueBoardLED();
}
 /* Notice: the file ends with a blank new line to avoid compiler warnings */
