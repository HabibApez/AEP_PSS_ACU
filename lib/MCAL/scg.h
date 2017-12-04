/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: scg.h $
 * $Revision: version 3 $
 * $Author: Habib Apez $
 * $Date: 2017-11-08 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \scg.h
    Header file for scg.c. Located at MCAL.
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
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/* Habib Apez          |          1         |   Initial version               */
/* Habib Apez          |          2         |   Naming conventions            */
/*                     |                    |   and MISRA checked             */
/* Habib Apez          |          3         |   Function descriptions added   */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: scg.h  $
  ============================================================================*/
#ifndef __SCG_H
#define __SCG_H

/* Includes */
/*============================================================================*/
#include "C:\My Documents\Continental\IAR\Devs\lib\MCAL\wdt.c"

/* Constants and types */
/*============================================================================*/
/** Peripheral SCG base addresses */
#define SCG_BASE_ADDRESS 0x40064000
    
/** SCG - Register Layout Typedef */
typedef struct {
  T_ULONG rul_VERID;                             /**< Version ID Register, offset: 0x0 */
  T_ULONG rul_PARAM;                             /**< Parameter Register, offset: 0x4 */
  T_UBYTE raub_RESERVED_0[8];
  T_ULONG rul_CSR;                               /**< Clock Status Register, offset: 0x10 */
  T_ULONG rul_RCCR;                              /**< Run Clock Control Register, offset: 0x14 */
  T_ULONG rul_VCCR;                              /**< VLPR Clock Control Register, offset: 0x18 */
  T_ULONG rul_HCCR;                              /**< HSRUN Clock Control Register, offset: 0x1C */
  T_ULONG rul_CLKOUTCNFG;                        /**< SCG CLKOUT Configuration Register, offset: 0x20 */
  T_UBYTE raub_RESERVED_1[220];
  T_ULONG rul_SOSCCSR;                           /**< System OSC Control Status Register, offset: 0x100 */
  T_ULONG rul_SOSCDIV;                           /**< System OSC Divide Register, offset: 0x104 */
  T_ULONG rul_SOSCCFG;                           /**< System Oscillator Configuration Register, offset: 0x108 */
  T_UBYTE raub_RESERVED_2[244];
  T_ULONG rul_SIRCCSR;                           /**< Slow IRC Control Status Register, offset: 0x200 */
  T_ULONG rul_SIRCDIV;                           /**< Slow IRC Divide Register, offset: 0x204 */
  T_ULONG rul_SIRCCFG;                           /**< Slow IRC Configuration Register, offset: 0x208 */
  T_UBYTE raub_RESERVED_3[244];
  T_ULONG rul_FIRCCSR;                           /**< Fast IRC Control Status Register, offset: 0x300 */
  T_ULONG rul_FIRCDIV;                           /**< Fast IRC Divide Register, offset: 0x304 */
  T_ULONG rul_FIRCCFG;                           /**< Fast IRC Configuration Register, offset: 0x308 */
  T_UBYTE raub_RESERVED_4[756];
  T_ULONG rul_SPLLCSR;                           /**< System PLL Control Status Register, offset: 0x600 */
  T_ULONG rul_SPLLDIV;                           /**< System PLL Divide Register, offset: 0x604 */
  T_ULONG rul_SPLLCFG;                           /**< System PLL Configuration Register, offset: 0x608 */
} S_SCG;

/** Peripheral SCG base pointers*/
#define SCG_Address ((S_SCG *)SCG_BASE_ADDRESS)

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void scg_ConfigSOSC8mhz(void);
void scg_ConfigSPLL160mhz(void);
void scg_ConfigRunMode(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
