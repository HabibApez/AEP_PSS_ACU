/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: interrupts.c $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-11-08 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \interrupts.c
    Interrupts module file for SK32144 uC. Located at HAL
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
 * $Log: interrupts.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
# include "interrupts.h"

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/

/* Private functions prototypes */
/*============================================================================*/
void interrupts_InitIRQ(IRQn_Type lub_IRQn, T_UBYTE lub_Priority);

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/* Exported functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : interrupts_InitIRQ
 *  Description          : Initializes a specific Interrupt
 *  Parameters           : [T_UBYTE lub_IRQn, T_UBYTE lub_Priority]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void interrupts_InitIRQ(IRQn_Type lub_IRQn, T_UBYTE lub_Priority){
  nvic_ClearPendingInterrupt(lub_IRQn);
  nvic_EnableInterrupt(lub_IRQn);
  nvic_SetInterruptPriority(lub_IRQn, lub_Priority);
} 

/**************************************************************
 *  Name                 : interrupts_ConfigSysTickIRQ
 *  Description          : Loads the reload value to the SysTick counter
 *  Parameters           : [T_ULONG lul_Value]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void interrupts_ConfigSysTickIRQ(T_ULONG lul_Value){
  systick_InitSysTick( lul_Value );    // Configure SysTick Clock
}

/**************************************************************
 *  Name                 : interrupts_EnableSysTickIRQ
 *  Description          : Enables the SysTickIRQ      
 *  Parameters           : [T_ULONG lul_Value]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void interrupts_EnableSysTickIRQ(void){
  systick_EnableSysTick();              // Enable interrupt 
}

/**************************************************************
 *  Name                 : interrupts_DisableSysTickIRQ
 *  Description          : Enables the SysTickIRQ      
 *  Parameters           : [T_ULONG lul_Value]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void interrupts_DisableSysTickIRQ(void){
  systick_DisableSysTick();              // Enable interrupt 
}


/**************************************************************
 *  Name                 : interrupts_InitPortsIRQs
 *  Description          : Initializes all Ports IRQ
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void interrupts_InitPortsIRQs(void){
  interrupts_InitIRQ(PORTC_IRQn, 0x0A);
}

/**************************************************************
 *  Name                 : interrupts_GetRightButtonIntFlag
 *  Description          : Gets the PORTC12 Flag status
 *  Parameters           : [void]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE interrupts_GetRightButtonIntFlag(void){
  return port_GetIntStatusFlag(rps_PORTC, PTC12);
}

/**************************************************************
 *  Name                 : interrupts_GetLeftButtonIntFlag
 *  Description          : Gets the PORTC13 Flag status
 *  Parameters           : [void]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE interrupts_GetLeftButtonIntFlag(void){
  return port_GetIntStatusFlag(rps_PORTC, PTC13);
}

/**************************************************************
 *  Name                 : interrupts_ClearRightButtonIntFlag
 *  Description          : Gets the PORTC12 Flag status
 *  Parameters           : [void]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
void interrupts_ClearRightButtonIntFlag(void){
  port_ClearIntStatusFlag(rps_PORTC, PTC12);
}

/**************************************************************
 *  Name                 : interrupts_ClearLeftButtonIntFlag
 *  Description          : Gets the PORTC13 Flag status
 *  Parameters           : [void]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
void interrupts_ClearLeftButtonIntFlag(void){
  port_ClearIntStatusFlag(rps_PORTC, PTC13);
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
