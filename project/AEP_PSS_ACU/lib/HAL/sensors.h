/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: sensors.h $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-12-07  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \sensors.h
    Header file for sensors module. Located at HAL.
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
 * $Log: button.h  $
  ============================================================================*/
#ifndef __SENSORS_H
#define __SENSORS_H

/* Includes */
/*============================================================================*/
#include "MCAL\adc.c"

/* Constants and types */
/*============================================================================*/
#define DRIVER_SEAT_BELT_SENSOR		1	/* ADC Channel 1, PTA[1], Driver Seat Belt Sensor */
#define PASSENGER_SEAT_BELT_SENSOR	0	/* ADC Channel 0, PTA[0], Passenger Seat Belt Sensor */
#define PASSENGER_SEAT_SENSOR		3	/* ADC Channel 3, PTA[7], Passenger Seat Sensor */

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void sensor_InitSensors(void);
T_UWORD sensor_ReadDriverSeatBeltSensor(void);
T_UWORD sensor_ReadPassengerSeatBeltSensor(void);
T_UWORD sensor_ReadPassengerSeatSensor(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
