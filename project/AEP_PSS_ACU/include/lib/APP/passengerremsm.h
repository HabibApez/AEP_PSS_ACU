/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: passengerremsm.h $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-12-14  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \sensorsm.h
    Header file for state machine sensors module. Located at HAL.
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
 * $Log: passengerremsm.h  $
  ============================================================================*/
#ifndef __PASSENGERRMSM_H
#define __PASSENGERRMSM_H

/* Includes */
/*============================================================================*/
#include "HAL\sensors.h"

/* Constants and types */
/*============================================================================*/
#define CHIME_SOUND_TONE 			0x01	/* Sound Tone Active */
#define CHIME_CADENCE  				0x0C	/* 1200ms Cadence */
#define CHIME_DUTY_CYCLE			0x64	/* 100% Duty Cycle */
#define NO_CHIME_SOUND_TONE 		0x00	/* Sound Tone Inactive */
#define NO_CHIME_CADENCE  			0x00	/* No cadence */
#define NO_CHIME_DUTY_CYCLE 		0x00	/* 0% Duty Cycle */

#define INDICATION_ON      			0x01	/* Indication Active */
#define INDICATION_CONTINUOUS_DC	0x64	/* 50% Duty Cycle */
#define INDICATION_FLASHING_DC 		0x32	/* 50% Duty Cycle */
#define INDICATION_CONTINUOUS_T		0xFF	/* Continuous */
#define INDICATION_FLASHING_T  		0x01	/* 1Hz */
#define INDICATION_OFF  	       	0x00	/* Indication Inactive */
#define NO_INDICATION_DUTY_CYCLE 	0x00	/* 0% Duty Cycle */
#define NO_INDICATION_PERIOD  		0x00	/* 0Hz */

typedef enum{
  FASTENED_OR_NOT_OCCUPIED_PASSENGER,
  UNFASTENED_AND_OCCUPIED_PASSENGER,
}E_PassengerBasicReminderStateMachine;

typedef enum{
  NO_CHIME_AND_CONTINUOUS_INDICATION_PASSENGER,
  BASIC_INDICATION_PASSENGER,
}E_PassengerReminderStateMachine;

typedef enum{
  CHIME_TYPE1_PASSENGER,
  NO_CHIME_PASSENGER,
}E_PassengerReminderChimeStateMachine;

typedef enum{
  FLASHING_TELLTALE_PASSENGER,
  CONTINUOUS_TELLTALE_PASSENGER,
  NO_INDICATION_TELLTALE_PASSENGER
}E_PassengerReminderTellTaleStateMachine;

typedef struct{
  T_UBYTE rub_Indication;
  T_UBYTE rub_DutyCycle;
  T_UBYTE rub_Period;
} S_Indication;

typedef struct{
  T_UBYTE rub_SoundTone;
  T_UBYTE rub_Cadence;
  T_UBYTE rub_DutyCycle;
} S_Chime;

typedef struct{
  S_Indication rs_Indication;
  S_Chime rs_Chime;
} S_Reminder;


/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void passengerremsm_ModingStateMachine(void);
void passengerremsm_UnfastenedAndOccupiedStateMachine(void);
void passengerremsm_ChimeStateMachine(void);
void passengerremsm_TelltaleMachine(void);


#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
