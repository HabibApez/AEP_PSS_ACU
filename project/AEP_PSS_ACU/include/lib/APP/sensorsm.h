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
  SBS_FAULTY,
  SBS_BUCKLED,
  SBS_UNDETERMINED,
  SBS_UNBUCKLED
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
S_SeatBeltSensor rs_DriverSeatBeltSensor = {0, SBS_FAULTY, SBS_FAULTY, SBS_FAULTY};
S_SeatBeltSensor rs_PassengerSeatBeltSensor =  {0, SBS_FAULTY, SBS_FAULTY, SBS_FAULTY};
S_OcuppancySeatSensor rs_PassengerSeatSensor =  {0,OS_FAULTY, OS_FAULTY, OS_FAULTY};

S_SeatBeltSensor *rps_DriverSeatBeltSensor = &rs_DriverSeatBeltSensor;
S_SeatBeltSensor *rps_PassengerSeatBeltSensor = &rs_PassengerSeatBeltSensor;
S_OcuppancySeatSensor *rps_PassengerSeatSensor = &rs_PassengerSeatSensor;


/* Exported functions prototypes */
/*============================================================================*/
void sensorsm_StateMachine(void);


#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
