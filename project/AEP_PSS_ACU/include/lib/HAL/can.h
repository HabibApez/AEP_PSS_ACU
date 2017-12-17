/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: can.h $
 * $Revision: version 2$
 * $Author: Habib Apez $
 * $Date: 2017-12-15  $
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
/* Habib Apez          |          2         |   Messages configuration set    */
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

#define ENG_RPM_MSG_ID		0x100	/*Id of the Eng_RPM Message */
#define ENG_RPM_MSG_BUFF 	0 		/*Message Buffer of the Message Eng_RPM */

#define SEAT_BELT_INDICATOR_MSG_ID		0x601	/*Id of the Seat Belt Indicator Message */
#define SEAT_BELT_INDICATOR_MSG_BUFF 	1 		/*Message Buffer of the Seat Belt Indicator Message */

#define CHIME_REQUEST_MSG_ID		0x550	/*Id of the Chime Request Message*/
#define CHIME_REQUEST_MSG_BUFF 		2 		/*Message Buffer of the Chime Request Message */


/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void can_InitCAN0(void);
void can_TransmitMessageCAN0(T_UBYTE lub_MessageBuffer, T_ULONG lul_MessageId, T_ULONG *lpl_TxData);
void can_ReceiveMessageCAN0(T_UBYTE lub_MessageBuffer, T_ULONG *lpl_RxData);
T_UBYTE can_CheckMessageArrivalCAN0(T_UBYTE lub_MessageBuffer);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
