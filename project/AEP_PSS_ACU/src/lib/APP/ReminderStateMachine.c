/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: ACU_StateMachine.c $
 * $Revision: version 1 $
 * $Author: Antonio Vazquez $
 * $Date: 2017-12-09 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \DSBR.c
    State Machine function for the Driver Seat Belt Reminder. Located at APP
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
/* Antonio Vazquez    |          1         |   Initial version               */
/* Antonio Vázquez    |          2         | State Machine improved           */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: DSBR.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "APP/ReminderStateMachine.h"

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
 *  Name                 : ACU_StateMachine
 *  Description          : Manager the main function for the ACU module.
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void ACU_StateMachine (void){
  T_ULONG rx_msg_data[2];

if(FLEXCAN_msg_flag(rps_CAN0, MSG_BUF_4)){
  FLEXCAN_receive_msg(rps_CAN0, MSG_BUF_4, rx_msg_data);

  	  switch(rx_msg_data[FIRST_PART_OF_MSG]){
  	  case ENG_INACTIVE:
  		  rub_ACUMode = ACU_OFF_MODE;
  		  leds_ToggleBlueBoardLED();
  		  break;
  	  case ENG_ACTIVE:
  		  rub_ACUMode = ACU_ON_MODE;
  		  leds_ToggleRedBoardLED();
  		  break;
  	  default:
  		  break;
  	  }
}}



 /* Notice: the file ends with a blank new line to avoid compiler warnings */

 *
 *  Created on: 13/12/2017
 *      Author: uidn8311
 */


