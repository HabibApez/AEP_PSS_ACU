/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: interrupts.h $
 * $Revision: version 1$
 * $Author: Habib Apez $
 * $Date: 2017-10-23 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \interrupts.h
    Header file for interrupts module. Located at HAL.
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
/*  Author             |        Version     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/* Habib Apez          |          1         |   Initial version               */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: interrupts.h  $
  ============================================================================*/
#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H

/* Includes */
/*============================================================================*/
#include "C:\My Documents\Continental\IAR\Devs\lib\MCAL\nvic.c"
#include "C:\My Documents\Continental\IAR\Devs\lib\MCAL\systick.c"

/* Constants and types */
/*============================================================================*/

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void interrupts_InitPortsIRQs(void);
T_UBYTE interrupts_GetLeftButtonIntFlag(void);
T_UBYTE interrupts_GetRightButtonIntFlag(void);
void interrupts_ClearLeftButtonIntFlag(void);
void interrupts_ClearRightButtonIntFlag(void);
void interrupts_InitPortsIRQs(void);
void interrupts_ConfigSysTickIRQ(T_ULONG lul_Value);
void interrupts_EnableSysTickIRQ(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
