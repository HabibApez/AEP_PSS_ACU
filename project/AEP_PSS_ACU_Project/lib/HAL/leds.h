/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: leds.h $
 * $Revision: version 4 $
 * $Author: Habib Apez $
 * $Date: 2017-11-08 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \leds
    Header file for leds module. Located at HAL.
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
/* Habib Apez          |          4         |   Board LED functions added     */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: led.h  $
  ============================================================================*/
#ifndef __LED_H
#define __LED_H

/* Includes */
/*============================================================================*/

/* Constants and types */
/*============================================================================*/
#define PTE4 4		/* Port PTE4, bit 4: UP_LED output (blue LED) */
#define PTC17 17	/* Port PTC17, bit 17: ANTIPINCH_LED output (red LED) */
#define PTD1 1		/* Port PTD1, bit 1: DOWN_LED output (green LED) */    

#define PTD0 0		/* Port PTD0, bit 0: BLUE_BOARD_LED output (blue LED) */
#define PTD15 15	/* Port PTD15, bit 15: RED_BOARD_LED output (red LED) */
#define PTD16 16        /* Port PTD16, bit 16: GREEN_BOARD_LED output (green LED) */   
 
/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void leds_InitLeds(void);
void leds_TurnOnUpLED(void);
void leds_TurnOffUpLED(void);
void leds_TurnOnAntipinchLED(void);
void leds_TurnOffAntipinchLED(void);
void leds_TurnOnDownLED(void);
void leds_TurnOffDownLED(void);

void leds_InitBoardLeds(void);
void leds_ToggleBlueBoardLED(void);
void leds_ToggleRedBoardLED(void);
void leds_ToggleGreenBoardLED(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
