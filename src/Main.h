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

#ifndef __MMF2EXT_ASCII_MAIN_H__
#define __MMF2EXT_ASCII_MAIN_H__

// Object identifier "MKE1"
#define IDENTIFIER	                0x4D4B4531

// Object versions
#define	KCX_CURRENT_VERSION         1

// ---------------------------
// DEFINITION OF ACTIONS CODES
// ---------------------------
#define	ACT_LAST					0

// ------------------------------
// DEFINITION OF CONDITIONS CODES
// ------------------------------
#define	CND_LAST					0

// -------------------------------
// DEFINITION OF EXPRESSIONS CODES
// -------------------------------
#define EXP_INT2CHAR				0
#define	EXP_CHAR2INT				1

#define	EXP_LAST                    2

// ---------------------
// OBJECT DATA STRUCTURE 
// ---------------------
// Used at edit time and saved in the MFA/CCN/EXE files

typedef struct tagEDATA_V1
{
    // Header - required
    extHeader       eHeader;

    // Object's data

} EDITDATA;
typedef EDITDATA * LPEDATA;

// --------------------------------
// RUNNING OBJECT DATA STRUCTURE
// --------------------------------
// Used at runtime. Initialize it in the CreateRunObject function.
// Free any allocated memory or object in the DestroyRunObject function.
//
// Note: if you store C++ objects in this structure and do not store 
// them as pointers, you must call yourself their constructor in the
// CreateRunObject function and their destructor in the DestroyRunObject
// function. As the RUNDATA structure is a simple C structure and not a C++ object.

typedef struct tagRDATA
{
    // Main header - required
    headerObject    rHo;

    // Optional headers - depend on the OEFLAGS value, see documentation and examples for more info
//  rCom            rc; // Common structure for movements & animations
//  rMvt            rm; // Movements
//  rSpr            rs; // Sprite (displayable objects)
//  rVal            rv; // Alterable values

    // Object's runtime data

} RUNDATA;
typedef	RUNDATA	* LPRDATA;

// Size when editing the object under level editor
// -----------------------------------------------
#define	MAX_EDITSIZE            sizeof(EDITDATA)

// Default flags - see documentation for more info
// -------------
#define	OEFLAGS                 OEFLAG_DISPLAYINFRONT 
#define	OEPREFS                 0

// If to handle message, specify the priority of the handling procedure
// 0= low, 255= very high. You should use 100 as normal.                                                
// --------------------------------------------------------------------
#define	WINDOWPROC_PRIORITY     100

#endif /* __MMF2EXT_ASCII_MAIN_H__ */
/* END OF FILE */
