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

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
extern void SchM_1ms_Task(void);
extern void SchM_2ms_Task(void);
extern void SchM_4ms_Task(void);
extern void SchM_8ms_Task(void);
extern void SchM_16ms_Task(void);
extern void SchM_32ms_Task(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
