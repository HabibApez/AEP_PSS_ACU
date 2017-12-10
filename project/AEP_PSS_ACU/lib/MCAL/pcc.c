/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: pcc.c $
 * $Revision: version 3 $
 * $Author: Habib Apez $
 * $Date: 2017-11-08 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \pcc.c
    Peripheral Clock Controller module file for SK32144 uC. Located at MCAL.
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
 * $Log: pcc.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "pcc.h"

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/
/** Pointer to S_PCC */
S_PCC *rps_PCC = PCC_Address;

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/* Exported functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : pcc_EnablePeripheralClock
 *  Description          : Enables the PCC clock
 *  Parameters           : [T_UBYTE lub_PeripheralId]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void pcc_EnablePeripheralClock(T_UBYTE lub_PeripheralId){
  rps_PCC-> raul_PCCn[lub_PeripheralId] = 0x40000000;
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */