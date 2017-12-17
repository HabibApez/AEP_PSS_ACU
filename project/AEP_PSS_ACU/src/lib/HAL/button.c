/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: button.c $
 * $Revision: version 5 $
 * $Author: Habib Apez $
 * $Date: 2017-12-15 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \button.c
    button module file for SK32144 uC. Located at MCAL.
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
/* Habib Apez          |          3         |   Debounce adjusted at 10ms     */
/* Habib Apez          |          4         |   Function descriptions added   */
/* Habib Apez          |          5         |   In-Board button functions added*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: button.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "HAL\button.h"
#include "MCAL\pcc.h"
#include "HAL\delays.h"

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
 *  Name                 : button_InitButtons
 *  Description          : Configures 3 inputs for Up[PTA11], Down[PTA12] and
 *                         Antipinch[PTA13] buttons, each one with an input filter  
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void button_InitButtons(void){
  pcc_EnablePeripheralClock(PCC_PORTA_INDEX);

  io_InputPin(rps_PTA, 1<<PTA13);          /* Antipinch Button*/
  port_ConfigurePinMode(rps_PORTA, PTA13, 0x00000110);  /* MUX = GPIO, input filter enabled */

  io_InputPin(rps_PTA, 1<<PTA11);          /* Up Button*/
  port_ConfigurePinMode(rps_PORTE, PTA11, 0x00000110);  /* MUX = GPIO, input filter enabled */

  io_InputPin(rps_PTA, 1<<PTA12);          /* Down Button*/
  port_ConfigurePinMode(rps_PORTA, PTA12, 0x00000110);  /* MUX = GPIO, input filter enabled */
}

/**************************************************************
 *  Name                 : button_CheckButtonUp
 *  Description          : Checks if Up button is pressed
 *  Parameters           : [void]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE button_CheckButtonUp(void){
  return io_GetPinData(rps_PTA, PTA11);
}

/**************************************************************
 *  Name                 : button_CheckButtonDown
 *  Description          : Checks if Down button is pressed
 *  Parameters           : [void]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE button_CheckButtonDown(void){
  return io_GetPinData(rps_PTA, PTA12);
}

/**************************************************************
 *  Name                 : button_CheckButtonAntipinch
 *  Description          : Checks if Antipinch button is pressed
 *  Parameters           : [void]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE button_CheckButtonAntipinch(void){
  return io_GetPinData(rps_PTA, PTA13);
}

/**************************************************************
 *  Name                 : button_DebounceButtonUp
 *  Description          : Verifies if it is an Up button valid press
 *  Parameters           : [void]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE button_DebounceButtonUp(void){  
  if(button_CheckButtonUp()){
    delays_Wait10ms();
    if(button_CheckButtonUp()){
      return 1;
    }
    else {
      return 0;
    }
  }
  else{
    return 0;
  }
}

/**************************************************************
 *  Name                 : button_DebounceButtonDown
 *  Description          : Verifies if it is an Down button valid press
 *  Parameters           : [void]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE button_DebounceButtonDown(void){
   if(button_CheckButtonDown()){
    delays_Wait10ms();
    if(button_CheckButtonDown()){
      return 1;
    }
    else{
      return 0;
    }
  }
   else{
    return 0;
   }
}

/**************************************************************
 *  Name                 : button_DebounceButtonAntipinch
 *  Description          : Verifies if it is an Antipinch button valid press
 *  Parameters           : [void]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE button_DebounceButtonAntipinch(void){
   if(button_CheckButtonAntipinch()){
    delays_Wait10ms();
    if(button_CheckButtonAntipinch()){
      return 1;
    }
    else{
      return 0;
    }
  }
   else{
    return 0;
   }
}

/**************************************************************
 *  Name                 : button_InitBoardButtons
 *  Description          : Configures 2 inputs for Left[PTC13] and 
 *                         Right[PTC12] buttons, each one with an input filter 
 *                         and  Interrupt when logic 1  
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void button_InitBoardButtons(void){
  pcc_EnablePeripheralClock(PCC_PORTC_INDEX);

  io_InputPin(rps_PTC, 1<<PTC12);          /* BTN0 Right Button*/
  port_ConfigurePinMode(rps_PORTC, PTC12, 0x00060110);  /* MUX = GPIO, input filter enabled */

  io_InputPin(rps_PTC, 1<<PTC13);          /* BTN1 Left Button*/
  port_ConfigurePinMode(rps_PORTC, PTC13, 0x00060110);  /* MUX = GPIO, input filter enabled */
}

/**************************************************************
 *  Name                 : button_CheckLeftBoardButton
 *  Description          : Checks if Left button is pressed
 *  Parameters           : [void]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE button_CheckLeftBoardButton(void){
  return io_GetPinData(rps_PTC, PTC13);
}

/**************************************************************
 *  Name                 : button_CheckRightBoardButton
 *  Description          : Checks if Left button is pressed
 *  Parameters           : [void]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE button_CheckRightBoardButton(void){
  return io_GetPinData(rps_PTC, PTC12);
}

/**************************************************************
 *  Name                 : button_ValidRightBoardButtonPress
 *  Description          : Verifies if the Right button press is  valid
 *  Parameters           : [void]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE button_ValidRightBoardButtonPress(void){
   if(button_CheckRightBoardButton()){
    delays_Wait10ms();
    delays_Wait10ms();
    delays_Wait10ms();
    delays_Wait10ms();
    delays_Wait10ms();
    delays_Wait10ms();
    delays_Wait10ms();
    delays_Wait10ms();
    delays_Wait10ms();
    if(button_CheckRightBoardButton()){
      return 1;
    }
    else{
      return 0;
    }
  }
   else{
    return 0;
   }
}

/**************************************************************
 *  Name                 : button_ValidLeftBoardButtonPress
 *  Description          : Verifies if the Left button press is  valid
 *  Parameters           : [void]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE button_ValidLeftBoardButtonPress(void){
   if(button_CheckLeftBoardButton()){
    delays_Wait10ms();
    if(button_CheckLeftBoardButton()){
      return 1;
    }
    else{
      return 0;
    }
  }
   else{
    return 0;
   }
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
