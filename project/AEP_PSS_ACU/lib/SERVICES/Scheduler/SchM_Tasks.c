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
#include "APP\buttonsm.c"
#include "APP\windowlifter.c"

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
 *  Name                 : SchM_5ms_Task
 *  Description          : Executes a task each 5ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_5ms_Task(void){   /* Code Task0*/
  //leds_ToggleBlueBoardLED();
}

/**************************************************************
 *  Name                 : SchM_10ms_Task
 *  Description          : Executes a task each 10ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_10ms_Task(void){  /* Code Task1*/
  leds_ToggleRedBoardLED();
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
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
