/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: ACU_StateMachine.h $
 * $Revision: version 1 $
 * $Author: Antonio Vazquez $
 * $Date: 2017-12-09 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \ACU_StateMachine
    Header file for ACU_StateMachine. Located at APP.
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
/* Antonio Vazquez    |          1         |   Initial version               */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: ACU_StateMachine.h  $
  ============================================================================*/
#ifndef __ACU_H
#define __ACU_H

/* Includes */
/*============================================================================*/
#include "HAL\can.h"

/* Constants and types */
/*============================================================================*/


enum{
	ACU_OFF_MODE = 0,
	ACU_ON_MODE =1,
	ENG_ACTIVE =0x01010101,
	ENG_INACTIVE = 0x00000000
};

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void ACU_StateMachine(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
