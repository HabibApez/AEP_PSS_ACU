/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: passengerremsm.h $
 * $Revision: version 3 $
 * $Author: Habib Apez $
 * $Date: 2017-12-17  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \passengerremsm.h
    Header file for state machine of the passenger reminder. Located at HAL.
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
/* Habib Apez          |          2         |   Defines changed, S_ChimeRequest */
/*                     |                    |   and S_Indication redefined    */
/* Habib Apez          |          3         |   Get functions added           */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: passengerremsm.h  $
  ============================================================================*/
#ifndef __PASSENGERRMSM_H
#define __PASSENGERRMSM_H

/* Includes */
/*============================================================================*/
#include "HAL\sensors.h"

/* Constants and types */
/*============================================================================*/
#define INDICATION_ON_TRUE  			0x01	/* Indication On "True" */
#define INDICATION_CONTINUOUS_DC		0x64	/* 100% Duty Cycle */
#define INDICATION_FLASHING_DC 			0x32	/* 50% Duty Cycle */
#define INDICATION_CONTINUOUS_PERIOD	0xFF	/* Continuous, No Period*/
#define INDICATION_FLASHING_PERIOD  	0x01	/* 1Hz */
#define INDICATION_ON_FALSE	       		0x00	/* Indication on "False" */
#define NO_INDICATION_DC				0x00	/* 0% Duty Cycle */
#define NO_INDICATION_PERIOD  			0x00	/* 0Hz */

#define CHIME_ON 				0x01	/* Chime Active */
#define CHIME_OFF  				0x00	/* Chime Inactive */

#define CHIME_SOUND_TONE 			0x4B	/* 70Hz */
#define CHIME_CADENCE  				0x78	/* 1200ms Cadence */
#define CHIME_REPETITIONS  			0xFF	/* Multiple repetitions */
#define CHIME_DUTY_CYCLE			0x64	/* 100% Duty Cycle */
#define NO_CHIME_SOUND_TONE 		0x00	/* 0HZ */
#define NO_CHIME_CADENCE  			0x00	/* No cadence */
#define NO_CHIME_REPETITIONS  		0x00	/* No repetitions */
#define NO_CHIME_DUTY_CYCLE 		0x00	/* 0% Duty Cycle */

typedef enum{
  FASTENED_OR_NOT_OCCUPIED_PASSENGER,
  UNFASTENED_AND_OCCUPIED_PASSENGER,
}E_PassengerBasicReminderStateMachine;

typedef enum{
  IDLE_UNFASTENED_AND_OCUPPIED_PASSENGER,
  NO_CHIME_AND_CONTINUOUS_INDICATION_PASSENGER,
  BASIC_INDICATION_PASSENGER,
}E_PassengerReminderStateMachine;

typedef enum{
  IDLE_CHIME_PASSENGER,
  CHIME_TYPE1_PASSENGER,
  NO_CHIME_PASSENGER,
}E_PassengerReminderChimeStateMachine;

typedef enum{
  FLASHING_TELLTALE_PASSENGER,
  CONTINUOUS_TELLTALE_PASSENGER,
  NO_INDICATION_TELLTALE_PASSENGER
}E_PassengerReminderTellTaleStateMachine;

typedef struct{
  T_UBYTE rub_IndicationOn;
  T_UBYTE rub_DutyCycle;
  T_UBYTE rub_Period;
} S_Indication;

typedef struct{
  T_UBYTE rub_SoundTone;
  T_UBYTE rub_Cadence;
  T_UBYTE rub_Repetitions;
  T_UBYTE rub_DutyCycle;
} S_ChimeRequest;

typedef struct{
  S_Indication rs_Indication;
  T_UBYTE rub_ChimeStatus;
} S_Reminder;


/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void passengerremsm_ModingStateMachine(void);
void passengerremsm_UnfastenedAndOccupiedStateMachine(void);
void passengerremsm_ChimeStateMachine(void);
void passengerremsm_TelltaleMachine(void);

T_UBYTE passengerremsm_PassengerGetIndicatorStatus(void);
T_UBYTE passengerremsm_PassengerGetIndicationDutyCycle(void);
T_UBYTE passengerremsm_PassengerGetIndicationPeriod(void);

T_UBYTE passengerremsm_GetSoundTone(void);
T_UBYTE passengerremsm_GetSoundCadence(void);
T_UBYTE passengerremsm_GetSoundRepetitions(void);
T_UBYTE passengerremsm_GetSoundDutyCycle(void);
T_UBYTE passengerremsm_PassengerGetChimeStatus(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
