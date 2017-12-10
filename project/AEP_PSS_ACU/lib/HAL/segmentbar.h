/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: 10_segment_bar.h $
 * $Revision: version 4 $
 * $Author: Habib Apez $
 * $Date: 2017-11-16 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \10_segment_bar.h
   Header file for 10_segment_bar module. Located at HAL.
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
/* Estefania López     |          2         |   Naming conventions            */
/*                     |                    |   and MISRA checked             */
/* Habib Apez          |          3         |   Function descriptions added   */
/* Habib Apez          |          4         |   More functions added   */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: segmentbar.h  $
  ============================================================================*/
#ifndef __SEGMENTBAR_H
#define __SEGMENTBAR_H

/* Includes */
/*============================================================================*/
    
/* Constants and types */
/*============================================================================*/
#define PTA9 9		/* Port PTA9, bit 9: Top window segment output W[9] */
#define PTA8 8		/* Port PTA8, bit 8: window segment output W[8] */
#define PTE12 12	/* Port PTE12, bit 12: window segment output W[7] */
#define PTD17 17	/* Port PTD17, bit 17: window segment output W[6] */
#define PTC9 9		/* Port PTC9, bit 9: window segment output W[5] */
#define PTC8 8		/* Port PTC8, bit 8: window segment output W[4] */
#define PTD8 8		/* Port PTD8, bit 8: window segment output W[3] */
#define PTD9 9		/* Port PTD9, bit 9: window segment output W[2] */
#define PTD2 2		/* Port PTD2, bit 2: window segment output W[1] */
#define PTD3 3		/* Port PTD3, bit 3: Bottom window segment output W[0] */
    
/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void segmentbar_InitBar(void);
void segmentbar_SetLevelBar(T_UBYTE lub_level, T_UBYTE lub_UpFlagInd,T_UBYTE lub_DownFlagInd);

void segmentbar_TurnOnSeg0(void);
void segmentbar_TurnOffSeg0(void);
void segmentbar_TurnOnSeg1(void);
void segmentbar_TurnOffSeg1(void);
void segmentbar_TurnOnSeg2(void);
void segmentbar_TurnOffSeg2(void);
void segmentbar_TurnOnSeg3(void);
void segmentbar_TurnOffSeg3(void);
void segmentbar_TurnOnSeg4(void);
void segmentbar_TurnOffSeg4(void);
void segmentbar_TurnOnSeg5(void);
void segmentbar_TurnOffSeg5(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
