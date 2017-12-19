/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: main.c $
 * $Revision: version 8 $
 * $Author: Habib Apez $
 * $Date: 2017-12 -18 $
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
/*                     |                    |   scheduler                     */
/* Habib Apez          |          3         |   Passenger state machine added */
/* Habib Apez          |          4         |   Tx CAN msgs functions added   */
/* Habib Apez          |          5         |   Rx CAN msgs function added    */
/* Habib Apez          |          6         |   Driver state machine added    */
/* Habib Apez          |          7         |   Reminder state machine added  */
/* Habib Apez          |          8         |   Sensor Indicators added       */
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
#include "HAL\can.h"                       	   // OK
#include "SERVICES\Interrupts\interrupts.h"    // OK
#include "SERVICES\Scheduler\SchM.h"           // OK
#include "SERVICES\Scheduler\SchM_Cfg.h"       // OK
#include "HAL\seatindicators.h"


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
   //leds_ToggleBlueBoardLED();
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
  seatindicators_InitIndicators();

  can_InitCAN0();

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

