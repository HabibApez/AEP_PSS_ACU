/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: port.c $
 * $Revision: version 3 $
 * $Author: Habib Apez $
 * $Date: 2017-11-08 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \port.c
    Port Control and Interrupts module file for SK32144 uC. Located at MCAL.
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
 * $Log: port.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "port.h"

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/
/** Pointers to S_PORT */
S_PORT *rps_PORTA = PORTA_Address;
S_PORT *rps_PORTB = PORTB_Address;
S_PORT *rps_PORTC = PORTC_Address;
S_PORT *rps_PORTD = PORTD_Address;
S_PORT *rps_PORTE = PORTE_Address;

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/* Exported functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : port_ConfigurePinMode
 *  Description          : Configures the pin mode of a pin
 *  Parameters           : [S_PORT *lps_Port, T_UBYTE lub_Pin, T_ULONG lul_Mode]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void port_ConfigurePinMode(S_PORT *lps_Port, T_UBYTE lub_Pin, T_ULONG lul_Mode){
  lps_Port->raul_PCR[lub_Pin] = lul_Mode;
}

/**************************************************************
 *  Name                 : port_GetIntStatusFlag
 *  Description          : Gets Pin Interrupt Status Flag
 *  Parameters           : [S_PORT *lps_Port, T_UBYTE lub_Pin]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE port_GetIntStatusFlag(S_PORT *lps_Port, T_UBYTE lub_Pin){
  return lps_Port->raul_PCR[lub_Pin] & (1<<24);
}

/**************************************************************
 *  Name                 : ClearIntStatusFlag
 *  Description          : Clears Pin Interrupt Status Flag
 *  Parameters           : [S_PORT *lps_Port, T_UBYTE lub_Pin]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void port_ClearIntStatusFlag(S_PORT *lps_Port, T_UBYTE lub_Pin){
  lps_Port->raul_PCR[lub_Pin] |= (1<<24);
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
