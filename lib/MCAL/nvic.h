/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: nvic.h $
 * $Revision: version 1$
 * $Author: Habib Apez $
 * $Date: 2017-10-23 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \nvic.h
    Header file for nvic module. Located at MCAL.
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
 * $Log: nvic.h  $
  ============================================================================*/
#ifndef __NVIC_H
#define __NVIC_H

/* Includes */
/*============================================================================*/

/* Constants and types */
/*============================================================================*/
/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers for S32K144
   ---------------------------------------------------------------------------- */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 139u               /**< Number of interrupts in the Vector table */


/** NVIC base addresses */
#define NVIC_BASE_ADDRESS      0xE000E100

/** NVIC - Size of Registers Arrays */
#define NVIC_ISER_COUNT                      4u
#define NVIC_ICER_COUNT                      4u
#define NVIC_ISPR_COUNT                      4u
#define NVIC_ICPR_COUNT                      4u
#define NVIC_IABR_COUNT                      4u
#define NVIC_IP_COUNT                        123u
   
/** NVIC - Register Layout Typedef */
typedef struct {
  T_ULONG rul_ISER[NVIC_ISER_COUNT];         /**< Interrupt Set Enable Register n, array offset: 0x0, array step: 0x4 */
  T_UBYTE rub_RESERVED_0[112];
  T_ULONG rul_ICER[NVIC_ICER_COUNT];         /**< Interrupt Clear Enable Register n, array offset: 0x80, array step: 0x4 */
  T_UBYTE rub_RESERVED_1[112];
  T_ULONG rul_ISPR[NVIC_ISPR_COUNT];         /**< Interrupt Set Pending Register n, array offset: 0x100, array step: 0x4 */
  T_UBYTE rub_RESERVED_2[112];
  T_ULONG rul_ICPR[NVIC_ICPR_COUNT];         /**< Interrupt Clear Pending Register n, array offset: 0x180, array step: 0x4 */
  T_UBYTE rub_RESERVED_3[112];
  T_ULONG rul_IABR[NVIC_IABR_COUNT];         /**< Interrupt Active bit Register n, array offset: 0x200, array step: 0x4 */
  T_UBYTE rub_RESERVED_4[240];
  T_ULONG rul_IP[NVIC_IP_COUNT];             /**< Interrupt Priority Register n, array offset: 0x300, array step: 0x1 */
} S_NVIC;

/** NVIC base pointers*/
#define NVIC_Address ((S_NVIC *)NVIC_BASE_ADDRESS)

/**
 * @brief Defines the Interrupt Numbers definitions
 *
 * This enumeration is used to configure the interrupts.
 *
 * Implements : IRQn_Type_Class
 */
typedef enum
{
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M4 SV Hard Fault Interrupt */
  MemoryManagement_IRQn        = -12,              /**< Cortex-M4 Memory Management Interrupt */
  BusFault_IRQn                = -11,              /**< Cortex-M4 Bus Fault Interrupt */
  UsageFault_IRQn              = -10,              /**< Cortex-M4 Usage Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M4 SV Call Interrupt */
  DebugMonitor_IRQn            = -4,               /**< Cortex-M4 Debug Monitor Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M4 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M4 System Tick Interrupt */

  /* Device specific interrupts */
  DMA0_IRQn                    = 0u,               /**< DMA channel 0 transfer complete */
  DMA1_IRQn                    = 1u,               /**< DMA channel 1 transfer complete */
  DMA2_IRQn                    = 2u,               /**< DMA channel 2 transfer complete */
  DMA3_IRQn                    = 3u,               /**< DMA channel 3 transfer complete */
  DMA4_IRQn                    = 4u,               /**< DMA channel 4 transfer complete */
  DMA5_IRQn                    = 5u,               /**< DMA channel 5 transfer complete */
  DMA6_IRQn                    = 6u,               /**< DMA channel 6 transfer complete */
  DMA7_IRQn                    = 7u,               /**< DMA channel 7 transfer complete */
  DMA8_IRQn                    = 8u,               /**< DMA channel 8 transfer complete */
  DMA9_IRQn                    = 9u,               /**< DMA channel 9 transfer complete */
  DMA10_IRQn                   = 10u,              /**< DMA channel 10 transfer complete */
  DMA11_IRQn                   = 11u,              /**< DMA channel 11 transfer complete */
  DMA12_IRQn                   = 12u,              /**< DMA channel 12 transfer complete */
  DMA13_IRQn                   = 13u,              /**< DMA channel 13 transfer complete */
  DMA14_IRQn                   = 14u,              /**< DMA channel 14 transfer complete */
  DMA15_IRQn                   = 15u,              /**< DMA channel 15 transfer complete */
  DMA_Error_IRQn               = 16u,              /**< DMA error interrupt channels 0-15 */
  MCM_IRQn                     = 17u,              /**< FPU sources */
  FTFC_IRQn                    = 18u,              /**< FTFC Command complete */
  Read_Collision_IRQn          = 19u,              /**< FTFC Read collision */
  LVD_LVW_IRQn                 = 20u,              /**< PMC Low voltage detect interrupt */
  FTFC_Fault_IRQn              = 21u,              /**< FTFC Double bit fault detect */
  WDOG_EWM_IRQn                = 22u,              /**< Single interrupt vector for WDOG and EWM */
  RCM_IRQn                     = 23u,              /**< RCM Asynchronous Interrupt */
  LPI2C0_Master_IRQn           = 24u,              /**< LPI2C0 Master Interrupt */
  LPI2C0_Slave_IRQn            = 25u,              /**< LPI2C0 Slave Interrupt */
  LPSPI0_IRQn                  = 26u,              /**< LPSPI0 Interrupt */
  LPSPI1_IRQn                  = 27u,              /**< LPSPI1 Interrupt */
  LPSPI2_IRQn                  = 28u,              /**< LPSPI2 Interrupt */
  LPUART0_RxTx_IRQn            = 31u,              /**< LPUART0 Transmit / Receive Interrupt */
  LPUART1_RxTx_IRQn            = 33u,              /**< LPUART1 Transmit / Receive  Interrupt */
  LPUART2_RxTx_IRQn            = 35u,              /**< LPUART2 Transmit / Receive  Interrupt */
  ADC0_IRQn                    = 39u,              /**< ADC0 interrupt request. */
  ADC1_IRQn                    = 40u,              /**< ADC1 interrupt request. */
  CMP0_IRQn                    = 41u,              /**< CMP0 interrupt request */
  ERM_single_fault_IRQn        = 44u,              /**< ERM single bit error correction */
  ERM_double_fault_IRQn        = 45u,              /**< ERM double bit error non-correctable */
  RTC_IRQn                     = 46u,              /**< RTC alarm interrupt */
  RTC_Seconds_IRQn             = 47u,              /**< RTC seconds interrupt */
  LPIT0_Ch0_IRQn               = 48u,              /**< LPIT0 channel 0 overflow interrupt */
  LPIT0_Ch1_IRQn               = 49u,              /**< LPIT0 channel 1 overflow interrupt */
  LPIT0_Ch2_IRQn               = 50u,              /**< LPIT0 channel 2 overflow interrupt */
  LPIT0_Ch3_IRQn               = 51u,              /**< LPIT0 channel 3 overflow interrupt */
  PDB0_IRQn                    = 52u,              /**< PDB0 interrupt */
  SCG_IRQn                     = 57u,              /**< SCG bus interrupt request */
  LPTMR0_IRQn                  = 58u,              /**< LPTIMER interrupt request */
  PORTA_IRQn                   = 59u,              /**< Port A pin detect interrupt */
  PORTB_IRQn                   = 60u,              /**< Port B pin detect interrupt */
  PORTC_IRQn                   = 61u,              /**< Port C pin detect interrupt */
  PORTD_IRQn                   = 62u,              /**< Port D pin detect interrupt */
  PORTE_IRQn                   = 63u,              /**< Port E pin detect interrupt */
  SWI_IRQn                     = 64u,              /**< Software interrupt */
  PDB1_IRQn                    = 68u,              /**< PDB1 interrupt */
  FLEXIO_IRQn                  = 69u,              /**< FlexIO Interrupt */
  CAN0_ORed_IRQn               = 78u,              /**< CAN0 OR'ed [Bus Off OR Transmit Warning OR Receive Warning] */
  CAN0_Error_IRQn              = 79u,              /**< CAN0 Interrupt indicating that errors were detected on the CAN bus */
  CAN0_Wake_Up_IRQn            = 80u,              /**< CAN0 Interrupt asserted when Pretended Networking operation is enabled, and a valid message matches the selected filter criteria during Low Power mode */
  CAN0_ORed_0_15_MB_IRQn       = 81u,              /**< CAN0 OR'ed Message buffer (0-15) */
  CAN0_ORed_16_31_MB_IRQn      = 82u,              /**< CAN0 OR'ed Message buffer (16-31) */
  CAN1_ORed_IRQn               = 85u,              /**< CAN1 OR'ed [Bus Off OR Transmit Warning OR Receive Warning] */
  CAN1_Error_IRQn              = 86u,              /**< CAN1 Interrupt indicating that errors were detected on the CAN bus */
  CAN1_ORed_0_15_MB_IRQn       = 88u,              /**< CAN1 OR'ed Interrupt for Message buffer (0-15) */
  CAN2_ORed_IRQn               = 92u,              /**< CAN2 OR'ed [Bus Off OR Transmit Warning OR Receive Warning] */
  CAN2_Error_IRQn              = 93u,              /**< CAN2 Interrupt indicating that errors were detected on the CAN bus */
  CAN2_ORed_0_15_MB_IRQn       = 95u,              /**< CAN2 OR'ed Message buffer (0-15) */
  FTM0_Ch0_Ch1_IRQn            = 99u,              /**< FTM0 Channel 0 and 1 interrupt */
  FTM0_Ch2_Ch3_IRQn            = 100u,             /**< FTM0 Channel 2 and 3 interrupt */
  FTM0_Ch4_Ch5_IRQn            = 101u,             /**< FTM0 Channel 4 and 5 interrupt */
  FTM0_Ch6_Ch7_IRQn            = 102u,             /**< FTM0 Channel 6 and 7 interrupt */
  FTM0_Fault_IRQn              = 103u,             /**< FTM0 Fault interrupt */
  FTM0_Ovf_Reload_IRQn         = 104u,             /**< FTM0 Counter overflow and Reload interrupt */
  FTM1_Ch0_Ch1_IRQn            = 105u,             /**< FTM1 Channel 0 and 1 interrupt */
  FTM1_Ch2_Ch3_IRQn            = 106u,             /**< FTM1 Channel 2 and 3 interrupt */
  FTM1_Ch4_Ch5_IRQn            = 107u,             /**< FTM1 Channel 4 and 5 interrupt */
  FTM1_Ch6_Ch7_IRQn            = 108u,             /**< FTM1 Channel 6 and 7 interrupt */
  FTM1_Fault_IRQn              = 109u,             /**< FTM1 Fault interrupt */
  FTM1_Ovf_Reload_IRQn         = 110u,             /**< FTM1 Counter overflow and Reload interrupt */
  FTM2_Ch0_Ch1_IRQn            = 111u,             /**< FTM2 Channel 0 and 1 interrupt */
  FTM2_Ch2_Ch3_IRQn            = 112u,             /**< FTM2 Channel 2 and 3 interrupt */
  FTM2_Ch4_Ch5_IRQn            = 113u,             /**< FTM2 Channel 4 and 5 interrupt */
  FTM2_Ch6_Ch7_IRQn            = 114u,             /**< FTM2 Channel 6 and 7 interrupt */
  FTM2_Fault_IRQn              = 115u,             /**< FTM2 Fault interrupt */
  FTM2_Ovf_Reload_IRQn         = 116u,             /**< FTM2 Counter overflow and Reload interrupt */
  FTM3_Ch0_Ch1_IRQn            = 117u,             /**< FTM3 Channel 0 and 1 interrupt */
  FTM3_Ch2_Ch3_IRQn            = 118u,             /**< FTM3 Channel 2 and 3 interrupt */
  FTM3_Ch4_Ch5_IRQn            = 119u,             /**< FTM3 Channel 4 and 5 interrupt */
  FTM3_Ch6_Ch7_IRQn            = 120u,             /**< FTM3 Channel 6 and 7 interrupt */
  FTM3_Fault_IRQn              = 121u,             /**< FTM3 Fault interrupt */
  FTM3_Ovf_Reload_IRQn         = 122u              /**< FTM3 Counter overflow and Reload interrupt */
} IRQn_Type;

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void nvic_EnableInterrupt(IRQn_Type lub_IRQn);
void nvic_DisableInterrupt(IRQn_Type lub_IRQn);
void nvic_SetPendingInterrupt(IRQn_Type lub_IRQn);
void nvic_ClearPendingInterrupt(IRQn_Type lub_IRQn);
T_UBYTE nvic_GetActiveInterrupt(IRQn_Type lub_IRQn);
void nvic_SetInterruptPriority(IRQn_Type lub_IRQn, T_UBYTE lub_Priority);
T_UBYTE nvic_GetInterruptPriority(IRQn_Type lub_IRQn);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
