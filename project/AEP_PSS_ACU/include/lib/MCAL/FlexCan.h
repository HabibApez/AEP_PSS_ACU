/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: FlexCan.h $
 * $Revision: version 1 $
 * $Author: Antonio Vazquez $
 * $Date: 2017-12-08 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \FlexCan.h
    Header file for FlexCan.c located at MCAL.
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
 * $Log: FlexCan.h  $
  ============================================================================*/
#ifndef __FLEXCAN_H
#define __FLEXCAN_H

#ifndef NULL
#define NULL 0u
#endif
/* Includes */
/*============================================================================*/
#include "MCAL\pcc.h"

/* Constants and types */
/*============================================================================*/
/** Peripheral CAN base address */
#define CAN0_BASE_ADDRESS      0x40024000u
#define CAN1_BASE_ADDRESS      0x40025000u
#define CAN2_BASE_ADDRESS      0x4002B000u

/** CAN - Size of Registers Arrays */
#define CAN_RAMn_COUNT         128u
#define CAN_RXIMR_COUNT         16u
#define CAN_WMB_COUNT            4u

/*CAN Msg Buffer Size */
#define MSG_BUF_SIZE  4u

/*Configurate 32 MB*/
#define RESERVE_32MB_MASK       0x0000001Fu

/*Configuration to enable 500 KHz at the CAN */
#define CAN_MASK_500KHz         0x00DB0006u
#define CHECK_ALL_ID            0xFFFFFFFFu
#define GLOBAL_ACCEPTANCE_MASK  0x1FFFFFFFu
#define ENABLE_RECEPTION        0x04000000u
#define STANDARD_ID             0x00000000u

/*Message Buffers*/
#define MSG_BUF_0          0u
#define MSG_BUF_1          1u
#define MSG_BUF_2          2u
#define MSG_BUF_3          3u
#define MSG_BUF_4          4u
#define MSG_BUF_5          5u
#define MSG_BUF_6          6u
#define MSG_BUF_7          7u
#define MSG_BUF_8          8u
#define MSG_BUF_9          9u

/*Message Buffers Registers*/
#define MSG_BUF_CFG       0u
#define MSG_BUF_ID        1u
#define MSG_BUF_DATA1     2u
#define MSG_BUF_DATA2     3u

/*CAN ID*/
#define ID_0x511   0x14440000u
#define ID_0x320   0x0C800000u

/** CAN - Register Layout Typedef */
typedef struct {
  T_ULONG rul_MCR;                             /**< Version ID Register, offset: 0x0 */
  T_ULONG rul_CTRL1;                             /**< Parameter Register, offset: 0x4 */
  T_ULONG rul_TIMER;                               /**< Module Control Register, offset: 0x8 */
  T_UBYTE raub_RESERVED_0[4];                               /**< Module Status Register, offset: 0xC */
  T_ULONG rul_RXMGMASK;                              /**< Module Interrupt Enable Register, offset: 0x10 */
  T_ULONG rul_RX14MASK;                            /**< Set Timer Enable Register, offset: 0x14 */
  T_ULONG rul_RX15MASK;                            /**< Clear Timer Enable Register, offset: 0x18 */
  T_ULONG rul_ECR;
  T_ULONG rul_ESR1;
  T_UBYTE raub_RESERVED_1[4];
  T_ULONG IMASK1;
  T_UBYTE raub_RESERVED_2[4];
  T_ULONG rul_IFLAG1;
  T_ULONG rul_CTRL2;
  T_ULONG rul_ESR2;
  T_UBYTE raub_RESERVED_3[8];
  T_ULONG rul_CRCR;
  T_ULONG rul_RXFGMASK;
  T_ULONG rul_RXFIR;
  T_ULONG rul_CBT;
  T_UBYTE raub_RESERVED_4[44];
  T_ULONG raul_RAMn[CAN_RAMn_COUNT];
  T_UBYTE raub_RESERVED_5[1536];
  T_ULONG raul_RXIMR[CAN_RXIMR_COUNT];            /**< Rx Individual Mask Registers, array offset: 0x880, array step: 0x4 */
  T_UBYTE raub_RESERVED_6[576];
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
  T_UBYTE raub_RESERVED_7[24];
struct {                                         /* offset: 0xB40, array step: 0x10 */
  T_ULONG rul_WMBn_CS;                           /**< Wake Up Message Buffer Register for C/S, array offset: 0xB40, array step: 0x10 */
  T_ULONG rul_WMBn_ID;                           /**< Wake Up Message Buffer Register for ID, array offset: 0xB44, array step: 0x10 */
  T_ULONG rul_WMBn_D03;                          /**< Wake Up Message Buffer Register for Data 0-3, array offset: 0xB48, array step: 0x10 */
  T_ULONG rul_WMBn_D47;                          /**< Wake Up Message Buffer Register Data 4-7, array offset: 0xB4C, array step: 0x10 */
} ras_WMB[CAN_WMB_COUNT];
  T_UBYTE raub_RESERVED_8[128];
  T_ULONG rul_FDCTRL;                            /**< CAN FD Control Register, offset: 0xC00 */
  T_ULONG rul_FDCBT;                             /**< CAN FD Bit Timing Register, offset: 0xC04 */
  T_ULONG rul_FDCRC;                             /**< CAN FD CRC Register, offset: 0xC08 */
} S_CAN_Type;

/* MCR Bit Fields */
#define CAN_MCR_FRZACK_MASK                      0x1000000u
#define CAN_MCR_FRZACK_SHIFT                     24u
#define CAN_MCR_MDIS_MASK                        0x80000000u
#define CAN_CTRL1_CLKSRC_MASK                    0x2000u
#define CAN_MCR_NOTRDY_MASK                      0x8000000u
#define CAN_MCR_NOTRDY_SHIFT                     27u

/** Peripheral CAN base pointer */
#define rps_CAN0 ((S_CAN_Type *)CAN0_BASE_ADDRESS)
#define rps_CAN1 ((S_CAN_Type *)CAN1_BASE_ADDRESS)
#define rps_CAN2 ((S_CAN_Type *)CAN2_BASE_ADDRESS)

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void FLEXCAN0_init(void);


#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
