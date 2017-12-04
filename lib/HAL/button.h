/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: button.h $
 * $Revision: version 3 $
 * $Author: Habib Apez $
 * $Date: 2017-11-08  $
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
/* Habib Apez          |          2         |   Naming conventions            */
/*                     |                    |   and MISRA checked             */
/* Habib Apez          |          3         |   Function descriptions added   */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: button.h  $
  ============================================================================*/
#ifndef __BUTTON_H
#define __BUTTON_H

/* Includes */
/*============================================================================*/
#include "C:\My Documents\Continental\IAR\Devs\lib\MCAL\io.c"
#include "C:\My Documents\Continental\IAR\Devs\lib\MCAL\port.c"

/* Constants and types */
/*============================================================================*/
#define PTE5 5		/* Port PTE5, bit 5: UP_BUTTON intput (UP Button) */
#define PTA12 12	/* Port PTA12, bit 12: DOWN_BUTTON intput (DOWN Button) */
#define PTA13 13	/* Port PTA13, bit 13: ANTIPINCH_BUTTON intput (ANTIPINCH Button) */

#define PTC12 12	/* Port PTC12, bit 12: RIGHT_BOARD_BUTTON intput (RIGHT Button) */
#define PTC13 13	/* Port PTC13, bit 13: LEFT_BOARD_BUTTON intput (LEFT Button) */

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void button_InitButtons(void);
T_UBYTE button_CheckButtonUp(void);
T_UBYTE button_CheckButtonDown(void);
T_UBYTE button_CheckButtonAntipinch(void);
T_UBYTE button_DebounceButtonUp(void);
T_UBYTE button_DebounceButtonDown(void);
T_UBYTE button_DebounceButtonAntipinch(void);

void button_InitBoardButtons(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
