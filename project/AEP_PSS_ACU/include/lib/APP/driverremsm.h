/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: driverremsm.h $
 * $Revision: version 2 $
 * $Author: Habib Apez $
 * $Date: 2017-12-17  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \driverremsm.h
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
/* Habib Apez          |          1         |   Initial version based on      */
/* 					   | 					|  	passengerremsm.h              */
/* Habib Apez          |          2         |   Modified for its use with     */
/*                     |                    |   remindercommon.c              */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: driverremsm.h  $
  ============================================================================*/
#ifndef __DRIVERREMSM_H
#define __DRIVERREMSM_H

/* Includes */
/*============================================================================*/
#include "HAL\sensors.h"
#include "APP\remindercommon.h"

/* Constants and types */
/*============================================================================*/
typedef enum{
  FASTENED_DRIVER,
  UNFASTENED_DRIVER,
}E_DriverBasicReminderStateMachine;

typedef enum{
  BASIC_INDICATION_DRIVER,
}E_DriverReminderStateMachine;

typedef enum{
  IDLE_CHIME_DRIVER,
  CHIME_TYPE1_DRIVER,
  NO_CHIME_DRIVER,
}E_DriverReminderChimeStateMachine;

typedef enum{
  FLASHING_TELLTALE_DRIVER,
  CONTINUOUS_TELLTALE_DRIVER,
  NO_INDICATION_TELLTALE_DRIVER
}E_DriverReminderTellTaleStateMachine;

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void driverremsm_ModingStateMachine(void);
void driverremsm_UnfastenedStateMachine(void);
void driverremsm_ChimeStateMachine(void);
void driverremsm_TelltaleMachine(void);

T_UBYTE driverremsm_DriverGetIndicatorStatus(void);
T_UBYTE driverremsm_DriverGetIndicationDutyCycle(void);
T_UBYTE driverremsm_DriverGetIndicationPeriod(void);
T_UBYTE driverremsm_DriverGetChimeStatus(void);
#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
