/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: can.c $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-12-11 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \can.c
    can module file for SK32144 uC. Located at MCAL.
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
 * $Log: can.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "HAL\can.h"

/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/
void flexcan_ConfigCAN0Pins(void);

/* Exported functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : can_InitCAN0
 *  Description          : Initializes the CAN0
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void can_InitCAN0(){
  flexcan_InitFlexCAN0();
  flexcan_DisableFlexCANModule(rps_CAN0);
  flexcan_ConfigClock(rps_CAN0, 0x2000);
  flexcan_EnableFlexCANModule(rps_CAN0);

  flexcan_ConfigControlReg(rps_CAN0, 0x00DB0006);	  /* Configure for 500 KHz bit time */
													  /* Time quanta freq = 16 time quanta x 500 KHz bit time= 8MHz */
													  /* PRESDIV+1 = Fclksrc/Ftq = 8 MHz/8 MHz = 1 */
													  /*    so PRESDIV = 0 */
													  /* PSEG2 = Phase_Seg2 - 1 = 4 - 1 = 3 */
													  /* PSEG1 = PSEG2 = 3 */
													  /* PROPSEG= Prop_Seg - 1 = 7 - 1 = 6 */
													  /* RJW: since Phase_Seg2 >=4, RJW+1=4 so RJW=3. */
													  /* SMP = 1: use 3 bits per CAN sample */
													  /* CLKSRC=0 (unchanged): Fcanclk= Fosc= 8 MHz */
  flexcan_ClearMessageBuffer(rps_CAN0);
  flexcan_ConfigGlobalAccepMask(rps_CAN0, 0x1FFFFFFF);	/* Global acceptance mask: check all ID bits */

  flexcan_ConfigMessageBuffer(rps_CAN0, RX_MSG1_BUFF, (RX_MSG1_ID<<2)<<16, 0x04000000);   	/* Msg Buf 4, word 0: Enable for reception */
																			/* EDL,BRS,ESI=0: CANFD not used */
																			/* CODE=4: MB set to RX inactive */
																			/* IDE=0: Standard ID */
																			/* SRR, RTR, TIME STAMP = 0: not applicable */
																			/* Msg Buf 4, word 1: Standard ID = 0x511 */
  flexcan_ConfigMessageBuffer(rps_CAN0, RX_MSG2_BUFF, (RX_MSG2_ID<<2)<<16, 0x04000000);   	/* Msg Buf 1, word 0: Enable for reception */
																			/* EDL,BRS,ESI=0: CANFD not used */
																			/* CODE=4: MB set to RX inactive */
																			/* IDE=0: Standard ID */
																			/* SRR, RTR, TIME STAMP = 0: not applicable */
																			/* Msg Buf 1, word 1: Standard ID = 0x320 */
  flexcan_ValidateConfiguration(rps_CAN0);
  flexcan_ConfigCAN0Pins();
}

/**************************************************************
 *  Name                 : can_TransmitMessage
 *  Description          : Transmits a CAN message
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : Assumption:  Message buffer CODE is INACTIVE
 **************************************************************/
void can_TransmitMessageCAN0(T_UBYTE lub_MessageBuffer, T_ULONG lul_MessageId, T_ULONG *lpl_TxData){
  flexcan_ClearMessageBufferFlag(rps_CAN0, lub_MessageBuffer);
  flexcan_TransmitMessageFlexCAN(rps_CAN0, lub_MessageBuffer, (lul_MessageId<<2)<<16, lpl_TxData);
}

/**************************************************************
 *  Name                 : can_ReceiveMessage
 *  Description          : Receives a CAN message
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void can_ReceiveMessageCAN0(T_UBYTE lub_MessageBuffer, T_ULONG *lpl_RxData){
  flexcan_ReceiveMessageFlexCAN(rps_CAN0, lub_MessageBuffer, lpl_RxData);
  flexcan_ClearMessageBufferFlag(rps_CAN0, lub_MessageBuffer);
}

/**************************************************************
 *  Name                 : can_CheckMessageArrivalCAN0
 *  Description          : Checks if a CAN Messages has arrived
 *  Parameters           : [T_UBYTE lub_MessageBuffer]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE can_CheckMessageArrivalCAN0(T_UBYTE lub_MessageBuffer){
  return flexcan_CheckMessageBufferRxFlag(rps_CAN0, lub_MessageBuffer);
}

/**************************************************************
 *  Name                 : flexcan_ConfigCAN0Pins
 *  Description          : Configures the CAN pins
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void flexcan_ConfigCAN0Pins(void){
  pcc_EnablePeripheralClock(PCC_PORTE_INDEX);

  io_InputPin(rps_PTE, 1<<PTE4);           /* CAN_RX */
  port_ConfigurePinMode(rps_PORTE, PTE4, 0x00000500);  /* MUX = CAN_RX, input filter disabled */

  io_InputPin(rps_PTE, 1<<PTE5);          /* CAN_TX*/
  port_ConfigurePinMode(rps_PORTE, PTE5, 0x00000500);  /* MUX = CAN_TX, input filter disabled */
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
