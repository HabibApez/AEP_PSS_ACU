/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Main.c $
 * $Revision: version 1$
 * $Author: Habib Apez $
 * $Date: 2017-11- 22 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \Mainc
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
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: Main.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "C:\My Documents\Continental\IAR\Devs\lib\Common\Std_Types.h"                  // OK
#include "C:\My Documents\Continental\IAR\Devs\lib\HAL\clock.c"                         // OK
#include "C:\My Documents\Continental\IAR\Devs\lib\HAL\delays.c"                        // OK
#include "C:\My Documents\Continental\IAR\Devs\lib\HAL\button.c"                        // OK
#include "C:\My Documents\Continental\IAR\Devs\lib\HAL\segmentbar.c"                    // OK
#include "C:\My Documents\Continental\IAR\Devs\lib\HAL\leds.c"                          // OK
#include "C:\My Documents\Continental\IAR\Devs\lib\SERVICES\Interrupts\interrupts.c"    // OK
#include "C:\My Documents\Continental\IAR\Devs\lib\SERVICES\Scheduler\SchM.c"           // OK
#include "C:\My Documents\Continental\IAR\Devs\lib\SERVICES\Scheduler\SchM_Cfg.c"       // OK

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
  if ( NULL!= GlbSysTickCallback)
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
 void main(void){
  clock_InitClock();
  delays_InitTimer();
  segmentbar_InitBar();
  button_InitButtons();
  leds_InitBoardLeds();
  leds_InitLeds();
    
  SchM_Init(&SchM_Config);	/* Scheduler Services Initialization */
  SchM_Start();		        /* Start Scheduler Services */
    
  for(;;){
    // Do nothing
  }
}

/* Exported functions */
/*============================================================================*/

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
