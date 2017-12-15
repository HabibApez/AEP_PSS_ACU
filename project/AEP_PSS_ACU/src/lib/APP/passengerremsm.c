/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: passengerremsm.c $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-12-14 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \passengerremsm.c
    state machine for the passenger reminder. Located at APP.
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
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: passengerremsm.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "APP\passengerremsm.h"
#include "APP\sensorsm.h"

/* Constants and types  */
/*============================================================================*/
#define ZERO		 			0
#define ZERO_SECONDS 			0
#define SIX_SECONDS 			6
#define TWENTY_SECONDS 			20
#define TWENTY_FIVE_SECONDS 	25
#define THIRTY_THREE_SECONDS 	33
#define THIRTY_FIVE_SECONDS 	35

/* Variables */
/*============================================================================*/

E_PassengerBasicReminderStateMachine re_ModingSmState = FASTENED_OR_NOT_OCCUPIED_PASSENGER;
E_PassengerReminderStateMachine re_UnfastenedAndOccupiedSmState = NO_CHIME_AND_CONTINUOUS_INDICATION_PASSENGER;
E_PassengerReminderChimeStateMachine re_ChimeSmState = CHIME_TYPE1_PASSENGER;
E_PassengerReminderTellTaleStateMachine re_TelltaleSmState = FLASHING_TELLTALE_PASSENGER;

S_Reminder rs_PassengerReminder;
S_Reminder *rps_PassengerReminder = &rs_PassengerReminder;

T_UBYTE rub_PowerUpCounter = ZERO;

/* Private functions prototypes */
/*============================================================================*/
void passengerremsm_PassengerFastenedOrNotOccupiedState(void);
void passengerremsm_PassengerUnfastenedAndOccupiedState(void);
void passengerremsm_PassengerNoChimeAndcontinuousIndicationState(void);
void passengerremsm_PassengerBasicIndicationState(void);
void passengerremsm_PassengerChimeType1State(void);
void passengerremsm_PassengerNoChimeState(void);
void passengerremsm_PassengerFlashingTelltaleState(void);
void passengerremsm_PassengerContinuousTelltaleState(void);
void passengerremsm_PassengerNoIndicationTelltaleState(void);

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/******************************************************************************/
/*******************    STATES DEFINITIONS   **********************************/
/******************************************************************************/

/**************************************************************
 *  Name                 : passengerremsm_PassengerFastenedOrNotOccupiedState
 *  Description          : Defines the Passenger Fastened Or Not Occupied state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_PassengerFastenedOrNotOccupiedState(void){
  if((rps_PassengerSeatBeltSensor-> re_SensorValidStatus == BS_UNBUCKLED) && (rps_PassengerSeatSensor-> re_SensorValidStatus == OS_OCUPPIED))
	  re_ModingSmState = UNFASTENED_AND_OCCUPIED_PASSENGER;
}

/**************************************************************
 *  Name                 : passengerremsm_PassengerUnfastenedAndOccupiedState
 *  Description          : Defines the Passenger Unfastened And Occupied state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_PassengerUnfastenedAndOccupiedState(void){
//  static T_UBYTE lub_PSBFilterCounter = ZERO_TIMES;

//  rub_PowerUpCounter++;

  if((rps_PassengerSeatBeltSensor-> re_SensorValidStatus == BS_BUCKLED) || (rps_PassengerSeatSensor-> re_SensorValidStatus == OS_UNOCUPPIED)){
	  re_ModingSmState = FASTENED_OR_NOT_OCCUPIED_PASSENGER;

	  /*SM Reset*/
	  re_UnfastenedAndOccupiedSmState = NO_CHIME_AND_CONTINUOUS_INDICATION_PASSENGER;
	  re_ChimeSmState = CHIME_TYPE1_PASSENGER;
	  re_TelltaleSmState = FLASHING_TELLTALE_PASSENGER;
  }
  else{
	  if(rub_PowerUpCounter <= TWENTY_FIVE_SECONDS)
	  	  re_UnfastenedAndOccupiedSmState = NO_CHIME_AND_CONTINUOUS_INDICATION_PASSENGER;
	  else
		  re_UnfastenedAndOccupiedSmState = BASIC_INDICATION_PASSENGER;
  }
}

/**************************************************************
 *  Name                 : passengerremsm_PassengerNoChimeAndcontinuousIndicationState
 *  Description          : Defines the state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_PassengerNoChimeAndcontinuousIndicationState(void){
  (rps_PassengerReminder->rs_Chime).rub_SoundTone = NO_CHIME_SOUND_TONE;		/* No Chime */
  (rps_PassengerReminder->rs_Chime).rub_Cadence = NO_CHIME_CADENCE;
  (rps_PassengerReminder->rs_Chime).rub_DutyCycle = NO_CHIME_DUTY_CYCLE;

  (rps_PassengerReminder->rs_Indication).rub_Indication = INDICATION_ON;		/* Continuous Indication */
  (rps_PassengerReminder->rs_Indication).rub_DutyCycle = INDICATION_CONTINUOUS_DC;
  (rps_PassengerReminder->rs_Indication).rub_Period = INDICATION_CONTINUOUS_T;

  if(rub_PowerUpCounter > TWENTY_FIVE_SECONDS)
    re_UnfastenedAndOccupiedSmState = BASIC_INDICATION_PASSENGER;
}

/**************************************************************
 *  Name                 : passengerremsm_PassengerBasicIndicationState
 *  Description          : Defines the Passenger Basic Indication state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_PassengerBasicIndicationState(void){
  if(rub_PowerUpCounter <= THIRTY_THREE_SECONDS)
 	  re_ChimeSmState = CHIME_TYPE1_PASSENGER;
  else
	  re_ChimeSmState = NO_CHIME_PASSENGER;
}

/**************************************************************
 *  Name                 :
 *  Description          : Defines the state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_PassengerChimeType1State(void){
  static T_UBYTE lub_PassengerChimeCounter = ZERO_SECONDS;

  lub_PassengerChimeCounter++;
  if(lub_PassengerChimeCounter >= SIX_SECONDS){
	  lub_PassengerChimeCounter = 0;
	  re_ChimeSmState = NO_CHIME_PASSENGER;
  }
  else{
    (rps_PassengerReminder->rs_Chime).rub_SoundTone = CHIME_SOUND_TONE;		/* Chime Type1 */
    (rps_PassengerReminder->rs_Chime).rub_Cadence = CHIME_CADENCE;
    (rps_PassengerReminder->rs_Chime).rub_DutyCycle = CHIME_DUTY_CYCLE;
  }
}

/**************************************************************
 *  Name                 : passengerremsm_PassengerNoChimeState
 *  Description          : Defines the Passenger No Chime state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_PassengerNoChimeState(void){
  (rps_PassengerReminder->rs_Chime).rub_SoundTone = NO_CHIME_SOUND_TONE;		/* Chime Type1 */
  (rps_PassengerReminder->rs_Chime).rub_Cadence = NO_CHIME_CADENCE;
  (rps_PassengerReminder->rs_Chime).rub_DutyCycle = NO_CHIME_DUTY_CYCLE;
}

/**************************************************************
 *  Name                 : passengerremsm_PassengerFlashingTelltaleState
 *  Description          : Defines the Passenger Flashing Telltale state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_PassengerFlashingTelltaleState(void){
  static T_UBYTE lub_PassengerTelltaleCounter = ZERO_SECONDS;

  lub_PassengerTelltaleCounter++;
  if(lub_PassengerTelltaleCounter >= TWENTY_SECONDS){
	  lub_PassengerTelltaleCounter = 0;
	  re_TelltaleSmState = CONTINUOUS_TELLTALE_PASSENGER;
  }
  else{
    (rps_PassengerReminder->rs_Indication).rub_Indication = INDICATION_ON;		/* Continuous Indication */
    (rps_PassengerReminder->rs_Indication).rub_DutyCycle = INDICATION_FLASHING_DC;
    (rps_PassengerReminder->rs_Indication).rub_Period = INDICATION_FLASHING_T;
  }
}

