/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: windowlifter.h $
 * $Revision: version 4 $
 * $Author: Habib Apez $
 * $Date: 2017-11-23 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \windowlifter.h
    Header file for windowlifter application. Located at APP.
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
/* Habib Apez          |          2         |   Naming conventions            */
/*                     |                    |   and MISRA checked             */
/* Habib Apez          |          3         |   Function descriptions added   */
/*                     |                    |     and uses delays module      */ 
/* Habib Apez          |          5         |   Design for its use with       */
/*                     |                    |     scheduler and state machine */ 
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: windowlifter.h  $
  ============================================================================*/
#ifndef __WINDOWLIFTER_H
#define __WINDOWLIFTER_H

/* Includes */
/*============================================================================*/

/* Constants and types */
/*============================================================================*/
typedef enum{
  WINDOW_IDLE,
  ONE_TOUCH_UP,
  UP_NORMAL,
  ONE_TOUCH_DOWN,
  DOWN_NORMAL,
  ANTIPINCH,
  BLOCK
}E_WindowStateMachineType;

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void windowlifter_StateMachine(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
