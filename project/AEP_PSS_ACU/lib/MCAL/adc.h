/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: adc.h $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-12-07 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \adc.h
    Header file for adc module. Located at MCAL.
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
 * $Log: adc.h  $
  ============================================================================*/
#ifndef __ADC_H
#define __ADC_H

/* Includes */
/*============================================================================*/
//#include "MCAL\pcc.c"

/* Constants and types */
/*============================================================================*/
/** ADC - Size of Registers Arrays */
#define ADC_SC1_COUNT                     	16
#define ADC_R_COUNT        					16
#define ADC_CV_COUNT                		2

/** ADC - Register Layout Typedef */
typedef struct {
  T_ULONG rul_SC1[ADC_SC1_COUNT];                /**< ADC Status and Control Register 1, array offset: 0x0, array step: 0x4 */
  T_ULONG rul_CFG1;                              /**< ADC Configuration Register 1, offset: 0x40 */
  T_ULONG rul_CFG2;                              /**< ADC Configuration Register 2, offset: 0x44 */
  T_ULONG rul_R[ADC_R_COUNT];                    /**< ADC Data Result Registers, array offset: 0x48, array step: 0x4 */
  T_ULONG rul_CV[ADC_CV_COUNT];                  /**< Compare Value Registers, array offset: 0x88, array step: 0x4 */
  T_ULONG rul_SC2;                               /**< Status and Control Register 2, offset: 0x90 */
  T_ULONG rul_SC3;                               /**< Status and Control Register 3, offset: 0x94 */
  T_ULONG rul_BASE_OFS;                          /**< BASE Offset Register, offset: 0x98 */
  T_ULONG rul_OFS;                               /**< ADC Offset Correction Register, offset: 0x9C */
  T_ULONG rul_USR_OFS;                           /**< USER Offset Correction Register, offset: 0xA0 */
  T_ULONG rul_XOFS;                              /**< ADC X Offset Correction Register, offset: 0xA4 */
  T_ULONG rul_YOFS;                              /**< ADC Y Offset Correction Register, offset: 0xA8 */
  T_ULONG rul_G;                                 /**< ADC Gain Register, offset: 0xAC */
  T_ULONG rul_UG;                                /**< ADC User Gain Register, offset: 0xB0 */
  T_ULONG rul_CLPS;                              /**< ADC General Calibration Value Register S, offset: 0xB4 */
  T_ULONG rul_CLP3;                              /**< ADC Plus-Side General Calibration Value Register 3, offset: 0xB8 */
  T_ULONG rul_CLP2;                              /**< ADC Plus-Side General Calibration Value Register 2, offset: 0xBC */
  T_ULONG rul_CLP1;                              /**< ADC Plus-Side General Calibration Value Register 1, offset: 0xC0 */
  T_ULONG rul_CLP0;                              /**< ADC Plus-Side General Calibration Value Register 0, offset: 0xC4 */
  T_ULONG rul_CLPX;                              /**< ADC Plus-Side General Calibration Value Register X, offset: 0xC8 */
  T_ULONG rul_CLP9;                              /**< ADC Plus-Side General Calibration Value Register 9, offset: 0xCC */
  T_ULONG rul_CLPS_OFS;                          /**< ADC General Calibration Offset Value Register S, offset: 0xD0 */
  T_ULONG rul_CLP3_OFS;                          /**< ADC Plus-Side General Calibration Offset Value Register 3, offset: 0xD4 */
  T_ULONG rul_CLP2_OFS;                          /**< ADC Plus-Side General Calibration Offset Value Register 2, offset: 0xD8 */
  T_ULONG rul_CLP1_OFS;                          /**< ADC Plus-Side General Calibration Offset Value Register 1, offset: 0xDC */
  T_ULONG rul_CLP0_OFS;                          /**< ADC Plus-Side General Calibration Offset Value Register 0, offset: 0xE0 */
  T_ULONG rul_CLPX_OFS;                          /**< ADC Plus-Side General Calibration Offset Value Register X, offset: 0xE4 */
  T_ULONG rul_CLP9_OFS;                          /**< ADC Plus-Side General Calibration Offset Value Register 9, offset: 0xE8 */
} S_ADC;


/** Peripheral ADC base addresses */
#define ADC0_BASE_ADDRESS      0x4003B000
#define ADC1_BASE_ADDRESS      0x40027000

/** Peripheral PTx base pointers*/
#define ADC0_Address ((S_ADC *)ADC0_BASE_ADDRESS)
#define ADC1_Address ((S_ADC *)ADC1_BASE_ADDRESS)

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void adc_InitADC();
T_ULONG adc_ReadADCChannel(S_ADC *lps_ADC, T_UBYTE lub_ADCH);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
