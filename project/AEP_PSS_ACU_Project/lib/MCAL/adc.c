/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: adc.c $
 * $Revision: version 1 $
 * $Author: Habib Apez $
 * $Date: 2017-12-07 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \io.c
    io module file for SK32144 uC. Located at MCAL.
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
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: adc.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
# include "adc.h"

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/
/** Pointers to S_ADC */
S_ADC *rps_ADC0 = ADC0_Address;
S_ADC *rps_ADC1 = ADC1_Address;

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/
void adc_DisableConversionModule(S_ADC *lps_ADC);
void adc_DisableInterrupts(S_ADC *lps_ADC);
void adc_EnableInterrupts(S_ADC *lps_ADC);
void adc_ConfigClock(S_ADC *lps_ADC, T_UWORD luw_Config1);
void adc_ConfigSampleTime(S_ADC *lps_ADC, T_UBYTE lub_Config2);
void adc_ConfigSC2Register(S_ADC *lps_ADC, T_UBYTE lub_SC2);
void adc_ConfigSC3Register(S_ADC *lps_ADC, T_UBYTE lub_SC3);
T_UBYTE adc_CheckCompConvFlag(S_ADC *lps_ADC);
T_UWORD adc_ReadConversionResult(S_ADC *lps_ADC, T_UBYTE lub_ADCH);
T_ULONG adc_ReadADCChannel(S_ADC *lps_ADC, T_UBYTE lub_ADCH);
void adc_StartConversion(S_ADC *lps_ADC, T_UBYTE lub_ADCH);

/* Exported functions */
/*============================================================================*/

/**************************************************************
 *  Name                 : adc_InitADC
 *  Description          : Selects one of the input channels
 *  Parameters           : [S_ADC *lps_ADC]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void adc_InitADC(){
  rps_PCC->raul_PCCn[PCC_ADC0_INDEX] &=~ 0x40000000; 	/* Disable clock to change PCS */
  rps_PCC->raul_PCCn[PCC_ADC0_INDEX] |= 1<<24; 			/* PCS=1: Select SOSCDIV2_CLK */
  rps_PCC->raul_PCCn[PCC_ADC0_INDEX] |= 0x40000000; 	/* Enable bus clock in ADC */;

  adc_DisableConversionModule(rps_ADC0);
  adc_DisableInterrupts(rps_ADC0);
  adc_ConfigClock(rps_ADC0, 0x000000004);		  /* ADICLK=0: Input clk=ALTCLK1=SOSCDIV2 */
  	  	  	  	  	  	  	  	  	  	  	  	  /* ADIV=0: Prescaler=1 */
  	  	  	  	  	  	  	  	  	  	  	  	  /* MODE=1: 12-bit conversion */
  adc_ConfigSampleTime(rps_ADC0, 0x00000000C); 	  /* SMPLTS=12(default): sample time is 13 ADC clks */
  adc_ConfigSC2Register(rps_ADC0, 0x00000000);	  /* ADTRG=0: SW trigger */
  	  	  	  	  	  	  	  	  	  	  	  	  /* ACFE,ACFGT,ACREN=0: Compare func disabled */
  	  	  	  	  	  	  	  	  	  	  	  	  /* DMAEN=0: DMA disabled */
  	  	  	  	  	  	  	  	  	  	  	  	  /* REFSEL=0: Voltage reference pins= VREFH, VREEFL */
  adc_ConfigSC3Register(rps_ADC0, 0x00000000); 	  /* CAL=0: Do not start calibration sequence */
  	  	  	  	  	  	  	  	  	  	  	  	  /* ADCO=0: One conversion performed */
  	  	  	  	  	  	  	  	  	  	  	  	  /* AVGE,AVGS=0: HW average function disabled */
}

/**************************************************************
 *  Name                 : adc_DisableConversionModule
 *  Description          : Selects one of the input channels
 *  Parameters           : [S_ADC *lps_ADC]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void adc_DisableConversionModule(S_ADC *lps_ADC){
  lps_ADC->rul_SC1[0] = 0x00003F;				/* ADCH=1F: Module is disabled for conversions*/
}

/**************************************************************
 *  Name                 : adc_DisableInterrupts
 *  Description          : Disables conversion complete interrupts
 *  Parameters           : [S_ADC *lps_ADC]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void adc_DisableInterrupts(S_ADC *lps_ADC){
  lps_ADC->rul_SC1[0] &= ~(1<<6);				/* AIEN=0: Interrupts are disabled */
}

