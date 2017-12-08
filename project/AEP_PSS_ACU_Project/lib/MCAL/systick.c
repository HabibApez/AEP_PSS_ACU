/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: systick.c $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-11-15 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \systick.c
    systick module file for SK32144 uC. Located at SERVICES.
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
 * $Log: systick.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
# include "systick.h"

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/
/** Pointers to S_SYSTICK */
S_SYSTICK *rps_SYSTICK = SYSTICK_Address;

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/* Exported functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : InitSysTick
 *  Description          : Initializes System Tick Counter
 *  Parameters           : [T_ULONG lul_Value]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void systick_InitSysTick(T_ULONG lul_Value){
  systick_ReloadSysTickValue(lul_Value);
  rps_SYSTICK->rul_CVR = 0;
  rps_SYSTICK->rul_CSR = 6;                         /* Core Clock and interrupt enabled */
}

/**************************************************************
 *  Name                 : systick_EnableSysTick
 *  Description          : Enables counter
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void systick_EnableSysTick(void){
  rps_SYSTICK->rul_CSR |= 1;
}

/**************************************************************
 *  Name                 : systick_DisableSysTick
 *  Description          : Disables counter
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void systick_DisableSysTick(void){
  rps_SYSTICK->rul_CSR &= ~1;
}

/**************************************************************
 *  Name                 : ReloadSysTickValue
 *  Description          : Initializes System Tick Counter
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void systick_ReloadSysTickValue(T_ULONG lul_Value){ 
  rps_SYSTICK->rul_RVR = lul_Value;               /* TOSC = 1/FOSC = 1/80Mhz = 12.5us*/          
                                                  /* TickTime = Value * TOSC = Value * 12.5us */   
                                                  /* Value = TickTime / 12.5us = 781.25us / 12.5us = 62.5 */          
                                                  /* 24-bit register max_value = (2^21)-1 = 16777215 */
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
