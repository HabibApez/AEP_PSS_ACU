/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Communication.c $
 * $Revision: version 1 $
 * $Author: Antonio Vazquez $
 * $Date: 2017-12-08 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \Communication.c
    CAN BUS Communication. Located at HAL.
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
/* Antonio Vazquez    |          1         |   Initial version               */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: Communication.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "HAL\Communication.h"

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

/* Exported functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : FLEXCAN0_init
 *  Description          : Initialize the CAN0 BUS
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void FLEXCAN_init(S_CAN_Type *CAN){
ConfigureCAN(CAN, PCC_FlexCAN0_INDEX);
CHECK_MB_ID (CAN, CHECK_ALL_ID);
ACCEPTANCE_MB_ID (CAN, GLOBAL_ACCEPTANCE_MASK);
Configure_Receiver(CAN, MSG_BUF_4, STANDARD_ID, ID_0x511);
Configure_Receiver(CAN, MSG_BUF_1, STANDARD_ID, ID_0x320);
EnableCan(CAN); /*To change the number of MB reserved, a modification to this function is required.
                      *located at MCAL/FlexCan.c */
}

/**************************************************************
 *  Name                 : FLEXCAN0_transmit_msg
 *  Description          : Transmit a message through CAN BUS
 *  Parameters           : [S_CAN_Type *CAN, const T_UBYTE can_mb, T_ULONG ID_Type, const T_ULONG CAN_Id, const T_UBYTE DLC, T_ULONG *TxDATA]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void FLEXCAN_transmit_msg (S_CAN_Type *CAN, const T_UBYTE can_mb, T_ULONG ID_Type, const T_ULONG CAN_Id, const T_UBYTE DLC, T_ULONG *TxDATA){
        CAN->rul_IFLAG1 = FLAG_READY_MASK << can_mb;
        CAN->raul_RAMn[can_mb*MSG_BUF_SIZE+MSG_BUF_DATA1] = TxDATA[FIRST_PART_OF_MSG];
        CAN->raul_RAMn[can_mb*MSG_BUF_SIZE+MSG_BUF_DATA2] = TxDATA[SECOND_PART_OF_MSG];
        CAN->raul_RAMn[can_mb*MSG_BUF_SIZE+MSG_BUF_ID] = CAN_Id;
        CAN->raul_RAMn[can_mb*MSG_BUF_SIZE+MSG_BUF_CFG] = ENABLE_TRANSMITION | TRANSMISION_FRAME | ID_Type | DLC << CAN_WMBn_CS_DLC_SHIFT;
}


 /**************************************************************
  *  Name                 : FLEXCAN0_receive_msg
  *  Description          : Receives a message through CAN BUS
  *  Parameters           : [S_CAN_Type *CAN, const T_UBYTE can_mb, T_ULONG ID_Type, const T_ULONG CAN_Id, const T_UBYTE DLC, T_ULONG *TxDATA]
  *  Return               : void
  *  Critical/explanation : No
  **************************************************************/
  void FLEXCAN_receive_msg(S_CAN_Type *CAN, const T_UBYTE can_mb, T_ULONG *RxDATA){
 RxDATA[FIRST_PART_OF_MSG] = CAN->raul_RAMn[can_mb*MSG_BUF_SIZE+MSG_BUF_DATA1];
 RxDATA[SECOND_PART_OF_MSG] = CAN->raul_RAMn[can_mb*MSG_BUF_SIZE+MSG_BUF_DATA2];
 CAN->rul_IFLAG1 = FLAG_READY_MASK << can_mb;
  }

  /**************************************************************
   *  Name                 : FLEXCAN0_msg_flag
   *  Description          : Read msg flag to determinate waiting messages
   *  Parameters           : [S_CAN_Type *CAN, const T_UBYTE can_mb]
   *  Return               : void
   *  Critical/explanation : No
   **************************************************************/
   T_UBYTE FLEXCAN_msg_flag(S_CAN_Type *CAN, const T_UBYTE can_mb){
	   return ((CAN->rul_IFLAG1>> can_mb) & ACTIVE);
   }

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
