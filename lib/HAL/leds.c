/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: led.c $
 * $Revision: version 4 $
 * $Author: Habib Apez $
 * $Date: 2017-11-08 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \leds.c
    leds module file. Located at HAL.
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
 * $Log: led.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "leds.h"

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/* Exported functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : leds_InitLeds
 *  Description          : Configures 3 outputs for Up[PTE4], Down[PTD1] and 
 *                         Antipinch[PTC17] leds  
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void leds_InitLeds(void){
  pcc_EnablePeripheralClock(PCC_PORTC_INDEX);
  pcc_EnablePeripheralClock(PCC_PORTD_INDEX);
  pcc_EnablePeripheralClock(PCC_PORTE_INDEX);

  io_OutputPin(rps_PTE, 1<<PTE4);          /* Up LED*/
  port_ConfigurePinMode(rps_PORTE, PTE4, 0x00000100);  /* MUX = GPIO */

  io_OutputPin(rps_PTD, 1<<PTD1);          /* Down LED*/
  port_ConfigurePinMode(rps_PORTD, PTD1, 0x00000100);  /* MUX = GPIO */

  io_OutputPin(rps_PTC, 1<<PTC17);          /* Antipinch LED*/
  port_ConfigurePinMode(rps_PORTC, PTC17, 0x00000100);  /* MUX = GPIO */
}

/**************************************************************
 *  Name                 : leds_TurnOnUpLED
 *  Description          : Turns on Up LED
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void leds_TurnOnUpLED(void){
  io_SetOutput(rps_PTE, 1<<PTE4);
}

/**************************************************************
 *  Name                 : leds_TurnOnDownLED
 *  Description          : Turns on Down LED
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void leds_TurnOnDownLED(void){
  io_SetOutput(rps_PTD, 1<<PTD1);
}

/**************************************************************
 *  Name                 : leds_TurnOnAntipinchLED
 *  Description          : Turns on Antipinch LED
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void leds_TurnOnAntipinchLED(void){
  io_SetOutput(rps_PTC, 1<<PTC17);
}

/**************************************************************
 *  Name                 : leds_TurnOffUpLED
 *  Description          : Turns off Up LED
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void leds_TurnOffUpLED(void){
  io_ClearOutput(rps_PTE, 1<<PTE4);
}

/**************************************************************
 *  Name                 : leds_TurnOffDownLED
 *  Description          : Turns off Down LED
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void leds_TurnOffDownLED(void){
  io_ClearOutput(rps_PTD, 1<<PTD1);
}

/**************************************************************
 *  Name                 : leds_TurnOffAntipinchLED
 *  Description          : Turns off Antipinch LED
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void leds_TurnOffAntipinchLED(void){
  io_ClearOutput(rps_PTC, 1<<PTC17);
}

/**************************************************************
 *  Name                 : leds_InitBoardLeds
 *  Description          : Configures 3 outputs for Blue[PTD0], Red[PTD15] and 
 *                         Green[PTC16] LEDs fron the dev board  
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void leds_InitBoardLeds(void){
  pcc_EnablePeripheralClock(PCC_PORTD_INDEX);

  io_OutputPin(rps_PTD, 1<<PTD0);          /*  Blue board LED*/
  port_ConfigurePinMode(rps_PORTD, PTD0, 0x00000100);  /* MUX = GPIO */
  io_SetOutput(rps_PTD, 1<<PTD0);

  io_OutputPin(rps_PTD, 1<<PTD15);          /* Red board LED*/
  port_ConfigurePinMode(rps_PORTD, PTD15, 0x00000100);  /* MUX = GPIO */
  io_SetOutput(rps_PTD, 1<<PTD15);

  io_OutputPin(rps_PTD, 1<<PTD16);          /* Green board LED*/
  port_ConfigurePinMode(rps_PORTD, PTD16, 0x00000100);  /* MUX = GPIO */
  io_SetOutput(rps_PTD, 1<<PTD16);
}

/**************************************************************
 *  Name                 : leds_ToggleBlueBoardLED
 *  Description          : Toggles Blue board LED
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void leds_ToggleBlueBoardLED(void){
  io_TogglePin(rps_PTD, 1<<PTD0); 
}

/**************************************************************
 *  Name                 : leds_ToggleRedBoardLED
 *  Description          : Toggles Red board LED
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void leds_ToggleRedBoardLED(void){
  io_TogglePin(rps_PTD, 1<<PTD15); 
}

/**************************************************************
 *  Name                 : leds_ToggleBlueBoardLED
 *  Description          : Toggles Green board LED
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void leds_ToggleGreenBoardLED(void){
  io_TogglePin(rps_PTD, 1<<PTD16); 
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
