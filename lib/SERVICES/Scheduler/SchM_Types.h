/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: SchM_Types.h $
 * $Revision: version 1$
 * $Author: Habib Apez $
 * $Date: 2017-11- 22 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \SchM_Cfg.h
    Header file for SchM_Types. Located at SERVICES in Scheduler.
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
 * $Log: SchM_Types.h  $
  ============================================================================*/
#ifndef __SCHM_TYPES_H
#define __SCHM_TYPES_H

/* Includes */
/*============================================================================*/
#include "C:\My Documents\Continental\IAR\Devs\lib\Common\Std_Types.h"
   
/* Constants and types */
/*============================================================================*/
/*=========================== Task Definition section ========================*/
/* The offset values to generate the task periods */
typedef enum{
  SCHM_OFFSET_ZERO,
  SCHM_OFFSET_ONE,
  SCHM_OFFSET_TWO,
  SCHM_OFFSET_THREE,
  SCHM_OFFSET_FOUR,
  SCHM_OFFSET_FIVE,
  SCHM_OFFSET_SIX
}SchM_TaskOffsetType;

/* The mask values to generate the task periods */
typedef enum{
  SCHM_MASK_1MS         =     3,
  SCHM_MASK_2MS         =     7,
  SCHM_MASK_4MS         =     15,
  SCHM_MASK_8MS         =     31,
  SCHM_MASK_16MS        =     63,
  SCHM_MASK_32MS        =     127
}SchM_TaskMaskType;

/* Task ID values */
typedef enum{
  SCHM_TASKID_BKG,
  SCHM_TASKID_1MS,
  SCHM_TASKID_2MS,
  SCHM_TASKID_4MS,
  SCHM_TASKID_8MS,
  SCHM_TASKID_16MS,
  SCHM_TASKID_32MS
}SchM_TaskIDType;

typedef void (*TaskFunctionPtrType)(void);

/* Structure of a single Task for configuration purposes*/
typedef struct{
  SchM_TaskOffsetType SchM_TaskOffset;           /* Offset */
  SchM_TaskMaskType SchM_TaskMask;               /* Mask */
  SchM_TaskIDType SchM_TaskID;                   /* Task_ID */
  TaskFunctionPtrType SchM_TaskFunctionPtr;	/* Callback, Function Ptr */
}SchM_TaskConfigType;

/* Task States */
typedef enum{
  SCHM_TASK_STATE_SUSPENDED,
  SCHM_TASK_STATE_READY,
  SCHM_TASK_STATE_RUNNING	
}SchM_TaskStateType;

/* Task Control Block Structure */
typedef struct{
  SchM_TaskStateType SchM_TaskState;             /* State */
  TaskFunctionPtrType TaskFunctionControlPtr;   /* Function Pointer */          
}SchM_TaskControlBlockType;   

/*=========================== Scheduler Definition Section ===================*/
/* Scheduler States */
typedef enum{
  SCHM_UNINIT,
  SCHM_INIT,
  SCHM_IDLE,
  SCHM_RUNNING,
  SCHM_OVERLOAD,
  SCHM_HALTED
}SchM_SchedulerStateType;

/* Scheduler Control Structure */ //????? add a task_running variable
typedef struct{
  T_ULONG SchM_OsTickCounter;
  SchM_SchedulerStateType SchM_State;	
}SchM_ControlType;

/* Scheduler configuration Structure for configuration purposes*/
typedef struct{
  T_UBYTE SchM_NumOfTasks;                              /* Number of Tasks */
  const SchM_TaskConfigType *SchM_TaskDescriptor;       /* Tasks Descriptions */ 
}SchM_ConfigType;

/* Exported Variables */
/*============================================================================*/
extern const SchM_ConfigType SchM_Config;

/* Exported functions prototypes */
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
