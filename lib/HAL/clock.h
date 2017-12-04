/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: clock.h $
 * $Revision: version 3 $
 * $Author: Habib Apez $
 * $Date: 2017-11-08 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \clock
    Header file for clock module. Located at HAL.
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
/* Habib Apez          |          2         |   Naming conventions            */
/*                     |                    |   and MISRA checked             */
/* Habib Apez          |          3         |   Function descriptions added   */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: clock.h  $
  ============================================================================*/
#ifndef __CLOCK_H
#define __CLOCK_H

/* Includes */
/*============================================================================*/
#include "C:\My Documents\Continental\IAR\Devs\lib\MCAL\scg.c"

/* Constants and types */
/*============================================================================*/

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void clock_InitClock(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
