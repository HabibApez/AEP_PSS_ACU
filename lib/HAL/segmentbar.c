/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: 10_segment_bar.c $
 * $Revision: version 5 $
 * $Author: Habib Apez $
 * $Date: 2017-11-16 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \10_segment_bar.c
    10 segment bar module file. Located at HAL.
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
/* Habib Apez          |          2         |   Naming conventions            */
/*                     |                    |   and MISRA checked             */
/* Habib Apez          |          3         |   Turn On/Off segment algorithm */
/*                     |                    |   changed                       */
/* Habib Apez          |          4         |   Function descriptions added   */
/* Habib Apez          |          5         |   More functions added   */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: segmentbar.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "segmentbar.h"

/* Constants and types  */
/*============================================================================*/
    
/* Variables */
/*============================================================================*/

/* Private functions prototypes */
/*============================================================================*/
void segmentbar_SetLevel10(T_UBYTE lub_UpFlagInd);
void segmentbar_SetLevel9(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd);
void segmentbar_SetLevel8(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd);
void segmentbar_SetLevel7(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd);
void segmentbar_SetLevel6(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd);
void segmentbar_SetLevel5(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd);
void segmentbar_SetLevel4(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd);
void segmentbar_SetLevel3(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd);
void segmentbar_SetLevel2(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd);
void segmentbar_SetLevel1(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd);
void segmentbar_SetLevel0(T_UBYTE lub_DownFlagInd);

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : segmentbar_SetLevel10
 *  Description          : Sets the segment bar 10th level
 *  Parameters           : [T_UBYTE lub_UpFlagInd]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_SetLevel10(T_UBYTE lub_UpFlagInd){
   if(lub_UpFlagInd == 1){
    io_SetOutput(rps_PTA, 1<<PTA9);
  }
  else{
    /* Do nothing*/
  } 
}

/**************************************************************
 *  Name                 : segmentbar_SetLevel9
 *  Description          : Sets the segment bar 9th level
 *  Parameters           : [T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_SetLevel9(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd){
  if(lub_UpFlagInd == 1){
    io_SetOutput(rps_PTA, 1<<PTA8);
  }
  else{
    if(lub_DownFlagInd == 1){
      io_ClearOutput(rps_PTA, 1<<PTA9);
    }
  } 
}

/**************************************************************
 *  Name                 : segmentbar_SetLevel8
 *  Description          : Sets the segment bar 8th level
 *  Parameters           : [T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_SetLevel8(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd){
  if(lub_UpFlagInd == 1){
    io_SetOutput(rps_PTE, 1<<PTE12);
  }
  else{
    if(lub_DownFlagInd == 1){
      io_ClearOutput(rps_PTA, 1<<PTA8);
    }
  } 
}
/**************************************************************
 *  Name                 : segmentbar_SetLevel7
 *  Description          : Sets the segment bar 7h level
 *  Parameters           : [T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_SetLevel7(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd){
  if(lub_UpFlagInd == 1){
    io_SetOutput(rps_PTD, 1<<PTD17);
  }
  else{
    if(lub_DownFlagInd == 1){
      io_ClearOutput(rps_PTE, 1<<PTE12);
    } 
  }
}

/**************************************************************
 *  Name                 : segmentbar_SetLevel6
 *  Description          : Sets the segment bar 6th level
 *  Parameters           : [T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_SetLevel6(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd){
  if(lub_UpFlagInd == 1){
    io_SetOutput(rps_PTC, 1<<PTC9);
  }
  else{
    if(lub_DownFlagInd == 1){
      io_ClearOutput(rps_PTD, 1<<PTD17);
    } 
  }
}

/**************************************************************
 *  Name                 : segmentbar_SetLevel5
 *  Description          : Sets the segment bar 5th level
 *  Parameters           : [T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_SetLevel5(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd){
  if(lub_UpFlagInd == 1){
    io_SetOutput(rps_PTC, 1<<PTC8);
  }
  else{
    if(lub_DownFlagInd == 1){
      io_ClearOutput(rps_PTC, 1<<PTC9);
    }
  }
}

/**************************************************************
 *  Name                 : segmentbar_SetLevel4
 *  Description          : Sets the segment bar 4th level
 *  Parameters           : [T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_SetLevel4(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd){
  if(lub_UpFlagInd == 1){
    io_SetOutput(rps_PTD, 1<<PTD8);
  }
  else{
    if(lub_DownFlagInd == 1){
      io_ClearOutput(rps_PTC, 1<<PTC8);
    }
  }
}

/**************************************************************
 *  Name                 : segmentbar_SetLevel3
 *  Description          : Sets the segment bar 3rd level
 *  Parameters           : [T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_SetLevel3(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd){
  if(lub_UpFlagInd == 1){
    io_SetOutput(rps_PTD, 1<<PTD9);
  }
  else{
    if(lub_DownFlagInd == 1){
      io_ClearOutput(rps_PTD, 1<<PTD8);
    }
  }
}

/**************************************************************
 *  Name                 : segmentbar_SetLevel2
 *  Description          : Sets the segment bar 2nd level
 *  Parameters           : [T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_SetLevel2(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd){
  if(lub_UpFlagInd == 1){
    io_SetOutput(rps_PTD, 1<<PTD2);
  }
  else{
    if(lub_DownFlagInd == 1){
      io_ClearOutput(rps_PTD, 1<<PTD9);
    }
  }
}

/**************************************************************
 *  Name                 : segmentbar_SetLevel1
 *  Description          : Sets the segment bar 1st level
 *  Parameters           : [T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_SetLevel1(T_UBYTE lub_UpFlagInd, T_UBYTE lub_DownFlagInd){
  if(lub_UpFlagInd == 1){
    io_SetOutput(rps_PTD, 1<<PTD3);
  }
  else{
    if(lub_DownFlagInd == 1){
      io_ClearOutput(rps_PTD, 1<<PTD2);
    }
  }
}

/**************************************************************
 *  Name                 : segmentbar_SetLevel0
 *  Description          : Sets the segment bar 0 level
 *  Parameters           : [T_UBYTE lub_DownFlagInd]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_SetLevel0(T_UBYTE lub_DownFlagInd){
  if(lub_DownFlagInd == 1){
    io_ClearOutput(rps_PTD, 1<<PTD3);
  }
  else {
    /* Do nothing*/
    }
}

