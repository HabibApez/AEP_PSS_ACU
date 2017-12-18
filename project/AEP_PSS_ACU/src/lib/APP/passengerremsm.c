/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: passengerremsm.c $
 * $Revision: version 5 $
 * $Author: Habib Apez $
 * $Date: 2017-12-18 $
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
/* Habib Apez          |          2         |   Functions related to S_ChimeRequest */
/*                     |                    |   and S_Indication redefined    */
/* Habib Apez          |          3         |   State machines modified       */
/* Habib Apez          |          4         |   State machine reset when going*/
/*					   |					|   back to the Fastened or not   */
/*					   |					|   occupied state 			      */
/* Habib Apez          |          5         |   Modified for its use with     */
/*                     |                    |   remindercommon.c              */
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

/* Variables */
/*============================================================================*/

E_PassengerBasicReminderStateMachine re_ModingSmState = FASTENED_OR_NOT_OCCUPIED_PASSENG;
E_PassengerReminderStateMachine re_UnfastenedAndOccupiedSmState = IDLE_UNFASTENED_AND_OCUPPIED_PASSENG;
E_PassengerReminderChimeStateMachine re_ChimeSmState = IDLE_CHIME_PASSENG;
E_PassengerReminderTellTaleStateMachine re_TelltaleSmState = FLASHING_TELLTALE_PASSENG;

S_Reminder rs_PassengerReminder = {{INDICATION_ON_FALSE, NO_INDICATION_DC, NO_INDICATION_PERIOD}, CHIME_OFF};
S_Reminder *rps_PassengerReminder = &rs_PassengerReminder;


/* Private functions prototypes */
/*============================================================================*/
void passengerremsm_PassengerFastenedOrNotOccupiedState(void);
void passengerremsm_PassengerUnfastenedAndOccupiedState(void);
void passengerremsm_PassengerNoChimeAndContinuousIndicationState(void);
void passengerremsm_PassengerBasicIndicationState(void);
void passengerremsm_PassengerChimeType1State(void);
void passengerremsm_PassengerNoChimeState(void);
void passengerremsm_PassengerFlashingTelltaleState(void);
void passengerremsm_PassengerContinuousTelltaleState(void);
void passengerremsm_PassengerNoIndicationTelltaleState(void);
void passengerremsm_ConfigNoIndication(void);
void passengerremsm_ConfigContinuousIndication(void);
void passengerremsm_ConfigFlashingIndication(void);
void passengerremsm_ConfigNoChime(void);
void passengerremsm_ConfigType1Chime(void);
void passengerremsm_SetResetConfiguration(void);

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
	  re_ModingSmState = UNFASTENED_AND_OCCUPIED_PASSENG;
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
	  re_ModingSmState = FASTENED_OR_NOT_OCCUPIED_PASSENG;

	  passengerremsm_SetResetConfiguration();			/* SM Reset */
  }
  else{
	  passengerremsm_UnfastenedAndOccupiedStateMachine();
  }
}

/**************************************************************
 *  Name                 : passengerremsm_SetResetConfiguration
 *  Description          : Sets the Reset Configuration of the Basic Reminder State Machine
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_SetResetConfiguration(void){
  re_UnfastenedAndOccupiedSmState = IDLE_UNFASTENED_AND_OCUPPIED_PASSENG;
  re_ChimeSmState = IDLE_CHIME_PASSENG;
  re_TelltaleSmState = FLASHING_TELLTALE_PASSENG;

  passengerremsm_ConfigNoChime();
  passengerremsm_ConfigNoIndication();
}

/**************************************************************
 *  Name                 : passengerremsm_PassengerIdleUnfAndOccState
 *  Description          : Defines the Passenger Idle Unfastened and Occupied state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_PassengerIdleUnfAndOccState(void){
  if(rub_PowerUpCounter <= TWENTY_FIVE_SECONDS)
    re_UnfastenedAndOccupiedSmState = NO_CHIME_AND_CONTINUOUS_INDICATION_PASSENG;
  else
    re_UnfastenedAndOccupiedSmState = BASIC_INDICATION_PASSENG;
  passengerremsm_UnfastenedAndOccupiedStateMachine();
}

/**************************************************************
 *  Name                 : passengerremsm_PassengerNoChimeAndContinuousIndicationState
 *  Description          : Defines the Passenger No Chime And Continuous Indication state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_PassengerNoChimeAndContinuousIndicationState(void){
  passengerremsm_ConfigContinuousIndication();
  passengerremsm_ConfigNoChime();

  if(rub_PowerUpCounter > TWENTY_FIVE_SECONDS)
    re_UnfastenedAndOccupiedSmState = BASIC_INDICATION_PASSENG;
}

/**************************************************************
 *  Name                 : passengerremsm_ConfigNoChime
 *  Description          : Configures the chime to no chime
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_ConfigNoChime(void){
//  rps_Chime->rub_SoundTone = NO_CHIME_SOUND_TONE;
// rps_Chime->rub_Cadence = NO_CHIME_CADENCE;
//  rps_Chime->rub_Repetitions = NO_CHIME_REPETITIONS;
//  rps_Chime->rub_DutyCycle = NO_CHIME_DUTY_CYCLE;
  rps_PassengerReminder->rub_ChimeStatus = CHIME_OFF;
}

/**************************************************************
 *  Name                 : passengerremsm_ConfigType1Chime
 *  Description          : Configures the chime to Type1
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_ConfigType1Chime(void){
  rps_Chime->rub_SoundTone = CHIME_SOUND_TONE;
  rps_Chime->rub_Cadence = CHIME_CADENCE;
  rps_Chime->rub_Repetitions = CHIME_REPETITIONS;
  rps_Chime->rub_DutyCycle = CHIME_DUTY_CYCLE;
  rps_PassengerReminder->rub_ChimeStatus = CHIME_ON;
}

/**************************************************************
 *  Name                 : passengerremsm_ConfigNoIndication
 *  Description          : Configures the no indication
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_ConfigNoIndication(void){
  rps_PassengerReminder->rs_Indication.rub_IndicationOn = INDICATION_ON_FALSE;
  rps_PassengerReminder->rs_Indication.rub_DutyCycle = NO_INDICATION_DC;
  rps_PassengerReminder->rs_Indication.rub_Period = NO_INDICATION_PERIOD;
}

/**************************************************************
 *  Name                 : passengerremsm_ConfigContinuousIndication
 *  Description          : Configures the continuous indication
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_ConfigContinuousIndication(void){
  rps_PassengerReminder->rs_Indication.rub_IndicationOn = INDICATION_ON_TRUE;
  rps_PassengerReminder->rs_Indication.rub_DutyCycle = INDICATION_CONTINUOUS_DC;
  rps_PassengerReminder->rs_Indication.rub_Period = INDICATION_CONTINUOUS_PERIOD;
}

/**************************************************************
 *  Name                 : passengerremsm_ConfigFlashingIndication
 *  Description          : Configures the Flashing indication
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_ConfigFlashingIndication(void){
  rps_PassengerReminder->rs_Indication.rub_IndicationOn = INDICATION_ON_TRUE;
  rps_PassengerReminder->rs_Indication.rub_DutyCycle = INDICATION_FLASHING_DC;
  rps_PassengerReminder->rs_Indication.rub_Period = INDICATION_FLASHING_PERIOD;
}

/**************************************************************
 *  Name                 : passengerremsm_PassengerBasicIndicationState
 *  Description          : Defines the Passenger Basic Indication state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_PassengerBasicIndicationState(void){
  passengerremsm_ChimeStateMachine();
  passengerremsm_TelltaleMachine();
}

/**************************************************************
 *  Name                 : passengerremsm_PassengerIdleChimeState
 *  Description          : Defines the Passenger Idle Chime state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_PassengerIdleChimeState(void){
  if(rub_PowerUpCounter <= THIRTY_THREE_SECONDS)
 	  re_ChimeSmState = CHIME_TYPE1_PASSENG;
  else
	  re_ChimeSmState = NO_CHIME_PASSENG;
  passengerremsm_ChimeStateMachine();
}

/**************************************************************
 *  Name                 : passengerremsm_PassengerChimeType1Stat
 *  Description          : Defines the Chime Type1 state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_PassengerChimeType1State(void){
  static T_UBYTE lub_PassengerChimeCounter = ZERO_SECONDS;

  lub_PassengerChimeCounter++;
  if(lub_PassengerChimeCounter >= SIX_SECONDS){
	  lub_PassengerChimeCounter = 0;
	  re_ChimeSmState = NO_CHIME_PASSENG;
  }
  else{
	  passengerremsm_ConfigType1Chime();
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
  passengerremsm_ConfigNoChime();
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
	  re_TelltaleSmState = CONTINUOUS_TELLTALE_PASSENG;
  }
  else{
	  passengerremsm_ConfigFlashingIndication();
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
  if(lub_PassengerTelltaleTimeOutCounter >= THIRTY_FIVE_SECONDS){
	  lub_PassengerTelltaleTimeOutCounter = 0;
	  re_TelltaleSmState = NO_INDICATION_TELLTALE_PASSENG;
  }
  else{
	  passengerremsm_ConfigContinuousIndication();
  }
}

/**************************************************************
 *  Name                 : passengerremsm_PassengerNoIndicationTelltaleState
 *  Description          : Defines the Passenger No Indication Telltale state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void passengerremsm_PassengerNoIndicationTelltaleState(void){
  passengerremsm_ConfigNoIndication();
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
    case FASTENED_OR_NOT_OCCUPIED_PASSENG:
      passengerremsm_PassengerFastenedOrNotOccupiedState();
      break;

    case UNFASTENED_AND_OCCUPIED_PASSENG:
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
    case IDLE_UNFASTENED_AND_OCUPPIED_PASSENG:
    	passengerremsm_PassengerIdleUnfAndOccState();
    	break;

    case NO_CHIME_AND_CONTINUOUS_INDICATION_PASSENG:
      passengerremsm_PassengerNoChimeAndContinuousIndicationState();
      break;

    case BASIC_INDICATION_PASSENG:
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
    case IDLE_CHIME_PASSENG:
    	passengerremsm_PassengerIdleChimeState();
    break;

    case CHIME_TYPE1_PASSENG:
      passengerremsm_PassengerChimeType1State();
      break;

    case NO_CHIME_PASSENG:
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
    case FLASHING_TELLTALE_PASSENG:
      passengerremsm_PassengerFlashingTelltaleState();
      break;

    case CONTINUOUS_TELLTALE_PASSENG:
      passengerremsm_PassengerContinuousTelltaleState();
      break;

    case NO_INDICATION_TELLTALE_PASSENG:
      passengerremsm_PassengerNoIndicationTelltaleState();
      break;

    default:
      break;
  }
}

/**************************************************************
 *  Name                 : passengerremsm_PassengerGetIndicatorStatus
 *  Description          : Gets the Indicator Status
 *  Parameters           : [T_UBYTE]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE passengerremsm_PassengerGetIndicatorStatus(void){
  return (rps_PassengerReminder->rs_Indication).rub_IndicationOn;
}


/**************************************************************
 *  Name                 : passengerremsm_PassengerGetIndicationDutyCycle
 *  Description          : Gets the Indication DutyCycle
 *  Parameters           : [T_UBYTE]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE passengerremsm_PassengerGetIndicationDutyCycle(void){
  return (rps_PassengerReminder->rs_Indication).rub_DutyCycle;
}

/**************************************************************
 *  Name                 : passengerremsm_PassengerGetIndicationPeriod
 *  Description          : Gets the Indication Period
 *  Parameters           : [T_UBYTE]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE passengerremsm_PassengerGetIndicationPeriod(void){
  return (rps_PassengerReminder->rs_Indication).rub_Period;
}

/**************************************************************
 *  Name                 : passengerremsm_GetSoundTone
 *  Description          : Gets the Sound Tone
 *  Parameters           : [T_UBYTE]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE passengerremsm_GetSoundTone(void){
  return rps_Chime->rub_SoundTone;
}

/**************************************************************
 *  Name                 : passengerremsm_GetSoundCadence
 *  Description          : Gets the Sound Cadence
 *  Parameters           : [T_UBYTE]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE passengerremsm_GetSoundCadence(void){
  return rps_Chime->rub_Cadence;
}

/**************************************************************
 *  Name                 : passengerremsm_GetSoundDutyCycle
 *  Description          : Gets the Sound Duty Cycle
 *  Parameters           : [T_UBYTE]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE passengerremsm_GetSoundDutyCycle(void){
  return rps_Chime->rub_DutyCycle;
}

/**************************************************************
 *  Name                 : passengerremsm_GetSoundRepetitions
 *  Description          : Gets the Sound Repetitions
 *  Parameters           : [T_UBYTE]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE passengerremsm_GetSoundRepetitions(void){
  return rps_Chime->rub_Repetitions;
}

/**************************************************************
 *  Name                 : passengerremsm_GetChimeStatus
 *  Description          : Gets the Chime Status
 *  Parameters           : [T_UBYTE]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE passengerremsm_PassengerGetChimeStatus(void){
  return rps_PassengerReminder->rub_ChimeStatus;
}

/* Notice: the file ends with a blank new line to avoid compiler warnings */
