/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: canbus.c $
 * $Revision: version 2 $
 * $Author: Habib Apez $
 * $Date: 2017-12- 18 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \canbus.c
    Source of canbus. Located at SERVICES in communications.
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
/* Habib Apez          |          1         |   Engine Status function added  */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: canbus.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "SERVICES\Communications\canbus.h"
#include "HAL\leds.h"
#include "HAL\can.h"
#include "APP\driverremsm.h"
#include "APP\passengerremsm.h"

/* Constants and types  */
/*============================================================================*/
#define ZERO_SECONDS_TASK		0
#define TWO_HUNDRED_MS_TASK   	10

/* Variables */
/*============================================================================*/
T_UBYTE rub_EngineStatus;
T_UWORD ruw_EngineRPM;
T_ULONG rul_RxMessageData[2] = {0, 0};
T_ULONG rul_TxMessageData[2] = {0, 0};

/* Private functions prototypes */
/*============================================================================*/
void canbus_SendSeatBeltMessage(void);
void canbus_SendChimeMessage(void);

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : canbus_SendSeatBeltMessage
 *  Description          : Send Seat Belt data each 200ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void canbus_SendSeatBeltMessage(void){
  // Package CAN signals
  //Message1
  rul_TxMessageData[0] =  0;
  rul_TxMessageData[0] |= driverremsm_DriverGetIndicatorStatus() << 24; 	/* Driver Indication */
  rul_TxMessageData[0] |= driverremsm_DriverGetIndicationDutyCycle() << 16; 	/* Driver Indication Duty Cycle */
  rul_TxMessageData[0] |= driverremsm_DriverGetIndicationPeriod() << 8; 	/* Driver Indication Period*/
  rul_TxMessageData[0] |= passengerremsm_PassengerGetIndicatorStatus() << 0; 	/* Passenger Indication */

  rul_TxMessageData[1] = 0;
  rul_TxMessageData[1] |= passengerremsm_PassengerGetIndicationDutyCycle() << 24; 	/* Passenger Indication Duty Cycle*/
  rul_TxMessageData[1] |= passengerremsm_PassengerGetIndicationPeriod() << 16; 	/* Passenger Indication Period */
  rul_TxMessageData[1] |= (0x00) << 8; 	/* No data */
  rul_TxMessageData[1] |= (0x00) << 0; 	/* No data */

  // Send CAN messages
  can_TransmitMessageCAN0(SEAT_BELT_INDICATOR_MSG_BUFF, SEAT_BELT_INDICATOR_MSG_ID, rul_TxMessageData);
}

/**************************************************************
 *  Name                 : canbus_SendChimetMessage
 *  Description          : Send Chime data each 200ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
 void canbus_SendChimeMessage(void){
 // Package CAN signals
 //Message1
 rul_TxMessageData[0] = 0;
 rul_TxMessageData[0] |= remindercommon_GetSoundTone() << 24; 	/* Sound Tone */
 rul_TxMessageData[0] |= remindercommon_GetSoundCadence() << 16; 	/* Sound Cadence Period */
 rul_TxMessageData[0] |= remindercommon_GetSoundRepetitions() << 8; 	/* Sound Cadence Period */
 rul_TxMessageData[0] |= remindercommon_GetSoundDutyCycle() << 0; 	/* Sound Tone Duty Cycle */

 rul_TxMessageData[1] = 0;
 rul_TxMessageData[1] |= driverremsm_DriverGetChimeStatus() << 24; 	/*  location Driver */
 rul_TxMessageData[1] |= passengerremsm_PassengerGetChimeStatus() << 16; 	/* Location Passenger */
 rul_TxMessageData[1] |= (0x00) << 8; 	/* No data */
 rul_TxMessageData[1] |= (0x00) << 0; 	/* No data */

  // Send CAN messages
  can_TransmitMessageCAN0(CHIME_REQUEST_MSG_BUFF, CHIME_REQUEST_MSG_ID, rul_TxMessageData);
}

/* Exported functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : canbus_ReadEngRPM
 *  Description          : Read CAN bus and collect data from ECU each 10ms*
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void canbus_ReadEngRPMMessage(void){
  if(1 == can_CheckMessageArrivalCAN0(ENG_RPM_MSG_BUFF)){
    can_ReceiveMessageCAN0(ENG_RPM_MSG_BUFF, rul_RxMessageData);
    ruw_EngineRPM = ((rul_RxMessageData[0] & 0x00FF0000) >> 16) | ((rul_RxMessageData[0] & 0xFF000000) >> 16);
    rub_EngineStatus = (rul_RxMessageData[0] & 0x0000FF00) >> 8;
    if(0 == rub_EngineStatus)
      rub_PowerUpCounter = POWER_UP_CONTER_RESET;
  }
}

/**************************************************************
 *  Name                 : canbus_SendCANMessages
 *  Description          : Send Seat Belt and Chime messages each 200ms
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void canbus_SendCANMessages(void){
 static T_UBYTE lub_TwoMsCounter = ZERO_SECONDS_TASK;
 lub_TwoMsCounter++;

 if(TWO_HUNDRED_MS_TASK == lub_TwoMsCounter){
	  lub_TwoMsCounter = ZERO_SECONDS_TASK;
	  canbus_SendSeatBeltMessage();
	  canbus_SendChimeMessage();
 }
 else{
	  // Do nothing
 }
}

/**************************************************************
 *  Name                 : canbus_GetEngStatus
 *  Description          : Return the Engine Status
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE canbus_GetEngStatus(void){
  return rub_EngineStatus;
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
