/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: buttonsm.c $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-11-24 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \button.c
    State machine for the bottons. Located at APP.
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
 * $Log: buttonsm.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "APP\buttonsm.h"

/* Constants and types  */
/*============================================================================*/
#define ZERO_MS 0
#define TEN_MS  10

#define BTN_INACTIVE 0
#define BTN_ACTIVE 1
        
/* Variables */
/*============================================================================*/
E_ButtonStateMachine re_ButtonSmState = BUTTON_IDLE;
T_UBYTE lub_ButtonTimeCounter = ZERO_MS;
E_ButtonState re_ButtonState = NONE_BUTTON_PRESS;

/* Private functions prototypes */
/*============================================================================*/
void buttonsm_IdleState(void);
void buttonsm_UpValidationState(void);
void buttonsm_DownValidationState(void);
void buttonsm_AntipinchValidationState(void);

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/* Exported functions */
/*============================================================================*/
/******************************************************************************/
/************************    STATE MACHINE   **********************************/
/******************************************************************************/
/**************************************************************
 *  Name                 : buttonsm_StateMachine
 *  Description          : State Machine for buttons
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void buttonsm_StateMachine(void){
  switch(re_ButtonSmState){
    case BUTTON_IDLE:
      buttonsm_IdleState();
      break;

    case UP_VALIDATION:
      buttonsm_UpValidationState();
      break;		
			
    case DOWN_VALIDATION:
      buttonsm_DownValidationState();
      break;
  
    case ANTIPINCH_VALIDATION:
      buttonsm_AntipinchValidationState();
      break;		
			
    default:
      break;
    
  } 
}

/******************************************************************************/
/*******************    STATES DEFINITIONS   **********************************/
/******************************************************************************/

/**************************************************************
 *  Name                 : buttonsm_IdleState
 *  Description          : Defines the Idle state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void buttonsm_IdleState(void){
  if(button_CheckButtonAntipinch() == BTN_ACTIVE){		
    re_ButtonState = ANTIPINCH_VALIDATION;
  }		
  else if((button_CheckButtonUp() == BTN_ACTIVE) && (button_CheckButtonDown() == BTN_INACTIVE) ){		
    re_ButtonState = UP_VALIDATION;
  }	
  else if((button_CheckButtonDown() == BTN_ACTIVE) && (button_CheckButtonUp() == BTN_INACTIVE)){	
    re_ButtonState = DOWN_VALIDATION;
  }		
  else{
    lub_ButtonTimeCounter = ZERO_MS;       /* Reset time*/
    re_ButtonState = NONE_BUTTON_PRESS;
  }
}

/**************************************************************
 *  Name                 : buttonsm_DownValidationState
 *  Description          : Defines the DownValidation state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void buttonsm_DownValidationState(void){
  
  lub_ButtonTimeCounter++;                       /*Increases time to 10 milliseconds*/
    if(lub_ButtonTimeCounter >= TEN_MS){
      lub_ButtonTimeCounter = ZERO_MS;    /* Reset time*/
      re_ButtonState = DOWN_BUTTON_PRESS;
      re_ButtonSmState = BUTTON_IDLE;
    }
    else{
      //Do nothing
    }
}

/**************************************************************
 *  Name                 : buttonsm_UpValidationState
 *  Description          : Defines the UpValidation state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void buttonsm_UpValidationState(void){
   lub_ButtonTimeCounter++;	             /*Increases time to 10 milliseconds*/
    if(lub_ButtonTimeCounter >= TEN_MS){
      lub_ButtonTimeCounter = ZERO_MS;    /* Reset time*/
      re_ButtonState = UP_BUTTON_PRESS;
      re_ButtonSmState = BUTTON_IDLE;
    }
    else{
      //Do nothing
    }
}


/**************************************************************
 *  Name                 : buttonsm_AntipinchValidationState
 *  Description          : Defines the AntipinchValidation state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void buttonsm_AntipinchValidationState(void){
  lub_ButtonTimeCounter++;	             /*Increases time to 10 milliseconds*/
    if(lub_ButtonTimeCounter >= TEN_MS){
      lub_ButtonTimeCounter = ZERO_MS;    /* Reset time*/
      re_ButtonState = ANTIPINCH_BUTTON_PRESS;
      re_ButtonSmState = BUTTON_IDLE;
    }	
    else{
      //Do nothing
    }
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */
