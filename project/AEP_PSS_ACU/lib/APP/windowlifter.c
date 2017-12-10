/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: windowlifter.c $
 * $Revision: version 5 $
 * $Author: Habib Apez $
 * $Date: 2017-11-23 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \windowlifter.c
    Source of windowlifter application. Located at APP.
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
/* Habib Apez          |          3         |   New function to mange the     */
/*                     |                    |   10 segment led bar included   */
/* Habib Apez          |          4         |   Function descriptions added   */
/*                     |                    |    and uses delays module       */
/* Habib Apez          |          5         |   Design for its use with       */
/*                     |                    |     scheduler and state machine */ 
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: windowlifter.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "windowlifter.h"

/* Constants and types  */
/*============================================================================*/
#define TOP     10
#define BOTTON  0   
#define ZERO_MS 0
#define FIVE_HUNDRED_MS  250    // 250x2 = 500ms
#define FOUR_HUNDRED_MS  200    // 200x2 = 400ms
#define FIVE_S  2500            // 2500x2 = 5000ms

    
/* Variables */
/*============================================================================*/
T_UBYTE lub_UpFlag, lub_DownFlag, lub_AntipinchFlag, lub_Level = 0;
E_WindowStateMachineType rub_State = WINDOW_IDLE;

/* Private functions prototypes */
/*============================================================================*/
void windowlifter_UpNormal(void);
void windowlifter_DownNormal(void);

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/
/******************************************************************************/
/*******************    STATES DEFINITIONS   **********************************/
/******************************************************************************/
/**************************************************************
 *  Name                 : windowlifter_IdleState
 *  Description          : Defines the Idle state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void windowlifter_IdleState(void){
  if(rub_ButtonStatus == DOWN_BUTTON_PRESS){
    rub_State = ONE_TOUCH_DOWN;
  }			
  else if(rub_ButtonStatus == UP_BUTTON_PRESS){
    rub_State = ONE_TOUCH_UP;
  }	
  else if((rub_ButtonStatus == ANTIPINCH_BUTTON_PRESS) && ((rub_State == ONE_TOUCH_UP) || (rub_State == UP_NORMAL))){
    rub_State = ANTIPINCH;
  }
  else{

    rub_State = WINDOW_IDLE;
  }
}

/**************************************************************
 *  Name                 : windowlifter_OneTouchUpState
 *  Description          : Defines the OneTouchUp State
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void windowlifter_OneTouchUpState(void){                        //ONE_TOUCH_UP
  static T_UBYTE rub_UpButtonCounter = ZERO_MS;
  
  if(rub_ButtonStatus == UP_BUTTON_PRESS){
    rub_UpButtonCounter++;
    if(rub_UpButtonCounter > FIVE_HUNDRED_MS){        // Up Manual
      rub_UpButtonCounter = ZERO_MS;
      rub_State = UP_NORMAL;
    }	
    else{
      // Do nothing
    }
  }	
  else{                                                                                                                       
    rub_UpButtonCounter = ZERO_MS;
    windowlifter_UpNormal();                                      // One Touch Up
  }	
  if(rub_ButtonStatus == DOWN_BUTTON_PRESS){                    // Change window moving direction 
    rub_UpButtonCounter = ZERO_MS;
    leds_TurnOffUpLED();
    rub_State = DOWN_NORMAL;
  }
}

/**************************************************************
 *  Name                 : windowlifter_UpNormalState
 *  Description          : Defines the UpNormal State
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void windowlifter_UpNormalState(void){
  if(rub_ButtonStatus == ANTIPINCH_BUTTON_PRESS){
    leds_TurnOffUpLED();
    rub_State = ANTIPINCH;
  }
  else{
    if(rub_ButtonStatus == UP_BUTTON_PRESS){
      windowlifter_UpNormal();   
      if(rub_ButtonStatus == DOWN_BUTTON_PRESS){                    // Change window moving direction 
        leds_TurnOffUpLED();
        rub_State = DOWN_NORMAL;
      }
    }
    else{
      leds_TurnOffUpLED();
      rub_State = WINDOW_IDLE;
    }
  }
}

/**************************************************************
 *  Name                 : windowlifter_OneTouchDownState
 *  Description          : Defines the OneTouchDown State
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void windowlifter_OneTouchDownState(void){                        //ONE_TOUCH_DOWN
  static T_UBYTE rub_DownButtonCounter = ZERO_MS;
  
  if(rub_ButtonStatus == DOWN_BUTTON_PRESS){
    rub_DownButtonCounter++;
    if(rub_DownButtonCounter > FIVE_HUNDRED_MS){        // Down Manual
      rub_DownButtonCounter = ZERO_MS;
      rub_State = DOWN_NORMAL;
    }	
    else{
      // Do nothing
    }
  }	
  else{                                                                                                                       
    rub_DownButtonCounter = ZERO_MS;
    windowlifter_DownNormal();                                 // One Touch Down
  }	
  if(rub_ButtonStatus == UP_BUTTON_PRESS){                    // Change window moving direction 
    rub_DownButtonCounter = ZERO_MS;
    leds_TurnOffDownLED();
    rub_State = UP_NORMAL;
  }
}

/**************************************************************
 *  Name                 : windowlifter_DownNormalState
 *  Description          : Defines the DownNormal State
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void windowlifter_DownNormalState(void){
  if(rub_ButtonStatus == DOWN_BUTTON_PRESS){  
    windowlifter_DownNormal();   
      if(lub_Level == BOTTON){
      rub_State = WINDOW_IDLE;
    }
    if(rub_ButtonStatus == UP_BUTTON_PRESS){                    // Change window moving direction 
      leds_TurnOffDownLED();
      rub_State = UP_NORMAL;
    }
  }
  else{
    leds_TurnOffDownLED();
    rub_State = WINDOW_IDLE;
  }
}

/**************************************************************
 *  Name                 : windowlifter_AntipinchState
 *  Description          : Defines the Antipinch State
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void windowlifter_AntipinchState(void){
  leds_TurnOnAntipinchLED();          
  windowlifter_DownNormal();
  if(lub_Level == BOTTON){
    rub_State = BLOCK;
  }
}

/**************************************************************
 *  Name                 : windowlifter_BlockState
 *  Description          : Defines the Block State
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void windowlifter_BlockState(void){
  static T_ULONG rul_BlockCounter = ZERO_MS;

    rul_BlockCounter++;
    if(rul_BlockCounter > FIVE_S){        // 5s blocked
      rul_BlockCounter = ZERO_MS;
      leds_TurnOffAntipinchLED();
      rub_State = WINDOW_IDLE;
    }
}

/******************************************************************************/
/************************    STATE MACHINE FUNCTIONS  *************************/
/******************************************************************************/

