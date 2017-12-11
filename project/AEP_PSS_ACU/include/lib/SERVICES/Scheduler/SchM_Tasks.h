/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: SchM_Tasks.h $
 * $Revision: version 1$
 * $Author: Habib Apez $
 * $Date: 2017-11-2 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \SchM_Cfg.h
    Header of SchM_Tasks. Located at SERVICES in Scheduler.
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
 * $Log: SchM_Tasks.h  $
  ============================================================================*/
#ifndef __SCHM_TASKS_H
#define __SCHM_TASKS_H

/* Includes */
/*============================================================================*/

/* Constants and types */
/*============================================================================*/
/*=========================== Task Definition section ========================*/
/* The offset values to generate the task periods */
typedef enum{
  SCHM_OFFSET_ZERO,
  SCHM_OFFSET_ONE,
  SCHM_OFFSET_TWO,
  SCHM_OFFSET_THREE
}SchM_TaskOffsetType;

/* The mask values to generate the task periods */
typedef enum{
  SCHM_MASK_5MS          =     3,
  SCHM_MASK_10MS         =     7,
  SCHM_MASK_20MS         =     15,
  SCHM_MASK_40MS         =     31
}SchM_TaskMaskType;

/* Task ID values */
typedef enum{
  SCHM_TASKID_BKG,
  SCHM_TASKID_5MS,
  SCHM_TASKID_10MS,
  SCHM_TASKID_20MS,
  SCHM_TASKID_40MS
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

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
extern void SchM_5ms_Task(void);
extern void SchM_10ms_Task(void);
extern void SchM_20ms_Task(void);
extern void SchM_40ms_Task(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
