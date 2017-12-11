/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: sensorsm.h $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-12-08  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \sensorsm.h
    Header file for state machine sensors module. Located at HAL.
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
 * $Log: sensorsm.h  $
  ============================================================================*/
#ifndef __SENSORSM_H
#define __SENSORSM_H

/* Includes */
/*============================================================================*/
#include "HAL\sensors.h"

/* Constants and types */
/*============================================================================*/
typedef enum{
  SENSOR_IDLE,
  DRIVER_SEAT_BELT_VALIDATION,
  PASSENGER_SEAT_BELT_VALIDATION,
  PASSENGER_SEAT_VALIDATION,
}E_SensorStateMachine;

typedef enum{
  BS_FAULTY,
  BS_BUCKLE,
  BS_UNDETERMINED,
  BS_UNBUCKLED
}E_BeltSensorState;

typedef enum{
  OS_FAULTY,
  OS_UNOCUPPIED,
  OS_UNDETERMINED,
  OS_OCUPPIED
}E_OccupancySensorState;

typedef struct{
  T_ULONG rul_SensorReading;
  E_BeltSensorState re_SensorCurrentStatus;
  E_BeltSensorState re_SensorPreviousStatus;
  E_BeltSensorState re_SensorValidStatus;
} S_SeatBeltSensor;

typedef struct{
  T_ULONG rul_SensorReading;
  E_OccupancySensorState re_SensorCurrentStatus;
  E_OccupancySensorState re_SensorPreviousStatus;
  E_OccupancySensorState re_SensorValidStatus;
} S_OcuppancySeatSensor;

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void sensorsm_StateMachine(void);


#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
