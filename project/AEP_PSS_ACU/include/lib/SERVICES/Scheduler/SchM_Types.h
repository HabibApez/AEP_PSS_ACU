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
#include "Common\Std_Types.h"
#include "SchM_Tasks.h"
   
/* Constants and types */
/*============================================================================*/
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
