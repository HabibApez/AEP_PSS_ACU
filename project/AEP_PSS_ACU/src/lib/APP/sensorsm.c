/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: sensorsm.c $
 * $Revision: version 2 $
 * $Author: Habib Apez $
 * $Date: 2017-12-18 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \sensorsm.c
    state machine for the sensors. Located at APPL.
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
/* Habib Apez          |          2         |   Indicator functions added     */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: sensorsm.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "APP\sensorsm.h"
#include "HAL\leds.h"
#include "HAL\seatindicators.h"

/* Constants and types  */
/*============================================================================*/
#define ZERO_MS 0
#define TWENTY_MS 1
#define TWO_HUNDRED_SENSOR_MS  18
#define FIVE_HUNDRED_SENSOR_MS  44
#define OFFSET_DSB_MS 13
#define OFFSET_PSB_MS 3

#define ZERO_TIMES 0
#define FIVE_TIMES 5
#define SIX_TIMES 6

/* Variables */
/*============================================================================*/
E_SensorStateMachine re_SensorSmState = SENSOR_IDLE;


/* Private functions prototypes */
/*============================================================================*/
void sensorsm_IdleState(void);
void sensorsm_DriverSBValidationState(void);
void sensorsm_PassengerSBValidationState(void);
void sensorsm_PassengerSValidationState(void);
void sensorsm_UpdateSBStatus(S_SeatBeltSensor *lps_SSensor);
void sensorsm_UpdateSStatus(S_OcuppancySeatSensor *lps_SSensor);

void sensorsm_UpdateSBDriverIndicators(void);
void sensorsm_UpdateSBPassengerIndicators(void);
void sensorsm_UpdateOSPassengerIndicators(void);

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/******************************************************************************/
/*******************    STATES DEFINITIONS   **********************************/
/******************************************************************************/

/**************************************************************
 *  Name                 : sensorsm_IdleState
 *  Description          : Defines the Idle state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void sensorsm_IdleState(void){
  static T_UBYTE rub_DSBTimeCounter = ZERO_MS + OFFSET_DSB_MS;
  static T_UBYTE rub_PSBTimeCounter = ZERO_MS + OFFSET_PSB_MS;
  static T_UBYTE rub_PSTimeCounter = ZERO_MS;

  rub_DSBTimeCounter++;
  rub_PSBTimeCounter++;
  rub_PSTimeCounter++;

  if(rub_DSBTimeCounter == TWO_HUNDRED_SENSOR_MS){
      re_SensorSmState = DRIVER_SEAT_BELT_VALIDATION;
      rub_DSBTimeCounter = ZERO_MS;
    }


  	if(rub_PSBTimeCounter == TWO_HUNDRED_SENSOR_MS){
  	re_SensorSmState = PASSENGER_SEAT_BELT_VALIDATION;
  	rub_PSBTimeCounter = ZERO_MS;
  	}


  	  if(rub_PSTimeCounter == FIVE_HUNDRED_SENSOR_MS){
  	  re_SensorSmState = PASSENGER_SEAT_VALIDATION;
  	  rub_PSTimeCounter = ZERO_MS;
  	  }
}

/**************************************************************
 *  Name                 : sensorsm_DriverSBValidationState
 *  Description          : Defines the DriverSBValidation state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void sensorsm_DriverSBValidationState(void){
  static T_UBYTE lub_DSBFilterCounter = ZERO_TIMES;

  rps_DriverSeatBeltSensor-> rul_SensorReading = sensor_ReadSensor(DRIVER_SEAT_BELT_SENSOR);
  sensorsm_UpdateSBStatus(rps_DriverSeatBeltSensor);

  if(rps_DriverSeatBeltSensor-> re_SensorCurrentStatus == rps_DriverSeatBeltSensor-> re_SensorPreviousStatus){
	lub_DSBFilterCounter++;
	if(lub_DSBFilterCounter == FIVE_TIMES){
		rps_DriverSeatBeltSensor->re_SensorValidStatus = rps_DriverSeatBeltSensor-> re_SensorCurrentStatus;
		lub_DSBFilterCounter = ZERO_TIMES;
		sensorsm_UpdateSBDriverIndicators();
	}
  }
  else{
	lub_DSBFilterCounter = ZERO_TIMES;
  }
  rps_DriverSeatBeltSensor-> re_SensorPreviousStatus = rps_DriverSeatBeltSensor-> re_SensorCurrentStatus;
  re_SensorSmState = SENSOR_IDLE;
}

/**************************************************************
 *  Name                 : sensorsm_PassengerSBValidationState
 *  Description          : Defines the PassengerSBValidation state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void sensorsm_PassengerSBValidationState(void){
  static T_UBYTE lub_PSBFilterCounter = ZERO_TIMES;

  rps_PassengerSeatBeltSensor-> rul_SensorReading = sensor_ReadSensor(PASSENGER_SEAT_BELT_SENSOR);
  sensorsm_UpdateSBStatus(rps_PassengerSeatBeltSensor);

  if(rps_PassengerSeatBeltSensor-> re_SensorCurrentStatus == rps_PassengerSeatBeltSensor-> re_SensorPreviousStatus){
	lub_PSBFilterCounter++;
	if(lub_PSBFilterCounter == FIVE_TIMES){
		rps_PassengerSeatBeltSensor->re_SensorValidStatus = rps_PassengerSeatBeltSensor-> re_SensorCurrentStatus;
		lub_PSBFilterCounter = ZERO_TIMES;
		sensorsm_UpdateSBPassengerIndicators();
	}
  }
  else{
	lub_PSBFilterCounter = ZERO_TIMES;
  }
  rps_PassengerSeatBeltSensor-> re_SensorPreviousStatus = rps_PassengerSeatBeltSensor-> re_SensorCurrentStatus;
  re_SensorSmState = SENSOR_IDLE;
}


/**************************************************************
 *  Name                 : sensorsm_PassengerSValidationState
 *  Description          : Defines the PassengerSValidation state
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void sensorsm_PassengerSValidationState(void){
  static T_UBYTE lub_PSFilterCounter = ZERO_TIMES;

  rps_PassengerSeatSensor-> rul_SensorReading = sensor_ReadSensor(PASSENGER_SEAT_SENSOR);
  sensorsm_UpdateSStatus(rps_PassengerSeatSensor);

  if(rps_PassengerSeatSensor-> re_SensorCurrentStatus == rps_PassengerSeatSensor-> re_SensorPreviousStatus){
	lub_PSFilterCounter++;
	if(lub_PSFilterCounter == SIX_TIMES){
		rps_PassengerSeatSensor->re_SensorValidStatus = rps_PassengerSeatSensor-> re_SensorCurrentStatus;
		lub_PSFilterCounter = ZERO_TIMES;
		sensorsm_UpdateOSPassengerIndicators();
	}
  }
  else{
	lub_PSFilterCounter = ZERO_TIMES;
  }
  rps_PassengerSeatSensor-> re_SensorPreviousStatus = rps_PassengerSeatSensor-> re_SensorCurrentStatus;
  re_SensorSmState = SENSOR_IDLE;
}

/**************************************************************
 *  Name                 : sensorsm_UpdateSBStatus
 *  Description          : Asserts the new sensor state
 *  Parameters           : [S_SeatBeltSensor *lps_SBSensor]
 *  Return               : E_BeltSensorState
 *  Critical/explanation : No
 **************************************************************/
