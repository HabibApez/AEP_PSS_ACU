/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: remindersm.h $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-12-18  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \remindersm.h
    Header file for state machine of the reminder. Located at HAL.
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
 * $Log: remindersm.h  $
  ============================================================================*/
#ifndef __REMINDERSM_H
#define __REMINDERSM_H

/* Includes */
/*============================================================================*/
#include "APP\driverremsm.h"
#include "APP\passengerremsm.h"

/* Constants and types */
/*============================================================================*/

typedef enum{
  ECU_OFF_MODE,
  ECU_RUN_MODE,
}E_ReminderStateMachine;

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void remindersm_ReminderStateMachine(void);
void remindersm_FullFunctionalState(void);
void remindersm_NoFunctionalState(void);

void remindersm_RunDriverAndPassengerReminderSM(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
