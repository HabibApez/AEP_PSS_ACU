/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: driverremsm.c $
 * $Revision: version 2 $
 * $Author: Habib Apez $
 * $Date: 2017-12-17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \driverremsm.c
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
/* Habib Apez          |          1         |   Initial version based on      */
/* 					   | 					|  	passengerremsm.c              */
/* Habib Apez          |          2         |   Modified for its use with     */
/*                     |                    |   remindercommon.c              */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: driverremsm.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "APP\driverremsm.h"
#include "APP\sensorsm.h"
#include "HAL\leds.h"

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/

E_DriverBasicReminderStateMachine re_DriverModingSmState = FASTENED_DRIVER;
E_DriverReminderStateMachine re_DriverUnfastenedSmState = BASIC_INDICATION_DRIVER;
E_DriverReminderChimeStateMachine re_DriverChimeSmState = IDLE_CHIME_DRIVER;
E_DriverReminderTellTaleStateMachine re_DriverTelltaleSmState = FLASHING_TELLTALE_DRIVER;

S_Reminder rs_DriverReminder = {{INDICATION_ON_FALSE, NO_INDICATION_DC, NO_INDICATION_PERIOD}, CHIME_OFF};
S_Reminder *rps_DriverReminder = &rs_DriverReminder;

/* Private functions prototypes */
/*============================================================================*/
void driverremsm_DriverFastenedState(void);
void driverremsm_DriverUnfastenedState(void);
void driverremsm_DriverNoChimeAndContinuousIndicationState(void);
void driverremsm_DriverBasicIndicationState(void);
void driverremsm_DriverChimeType1State(void);
void driverremsm_DriverNoChimeState(void);
void driverremsm_DriverFlashingTelltaleState(void);
void driverremsm_DriverContinuousTelltaleState(void);
void driverremsm_DriverNoIndicationTelltaleState(void);
void driverremsm_ConfigNoIndication(void);
void driverremsm_ConfigContinuousIndication(void);
void driverremsm_ConfigFlashingIndication(void);
void driverremsm_ConfigNoChime(void);
void driverremsm_ConfigType1Chime(void);
void driverremsm_SetResetConfiguration(void);

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/******************************************************************************/
/*******************    STATES DEFINITIONS   **********************************/
/******************************************************************************/

/**************************************************************
 *  Name                 : driverremsm_DriverFastenedState
 *  Description          : Defines the Passenger Fastened Or Not Occupied state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_DriverFastenedState(void){
  if(rps_DriverSeatBeltSensor-> re_SensorValidStatus == SBS_UNBUCKLED)
	re_DriverModingSmState = UNFASTENED_DRIVER;
  else{
	  // Do nothing
  }

}

/**************************************************************
 *  Name                 : driverremsm_DriverUnfastenedState
 *  Description          : Defines the Passenger Unfastened And Occupied state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_DriverUnfastenedState(void){
  if(rps_DriverSeatBeltSensor-> re_SensorValidStatus == SBS_BUCKLED){
	  re_DriverModingSmState = FASTENED_DRIVER;
	  driverremsm_SetResetConfiguration();			/* SM Reset */
  }
  else{
	  driverremsm_UnfastenedStateMachine();
  }
}

