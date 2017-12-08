/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: SchM_Cfg.c $
 * $Revision: version 1$
 * $Author: Habib Apez $
 * $Date: 2017-11- 22 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \SchM_Cfg.c
    Source of SchM_Cfg Located at SERVICES in Scheduler.
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
 * $Log: SchM_Cfg.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "SchM_Cfg.h"
//#include "SchM_Tasks.h"
#include "SchM_Tasks.c"

/* Constants and types  */
/*============================================================================*/
const SchM_TaskConfigType SchM_TaskDescriptor[] = {
  /*    Offset,                 Mask,                   Task_ID,                Function Pointer*/
  {   SCHM_OFFSET_ZERO,      SCHM_MASK_1MS,             SCHM_TASKID_1MS,        &SchM_1ms_Task          },
  {   SCHM_OFFSET_ONE,       SCHM_MASK_2MS,             SCHM_TASKID_2MS,        &SchM_2ms_Task          },
  {   SCHM_OFFSET_TWO,       SCHM_MASK_4MS,             SCHM_TASKID_4MS,        &SchM_4ms_Task          },
  {   SCHM_OFFSET_THREE,     SCHM_MASK_8MS,             SCHM_TASKID_8MS,        &SchM_8ms_Task          },
  {   SCHM_OFFSET_FIVE,      SCHM_MASK_16MS,            SCHM_TASKID_16MS,       &SchM_16ms_Task         },
  {   SCHM_OFFSET_SIX,       SCHM_MASK_32MS,            SCHM_TASKID_32MS,       &SchM_32ms_Task         }
};

const SchM_ConfigType SchM_Config = {
  (sizeof(SchM_TaskDescriptor)/sizeof(SchM_TaskConfigType)),    /* Number of Tasks */
  &SchM_TaskDescriptor[0]                                       /* Tasks Descriptions */ 
                                                                /* SchMTaskDescriptor */ 
};

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

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
