/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: remindercommon.h $
 * $Revision: version 2 $
 * $Author: Habib Apez $
 * $Date: 2017-12-17  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \remindercommon.h
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
/* Habib Apez          |          2         |   Get functions added           */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: remindercommon.h  $
  ============================================================================*/
#ifndef __REMINDERCOMMON_H
#define __REMINDERCOMMON_H

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

#define ZERO		 			0
#define ZERO_SECONDS 			0
#define SIX_SECONDS 			6
#define EIGHT_SECONDS 			8
#define TWENTY_SECONDS 			20
#define TWENTY_FIVE_SECONDS 	25
#define THIRTY_THREE_SECONDS 	33
#define THIRTY_FIVE_SECONDS 	35

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
T_UBYTE rub_PowerUpCounter = ZERO;

S_ChimeRequest rs_Chime = {NO_CHIME_SOUND_TONE, NO_CHIME_CADENCE, NO_CHIME_REPETITIONS, NO_CHIME_DUTY_CYCLE};
S_ChimeRequest *rps_Chime = &rs_Chime;

/* Exported functions prototypes */
/*============================================================================*/

T_UBYTE remindercommon_GetSoundTone(void);
T_UBYTE remindercommon_GetSoundCadence(void);
T_UBYTE remindercommon_GetSoundRepetitions(void);
T_UBYTE remindercommon_GetSoundDutyCycle(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