/**************************************************************
 *  Name                 : windowlifter_UpNormal
 *  Description          : Moves the Window upwards
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void windowlifter_UpNormal(void){
  static T_UBYTE rub_UpTransitionCounter = ZERO_MS;
  
 // if(rub_ButtonStatus == UP_BUTTON_PRESS){
    if(rub_ButtonStatus == ANTIPINCH_BUTTON_PRESS){
      leds_TurnOffUpLED();
      rub_State = ANTIPINCH;	
    }
    else {
      if(lub_Level<TOP){
        if(rub_UpTransitionCounter == ZERO_MS) leds_TurnOnUpLED();
        rub_UpTransitionCounter++;
        if(FOUR_HUNDRED_MS == rub_UpTransitionCounter){
          leds_ToggleBlueBoardLED();
          lub_Level++;
          //delays_Wait400ms();
          segmentbar_SetLevelBar(lub_Level, 1,0);
          rub_UpTransitionCounter = ZERO_MS;
          leds_TurnOffUpLED();
        }
      }
    }
    if(lub_Level == TOP){
      leds_TurnOffUpLED();
      rub_State = WINDOW_IDLE;
    }
/*
  }
  else{
    leds_TurnOffUpLED();
    rub_State = WINDOW_IDLE;
  }
*/
}

/**************************************************************
 *  Name                 : windowlifter_DownNormal
 *  Description          : Moves the Window downwards
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void windowlifter_DownNormal(void){
  static T_UBYTE rub_DownTransitionCounter = ZERO_MS;
  
//  if(rub_ButtonStatus == DOWN_BUTTON_PRESS){
    if(lub_Level>BOTTON){
      if(rub_DownTransitionCounter == ZERO_MS) leds_TurnOnDownLED();
      rub_DownTransitionCounter++;
      if(FOUR_HUNDRED_MS == rub_DownTransitionCounter){
        lub_Level--;
        //delays_Wait400ms();
        segmentbar_SetLevelBar(lub_Level, 0, 1);
        rub_DownTransitionCounter = ZERO_MS;
        leds_TurnOffDownLED();
      }
    }
    if(lub_Level == BOTTON){
      leds_TurnOffDownLED();
      rub_State = WINDOW_IDLE;
    }  
/* 
  }
  else{
    leds_TurnOffDownLED();
    rub_State = WINDOW_IDLE;
  }
*/
}


/* Exported functions */
/*============================================================================*/
/******************************************************************************/
/************************    STATE MACHINE   **********************************/
/******************************************************************************/
/**************************************************************
 *  Name                 : windowlifter_StateMachine
 *  Description          : State Machine for WindowLifter functionality
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void windowlifter_StateMachine(void){
  switch(rub_State){
    case WINDOW_IDLE:
      windowlifter_IdleState();
      break;

    case ONE_TOUCH_UP:
      windowlifter_OneTouchUpState();
      break;		
			
    case ONE_TOUCH_DOWN:
      windowlifter_OneTouchDownState();
      break;
  
    case UP_NORMAL:
      windowlifter_UpNormalState();
      break;		
			
    case DOWN_NORMAL:
      windowlifter_DownNormalState();
      break;		
					
    case ANTIPINCH:	
      windowlifter_AntipinchState();
      break;
			
    case BLOCK:
      windowlifter_BlockState();
      break;
      
    default:
      break;
  } 
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
