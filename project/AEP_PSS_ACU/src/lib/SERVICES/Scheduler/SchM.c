/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: SchM.c $
 * $Revision: version 1$
 * $Author: Habib Apez $
 * $Date: 2017-11- 16 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \SchM.c
    Source of SchM Located at SERVICES in Scheduler.
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
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: SchM.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "SERVICES\Scheduler\SchM.h"
#include "SERVICES\Interrupts\interrupts.h"
// include interrupts

/* Constants and types  */
/*============================================================================*/
const SchM_ConfigType *SchM_ConfigGlobal;
#define NUM_OF_TASKS (0x4)

/* Variables */
/*============================================================================*/

SchM_ControlType SchM_Control={0, SCHM_UNINIT};

SchM_TaskControlBlockType SchM_TaskControlBlock[NUM_OF_TASKS];

/* Private functions prototypes */
/*============================================================================*/
void SchM_OsTick(void);
void SchM_Background(void);

void SysTick_Init(tCallbackFunction Callback);

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : SchM_OsTick
 *  Description          : OS Tick Function
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/ 
void SchM_OsTick(void){
  T_UBYTE lub_Index;

    for(lub_Index = 0; lub_Index < SchM_ConfigGlobal->SchM_NumOfTasks; lub_Index++){
      if(((SchM_ConfigGlobal->SchM_TaskDescriptor[lub_Index].SchM_TaskMask) & (SchM_Control.SchM_OsTickCounter)) == SchM_ConfigGlobal->SchM_TaskDescriptor[lub_Index].SchM_TaskOffset){
        if(SCHM_RUNNING == SchM_Control.SchM_State){
          SchM_Control.SchM_State = SCHM_OVERLOAD;      // Set Overload Flag 
        }
        SchM_TaskControlBlock[lub_Index].SchM_TaskState = SCHM_TASK_STATE_READY;
      }		
      else {
        // No-Task to be executed
      }
    }
  SchM_Control.SchM_OsTickCounter++;
 }
 
/**************************************************************
 *  Name                 : SchM_Background
 *  Description          : Background Task
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
 void SchM_Background(void){
  T_UBYTE lub_LocTaskIdx;  // Protect this variable due to an interrupt
  while(1){
    for(lub_LocTaskIdx = 0; lub_LocTaskIdx < SchM_ConfigGlobal->SchM_NumOfTasks; lub_LocTaskIdx++){
      if(SCHM_TASK_STATE_READY == SchM_TaskControlBlock[lub_LocTaskIdx].SchM_TaskState){
	SchM_TaskControlBlock[lub_LocTaskIdx].SchM_TaskState = SCHM_TASK_STATE_RUNNING;
        SchM_Control.SchM_State = SCHM_RUNNING;
	//leds_TurnOnUpLED();
        SchM_ConfigGlobal->SchM_TaskDescriptor[lub_LocTaskIdx].SchM_TaskFunctionPtr();
	//leds_TurnOffUpLED();
        SchM_TaskControlBlock[lub_LocTaskIdx].SchM_TaskState = SCHM_TASK_STATE_SUSPENDED;
	SchM_Control.SchM_State = SCHM_IDLE;
      }
      else{ 
        // Background Task
      }
    }
  }
 } 
 
/* Exported functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : SchM_Init
 *  Description          : Initializes the scheduler
 *  Parameters           : [const SchM_ConfigType *SchM_Config]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_Init(const SchM_ConfigType *SchM_Config){
  SchM_ConfigGlobal = SchM_Config;
  T_UBYTE LocTaskIdx;
  SchM_Control.SchM_State = SCHM_UNINIT;

  for(LocTaskIdx = 0; LocTaskIdx < SchM_ConfigGlobal->SchM_NumOfTasks; LocTaskIdx++){
    SchM_TaskControlBlock[LocTaskIdx].SchM_TaskState = SCHM_TASK_STATE_SUSPENDED;
    }

  SysTick_Init(SchM_OsTick);
  SchM_Control.SchM_State = SCHM_INIT;
}

/**************************************************************
 *  Name                 : SysTick_Init
 *  Description          : Initializes the SysTick
 *  Parameters           : [tCallbackFunction Callback]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SysTick_Init(tCallbackFunction Callback){
  interrupts_InitIRQ(SysTick_IRQn, 0xA);
  interrupts_ConfigSysTickIRQ(100000);   // Configure SysTick Clock
  GlbSysTickCallback = Callback;        // 0.0125 us each = 250us
}

/**************************************************************
 *  Name                 : SchM_Init
 *  Description          : Starts the scheduler
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_Start(void){
  interrupts_EnableSysTickIRQ();
  SchM_Background();
}

/**************************************************************
 *  Name                 : SchM_Stop
 *  Description          : Stops the scheduler
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void SchM_Stop(void){
  interrupts_DisableSysTickIRQ();
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
