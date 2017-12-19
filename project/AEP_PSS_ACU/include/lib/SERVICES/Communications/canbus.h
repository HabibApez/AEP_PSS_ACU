/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: canbus.h $
 * $Revision: version 2 $
 * $Author: Habib Apez $
 * $Date: 2017-12-18  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \canbus.h
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
/* Habib Apez          |          2         |   Engine Status function added  *//*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: canbus.h  $
  ============================================================================*/
#ifndef __CANBUS_H
#define __CANBUS_H

/* Includes */
/*============================================================================*/
#include "Common\Std_Types.h"

/* Constants and types */
/*============================================================================*/
#define POWER_UP_CONTER_RESET	0


/* Exported Variables */
/*============================================================================*/
T_UBYTE rub_PowerUpCounter;

/* Exported functions prototypes */
/*============================================================================*/
void canbus_SendCANMessages(void);
void canbus_ReadEngRPMMessage(void);
T_UBYTE canbus_GetEngStatus(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
