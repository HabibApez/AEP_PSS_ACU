/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: FlexCan.c $
 * $Revision: version  $
 * $Author: Antonio vazquez $
 * $Date: 2017-12-08 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \FlexCan.c
    Flex Can module file for SK32144 uC. Located at MCAL.
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
 * $Log: FlexCan.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "MCAL\FlexCan.h"
#include "MCAL\port.h"

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
 *  Name                 : EnableCAN
 *  Description          : Configures the CAN
 *  Parameters           : [S_CAN_Type *CAN]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
S_CAN_Type *CANStructure;
void ConfigureCAN (S_CAN_Type *CAN, T_UBYTE INDEX){
  T_ULONG i=0;
  rps_PCC->raul_PCCn[INDEX] |= PCC_PCCn_CGC_MASK;
  CAN->rul_MCR |= CAN_MCR_MDIS_MASK;
  CAN->rul_CTRL1 &= ~CAN_CTRL1_CLKSRC_MASK;  /* CLKSRC=0: Clock Source = oscillator (8 MHz) */
  CAN->rul_MCR &= ~CAN_MCR_MDIS_MASK;        /* MDIS=0; Enable module config. (Sets FRZ, HALT)*/
  while (!((CAN->rul_MCR & CAN_MCR_FRZACK_MASK) >> CAN_MCR_FRZACK_SHIFT))  {}
                 /* Good practice: wait for FRZACK=1 on freeze mode entry/exit */
  CAN->rul_CTRL1 = CAN_MASK_500KHz; /* Configure for 500 KHz bit time */
                            /* Time quanta freq = 16 time quanta x 500 KHz bit time= 8MHz */
                            /* PRESDIV+1 = Fclksrc/Ftq = 8 MHz/8 MHz = 1 */
                            /*    so PRESDIV = 0 */
                            /* PSEG2 = Phase_Seg2 - 1 = 4 - 1 = 3 */
                            /* PSEG1 = PSEG2 = 3 */
                            /* PROPSEG= Prop_Seg - 1 = 7 - 1 = 6 */
                            /* RJW: since Phase_Seg2 >=4, RJW+1=4 so RJW=3. */
                            /* SMP = 1: use 3 bits per CAN sample */
                            /* CLKSRC=0 (unchanged): Fcanclk= Fosc= 8 MHz */
  for(i=0; i<CAN_RAMn_COUNT; i++ ) {   /* CAN0: clear 32 msg bufs x 4 words/msg buf = 128 words*/
    CAN->raul_RAMn[i] = NULL;      /* Clear msg buf word */
  }
}

/**************************************************************
 *  Name                 : CHECK_MB_ID
 *  Description          : Check the ID bits
 *  Parameters           : [S_CAN_Type *CAN, T_UBYTE ID]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void CHECK_MB_ID (S_CAN_Type *CAN, T_ULONG ID){
  T_ULONG i=0;
  for(i=0; i<16; i++ ) {          /* In FRZ mode, init CAN0 16 msg buf filters */
    CAN->raul_RXIMR[i] = ID;  /* Check all ID bits for incoming messages */
  }
}

/**************************************************************
 *  Name                 : ACCEPTANCE_MB_ID
 *  Description          : Configures the MB to be accepted
 *  Parameters           : [S_CAN_Type *CAN, T_UBYTE ID]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void ACCEPTANCE_MB_ID (S_CAN_Type *CAN, T_ULONG ID){
  CAN->rul_RXMGMASK = ID;
}

/**************************************************************
 *  Name                 : Configure_Receiver
 *  Description          : Configures a MB to receives messages
 *  Parameters           : [S_CAN_Type *CAN, T_UBYTE MB, T_UBYTE ID_Type, T_UBYTE ID]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
 void Configure_Receiver (S_CAN_Type *CAN, T_UBYTE MB, T_ULONG ID_Type, T_ULONG ID){
   CAN->raul_RAMn[ MB*MSG_BUF_SIZE + MSG_BUF_CFG] = ENABLE_RECEPTION | ID_Type;
   CAN->raul_RAMn[ MB*MSG_BUF_SIZE + MSG_BUF_ID] = ID;
 }

 /**************************************************************
  *  Name                 : EnableCAN
  *  Description          : Enables the CAN
  *  Parameters           : [S_CAN_Type *CAN]
  *  Return               : void
  *  Critical/explanation : No
  **************************************************************/

  void EnableCan(S_CAN_Type *CAN){
    CAN->rul_MCR = RESERVE_32MB_MASK;       /* Negate FlexCAN 1 halt state for 32 MBs */
    while ((CAN->rul_MCR && CAN_MCR_FRZACK_MASK) >> CAN_MCR_FRZACK_SHIFT)  {}
                   /* Good practice: wait for FRZACK to clear (not in freeze mode) */
    while ((CAN->rul_MCR && CAN_MCR_NOTRDY_MASK) >> CAN_MCR_NOTRDY_SHIFT)  {}

    rps_PORTE->raul_PCR[4] |= 0x00000500;
    rps_PORTE->raul_PCR[5] |= 0x00000500;
  }

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
