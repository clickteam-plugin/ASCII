/*
 * Copyright 2009-2013 Olivier WENGER
 *     http://www.magicspark.org/ or http://oulydev.free.fr/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// ============================================================================
//
// This file are where the Conditions/Actions/Expressions are defined.
// See the Extension FAQ in this SDK for more info and where to download it
//
// ============================================================================

// Common Include
#include "common.h"

// ============================================================================
//
// ACTIONS ROUTINES
// 
// ============================================================================

/* Nothing for this extension */

// ============================================================================
//
// CONDITION ROUTINES
// 
// ============================================================================

/* Nothing for this extension */

// ============================================================================
//
// EXPRESSIONS ROUTINES
// 
// ============================================================================

// Convert unsigned char to integer
long WINAPI DLLExport ASCII_char2int(
    LPRDATA rdPtr,
    long    param1 )
{
	LPSTR string =
		(LPSTR) CNC_GetFirstExpressionParameter(
            rdPtr,
            param1,
            TYPE_STRING );
	
	return string ? (unsigned char) string[0] : 0;
}

// Convert integer to char
long WINAPI DLLExport ASCII_int2char(
    LPRDATA rdPtr,
    long    param1 )
{
	unsigned long value =
		(unsigned long) CNC_GetFirstExpressionParameter(
        rdPtr,
        param1,
        TYPE_INT );
	LPSTR temp = NULL;

	// Tells MMF to allocate a temporary buffer to store the string.
	// This temporary buffer will be freed as soon as MMF no longer
    // needs the returned string.
	temp = (LPSTR) callRunTimeFunction(
        rdPtr,
        RFUNCTION_GETSTRINGSPACE,
        2,
        0 );
	if ( temp != NULL ) /* Check allocation */
	{
		temp[0] = (unsigned char) value;
		temp[1] = 0; // Null terminated C string.
	}
    else
    {
        // MMF don't like NULL pointer, giving him an empty string instead.
        temp = "";
    }
	
	// Setting the HOF_STRING flag lets MMF know that you are returning a string.
    rdPtr->rHo.hoFlags |= HOF_STRING;
    // This returns a pointer to the string for MMF.
	return (long) temp;
}

// ============================================================================
//
// MMF Interface
// 
// ============================================================================

// ----------------------------------------------------------
// Condition / Action / Expression prototypes
// ----------------------------------------------------------

// Quick memo: content of the eventInformations arrays
// ---------------------------------------------------
// Menu ID
// String ID
// Code
// Flags
// Number_of_parameters
// Parameter_type [Number_of_parameters]
// Parameter_TitleString [Number_of_parameters]

// Definitions of parameters for each action
#if ACT_LAST > 0
short actionsInfos[] = { 0, 0, 0, 0, 0 }; /* Empty item -> end of array */
#endif

// Definitions of parameters for each condition
short conditionsInfos[] = { 0, 0, 0, 0, 0 }; /* Empty item -> end of array */

// Definitions of parameters for each expression
short expressionsInfos[] = {
    EXP_IDMN_INT2CHAR, EXP_IDS_INT2CHAR, EXP_INT2CHAR, EXPFLAG_STRING,    1, EXPPARAM_LONG,   0,
    EXP_IDMN_CHAR2INT, EXP_IDS_CHAR2INT, EXP_CHAR2INT, 0,                 1, EXPPARAM_STRING, 0,
    0 }; /* End of array */

// ----------------------------------------------------------
// Condition / Action / Expression jump table
// ----------------------------------------------------------
// Contains the address inside the extension of the different
// routines that handle the action, conditions and expressions.
// Located at the end of the source for convinience
// Must finish with a 0
//
short (WINAPI * ActionJumps[])(LPRDATA rdPtr, long param1, long param2) = {
    0 }; /* End of array */

long (WINAPI * ConditionJumps[])(LPRDATA rdPtr, long param1, long param2) = {
    0 }; /* End of array */

long (WINAPI * ExpressionJumps[])(LPRDATA rdPtr, long param) = {     
    ASCII_int2char,
    ASCII_char2int,

    0 }; /* End of array */

/* END OF FILE */
