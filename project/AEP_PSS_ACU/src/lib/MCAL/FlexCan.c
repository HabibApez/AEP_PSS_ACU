/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: flexcan.c $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-12-11 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \flexcan.c
    flexcan module file for SK32144 uC. Located at MCAL.
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
/* Antonio Vazquez     |          2         |   Macros' revision              */
/* Habib Apez          |          3         |   Macros correction             */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: flexcan.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "MCAL\flexcan.h"

/* Constants and types  */
/*============================================================================*/
    /* Msg Buffer Size. (CAN 2.0AB: 2 hdr +  2 data= 4 words) */

/* Variables */
/*============================================================================*/

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/**************************************************************
 *  Name                 : flexcan_DisableFlexCANModule
 *  Description          : Disables the specified FlexCan module
 *  Parameters           : [S_CAN *lps_CAN]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void flexcan_DisableFlexCANModule(S_CAN *lps_CAN){
  lps_CAN->rul_MCR |= FLEXCAN_DISABLE_MASK;				/* MDIS=1: Disable module before selecting clock */
}

/**************************************************************
 *  Name                 : flexcan_DisableFlexCANModule
 *  Description          : Enables the specified FlexCan module
 *  Parameters           : [S_CAN *lps_CAN]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void flexcan_EnableFlexCANModule(S_CAN *lps_CAN){
  lps_CAN->rul_MCR &= ~FLEXCAN_DISABLE_MASK;				/* MDIS=0; Enable module config. (Sets FRZ, HALT)*/
  while (!((lps_CAN->rul_MCR & CAN_FROZEN_MASK) >> CAN_FROZEN_SHIFT));
                   /* Good practice: wait for FRZACK=1 on freeze mode entry/exit */

}

/**************************************************************
 *  Name                 : flexcan_ConfigClock
 *  Description          : Configures the clock
 *  Parameters           : [S_CAN *lps_CAN, T_UWORD luw_Config1]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void flexcan_ConfigClock(S_CAN *lps_CAN, T_UWORD luw_Config1){
  lps_CAN->rul_CTRL1 &= ~luw_Config1;
}

/**************************************************************
 *  Name                 : flexcan_ConfigControlReg
 *  Description          : Configures specific FlexCAN control features related to the CAN bus.
 *  Parameters           : [S_CAN *lps_CAN, T_ULONG lul_Config2]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void flexcan_ConfigControlReg(S_CAN *lps_CAN, T_ULONG lul_Config2){
  lps_CAN->rul_CTRL1 = lul_Config2;
}

/**************************************************************
 *  Name                 : flexcan_ClearMessageBuffer
 *  Description          : Clear 32 msg bufs x 4 words/msg buf = 128 words
 *  Parameters           : [S_CAN *lps_CAN]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void flexcan_ClearMessageBuffer(S_CAN *lps_CAN){
	T_UBYTE i=0;
	for(i=0; i<CAN_RAMn_COUNT; i++ ) {   /* CAN: clear 32 msg bufs x 4 words/msg buf = 128 words*/
	lps_CAN->rul_RAMn[i] = NULL;      /* Clear msg buf word */
  }
  for(i=0; i<CAN_RXIMR_COUNT; i++ ) {          /* In FRZ mode, init CAN0 16 msg buf filters */
	lps_CAN->rul_RXIMR[i] = INCOMING_MSG_IDS_CHECK;  /* Check all ID bits for incoming messages */
  }
}

/**************************************************************
 *  Name                 : flexcan_ConfigGlobalAccepMask
 *  Description          : Sets the global acceptance mask
 *  Parameters           : [S_CAN *lps_CAN, T_ULONG lul_Mask]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void flexcan_ConfigGlobalAccepMask(S_CAN *lps_CAN, T_ULONG lul_Mask){
	lps_CAN->rul_RXMGMASK = lul_Mask;  /* Global acceptance mask: check all ID bits */
}

/**************************************************************
 *  Name                 : flexcan_ConfigMessageBuffer
 *  Description          : Configures a Message Buffer
 *  Parameters           : [S_CAN *lps_CAN, T_BYTE_MessageNumber, T_ULONG lul_MessageId, T_ULONG lul_MessageConfig]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void flexcan_ConfigMessageBuffer(S_CAN *lps_CAN, T_UBYTE lub_MessageBoxNumber, T_ULONG lul_MessageId, T_ULONG lul_MessageConfig){
  lps_CAN->rul_RAMn[ lub_MessageBoxNumber*MSG_BUF_SIZE + MSG_BUFF_CFG] = lul_MessageConfig;
  lps_CAN->rul_RAMn[ lub_MessageBoxNumber*MSG_BUF_SIZE + MSG_BUFF_ID] = lul_MessageId;
}

/**************************************************************
 *  Name                 : flexcan_ValidateConfiguration
 *  Description          : Wait until FlexCAN initialization is complete
 *  Parameters           : [S_CAN *lps_CAN]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void flexcan_ValidateConfiguration(S_CAN *lps_CAN){
	lps_CAN->rul_MCR = RESERVE_32MB;       /* Negate FlexCAN 1 halt state for 32 MBs */
	  while ((lps_CAN->rul_MCR && CAN_FROZEN_MASK) >> CAN_FROZEN_SHIFT);
	                 /* Good practice: wait for FRZACK to clear (not in freeze mode) */
	  while ((lps_CAN->rul_MCR && CAN_NOTREADY_MASK) >> CAN_NOTREADY_SHIFT);
	                 /* Good practice: wait for NOTRDY to clear (module ready)  */
}


