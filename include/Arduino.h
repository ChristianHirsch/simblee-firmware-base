/*
 * Modified by RF Digital Corp. 2015.
 * www.RFDigital.com
 * 
 * THE SOURCE CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND.
 */

/*
  Copyright (c) 2012 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef Arduino_h
#define Arduino_h

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "binary.h"

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

// Includes CMSIS
#include <chip.h>

#include "wiring_constants.h"

#define countof(x) (sizeof(x)/sizeof(x[0]))

#define clockCyclesPerMicrosecond() ( VARIANT_MCK / 1000000L )
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a) ( (a) * clockCyclesPerMicrosecond() )

void yield(void);

//#include "libSimblee.h"
typedef int (*pin_callback_t)(uint32_t ulPin); // from libSimblee.h
#define DISABLE 5 // from libSimblee.h
extern int SimbleeBLE_used;
extern int SimbleeGZLL_used;
extern int SimbleeBLE_enabled;
extern int SimbleeGZLL_enabled;

#include "wiring.h"
#include "wiring_digital.h"
#include "wiring_analog.h"
#include "wiring_shift.h"
#include "WInterrupts.h"

/* sketch */
extern void setup( void ) ;
extern void loop( void ) ;

#ifdef __cplusplus
} // extern "C"

#include "WCharacter.h"
#include "WString.h"
#include "Tone.h"
#include "WMath.h"
#include "HardwareSerial.h"
#include "wiring_pulse.h"

#endif // __cplusplus

// Include board variant
#include "variant.h"

#endif // Arduino_h