/**************************************************************
 *  Name                 : driverremsm_SetResetConfiguration
 *  Description          : Sets the Reset Configuration of the Basic Reminder State Machine
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_SetResetConfiguration(void){
  re_DriverUnfastenedSmState = BASIC_INDICATION_DRIVER;
  re_DriverChimeSmState = IDLE_CHIME_DRIVER;
  re_DriverTelltaleSmState = FLASHING_TELLTALE_DRIVER;

  driverremsm_ConfigNoChime();
  driverremsm_ConfigNoIndication();
}

/**************************************************************
 *  Name                 : driverremsm_DriverNoChimeAndContinuousIndicationState
 *  Description          : Defines the Passenger No Chime And Continuous Indication state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_DriverNoChimeAndContinuousIndicationState(void){
  driverremsm_ConfigContinuousIndication();
  driverremsm_ConfigNoChime();

  if(rub_PowerUpCounter > TWENTY_FIVE_SECONDS)
    re_DriverUnfastenedSmState = BASIC_INDICATION_DRIVER;
}

/**************************************************************
 *  Name                 : driverremsm_ConfigNoChime
 *  Description          : Configures the chime to no chime
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_ConfigNoChime(void){
//  rps_Chime->rub_SoundTone = NO_CHIME_SOUND_TONE;
//  rps_Chime->rub_Cadence = NO_CHIME_CADENCE;
//  rps_Chime->rub_Repetitions = NO_CHIME_REPETITIONS;
//  rps_Chime->rub_DutyCycle = NO_CHIME_DUTY_CYCLE;
  rps_DriverReminder->rub_ChimeStatus = CHIME_OFF;
}

/**************************************************************
 *  Name                 : driverremsm_ConfigType1Chime
 *  Description          : Configures the chime to Type1
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_ConfigType1Chime(void){
  rps_Chime->rub_SoundTone = CHIME_SOUND_TONE;
  rps_Chime->rub_Cadence = CHIME_CADENCE;
  rps_Chime->rub_Repetitions = CHIME_REPETITIONS;
  rps_Chime->rub_DutyCycle = CHIME_DUTY_CYCLE;
  rps_DriverReminder->rub_ChimeStatus = CHIME_ON;
}

/**************************************************************
 *  Name                 : driverremsm_ConfigNoIndication
 *  Description          : Configures the no indication
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_ConfigNoIndication(void){
  rps_DriverReminder->rs_Indication.rub_IndicationOn = INDICATION_ON_FALSE;
  rps_DriverReminder->rs_Indication.rub_DutyCycle = NO_INDICATION_DC;
  rps_DriverReminder->rs_Indication.rub_Period = NO_INDICATION_PERIOD;
}

/**************************************************************
 *  Name                 : driverremsm_ConfigContinuousIndication
 *  Description          : Configures the continuous indication
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_ConfigContinuousIndication(void){
  rps_DriverReminder->rs_Indication.rub_IndicationOn = INDICATION_ON_TRUE;
  rps_DriverReminder->rs_Indication.rub_DutyCycle = INDICATION_CONTINUOUS_DC;
  rps_DriverReminder->rs_Indication.rub_Period = INDICATION_CONTINUOUS_PERIOD;
}

/**************************************************************
 *  Name                 : driverremsm_ConfigFlashingIndication
 *  Description          : Configures the Flashing indication
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_ConfigFlashingIndication(void){
  rps_DriverReminder->rs_Indication.rub_IndicationOn = INDICATION_ON_TRUE;
  rps_DriverReminder->rs_Indication.rub_DutyCycle = INDICATION_FLASHING_DC;
  rps_DriverReminder->rs_Indication.rub_Period = INDICATION_FLASHING_PERIOD;
}

/**************************************************************
 *  Name                 : driverremsm_DriverBasicIndicationState
 *  Description          : Defines the Passenger Basic Indication state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_DriverBasicIndicationState(void){
  driverremsm_ChimeStateMachine();
  driverremsm_TelltaleMachine();
}

/**************************************************************
 *  Name                 : driverremsm_DriverIdleChimeState
 *  Description          : Defines the Passenger Idle Chime state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_DriverIdleChimeState(void){
  if(rub_PowerUpCounter <= EIGHT_SECONDS)
 	  re_DriverChimeSmState = CHIME_TYPE1_DRIVER;
  else{
		re_DriverChimeSmState = NO_CHIME_DRIVER;
  }
  driverremsm_ChimeStateMachine();
}

/**************************************************************
 *  Name                 : driverremsm_DriverChimeType1Stat
 *  Description          : Defines the Chime Type1 state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_DriverChimeType1State(void){
  static T_UBYTE lub_DriverChimeCounter = ZERO_SECONDS;

  lub_DriverChimeCounter++;
  if(lub_DriverChimeCounter >= SIX_SECONDS){
	  lub_DriverChimeCounter = 0;
	  re_DriverChimeSmState = NO_CHIME_DRIVER;
  }
  else{
	  driverremsm_ConfigType1Chime();
  }
}

/**************************************************************
 *  Name                 : driverremsm_DriverNoChimeState
 *  Description          : Defines the Passenger No Chime state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_DriverNoChimeState(void){
  driverremsm_ConfigNoChime();
}

/**************************************************************
 *  Name                 : driverremsm_DriverFlashingTelltaleState
 *  Description          : Defines the Passenger Flashing Telltale state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_DriverFlashingTelltaleState(void){
  static T_UBYTE lub_DriverTelltaleCounter = ZERO_SECONDS;

  lub_DriverTelltaleCounter++;
  if(lub_DriverTelltaleCounter >= TWENTY_SECONDS){
	  lub_DriverTelltaleCounter = 0;
	  re_DriverTelltaleSmState = CONTINUOUS_TELLTALE_DRIVER;
  }
  else{
	  driverremsm_ConfigFlashingIndication();
  }
}

/**************************************************************
 *  Name                 : driverremsm_DriverContinuousTelltaleState
 *  Description          : Defines the Passenger Continuous Telltale state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_DriverContinuousTelltaleState(void){
  static T_UBYTE lub_DriverTelltaleTimeOutCounter = ZERO_SECONDS;

  lub_DriverTelltaleTimeOutCounter++;
  if(lub_DriverTelltaleTimeOutCounter >= THIRTY_FIVE_SECONDS){
	  lub_DriverTelltaleTimeOutCounter = 0;
	  re_DriverTelltaleSmState = NO_INDICATION_TELLTALE_DRIVER;
  }
  else{
	  driverremsm_ConfigContinuousIndication();
  }
}

/**************************************************************
 *  Name                 : driverremsm_DriverNoIndicationTelltaleState
 *  Description          : Defines the Passenger No Indication Telltale state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_DriverNoIndicationTelltaleState(void){
  driverremsm_ConfigNoIndication();
}

/* Exported functions */
/*============================================================================*/
/******************************************************************************/
/************************    STATE MACHINES   **********************************/
/******************************************************************************/
/**************************************************************
 *  Name                 : driverremsm_ModingStateMachine
 *  Description          : State Machine for passenger moding
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_ModingStateMachine(void){
  switch(re_DriverModingSmState){
    case FASTENED_DRIVER:
      driverremsm_DriverFastenedState();
      break;

    case UNFASTENED_DRIVER:
      driverremsm_DriverUnfastenedState();
      break;

    default:
      break;
  }
}

/**************************************************************
 *  Name                 : driverremsm_UnfastenedStateMachine
 *  Description          : State Machine for passenger moding
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_UnfastenedStateMachine(void){
  switch(re_DriverUnfastenedSmState){

  case BASIC_INDICATION_DRIVER:
      driverremsm_DriverBasicIndicationState();
      break;

    default:
      break;
  }
}

/**************************************************************
 *  Name                 : driverremsm_ChimeStateMachine
 *  Description          : State Machine for passenger moding
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_ChimeStateMachine(void){
  switch(re_DriverChimeSmState){
    case IDLE_CHIME_DRIVER:
    	driverremsm_DriverIdleChimeState();
    break;

    case CHIME_TYPE1_DRIVER:
      driverremsm_DriverChimeType1State();
      break;

    case NO_CHIME_DRIVER:
      driverremsm_DriverNoChimeState();
      break;

    default:
      break;
  }
}

/**************************************************************
 *  Name                 : driverremsm_TelltaleMachine
 *  Description          : State Machine for passenger telltale
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void driverremsm_TelltaleMachine(void){
  switch(re_DriverTelltaleSmState){
    case FLASHING_TELLTALE_DRIVER:
      driverremsm_DriverFlashingTelltaleState();
      break;

    case CONTINUOUS_TELLTALE_DRIVER:
      driverremsm_DriverContinuousTelltaleState();
      break;

    case NO_INDICATION_TELLTALE_DRIVER:
      driverremsm_DriverNoIndicationTelltaleState();
      break;

    default:
      break;
  }
}

/**************************************************************
 *  Name                 : driverremsm_DriverGetIndicatorStatus
 *  Description          : Gets the Indicator Status
 *  Parameters           : [T_UBYTE]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE driverremsm_DriverGetIndicatorStatus(void){
  return (rps_DriverReminder->rs_Indication).rub_IndicationOn;
}


/**************************************************************
 *  Name                 : driverremsm_DriverGetIndicationDutyCycle
 *  Description          : Gets the Indication DutyCycle
 *  Parameters           : [T_UBYTE]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE driverremsm_DriverGetIndicationDutyCycle(void){
  return (rps_DriverReminder->rs_Indication).rub_DutyCycle;
}

/**************************************************************
 *  Name                 : driverremsm_DriverGetIndicationPeriod
 *  Description          : Gets the Indication Period
 *  Parameters           : [T_UBYTE]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE driverremsm_DriverGetIndicationPeriod(void){
  return (rps_DriverReminder->rs_Indication).rub_Period;
}

/**************************************************************
 *  Name                 : driverremsm_GetChimeStatus
 *  Description          : Gets the Chime Status
 *  Parameters           : [T_UBYTE]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE driverremsm_DriverGetChimeStatus(void){
  return rps_DriverReminder->rub_ChimeStatus;
}

/* Notice: the file ends with a blank new line to avoid compiler warnings */