/* Exported functions */
/*============================================================================*/

/**************************************************************
 *  Name                 : flexcan_InitCAN
 *  Description          : Initializes the FlexCANx module
 *  Parameters           : [T_UBYTE PCC_CANx_INDEX]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void flexcan_InitFlexCAN0(){
  rps_PCC-> raul_PCCn[PCC_FlexCAN0_INDEX] |= ENABLE_PERIPHERAL_CLOCK; 	/* CGC=1: enable clock to FlexCAN0 */
}

/**************************************************************
 *  Name                 : flexcan_ClearMessageBufferFlag
 *  Description          : Clears Message Buffer Flag
 *  Parameters           : [S_FlexCAN *lps_CAN, T_UBYTE lub_MessageBuffer]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void flexcan_ClearMessageBufferFlag(S_CAN *lps_CAN, T_UBYTE lub_MessageBuffer){
	lps_CAN->rul_IFLAG1 = (CLEAR_FLAG_MASK << lub_MessageBuffer);       /* Clear CAN can_mb MB  flag without clearing others*/
}

/**************************************************************
 *  Name                 : flexcan_TransmitMessageFlexCAN(
 *  Description          : Transmit a CAN message
 *  Parameters           : [S_FlexCAN *lps_CAN, T_UBYTE lub_MessageBuffer, T_ULONG lul_MessageId, T_ULONG *lpl_TxData]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void flexcan_TransmitMessageFlexCAN(S_CAN *lps_CAN, T_UBYTE lub_MessageBuffer, T_ULONG lul_MessageId, T_ULONG *lpul_TxData){
  lps_CAN->rul_RAMn[lub_MessageBuffer*MSG_BUF_SIZE + MSG_BUFF_DATA1] = lpul_TxData[SECOND_PART_OF_MSG]; /* MB word 3: data word 1 */
  lps_CAN->rul_RAMn[lub_MessageBuffer*MSG_BUF_SIZE + MSG_BUFF_DATA0] = lpul_TxData[FIRST_PART_OF_MSG]; /* MB word 2: data word 0 */
  lps_CAN->rul_RAMn[lub_MessageBuffer*MSG_BUF_SIZE + MSG_BUFF_ID] = lul_MessageId;
  lps_CAN->rul_RAMn[lub_MessageBuffer*MSG_BUF_SIZE + MSG_BUFF_CFG] = TRANSMISION_ENABLE_MASK | (MSG_DLC_SIZE << DLC_SHIFT); /* MB0 word 0: */
		                                                /* EDL,BRS,ESI=0: CANFD not used */
		                                                /* CODE=0xC: Activate msg buf to transmit */
		                                                /* IDE=0: Standard ID */
		                                                /* SRR=1 Tx frame (not req'd for std ID) */
		                                                /* RTR = 0: data, not remote tx request frame*/
		                                                /* DLC = 8 bytes */
}

/**************************************************************
 *  Name                 : flexcan_ReceiveMessageFlexCAN
 *  Description          : Receive a CAN message
 *  Parameters           : [S_FlexCAN *lps_CAN, T_ULONG *lpl_TxData]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void flexcan_ReceiveMessageFlexCAN(S_CAN *lps_CAN, T_UBYTE lub_MessageBuffer, T_ULONG *lpul_RxData){
  T_UBYTE i = 0;

  for (i=0; i<2; i++) {  /* Read two words of data (8 bytes) */
	  lpul_RxData[i] = lps_CAN->rul_RAMn[lub_MessageBuffer*MSG_BUF_SIZE + 2 + i];
    }
  i = lps_CAN->rul_TIMER; /* Read TIMER to unlock message buffers */
}

/**************************************************************
 *  Name                 : flexcan_CheckMessageBufferRxFlag
 *  Description          : Checks the Rx Buffer Flag
 *  Parameters           : [S_FlexCAN *lps_CAN, T_UBYTE lub_MessageBuffer]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE flexcan_CheckMessageBufferRxFlag(S_CAN *lps_CAN, T_UBYTE lub_MessageBuffer){
  return (lps_CAN->rul_IFLAG1 >> lub_MessageBuffer) & TRUE;
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */
