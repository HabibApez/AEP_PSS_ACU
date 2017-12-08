/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: wdt.h $
 * $Revision: version 3 $
 * $Author: Habib Apez $
 * $Date: 2017-11-08 $
*/
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \wdt.h
    Header file for wdt module . Located at MCAL.
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
 * $Log: wdt.h  $
  ============================================================================*/
#ifndef __WDT_H
#define __WDT_H

/* Includes */
/*============================================================================*/

/* Constants and types */
/*============================================================================*/
/** Peripheral WDT base addresses */
#define WDT_BASE_ADDRESS      0x40052000

/** WDOG - Register Layout Typedef */
typedef struct {
  T_ULONG rul_CS;                                /**< Watchdog Control and Status Register, offset: 0x0 */
  T_ULONG rul_CNT;                               /**< Watchdog Counter Register, offset: 0x4 */
  T_ULONG rul_TOVAL;                             /**< Watchdog Timeout Value Register, offset: 0x8 */
  T_ULONG rul_WIN;                               /**< Watchdog Window Register, offset: 0xC */
} S_WDT;

/** Peripheral WDT base pointers*/
#define WDT_Address ((S_WDT *)WDT_BASE_ADDRESS)

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void wdt_DisableWdt(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
