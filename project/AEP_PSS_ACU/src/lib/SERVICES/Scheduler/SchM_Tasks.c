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
#define ONE_SECOND_TASK 		25
#define TWO_HUNDRED_MS_TASK   	10
#define ZERO_SECONDS_TASK		0
#define POWER_UP_CONTER_RESET	0


/* Variables */
/*============================================================================*/
T_UBYTE rub_PowerUpCounter;
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
  //leds_ToggleBlueBoardLED();
  // Read CAN bus and collect data from ECU each 10ms*

	//leds_TurnOnAntipinchLED();
	if(1 == can_CheckMessageArrivalCAN0(ENG_RPM_MSG_BUFF)){
		  //leds_TurnOnDownLED();
	      can_ReceiveMessageCAN0(ENG_RPM_MSG_BUFF, rul_RxMessageData);
	      ruw_EngineRPM = ((rul_RxMessageData[0] & 0x00FF0000) >> 16) | ((rul_RxMessageData[0] & 0xFF000000) >> 16);
	      rub_EngineStatus = (rul_RxMessageData[0] & 0x0000FF00) >> 8;

		  //can_TransmitMessageCAN0(TX_MSG1_BUFF, TX_MSG1_ID, rul_TxMessageData);
	      //leds_TurnOffDownLED();
	      if(0 == rub_EngineStatus)
	      rub_PowerUpCounter = POWER_UP_CONTER_RESET;
	}
	//leds_TurnOffAntipinchLED();
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
  // Send Chrime and Seat Belt data each 200ms
  static T_UBYTE lub_TwoMsCounter = ZERO_SECONDS_TASK;
  lub_TwoMsCounter++;

  if(TWO_HUNDRED_MS_TASK == lub_TwoMsCounter){
	  lub_TwoMsCounter = ZERO_SECONDS_TASK;
	  // Package CAN signals
	  //Message1
	  rul_TxMessageData[0] = 0;
	  rul_TxMessageData[0] |= (0x01) << 24; 	/* Driver Indication */
	  rul_TxMessageData[0] |= (0x64) << 16; 	/* Driver Indication Duty Cycle */
	  rul_TxMessageData[0] |= (0x01) << 8; 	/* Driver Indication Period*/
	  rul_TxMessageData[0] |= passengerremsm_PassengerGetIndicatorStatus() << 0; 	/* Passenger Indication */

	  rul_TxMessageData[1] = 0;
	  rul_TxMessageData[1] |= passengerremsm_PassengerGetIndicationDutyCycle() << 24; 	/* Passenger Indication Duty Cycle*/
	  rul_TxMessageData[1] |= passengerremsm_PassengerGetIndicationPeriod() << 16; 	/* Passenger Indication Period */
	  rul_TxMessageData[1] |= (0x00) << 8; 	/* No data */
	  rul_TxMessageData[1] |= (0x00) << 0; 	/* No data */

	  // Send CAN messages
	  can_TransmitMessageCAN0(SEAT_BELT_INDICATOR_MSG_BUFF, SEAT_BELT_INDICATOR_MSG_ID, rul_TxMessageData);


	  // Package CAN signals
	  //Message1
	  rul_TxMessageData[0] = 0;
	  rul_TxMessageData[0] |= passengerremsm_GetSoundTone() << 24; 	/* Sound Tone */
	  rul_TxMessageData[0] |= passengerremsm_GetSoundCadence() << 16; 	/* Sound Cadence Period */
	  rul_TxMessageData[0] |= passengerremsm_GetSoundRepetitions() << 8; 	/* Sound Cadence Period */
	  rul_TxMessageData[0] |= passengerremsm_GetSoundDutyCycle() << 0; 	/* Sound Tone Duty Cycle */

	  rul_TxMessageData[1] = 0;
	  rul_TxMessageData[1] |= (0x01) << 24; 	/*  location Driver */
	  rul_TxMessageData[1] |= passengerremsm_PassengerGetChimeStatus() << 16; 	/* Location Passenger */
	  rul_TxMessageData[1] |= (0x00) << 8; 	/* No data */
	  rul_TxMessageData[1] |= (0x00) << 0; 	/* No data */

	  // Send CAN messages
	  can_TransmitMessageCAN0(CHIME_REQUEST_MSG_BUFF, CHIME_REQUEST_MSG_ID, rul_TxMessageData);

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
  leds_TurnOnAntipinchLED();
  // Run Driver an Passenger Reminders state machines
  static T_UBYTE lub_OneSecondCounter = ZERO_SECONDS_TASK;
  lub_OneSecondCounter++;
  if(lub_OneSecondCounter >= ONE_SECOND_TASK){
	  leds_TurnOnUpLED();
	  lub_OneSecondCounter = ZERO_SECONDS_TASK;

	  rub_PowerUpCounter++;
	  if(rub_PowerUpCounter >= 5){
		  leds_ToggleDownLED();
	  }

	  passengerremsm_ModingStateMachine();
	  leds_TurnOffUpLED();
  }
  else{
	  // Do nothing
  }
  leds_TurnOffAntipinchLED();
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
