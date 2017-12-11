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
#include "HAL\leds.h"                         // OK
#include "HAL\sensors.h"                         // OK
#include "SERVICES\Interrupts\interrupts.h"    // OK
#include "SERVICES\Scheduler\SchM.h"           // OK
#include "SERVICES\Scheduler\SchM_Cfg.h"       // OK


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

 // for(;;){
 //   sensorsm_StateMachine();
 // }

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

