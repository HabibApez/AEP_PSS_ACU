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
/* Antonio Vazquez          |          2         |   Macros' revision              */
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
#include "MCAL\io.h"
#include "MCAL\pcc.h"
#include "MCAL\port.h"

/* Constants and types */
/*============================================================================*/
#define PTE4 	4 	/* CAN_RX */
#define PTE5 	5 	/* CAN_TX */

#define ID_0x100      0x04000000u
#define ID_0x511  		0x14440000u		/*Id of the Message1 */
#define ID_0x320   		0x0C800000u		/*Id of the Message1 */
#define RX_MSG1_BUFF 	4 		/*Message Buffer of the Message1 */
#define RX_MSG2_BUFF 	0 		/*Message Buffer of the Message1 */

#define ID_0x601  		0x18040000u		/*Id of the Message1 */
#define ID_0x602  		0x18080000u		/*Id of the Message1 */
#define TX_MSG1_BUFF 	1 		/*Message Buffer of the Message1 */
#define TX_MSG2_BUFF 	2 		/*Message Buffer of the Message1 */

#define MUX_CAN_MASK  0x00000500u
#define OSCILLATOR_CLOCK_SOURCE 0x2000u
#define CLOCK_500KHz  0x00DB0006
#define GLOBAL_ID_ACCEPTANCE  0x1FFFFFFFu
#define RECEPTION_STD_ID      0x04000000u


/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void can_InitCAN0(void);
void can_TransmitMessageCAN0(T_UBYTE lub_MessageBuffer, T_ULONG lul_MessageId, T_ULONG *lpl_TxData);
void can_ReceiveMessageCAN0(T_UBYTE lub_MessageBuffer, T_ULONG *lpl_RxData);
T_UBYTE can_CheckMessageArrivalCAN0(T_UBYTE lub_MessageBuffer);


#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