/**************************************************************
 *  Name                 : adc_EnableInterrupts
 *  Description          : Enables conversion complete interrupts
 *  Parameters           : [S_ADC *lps_ADC]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void adc_EnableInterrupts(S_ADC *lps_ADC){
  lps_ADC->rul_SC1[0] |= 1<<6;
}

/**************************************************************
 *  Name                 : adc_ConfigClock
 *  Description          : Selects the mode of operation, clock source, clock divide.
 *  Parameters           : [S_ADC *lps_ADC, T_UWORD luw_Config1]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void adc_ConfigClock(S_ADC *lps_ADC, T_UWORD luw_Config1){
  lps_ADC->rul_CFG1 = luw_Config1;
}

/**************************************************************
 *  Name                 : adc_ConfigSampleTime
 *  Description          : Selects the long sample time duration during long sample mode.
 *  Parameters           : [S_ADC *lps_ADC, T_UBYTE lub_Config2]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void adc_ConfigSampleTime(S_ADC *lps_ADC, T_UBYTE lub_Config2){
  lps_ADC->rul_CFG2 = lub_Config2;
}

/**************************************************************
 *  Name                 : adc_ConfigSC2Register
 *  Description          : Configures Status and Control register 2.
 *  Parameters           : [S_ADC *lps_ADC, T_UBYTE lub_SC2]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void adc_ConfigSC2Register(S_ADC *lps_ADC, T_UBYTE lub_SC2){
  lps_ADC->rul_SC2 = lub_SC2;
}

/**************************************************************
 *  Name                 : adc_ConfigSC3Register
 *  Description          : Configures Status and Control register 3
 *  Parameters           : [S_ADC *lps_ADC, T_UBYTE lub_SC3]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void adc_ConfigSC3Register(S_ADC *lps_ADC, T_UBYTE lub_SC3){
  lps_ADC->rul_SC3 = lub_SC3;
}

/**************************************************************
 *  Name                 : adc_CheckCompConvFlag
 *  Description          : Checks the complete conversion flag
 *  Parameters           : [S_ADC *lps_ADC]
 *  Return               : T_UBYTE
 *  Critical/explanation : No
 **************************************************************/
T_UBYTE adc_CheckCompConvFlag(S_ADC *lps_ADC){
  return (lps_ADC->rul_SC1[0] & 0x80) >> 7;
}

/**************************************************************
 *  Name                 : adc_ReadConversionResult
 *  Description          : Reads the result of an ADC conversion of the channel selected
 *  Parameters           : [S_ADC *lps_ADC, T_UBYTE lub_ADCH]
 *  Return               : T_UWORD
 *  Critical/explanation : No
 **************************************************************/
T_UWORD adc_ReadConversionResult(S_ADC *lps_ADC, T_UBYTE lub_ADCH){
  return lps_ADC->rul_R[0];
}

/**************************************************************
 *  Name                 : adc_ReadADCChannel
 *  Description          : Reads the result of an ADC conversion of the channel selected
 *  Parameters           : [S_ADC *lps_ADC, T_UBYTE lub_ADCH]
 *  Return               : T_ULONG
 *  Critical/explanation : No
 **************************************************************/
T_ULONG adc_ReadADCChannel(S_ADC *lps_ADC, T_UBYTE lub_ADCH){
  T_UWORD luw_ADCResult = 0;

  adc_StartConversion(lps_ADC, lub_ADCH);
  while(0 == adc_CheckCompConvFlag(lps_ADC)){};
  luw_ADCResult = adc_ReadConversionResult(lps_ADC, lub_ADCH);

  return (T_ULONG) ((5000*luw_ADCResult)/0xFFF); /* Convert result to mv for 0-5V range */
}

/**************************************************************
 *  Name                 : adc_SelectInputChannel
 *  Description          : Selects one of the input channels
 *  Parameters           : [S_ADC *lps_ADC, T_UBYTE lul_ADCH]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void adc_StartConversion(S_ADC *lps_ADC, T_UBYTE lub_ADCH){
	lps_ADC->rul_SC1[0] &= ~(0x1F);
	lps_ADC->rul_SC1[0] |= lub_ADCH & 0x1F;
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
