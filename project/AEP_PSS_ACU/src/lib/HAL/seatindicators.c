/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: seatindicator.c $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-12-18 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \seatindicators.c
    seatindicators module file for SK32144 uC. Located at MCAL.
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
 * $Log: seatindicators.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "HAL\seatindicators.h"
#include "MCAL\pcc.h"

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
 *  Name                 : seatindicators_InitIndicators
 *  Description          : Configures the 15 outputs for the indicators
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void seatindicators_InitIndicators(void){
  pcc_EnablePeripheralClock(PCC_PORTA_INDEX);
  pcc_EnablePeripheralClock(PCC_PORTB_INDEX);
  pcc_EnablePeripheralClock(PCC_PORTC_INDEX);
  pcc_EnablePeripheralClock(PCC_PORTD_INDEX);
  pcc_EnablePeripheralClock(PCC_PORTE_INDEX);

  io_OutputPin(rps_PTD, 1<<DRIVER_SBS_UP_FAULTY_PIN);          				/* LED */
  port_ConfigurePinMode(rps_PORTD, DRIVER_SBS_UP_FAULTY_PIN, 0x00000100);  	/* MUX = GPIO */
  io_OutputPin(rps_PTD, 1<<DRIVER_SBS_BUCLKED_PIN);          				/* LED */
  port_ConfigurePinMode(rps_PORTD, DRIVER_SBS_BUCLKED_PIN, 0x00000100);  	/* MUX = GPIO */
  io_OutputPin(rps_PTD, 1<<DRIVER_SBS_UNDETERMINED_PIN);          			/* LED */
  port_ConfigurePinMode(rps_PORTD, DRIVER_SBS_UNDETERMINED_PIN, 0x00000100);/* MUX = GPIO */
  io_OutputPin(rps_PTA, 1<<DRIVER_SBS_UNBUCKLED_PIN);           			/* LED */
  port_ConfigurePinMode(rps_PORTA, DRIVER_SBS_UNBUCKLED_PIN, 0x00000100);  	/* MUX = GPIO */
  io_OutputPin(rps_PTE, 1<<DRIVER_SBS_DOWN_FAULTY_PIN);          			/* LED */
  port_ConfigurePinMode(rps_PORTE, DRIVER_SBS_DOWN_FAULTY_PIN, 0x00000100); /* MUX = GPIO */

  io_OutputPin(rps_PTD, 1<<PASSENG_SBS_UP_FAULTY_PIN);          			/* LED */
  port_ConfigurePinMode(rps_PORTD, PASSENG_SBS_UP_FAULTY_PIN, 0x00000100);  /* MUX = GPIO */
  io_OutputPin(rps_PTD, 1<<PASSENG_SBS_BUCLKED_PIN);          				/* LED */
  port_ConfigurePinMode(rps_PORTD, PASSENG_SBS_BUCLKED_PIN, 0x00000100);  	/* MUX = GPIO */
  io_OutputPin(rps_PTC, 1<<PASSENG_SBS_UNDETERMINED_PIN);          			/* LED */
  port_ConfigurePinMode(rps_PORTC, PASSENG_SBS_UNDETERMINED_PIN, 0x00000100); /* MUX = GPIO */
  io_OutputPin(rps_PTC, 1<<PASSENG_SBS_UNBUCKLED_PIN);          			/* LED */
  port_ConfigurePinMode(rps_PORTC, PASSENG_SBS_UNBUCKLED_PIN, 0x00000100);  /* MUX = GPIO */
  io_OutputPin(rps_PTB, 1<<PASSENG_SBS_DOWN_FAULTY_PIN);          			/* LED*/
  port_ConfigurePinMode(rps_PORTB, PASSENG_SBS_DOWN_FAULTY_PIN, 0x00000100); /* MUX = GPIO */

  io_OutputPin(rps_PTB, 1<<PASSENG_OS_UP_FAULTY_PIN);          				/* LED */
  port_ConfigurePinMode(rps_PORTB, PASSENG_OS_UP_FAULTY_PIN, 0x00000100);  	/* MUX = GPIO */
  io_OutputPin(rps_PTB, 1<<PASSENG_OS_UNOCCUPIED_PIN);          			/* LED */
  port_ConfigurePinMode(rps_PORTB, PASSENG_OS_UNOCCUPIED_PIN, 0x00000100);  /* MUX = GPIO */
  io_OutputPin(rps_PTB, 1<<PASSENG_OS_UNDETERMINED_PIN);          			/* LED */
  port_ConfigurePinMode(rps_PORTB, PASSENG_OS_UNDETERMINED_PIN, 0x00000100);/* MUX = GPIO */
  io_OutputPin(rps_PTA, 1<<PASSENG_OS_OCCUPIED_PIN);           				/* LED */
  port_ConfigurePinMode(rps_PORTA, PASSENG_OS_OCCUPIED_PIN, 0x00000100);  	/* MUX = GPIO */
  io_OutputPin(rps_PTA, 1<<PASSENG_OS_DOWN_FAULTY_PIN);          			/* LED */
  port_ConfigurePinMode(rps_PORTA, PASSENG_OS_DOWN_FAULTY_PIN, 0x00000100); /* MUX = GPIO */
}

/**************************************************************
 *  Name                 : seatindicators_TurnOnIndicator
 *  Description          : Turns on an indicator
 *  Parameters           : [S_GPIO *lps_IndicatorPort, T_ULONG lub_IndicatorPin]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void seatindicators_TurnOnIndicator(S_GPIO *lps_IndicatorPort, T_ULONG lub_IndicatorPin){
  io_SetOutput(lps_IndicatorPort, lub_IndicatorPin);
}

/**************************************************************
 *  Name                 : seatindicators_TurnOffIndicator
 *  Description          : Turns off an indicator
 *  Parameters           : [S_GPIO *lps_IndicatorPort, T_ULONG lub_IndicatorPin]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void seatindicators_TurnOffIndicator(S_GPIO *lps_IndicatorPort, T_ULONG lub_IndicatorPin){
  io_ClearOutput(lps_IndicatorPort, lub_IndicatorPin);
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
