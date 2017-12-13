/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: flexcan.h $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-12-11 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \flexcan.h
    Header file for flexcan module. Located at MCAL.
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
 * $Log: flexcan.h  $
  ============================================================================*/
#ifndef __FLEXCAN_H
#define __FLEXCAN_H

/* Includes */
/*============================================================================*/
#include "Common\Std_Types.h"
#include "MCAL\pcc.h"

/* Constants and types */
/*============================================================================*/
/** CAN - Size of Registers Arrays */
#define CAN_RAMn_COUNT                           128u
#define CAN_RXIMR_COUNT                          16u
#define CAN_WMB_COUNT                            4u

/** CAN - Register Layout Typedef */
typedef struct {
  T_ULONG rul_MCR;                               /**< Module Configuration Register, offset: 0x0 */
  T_ULONG rul_CTRL1;                             /**< Control 1 register, offset: 0x4 */
  T_ULONG rul_TIMER;                             /**< Free Running Timer, offset: 0x8 */
  T_UBYTE rub_RESERVED_0[4];
  T_ULONG rul_RXMGMASK;                          /**< Rx Mailboxes Global Mask Register, offset: 0x10 */
  T_ULONG rul_RX14MASK;                          /**< Rx 14 Mask register, offset: 0x14 */
  T_ULONG rul_RX15MASK;                          /**< Rx 15 Mask register, offset: 0x18 */
  T_ULONG rul_ECR;                               /**< Error Counter, offset: 0x1C */
  T_ULONG rul_ESR1;                              /**< Error and Status 1 register, offset: 0x20 */
  T_UBYTE rub_RESERVED_1[4];
  T_ULONG rul_IMASK1;                            /**< Interrupt Masks 1 register, offset: 0x28 */
  T_UBYTE rub_RESERVED_2[4];
  T_ULONG rul_IFLAG1;                            /**< Interrupt Flags 1 register, offset: 0x30 */
  T_ULONG rul_CTRL2;                             /**< Control 2 register, offset: 0x34 */
  T_ULONG rul_ESR2;                              /**< Error and Status 2 register, offset: 0x38 */
  T_UBYTE rub_RESERVED_3[8];
  T_ULONG rul_CRCR;                              /**< CRC Register, offset: 0x44 */
  T_ULONG rul_RXFGMASK;                          /**< Rx FIFO Global Mask register, offset: 0x48 */
  T_ULONG rul_RXFIR;                             /**< Rx FIFO Information Register, offset: 0x4C */
  T_ULONG rul_CBT;                               /**< CAN Bit Timing Register, offset: 0x50 */
  T_UBYTE rub_RESERVED_4[44];
  T_ULONG rul_RAMn[CAN_RAMn_COUNT];              /**< Embedded RAM, array offset: 0x80, array step: 0x4 */
  T_UBYTE rub_RESERVED_5[1536];
  T_ULONG rul_RXIMR[CAN_RXIMR_COUNT];            /**< Rx Individual Mask Registers, array offset: 0x880, array step: 0x4 */
  T_UBYTE rub_RESERVED_6[576];
  T_ULONG rul_CTRL1_PN;                          /**< Pretended Networking Control 1 Register, offset: 0xB00 */
  T_ULONG rul_CTRL2_PN;                          /**< Pretended Networking Control 2 Register, offset: 0xB04 */
  T_ULONG rul_WU_MTC;                            /**< Pretended Networking Wake Up Match Register, offset: 0xB08 */
  T_ULONG rul_FLT_ID1;                           /**< Pretended Networking ID Filter 1 Register, offset: 0xB0C */
  T_ULONG rul_FLT_DLC;                           /**< Pretended Networking DLC Filter Register, offset: 0xB10 */
  T_ULONG rul_PL1_LO;                            /**< Pretended Networking Payload Low Filter 1 Register, offset: 0xB14 */
  T_ULONG rul_PL1_HI;                            /**< Pretended Networking Payload High Filter 1 Register, offset: 0xB18 */
  T_ULONG rul_FLT_ID2_IDMASK;                    /**< Pretended Networking ID Filter 2 Register / ID Mask Register, offset: 0xB1C */
  T_ULONG rul_PL2_PLMASK_LO;                     /**< Pretended Networking Payload Low Filter 2 Register / Payload Low Mask Register, offset: 0xB20 */
  T_ULONG rul_PL2_PLMASK_HI;                     /**< Pretended Networking Payload High Filter 2 low order bits / Payload High Mask Register, offset: 0xB24 */
  T_UBYTE rub_RESERVED_7[24];
  struct {                                         /* offset: 0xB40, array step: 0x10 */
    T_ULONG rul_WMBn_CS;                           /**< Wake Up Message Buffer Register for C/S, array offset: 0xB40, array step: 0x10 */
    T_ULONG rul_WMBn_ID;                           /**< Wake Up Message Buffer Register for ID, array offset: 0xB44, array step: 0x10 */
    T_ULONG rul_WMBn_D03;                          /**< Wake Up Message Buffer Register for Data 0-3, array offset: 0xB48, array step: 0x10 */
    T_ULONG rul_WMBn_D47;                          /**< Wake Up Message Buffer Register Data 4-7, array offset: 0xB4C, array step: 0x10 */
  } S_WMB[CAN_WMB_COUNT];
  T_UBYTE rub_RESERVED_8[128];
  T_ULONG rul_FDCTRL;                            /**< CAN FD Control Register, offset: 0xC00 */
  T_ULONG rul_FDCBT;                             /**< CAN FD Bit Timing Register, offset: 0xC04 */
  T_ULONG rul_FDCRC;                             /**< CAN FD CRC Register, offset: 0xC08 */
} S_CAN;



/** Peripheral CAN base addresses */
#define CAN0_BASE_ADDRESS      0x40024000
#define CAN1_BASE_ADDRESS      0x40025000

/** Peripheral CANx base pointers*/
#define CAN0_Address ((S_CAN *)CAN0_BASE_ADDRESS)
#define CAN1_Address ((S_CAN *)CAN1_BASE_ADDRESS)

/* Exported Variables */
/*============================================================================*/
/** Pointers to S_CAN */
S_CAN *rps_CAN0 = CAN0_Address;
S_CAN *rps_CAN1 = CAN1_Address;

/* Exported functions prototypes */
/*============================================================================*/
void flexcan_InitFlexCAN0();
void flexcan_DisableFlexCANModule(S_CAN *lps_CAN);
void flexcan_EnableFlexCANModule(S_CAN *lps_CAN);
void flexcan_ConfigClock(S_CAN *lps_CAN, T_UWORD luw_Config1);
void flexcan_ConfigControlReg(S_CAN *lps_CAN, T_ULONG lul_Config2);
void flexcan_ClearMessageBuffer(S_CAN *lps_CAN);
void flexcan_ConfigGlobalAccepMask(S_CAN *lps_CAN, T_ULONG lul_Mask);
void flexcan_ConfigMessageBuffer(S_CAN *lps_CAN, T_UBYTE lub_MessageBoxNumber, T_ULONG lul_MessageId, T_ULONG lul_MessageConfig);
void flexcan_ValidateConfiguration(S_CAN *lps_CAN);
void flexcan_ClearMessageBufferFlag(S_CAN *lps_CAN, T_UBYTE lub_MessageBuffer);
void flexcan_TransmitMessageFlexCAN(S_CAN *lps_CAN, T_UBYTE lub_MessageBuffer, T_ULONG lul_MessageId, T_ULONG *lpul_TxData);
void flexcan_ReceiveMessageFlexCAN(S_CAN *lps_CAN, T_UBYTE lub_MessageBuffer, T_ULONG *lpul_RxData);
T_UBYTE flexcan_CheckMessageBufferRxFlag(S_CAN *lps_CAN, T_UBYTE lub_MessageBuffer);
void flexcan_ConfigPinsCAN0();

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
