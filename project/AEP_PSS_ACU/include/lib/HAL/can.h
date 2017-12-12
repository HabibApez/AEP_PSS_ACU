/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: can.h $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-12-11  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \can.h
    Header file for can module. Located at HAL.
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
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: can.h  $
  ============================================================================*/
#ifndef __CAN_H
#define __CAN_H

/* Includes */
/*============================================================================*/
#include "MCAL\flexcan.h"

/* Constants and types */
/*============================================================================*/
#define RX_MESSAGE1_ID		511		/*Id of the Message1 */
#define RX_MESSAGE2_ID		320		/*Id of the Message1 */

#define TX_MESSAGE1_ID		510		/*Id of the Message1 */
#define TX_MESSAGE2_ID		550		/*Id of the Message1 */

#define RX_MESSAGE1_MESSAGEBUFFER 	4 		/*Message Buffer of the Message1 */
#define RX_MESSAGE2_MESSAGEBUFFER 	0 		/*Message Buffer of the Message1 */

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void can_InitCAN0(void);
void can_TransmitMessageCAN0(T_UBYTE lub_MessageBuffer, T_ULONG lul_MessageId, T_ULONG *lpl_TxData);
void can_ReceiveMessageCAN0(T_UBYTE lub_MessageBuffer, T_ULONG *lpl_RxData);
T_UBYTE can_CheckMessageArrivalCAN0(T_UBYTE lub_MessageBuffer);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