void sensorsm_UpdateSBStatus(S_SeatBeltSensor *lps_SBSensor){
  T_ULONG lul_SensorVoltage = lps_SBSensor-> rul_SensorReading;

  if(lul_SensorVoltage >2000){			/* If voltage > 20V */
    lps_SBSensor-> re_SensorCurrentStatus = SBS_FAULTY;
  }
  else if (lul_SensorVoltage > 1200) { 	/* If voltage > 12V */
    lps_SBSensor-> re_SensorCurrentStatus = SBS_BUCKLED;
  }
  else if (lul_SensorVoltage >1000) { 	/* If voltage > 10v */
	lps_SBSensor-> re_SensorCurrentStatus = SBS_UNDETERMINED;
  }
  else if (lul_SensorVoltage >200) { 	/* If voltage > 2v */
	lps_SBSensor-> re_SensorCurrentStatus = SBS_UNBUCKLED;
  }
  else {
	lps_SBSensor-> re_SensorCurrentStatus = SBS_FAULTY;
  }
}

/**************************************************************
 *  Name                 : sensorsm_AssertNewSStatus
 *  Description          : Asserts the new sensor state
 *  Parameters           : [S_SeatBeltSensor *lps_SBSensor]
 *  Return               : E_OccupancySensorState
 *  Critical/explanation : No
 **************************************************************/
void sensorsm_UpdateSStatus(S_OcuppancySeatSensor *lps_SSensor){
  T_ULONG lul_SensorVoltage = lps_SSensor-> rul_SensorReading;

  if(lul_SensorVoltage >2000){			/* If voltage > 20V */
    lps_SSensor-> re_SensorCurrentStatus = OS_FAULTY;
  }
  else if (lul_SensorVoltage > 1200) { 	/* If voltage > 12V */
    lps_SSensor-> re_SensorCurrentStatus = OS_UNOCUPPIED;
  }
  else if (lul_SensorVoltage >1000) { 	/* If voltage > 10v */
	lps_SSensor-> re_SensorCurrentStatus = OS_UNDETERMINED;
  }
  else if (lul_SensorVoltage >200) { 	/* If voltage > 2v */
	lps_SSensor-> re_SensorCurrentStatus = OS_OCUPPIED;
  }
  else {
	lps_SSensor-> re_SensorCurrentStatus = OS_FAULTY;
  }
}

