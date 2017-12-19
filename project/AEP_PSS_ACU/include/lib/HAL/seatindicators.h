/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: seatindicators.h $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-12-18  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \seatindicators
    Header file for seatindicators module. Located at HAL.
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
 * $Log: seatindicators.h  $
  ============================================================================*/
#ifndef __SEATINDICATORS_H
#define __SEATINDICATORS_H

/* Includes */
/*============================================================================*/
#include "MCAL\io.h"
#include "MCAL\port.h"

/* Constants and types */
/*============================================================================*/
#define DRIVER_SBS_UP_FAULTY_PIN 		12	/* Port PTD12, Seat Belt Driver UP FAULTY led */
#define DRIVER_SBS_BUCLKED_PIN 			11	/* Port PTD11, Seat Belt Driver BUCLKED led */
#define DRIVER_SBS_UNDETERMINED_PIN 	10	/* Port PTD10, Seat Belt Driver UNDETERMINED led */
#define DRIVER_SBS_UNBUCKLED_PIN 		17	/* Port PTA7,  Seat Belt Driver UNBUCKLEDUP_FAULTY led */
#define DRIVER_SBS_DOWN_FAULTY_PIN 		3	/* Port PTE3,  Seat Belt Driver DOWN_FAULTY led */

#define PASSENG_SBS_UP_FAULTY_PIN 		3	/* Port PTD3,  Passenger Seat Belt Sensor Passenger UP FAULTY led */
#define PASSENG_SBS_BUCLKED_PIN 		5	/* Port PTD5,  Passenger Seat Belt Sensor BUCLKED led */
#define PASSENG_SBS_UNDETERMINED_PIN 	11	/* Port PTC11, Passenger Seat Belt Sensor UNDETERMINED led */
#define PASSENG_SBS_UNBUCKLED_PIN 		10	/* Port PTC10, Passenger Seat Belt Sensor UNBUCKLEDUP_FAULTY led */
#define PASSENG_SBS_DOWN_FAULTY_PIN 	11	/* Port PTB11, Passenger Seat Belt Sensor DOWN_FAULTY led */

#define PASSENG_OS_UP_FAULTY_PIN 		10	/* Port PTB10, Passenger Occupancy Sensor UP FAULTY led */
#define PASSENG_OS_UNOCCUPIED_PIN 		9	/* Port PTB9,  Passenger Occupancy Sensor BUCLKED led */
#define PASSENG_OS_UNDETERMINED_PIN 	8	/* Port PTB8,  Passenger Occupancy Sensor UNDETERMINED led */
#define PASSENG_OS_OCCUPIED_PIN 		3	/* Port PTA3,  Passenger Occupancy Sensor UNBUCKLEDUP_FAULTY led */
#define PASSENG_OS_DOWN_FAULTY_PIN 		2	/* Port PTA2,  Passenger Occupancy Sensor DOWN_FAULTY led */


/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void seatindicators_InitIndicators(void);

void seatindicators_TurnOnIndicator(S_GPIO *lps_IndicatorPort, T_ULONG lub_IndicatorPin);
void seatindicators_TurnOffIndicator(S_GPIO *lps_IndicatorPort, T_ULONG lub_IndicatorPin);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