/* Exported functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : segmentbar_InitBar
 *  Description          : Configures 10 outputs for the 10 segment bar
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_InitBar(void){
  pcc_EnablePeripheralClock(PCC_PORTA_INDEX);
  pcc_EnablePeripheralClock(PCC_PORTC_INDEX);
  pcc_EnablePeripheralClock(PCC_PORTD_INDEX);
  pcc_EnablePeripheralClock(PCC_PORTE_INDEX);
  
  io_OutputPin(rps_PTA, 1<<PTA8 | 1<<PTA9);
  io_OutputPin(rps_PTC, 1<<PTC8 | 1<<PTC9);
  io_OutputPin(rps_PTD, 1<<PTD2 | 1<<PTD3 | 1<<PTD8 | 1<<PTD9 | 1<<PTD17);
  io_OutputPin(rps_PTE, 1<<PTE12);
  
  port_ConfigurePinMode(rps_PORTA, PTA8, 0x00000100);
  port_ConfigurePinMode(rps_PORTA, PTA9, 0x00000100);
  port_ConfigurePinMode(rps_PORTC, PTC8, 0x00000100);
  port_ConfigurePinMode(rps_PORTC, PTC9, 0x00000100);
  port_ConfigurePinMode(rps_PORTD, PTD2, 0x00000100);
  port_ConfigurePinMode(rps_PORTD, PTD3, 0x00000100);
  port_ConfigurePinMode(rps_PORTD, PTD8, 0x00000100);
  port_ConfigurePinMode(rps_PORTD, PTD9, 0x00000100);
  port_ConfigurePinMode(rps_PORTD, PTD17, 0x00000100);
  port_ConfigurePinMode(rps_PORTE, PTE12, 0x00000100);
}

/**************************************************************
 *  Name                 : segmentbar_SetLevelBar
 *  Description          : Sets the 10 segment bar level
 *  Parameters           : [T_UBYTE lub_level, T_UBYTE lub_UpFlagInd,T_UBYTE lub_DownFlagInd]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_SetLevelBar(T_UBYTE lub_level, T_UBYTE lub_UpFlagInd,T_UBYTE lub_DownFlagInd){
  switch(lub_level){
  
  case 0: 
            segmentbar_SetLevel0(lub_DownFlagInd);
            break;
  case 1: 
            segmentbar_SetLevel1(lub_UpFlagInd, lub_DownFlagInd);
            break;
  case 2: 
            segmentbar_SetLevel2(lub_UpFlagInd, lub_DownFlagInd);
	    break;
  case 3: 
            segmentbar_SetLevel3(lub_UpFlagInd, lub_DownFlagInd);
	    break;
  case 4: 
            segmentbar_SetLevel4(lub_UpFlagInd, lub_DownFlagInd);
	    break;
  case 5: 
            segmentbar_SetLevel5(lub_UpFlagInd, lub_DownFlagInd);
	    break;
  case 6: 
            segmentbar_SetLevel6(lub_UpFlagInd, lub_DownFlagInd);
            break;
  case 7: 
            segmentbar_SetLevel7(lub_UpFlagInd, lub_DownFlagInd);
	    break;
  case 8: 
            segmentbar_SetLevel8(lub_UpFlagInd, lub_DownFlagInd);
	    break;
  case 9: 
            segmentbar_SetLevel9(lub_UpFlagInd, lub_DownFlagInd);
	    break;
  case 10: 
            segmentbar_SetLevel10(lub_UpFlagInd);
	    break;
            
  default: 
            break;
  }
}

/**************************************************************
 *  Name                 : segmentbar_TurnOnSeg0
 *  Description          : Turns on the segment0
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_TurnOnSeg0(void){
  io_SetOutput(rps_PTD, 1<<PTD3);
}

/**************************************************************
 *  Name                 : segmentbar_TurnOffSeg0
 *  Description          : Turns off the segment0
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_TurnOffSeg0(void){
  io_ClearOutput(rps_PTD, 1<<PTD3);
}

/**************************************************************
 *  Name                 : segmentbar_TurnOnSeg1
 *  Description          : Turns on the segment1
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_TurnOnSeg1(void){
  io_SetOutput(rps_PTD, 1<<PTD2);
}

/**************************************************************
 *  Name                 : segmentbar_TurnOffSeg1
 *  Description          : Turns off the segment1
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_TurnOffSeg1(void){
  io_ClearOutput(rps_PTD, 1<<PTD2);
}

/**************************************************************
 *  Name                 : segmentbar_TurnOnSeg2
 *  Description          : Turns on the segment2
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_TurnOnSeg2(void){
  io_SetOutput(rps_PTD, 1<<PTD9);
}

/**************************************************************
 *  Name                 : segmentbar_TurnOffSeg2
 *  Description          : Turns off the segment2
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_TurnOffSeg2(void){
  io_ClearOutput(rps_PTD, 1<<PTD9);
}

/**************************************************************
 *  Name                 : segmentbar_TurnOnSeg3
 *  Description          : Turns on the segment3
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_TurnOnSeg3(void){
  io_SetOutput(rps_PTD, 1<<PTD8);
}

/**************************************************************
 *  Name                 : segmentbar_TurnOffSeg3
 *  Description          : Turns off the segment3
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_TurnOffSeg3(void){
  io_ClearOutput(rps_PTD, 1<<PTD8);
}

/**************************************************************
 *  Name                 : segmentbar_TurnOnSeg4
 *  Description          : Turns on the segment4
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_TurnOnSeg4(void){
  io_SetOutput(rps_PTC, 1<<PTC8);
}

/**************************************************************
 *  Name                 : segmentbar_TurnOffSeg4
 *  Description          : Turns off the segment4
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_TurnOffSeg4(void){
  io_ClearOutput(rps_PTC, 1<<PTC8);
}

/**************************************************************
 *  Name                 : segmentbar_TurnOnSeg5
 *  Description          : Turns on the segment5
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_TurnOnSeg5(void){
  io_SetOutput(rps_PTC, 1<<PTC9);
}

/**************************************************************
 *  Name                 : segmentbar_TurnOffSeg5
 *  Description          : Turns off the segment5
 *  Parameters           : [void]
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
void segmentbar_TurnOffSeg5(void){
  io_ClearOutput(rps_PTC, 1<<PTC9);
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */
