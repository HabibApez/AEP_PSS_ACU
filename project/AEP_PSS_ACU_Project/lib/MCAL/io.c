/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: io.c $
 * $Revision: version 4 $
 * $Author: Habib Apez $
 * $Date: 2017-11-08 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \io.c
    io module file for SK32144 uC. Located at MCAL.
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
/* Habib Apez          |          2         |   Naming conventions            */
/*                     |                    |   and MISRA checked             */
/* Habib Apez          |          3         |   Minior changes                */
/* Habib Apez          |          4         |   Function descriptions added   */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: io.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
# include "io.h"

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/
/** Pointers to S_GPIO */
S_GPIO *rps_PTA = PTA_Address;
S_GPIO *rps_PTB = PTB_Address;
S_GPIO *rps_PTC = PTC_Address;
S_GPIO *rps_PTD = PTD_Address;
S_GPIO *rps_PTE = PTE_Address;

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/* Exported functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : io_InputPin
 *  Description          : Configures a pin as an input
 *  Parameters           : [S_GPIO *lps_Port, T_ULONG lul_Pin]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void io_InputPin(S_GPIO *lps_Port, T_ULONG lul_Pin){
  lps_Port->rul_PDDR &= ~(lul_Pin);
}

/**************************************************************
 *  Name                 : io_OutputPin
 *  Description          : Configures a pin as an output
 *  Parameters           : [S_GPIO *lps_Port, T_ULONG lul_Pin]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void io_OutputPin(S_GPIO *lps_Port, T_ULONG lul_Pin){
  lps_Port->rul_PDDR |= lul_Pin;
}

/**************************************************************
 *  Name                 : io_TooglePin
 *  Description          : Toggles an output pin
 *  Parameters           : [S_GPIO *lps_Port, T_ULONG lul_Pin]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void io_TogglePin(S_GPIO *lps_Port, T_ULONG lul_Pin){
  lps_Port->rul_PTOR |= lul_Pin;
}

/**************************************************************
 *  Name                 : io_SetOutput
 *  Description          : Sets an output pin
 *  Parameters           : [S_GPIO *lps_Port, T_ULONG lul_Pin]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void io_SetOutput(S_GPIO *lps_Port, T_ULONG lul_Pin){
  lps_Port->rul_PSOR |= lul_Pin;
}

/**************************************************************
 *  Name                 : io_ClearOutput
 *  Description          : Clears an output pin 
 *  Parameters           : [S_GPIO *lps_Port, T_ULONG lul_Pin]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void io_ClearOutput(S_GPIO *lps_Port, T_ULONG lul_Pin){
  lps_Port->rul_PCOR |= lul_Pin;
}

/**************************************************************
 *  Name                 : io_GetPinData
 *  Description          : Gets data from an input pin 
 *  Parameters           : [S_GPIO *lps_Port, T_UBYTE lul_Pin]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE io_GetPinData(S_GPIO *lps_Port, T_UBYTE lul_Pin){
  if((lps_Port->rul_PDIR) & (1<<lul_Pin))
    return 1;
  else 
    return 0;
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
