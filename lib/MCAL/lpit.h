/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: lpit.h $
 * $Revision: version 3 $
 * $Author: Habib Apez $
 * $Date: 2017-11-08 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \lpit.h
    Header file for lpit.c Located at MCAL.
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
/* Habib Apez          |          3         |   Function descriptions added   */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: lpit.h  $
  ============================================================================*/
#ifndef __LPIT_H
#define __LPIT_H

/* Includes */
/*============================================================================*/
#include "C:\My Documents\Continental\IAR\Devs\lib\MCAL\pcc.c"

/* Constants and types */
/*============================================================================*/
/** Peripheral LPITx base addresses */
#define LPIT_BASE_ADDRESS      0X40037000

/** LPIT - Size of Registers Arrays */
#define LPIT_TMR_COUNTER          4

/** LPIT - Register Layout Typedef */
typedef struct {
  T_ULONG rul_VERID;                             /**< Version ID Register, offset: 0x0 */
  T_ULONG rul_PARAM;                             /**< Parameter Register, offset: 0x4 */
  T_ULONG rul_MCR;                               /**< Module Control Register, offset: 0x8 */
  T_ULONG rul_MSR;                               /**< Module Status Register, offset: 0xC */
  T_ULONG rul_MIER;                              /**< Module Interrupt Enable Register, offset: 0x10 */
  T_ULONG rul_SETTEN;                            /**< Set Timer Enable Register, offset: 0x14 */
  T_ULONG rul_CLRTEN;                            /**< Clear Timer Enable Register, offset: 0x18 */
  T_UBYTE raub_RESERVED_0[4];
  struct {                                         /* offset: 0x20, array step: 0x10 */
    T_ULONG rul_TVAL;                              /**< Timer Value Register, array offset: 0x20, array step: 0x10 */
    T_ULONG rul_CVAL;                              /**< Current Timer Value, array offset: 0x24, array step: 0x10 */
    T_ULONG rul_TCTRL;                             /**< Timer Control Register, array offset: 0x28, array step: 0x10 */
    T_UBYTE raul_RESERVED_0[4];
  } S_TMR[LPIT_TMR_COUNTER];
} S_LPIT; 

/** Peripheral LPIT base pointers*/
#define LPIT_Address ((S_LPIT *)LPIT_BASE_ADDRESS)

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void lpit_EnableLPITO(void);
void lpit_ChargeLPITOCh0(T_ULONG lul_value);
void lpit_EnableLPIT0Ch0(void);
void lpit_DisableLPIT0Ch0(void);
T_UBYTE lpit_ChecklFlagLPIT0Ch0(void);
void lpit_ClearFlagLPIT0Ch0(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
