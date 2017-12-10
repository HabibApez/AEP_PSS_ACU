/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: buttonsm.h $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-11-24  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \button
    Header file for button module. Located at HAL.
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
 * $Log: buttonsm.h  $
  ============================================================================*/
#ifndef __BUTTONSM_H
#define __BUTTONSM_H

/* Includes */
/*============================================================================*/

/* Constants and types */
/*============================================================================*/
typedef enum{
  BUTTON_IDLE,
  UP_VALIDATION,
  DOWN_VALIDATION,
  ANTIPINCH_VALIDATION,
}E_ButtonStateMachineType;

typedef enum{
  NONE_BUTTON_PRESS,
  UP_BUTTON_PRESS,
  DOWN_BUTTON_PRESS,
  ANTIPINCH_BUTTON_PRESS
}E_ButtonStateType;

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void buttonsm_StateMachine(void);
 

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