/**************************************************************
 *  Name                 : sensorsm_UpdateSBDriverIndicators
 *  Description          : Updates the Driver Seat Belt Sensor Indicators
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void sensorsm_UpdateSBDriverIndicators(void){
  switch(rps_DriverSeatBeltSensor->re_SensorValidStatus){
  case SBS_FAULTY:
	  seatindicators_TurnOnIndicator(rps_PTD, 1<<DRIVER_SBS_UP_FAULTY_PIN);
	  seatindicators_TurnOffIndicator(rps_PTD, 1<<DRIVER_SBS_BUCLKED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTD, 1<<DRIVER_SBS_UNDETERMINED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTA, 1<<DRIVER_SBS_UNBUCKLED_PIN);
	  seatindicators_TurnOnIndicator(rps_PTE, 1<<DRIVER_SBS_DOWN_FAULTY_PIN);
	break;

  case SBS_BUCKLED:
	  seatindicators_TurnOffIndicator(rps_PTD, 1<<DRIVER_SBS_UP_FAULTY_PIN);
	  seatindicators_TurnOnIndicator(rps_PTD, 1<<DRIVER_SBS_BUCLKED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTD, 1<<DRIVER_SBS_UNDETERMINED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTA, 1<<DRIVER_SBS_UNBUCKLED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTE, 1<<DRIVER_SBS_DOWN_FAULTY_PIN);
	break;

  case SBS_UNDETERMINED:
	  seatindicators_TurnOffIndicator(rps_PTD, 1<<DRIVER_SBS_UP_FAULTY_PIN);
	  seatindicators_TurnOffIndicator(rps_PTD, 1<<DRIVER_SBS_BUCLKED_PIN);
	  seatindicators_TurnOnIndicator(rps_PTD, 1<<DRIVER_SBS_UNDETERMINED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTA, 1<<DRIVER_SBS_UNBUCKLED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTE, 1<<DRIVER_SBS_DOWN_FAULTY_PIN);
	break;

  case SBS_UNBUCKLED:
	  seatindicators_TurnOffIndicator(rps_PTD, 1<<DRIVER_SBS_UP_FAULTY_PIN);
	  seatindicators_TurnOffIndicator(rps_PTD, 1<<DRIVER_SBS_BUCLKED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTD, 1<<DRIVER_SBS_UNDETERMINED_PIN);
	  seatindicators_TurnOnIndicator(rps_PTA, 1<<DRIVER_SBS_UNBUCKLED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTE, 1<<DRIVER_SBS_DOWN_FAULTY_PIN);
	break;

  default:
    break;
  }
}

/**************************************************************
 *  Name                 : sensorsm_UpdateSBPassengerIndicators
 *  Description          : Updates the Passenger Seat Belt Sensor Indicators
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void sensorsm_UpdateSBPassengerIndicators(void){
  switch(rps_PassengerSeatBeltSensor->re_SensorValidStatus){
  case SBS_FAULTY:
	  seatindicators_TurnOnIndicator(rps_PTD, 1<<PASSENG_SBS_UP_FAULTY_PIN);
	  seatindicators_TurnOffIndicator(rps_PTD, 1<<PASSENG_SBS_BUCLKED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTC, 1<<PASSENG_SBS_UNDETERMINED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTC, 1<<PASSENG_SBS_UNBUCKLED_PIN);
	  seatindicators_TurnOnIndicator(rps_PTB, 1<<PASSENG_SBS_DOWN_FAULTY_PIN);
	break;

  case SBS_BUCKLED:
	  seatindicators_TurnOffIndicator(rps_PTD, 1<<PASSENG_SBS_UP_FAULTY_PIN);
	  seatindicators_TurnOnIndicator(rps_PTD, 1<<PASSENG_SBS_BUCLKED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTC, 1<<PASSENG_SBS_UNDETERMINED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTC, 1<<PASSENG_SBS_UNBUCKLED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTB, 1<<PASSENG_SBS_DOWN_FAULTY_PIN);
	break;

  case SBS_UNDETERMINED:
	  seatindicators_TurnOffIndicator(rps_PTD, 1<<PASSENG_SBS_UP_FAULTY_PIN);
	  seatindicators_TurnOffIndicator(rps_PTD, 1<<PASSENG_SBS_BUCLKED_PIN);
	  seatindicators_TurnOnIndicator(rps_PTC, 1<<PASSENG_SBS_UNDETERMINED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTC, 1<<PASSENG_SBS_UNBUCKLED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTB, 1<<PASSENG_SBS_DOWN_FAULTY_PIN);
	break;

  case SBS_UNBUCKLED:
	  seatindicators_TurnOffIndicator(rps_PTD, 1<<PASSENG_SBS_UP_FAULTY_PIN);
	  seatindicators_TurnOffIndicator(rps_PTD, 1<<PASSENG_SBS_BUCLKED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTC, 1<<PASSENG_SBS_UNDETERMINED_PIN);
	  seatindicators_TurnOnIndicator(rps_PTC, 1<<PASSENG_SBS_UNBUCKLED_PIN);
	  seatindicators_TurnOffIndicator(rps_PTB, 1<<PASSENG_SBS_DOWN_FAULTY_PIN);
	break;

  default:
    break;
  }
}


/**************************************************************
 *  Name                 : sensorsm_UpdateOSPassengerIndicators
 *  Description          : Updates the Passenger Occupancy Sensor Indicators
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void sensorsm_UpdateOSPassengerIndicators(void){
  switch(rps_PassengerSeatSensor-> re_SensorCurrentStatus){
  case OS_FAULTY:
	seatindicators_TurnOnIndicator(rps_PTB, 1<<PASSENG_OS_UP_FAULTY_PIN);
	seatindicators_TurnOffIndicator(rps_PTB, 1<<PASSENG_OS_UNOCCUPIED_PIN);
	seatindicators_TurnOffIndicator(rps_PTB, 1<<PASSENG_OS_UNDETERMINED_PIN);
	seatindicators_TurnOffIndicator(rps_PTA, 1<<PASSENG_OS_OCCUPIED_PIN);
	seatindicators_TurnOnIndicator(rps_PTA, 1<<PASSENG_OS_DOWN_FAULTY_PIN);
    break;

  case OS_UNOCUPPIED:
	seatindicators_TurnOffIndicator(rps_PTB, 1<<PASSENG_OS_UP_FAULTY_PIN);
	seatindicators_TurnOnIndicator(rps_PTB, 1<<PASSENG_OS_UNOCCUPIED_PIN);
	seatindicators_TurnOffIndicator(rps_PTB, 1<<PASSENG_OS_UNDETERMINED_PIN);
	seatindicators_TurnOffIndicator(rps_PTA, 1<<PASSENG_OS_OCCUPIED_PIN);
	seatindicators_TurnOffIndicator(rps_PTA, 1<<PASSENG_OS_DOWN_FAULTY_PIN);
	break;

  case OS_UNDETERMINED:
	seatindicators_TurnOffIndicator(rps_PTB, 1<<PASSENG_OS_UP_FAULTY_PIN);
	seatindicators_TurnOffIndicator(rps_PTB, 1<<PASSENG_OS_UNOCCUPIED_PIN);
	seatindicators_TurnOnIndicator(rps_PTB, 1<<PASSENG_OS_UNDETERMINED_PIN);
	seatindicators_TurnOffIndicator(rps_PTA, 1<<PASSENG_OS_OCCUPIED_PIN);
	seatindicators_TurnOffIndicator(rps_PTA, 1<<PASSENG_OS_DOWN_FAULTY_PIN);
    break;

  case OS_OCUPPIED:
	seatindicators_TurnOffIndicator(rps_PTB, 1<<PASSENG_OS_UP_FAULTY_PIN);
	seatindicators_TurnOffIndicator(rps_PTB, 1<<PASSENG_OS_UNOCCUPIED_PIN);
	seatindicators_TurnOffIndicator(rps_PTB, 1<<PASSENG_OS_UNDETERMINED_PIN);
	seatindicators_TurnOnIndicator(rps_PTA, 1<<PASSENG_OS_OCCUPIED_PIN);
	seatindicators_TurnOffIndicator(rps_PTA, 1<<PASSENG_OS_DOWN_FAULTY_PIN);
    break;
  }
}

/* Exported functions */
/*============================================================================*/
/******************************************************************************/
/************************    STATE MACHINE   **********************************/
/******************************************************************************/
/**************************************************************
 *  Name                 : sensorsm_StateMachine
 *  Description          : State Machine for sensors
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void sensorsm_StateMachine(void){
  switch(re_SensorSmState){
    case SENSOR_IDLE:
      sensorsm_IdleState();
      break;

    case DRIVER_SEAT_BELT_VALIDATION:
    	sensorsm_DriverSBValidationState();
      break;

    case PASSENGER_SEAT_BELT_VALIDATION:
    	sensorsm_PassengerSBValidationState();
      break;

    case PASSENGER_SEAT_VALIDATION:
    	sensorsm_PassengerSValidationState();
      break;

    default:
      break;
  }
}

/* Notice: the file ends with a blank new line to avoid compiler warnings */
