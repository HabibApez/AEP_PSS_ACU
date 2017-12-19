/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: passengerremsm.h $
 * $Revision: version 2 $
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
/* Habib Apez          |          2         |   Modified for its use with     */
/*                     |                    |   remindercommon.c              */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: passengerremsm.h  $
  ============================================================================*/
#ifndef __PASSENGRRMSM_H
#define __PASSENGRRMSM_H

/* Includes */
/*============================================================================*/
#include "HAL\sensors.h"
#include "APP\remindercommon.h"

/* Constants and types */
/*============================================================================*/
typedef enum{
  FASTENED_OR_NOT_OCCUPIED_PASSENG,
  UNFASTENED_AND_OCCUPIED_PASSENG,
}E_PassengerBasicReminderStateMachine;

typedef enum{
  IDLE_UNFASTENED_AND_OCUPPIED_PASSENG,
  NO_CHIME_AND_CONTINUOUS_INDICATION_PASSENG,
  BASIC_INDICATION_PASSENG,
}E_PassengerReminderStateMachine;

typedef enum{
  IDLE_CHIME_PASSENG,
  CHIME_TYPE1_PASSENG,
  NO_CHIME_PASSENG,
}E_PassengerReminderChimeStateMachine;

typedef enum{
  FLASHING_TELLTALE_PASSENG,
  CONTINUOUS_TELLTALE_PASSENG,
  NO_INDICATION_TELLTALE_PASSENG
}E_PassengerReminderTellTaleStateMachine;

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
T_UBYTE passengerremsm_PassengerGetChimeStatus(void);

void passengerremsm_SetResetConfiguration(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
