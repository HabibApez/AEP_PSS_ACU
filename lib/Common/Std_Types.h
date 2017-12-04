/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Std_Type.h $
 * $Revision: version 1$
 * $Author: Habib Apez $
 * $Date: 2017-11-16 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \Std_Type.h
    Header of Std_Type. Located at SERVICES in Scheduler.
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
 * $Log: Std_Type.h  $
  ============================================================================*/
#ifndef __COMMON_STD_TYPES_H
#define __COMMON_STD_TYPES_H

/* Includes */
/*============================================================================*/
//#include "stdint.h"

/* Constants and types */
/*============================================================================*/
/*type used for callback function*/
typedef void  ( * tCallbackFunction )( void  );

#ifndef NULL
	#define    NULL    ( ( void * ) 0 )
#endif

/*
typedef volatile unsigned char T_UBYTE;
typedef volatile unsigned short T_UWORD;
typedef volatile unsigned int T_ULONG;
*/

typedef unsigned char T_UBYTE;
typedef unsigned short T_UWORD;
typedef unsigned int T_ULONG;


typedef volatile signed char T_SBYTE;
typedef volatile signed short T_SWORD;
typedef volatile signed int T_SLONG;

/*
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;
*/

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