/**************************************************************
 *  Name                 : passengerremsm_PassengerContinuousTelltaleState
 *  Description          : Defines the Passenger Continuous Telltale state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_PassengerContinuousTelltaleState(void){
  static T_UBYTE lub_PassengerTelltaleTimeOutCounter = ZERO_SECONDS;

  lub_PassengerTelltaleTimeOutCounter++;
  if(lub_PassengerTelltaleTimeOutCounter >= THIRTY_THREE_SECONDS){
	  lub_PassengerTelltaleTimeOutCounter = 0;
	  re_TelltaleSmState = NO_INDICATION_TELLTALE_PASSENGER;
  }
  else{
    (rps_PassengerReminder->rs_Indication).rub_Indication = INDICATION_ON;		/* Continuous Indication */
    (rps_PassengerReminder->rs_Indication).rub_DutyCycle = INDICATION_CONTINUOUS_DC;
    (rps_PassengerReminder->rs_Indication).rub_Period = INDICATION_CONTINUOUS_T;
  }
}

/**************************************************************
 *  Name                 :
 *  Description          : Defines the state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_PassengerNoIndicationTelltaleState(void){
  (rps_PassengerReminder->rs_Indication).rub_Indication = INDICATION_OFF;		/* Continuous Indication */
  (rps_PassengerReminder->rs_Indication).rub_DutyCycle = NO_INDICATION_DUTY_CYCLE;
  (rps_PassengerReminder->rs_Indication).rub_Period = NO_INDICATION_PERIOD;
}

/* Exported functions */
/*============================================================================*/
/******************************************************************************/
/************************    STATE MACHINES   **********************************/
/******************************************************************************/
/**************************************************************
 *  Name                 : passengerremsm_ModingStateMachine
 *  Description          : State Machine for passenger moding
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_ModingStateMachine(void){
  switch(re_ModingSmState){
    case FASTENED_OR_NOT_OCCUPIED_PASSENGER:
      passengerremsm_PassengerFastenedOrNotOccupiedState();
      break;

    case UNFASTENED_AND_OCCUPIED_PASSENGER:
      passengerremsm_PassengerUnfastenedAndOccupiedState();
      break;

    default:
      break;
  }
}

/**************************************************************
 *  Name                 : passengerremsm_UnfastenedAndOccupiedStateMachine
 *  Description          : State Machine for passenger moding
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_UnfastenedAndOccupiedStateMachine(void){
  switch(re_UnfastenedAndOccupiedSmState){
    case NO_CHIME_AND_CONTINUOUS_INDICATION_PASSENGER:
      passengerremsm_PassengerNoChimeAndcontinuousIndicationState();
      break;

    case BASIC_INDICATION_PASSENGER:
      passengerremsm_PassengerBasicIndicationState();
      break;

    default:
      break;
  }
}

/**************************************************************
 *  Name                 : passengerremsm_ChimeStateMachine
 *  Description          : State Machine for passenger moding
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_ChimeStateMachine(void){
  switch(re_ChimeSmState){
    case CHIME_TYPE1_PASSENGER:
      passengerremsm_PassengerChimeType1State();
      break;

    case NO_CHIME_PASSENGER:
      passengerremsm_PassengerNoChimeState();
      break;

    default:
      break;
  }
}

/**************************************************************
 *  Name                 : passengerremsm_TelltaleMachine
 *  Description          : State Machine for passenger telltale
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_TelltaleMachine(void){
  switch(re_TelltaleSmState){
    case FLASHING_TELLTALE_PASSENGER:
      passengerremsm_PassengerFlashingTelltaleState();
      break;

    case CONTINUOUS_TELLTALE_PASSENGER:
      passengerremsm_PassengerContinuousTelltaleState();
      break;

    case NO_INDICATION_TELLTALE_PASSENGER:
      passengerremsm_PassengerNoIndicationTelltaleState();
      break;

    default:
      break;
  }
}

/* Notice: the file ends with a blank new line to avoid compiler warnings */
