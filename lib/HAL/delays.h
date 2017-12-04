/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: delays.h $
 * $Revision: version 2 $
 * $Author: Habib Apez $
 * $Date: 2017-11-16 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \delays.h
    Header file for delays module. Located at HAL.
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
/* Habib Apez          |          2         |   More delays added             */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: delays.h  $
  ============================================================================*/
#ifndef __DELAYS_H
#define __DELAYS_H

/* Includes */
/*============================================================================*/
#include "C:\My Documents\Continental\IAR\Devs\lib\MCAL\lpit.c"

/* Constants and types */
/*============================================================================*/

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void delays_InitTimer(void);
void delays_Wait500us(void);
void delays_Wait1ms(void);
void delays_Wait10ms(void);
void delays_Wait40ms(void);
void delays_Wait50ms(void);
void delays_Wait400ms(void);
void delays_Wait490ms(void);
void delays_Wait5s(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
