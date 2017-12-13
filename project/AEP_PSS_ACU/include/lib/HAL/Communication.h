/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Communication.h $
 * $Revision: version 1 $
 * $Author: Antonio Vazquez $
 * $Date: 2017-12-08 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \Communication
    Header file for CAN BUS Communication. Located at HAL.
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
/* Antonio Vazquez    |          1         |   Initial version               */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: Communication.h  $
  ============================================================================*/
#ifndef __COMMUNICATION_H
#define __COMMUNICATION_H

/* Includes */
/*============================================================================*/
#include "MCAL\FlexCan.h"

/* Constants and types */
/*============================================================================*/
#define FLAG_READY_MASK     0x00000001u
#define FIRST_PART_OF_MSG   0u
#define SECOND_PART_OF_MSG  1u
#define ENABLE_TRANSMITION  0x0C000000u
#define TRANSMISION_FRAME   0x00400000u
#define CAN_WMBn_CS_DLC_SHIFT  16u


#define ACTIVE				1
#define INACTIVE			2

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void FLEXCAN_init(S_CAN_Type *CAN);
void FLEXCAN_transmit_msg (S_CAN_Type *CAN, const T_UBYTE can_mb, T_ULONG ID_Type, const T_ULONG CAN_Id, const T_UBYTE DLC, T_ULONG *TxDATA);
void FLEXCAN_receive_msg(S_CAN_Type *CAN, const T_UBYTE can_mb, T_ULONG *RxDATA);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
