/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: remindercommon.c $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-12-17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \remindercommon.c
    state machine for the passenger reminder. Located at APP.
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
/* Habib Apez          |          1         |   Initial version               */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: remindercommon.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "APP\remindercommon.h"
#include "Common\Std_Types.h"

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
 *  Name                 : remindercommon_GetSoundTone
 *  Description          : Gets the Sound Tone
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE remindercommon_GetSoundTone(void){
  return rps_Chime->rub_SoundTone;
}

/**************************************************************
 *  Name                 : remindercommon_GetSoundCadence
 *  Description          : Gets the Sound Cadence
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE remindercommon_GetSoundCadence(void){
  return rps_Chime->rub_Cadence;
}

/**************************************************************
 *  Name                 : remindercommon_GetSoundRepetitions
 *  Description          : Gets the Sound Repetitions
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE remindercommon_GetSoundRepetitions(void){
  return rps_Chime->rub_Repetitions;
}

/**************************************************************
 *  Name                 : remindercommon_GetSoundDutyCycle
 *  Description          : Gets the Sound Duty Cycle
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE remindercommon_GetSoundDutyCycle(void){
  return rps_Chime->rub_DutyCycle;
}

/* Notice: the file ends with a blank new line to avoid compiler warnings */
