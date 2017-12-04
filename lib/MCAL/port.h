/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: port.h $
 * $Revision: version 3 $
 * $Author: Habib Apez $
 * $Date: 2017-11-08 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \port.h
    Header file for port module. Located at MCAL.
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
 * $Log: port.h  $
  ============================================================================*/
#ifndef __PORT_H
#define __PORT_H

/* Includes */
/*============================================================================*/

/* Constants and types */
/*============================================================================*/
/** Peripheral PORTx base addresses */
#define PORTA_BASE_ADDRESS      0X40049000
#define PORTB_BASE_ADDRESS      0X4004A000
#define PORTC_BASE_ADDRESS      0X4004B000
#define PORTD_BASE_ADDRESS      0X4004C000
#define PORTE_BASE_ADDRESS      0X4004D000

/** PORT - Size of Registers Arrays */
#define PORT_PCR_COUNTER  32

/** PORT - Register Layout Typedef */
typedef struct {
  T_ULONG raul_PCR[PORT_PCR_COUNTER];     /**< Pin Control Register n, array      offset: 0x0, array step: 0x4 */
  T_ULONG rul_GPCLR;                   /**< Global Pin Control Low Register,   offset: 0x80 */
  T_ULONG rul_GPCHR;                   /**< Global Pin Control High Register,  offset: 0x84 */
  T_ULONG rul_GICLR;                   /**< Global Interrupt Control Low Register,  offset: 0x88 */
  T_ULONG rul_GICHR;                   /**< Global Interrupt Control High Register,  offset: 0x8C */
  T_ULONG rul_ISFR;                    /**< Interrupt Status Flag Register,    offset: 0xA0 */
  T_UBYTE rub_RESERVED_1[28];
  T_ULONG rul_DFER;                    /**< Digital Filter Enable Register,    offset: 0xC0 */
  T_ULONG rul_DFCR;                    /**< Digital Filter Clock Register,     offset: 0xC4 */
  T_ULONG rul_DFWR;                    /**< Digital Filter Width Register,     offset: 0xC8 */
} S_PORT;

/** Peripheral PORT base pointers*/
#define PORTA_Address ((S_PORT *)PORTA_BASE_ADDRESS)
#define PORTB_Address ((S_PORT *)PORTB_BASE_ADDRESS)
#define PORTC_Address ((S_PORT *)PORTC_BASE_ADDRESS)
#define PORTD_Address ((S_PORT *)PORTD_BASE_ADDRESS)
#define PORTE_Address ((S_PORT *)PORTE_BASE_ADDRESS)

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void port_ConfigurePinMode(S_PORT *lps_Port, T_UBYTE lub_Pin, T_ULONG lul_Mode);
T_UBYTE port_GetIntStatusFlag(S_PORT *lps_Port, T_UBYTE lub_Pin);
void port_ClearIntStatusFlag(S_PORT *lps_Port, T_UBYTE lub_Pin);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
