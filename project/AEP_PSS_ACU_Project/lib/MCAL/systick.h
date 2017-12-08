/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: systick.h $
 * $Revision: version 1$
 * $Author: Habib Apez $
 * $Date: 2017-11-015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \systick.h
    Header file for systick module. Located at SERVICES.
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
 * $Log: systick.h  $
  ============================================================================*/
#ifndef __SYSTICK_H
#define __SYSTICK_H

/* Includes */
/*============================================================================*/

/* Constants and types */
/*============================================================================*/
/** SysTick base addresses */
#define SYSTICK_BASE_ADDRESS      0XE000E010
   
/** SysTick - Register Layout Typedef */
typedef struct {
  T_ULONG rul_CSR;              /**< Control and Status Register,       offset: 0x00 */
  T_ULONG rul_RVR;              /**< Reload Value Register,             offset: 0x04 */
  T_ULONG rul_CVR;              /**< Current Value Register,            offset: 0x08 */
  T_ULONG rul_CALIB;            /**< Calibration Value Register,        offset: 0x0C */
} S_SYSTICK; 

/** SysTick base pointers*/
#define SYSTICK_Address ((S_SYSTICK *)SYSTICK_BASE_ADDRESS)

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void systick_InitSysTick(T_ULONG lul_Value);
void systick_EnableSysTick(void);
void systick_DisableSysTick(void);
void systick_ReloadSysTickValue(T_ULONG lul_Value);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
