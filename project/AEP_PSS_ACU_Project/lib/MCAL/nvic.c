/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: nvic.c $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-11-08 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \nvic.c
    Nested Vectored Interrupt Controller module file for SK32144 uC. Located at 
    MCAL.
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
 * $Log: nvic.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
# include "nvic.h"

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/
/** Pointers to S_NVIC */
S_NVIC *rps_NVIC = NVIC_Address;

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/* Exported functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : nvic_EnableInterrupt
 *  Description          : Sets Enable Interrupt Flag
 *  Parameters           : [IRQn_Type lub_IRQn]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void nvic_EnableInterrupt(IRQn_Type lub_IRQn){
  rps_NVIC->rul_ISER[lub_IRQn / 32] |= 1 << (lub_IRQn % 32);
}

/**************************************************************
 *  Name                 : nvic_DisableInterrupt
 *  Description          : Clears Enable Interrupt Flag
 *  Parameters           : [IRQn_Type lub_IRQn]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void nvic_DisableInterrupt(IRQn_Type lub_IRQn){
  rps_NVIC->rul_ICER[lub_IRQn / 32] |= 1 << (lub_IRQn % 32);
}

/**************************************************************
 *  Name                 : nvic_SetPendingInterrupt
 *  Description          : Sets Pending Interrupt Flag
 *  Parameters           : [IRQn_Type lub_IRQn]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void nvic_SetPendingInterrupt(IRQn_Type lub_IRQn){
  rps_NVIC->rul_ISPR[lub_IRQn / 32] |= 1 << (lub_IRQn % 32);
}

/**************************************************************
 *  Name                 : nvic_ClearPendingInterrupt
 *  Description          : Clears Pending Interrupt Flag
 *  Parameters           : [IRQn_Type lub_IRQn]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void nvic_ClearPendingInterrupt(IRQn_Type lub_IRQn){
  rps_NVIC->rul_ICPR[lub_IRQn / 32] |= 1 << (lub_IRQn % 32);
}

/**************************************************************
 *  Name                 : nvic_GetActiveInterrupt
 *  Description          : Gets the Active bit Interrupt Flag
 *  Parameters           : [IRQn_Type lub_IRQn]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE nvic_GetActiveInterrupt(IRQn_Type lub_IRQn){
  return (rps_NVIC->rul_IABR[lub_IRQn / 32]) & (1 << (lub_IRQn % 32));
}

/**************************************************************
 *  Name                 : nvic_SetInterruptPriority
 *  Description          : Sets interrupt priority
 *  Parameters           : [IRQn_Type lub_IRQn, T_UBYTE lub_Priority]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void nvic_SetInterruptPriority(IRQn_Type lub_IRQn, T_UBYTE lub_Priority){
  rps_NVIC->rul_IP[lub_IRQn / 4] |= lub_Priority << (8 * (lub_IRQn % 4) + 4 );
}

/**************************************************************
 *  Name                 : nvic_SetInterruptPriority
 *  Description          : Sets interrupt priority
 *  Parameters           : [IRQn_Type lub_IRQn, T_UBYTE lub_Priority]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE nvic_GetInterruptPriority(IRQn_Type lub_IRQn){
  return (rps_NVIC->rul_IP[lub_IRQn / 4]) & (0x0F << (8 * (lub_IRQn % 4) + 4 ));
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
