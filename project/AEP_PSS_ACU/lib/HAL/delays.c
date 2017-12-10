/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: delays.c $
 * $Revision: version 2 $
 * $Author: Habib Apez $
 * $Date: 2017-11-16 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \delays.c
    delays module file. Located at HAL.
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
/* Habib Apez          |          2         |   More delays added             */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: delays.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "delays.h"

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
 *  Name                 : delays_InitTimer
 *  Description          : Intialises LPIT0
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void delays_InitTimer(void){
  lpit_EnableLPITO();
}

/**************************************************************
 *  Name                 : delays_Wait1ms
 *  Description          : Waits 500us
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void delays_Wait500us(void){
  lpit_ChargeLPITOCh0(20000);
  lpit_EnableLPIT0Ch0();
  while(0 == lpit_ChecklFlagLPIT0Ch0());
  lpit_ClearFlagLPIT0Ch0();
  lpit_DisableLPIT0Ch0();
}

/**************************************************************
 *  Name                 : delays_Wait1ms
 *  Description          : Waits 1ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void delays_Wait1ms(void){
  lpit_ChargeLPITOCh0(40000);
  lpit_EnableLPIT0Ch0();
  while(0 == lpit_ChecklFlagLPIT0Ch0());
  lpit_ClearFlagLPIT0Ch0();
  lpit_DisableLPIT0Ch0();
}

/**************************************************************
 *  Name                 : delays_Wait10ms
 *  Description          : Waits 10ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void delays_Wait10ms(void){
  lpit_ChargeLPITOCh0(400000);
  lpit_EnableLPIT0Ch0();
  while(0 == lpit_ChecklFlagLPIT0Ch0());
  lpit_ClearFlagLPIT0Ch0();
  lpit_DisableLPIT0Ch0();
}

/**************************************************************
 *  Name                 : delays_Wait40ms
 *  Description          : Waits 40ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void delays_Wait40ms(void){
  lpit_ChargeLPITOCh0(1600000);
  lpit_EnableLPIT0Ch0();
  while(0 == lpit_ChecklFlagLPIT0Ch0());
  lpit_ClearFlagLPIT0Ch0();
  lpit_DisableLPIT0Ch0();
}

/**************************************************************
 *  Name                 : delays_Wait50ms
 *  Description          : Waits 50ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void delays_Wait50ms(void){
  lpit_ChargeLPITOCh0(2000000);
  lpit_EnableLPIT0Ch0();
  while(0 == lpit_ChecklFlagLPIT0Ch0());
  lpit_ClearFlagLPIT0Ch0();
  lpit_DisableLPIT0Ch0();
}

/**************************************************************
 *  Name                 : delays_Wait400ms
 *  Description          : Waits 400ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void delays_Wait400ms(void){
  lpit_ChargeLPITOCh0(16000000);
  lpit_EnableLPIT0Ch0();
  while(0 == lpit_ChecklFlagLPIT0Ch0());
  lpit_ClearFlagLPIT0Ch0();
  lpit_DisableLPIT0Ch0();
}

/**************************************************************
 *  Name                 : delays_Wait490ms
 *  Description          : Waits 490ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void delays_Wait490ms(void){
  delays_Wait400ms();
  delays_Wait50ms();
  delays_Wait40ms();
}

/**************************************************************
 *  Name                 : delays_Wait5ms
 *  Description          : Waits 5ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void delays_Wait5s(void){
  lpit_ChargeLPITOCh0(200000000);
  lpit_EnableLPIT0Ch0();
  while(0 == lpit_ChecklFlagLPIT0Ch0());
  lpit_ClearFlagLPIT0Ch0();
  lpit_DisableLPIT0Ch0();
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
