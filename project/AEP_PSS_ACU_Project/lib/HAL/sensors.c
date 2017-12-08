/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: sensors.c $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-12-07 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \sensors.c
    sensors module file for SK32144 uC. Located at MCAL.
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
 * $Log: sensors.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "sensors.h"

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
 *  Name                 : sensor_InitSensors
 *  Description          : Configures the ADC and 3 inputs for the sensors
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void sensor_InitSensors(void){
  adc_InitADC();
}

/**************************************************************
 *  Name                 : sensor_ReadDriverSeatBeltSensor
 *  Description          : Read the voltage of the Driver Seat Belt Sensor in mv
 *  Parameters           : [void]
 *  Return               : T_UWORD
 *  Critical/explanation : No
 **************************************************************/
T_UWORD sensor_ReadDriverSeatBeltSensor(void){
  return adc_ReadADCChannel(rps_ADC0, DRIVER_SEAT_BELT_SENSOR);
}

/**************************************************************
 *  Name                 : sensor_ReadPassengerSeatBeltSensor
 *  Description          : Read the voltage of the Passenger Seat Belt Sensor in mv
 *  Parameters           : [void]
 *  Return               : T_UWORD
 *  Critical/explanation : No
 **************************************************************/
T_UWORD sensor_ReadPassengerSeatBeltSensor(void){
  return adc_ReadADCChannel(rps_ADC0, PASSENGER_SEAT_BELT_SENSOR);
}

/**************************************************************
 *  Name                 : sensor_ReadPassengerSeatSensor
 *  Description          : Read the voltage of the Passenger Seat Sensor in mv
 *  Parameters           : [void]
 *  Return               : T_UWORD
 *  Critical/explanation : No
 **************************************************************/
T_UWORD sensor_ReadPassengerSeatSensor(void){
  return adc_ReadADCChannel(rps_ADC0, PASSENGER_SEAT_SENSOR);
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */
