/*
* Modified by RF Digital Corp. 2015.
* www.RFDigital.com
* 
* THE SOURCE CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND.
*/

/*
Copyright (c) 2011 Arduino.  All right reserved.

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

/*
* Here should go some sort of liscense maybe? This file is a modified
* arduino source file.  It defines the board variant being used
*/

#ifndef _VARIANT_SIMBLEE_
#define _VARIANT_SIMBLEE_

/*----------------------------------------------------------------------------
*        Headers
*----------------------------------------------------------------------------*/

#include "Arduino.h"

#ifdef __cplusplus
#include "UARTClass.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

/**
* Libc porting layers
*/
#if defined (  __GNUC__  ) /* GCC CS3 */
#    include <syscalls.h> /** RedHat Newlib minimal stub */
#endif

/*----------------------------------------------------------------------------
*        Definitions
*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

#define SIMBLEE

/** Name of the board */
#define VARIANT_NAME        "Simblee"

/** Master clock frequency  (used in TWI and DAC) */
#define VARIANT_MCK         16000000UL

/*----------------------------------------------------------------------------
*        Pins
*----------------------------------------------------------------------------*/

// Number of pins
#define PINS_COUNT           (32u)

/* Pins descriptions to be instantiated into variant.cpp */
extern uint8_t PPI_Channels_Occupied[PINS_COUNT][2];
extern uint8_t GPIOTE_Channels_Occupied[PINS_COUNT];
extern uint8_t Timer1_Compare_Unit_Occupied_by_Pin[3]; // Contains Pin number which occupied appropriate CC register (0, 1 or 2) of Timer 1 for PWM purposes
extern uint8_t Timer2_Compare_Unit_Occupied_by_Pin[3]; // Contains Pin number which occupied appropriate CC register (0, 1 or 2) of Timer 2 for PWM purposes
extern uint8_t Pin_Occupied_for_PWM[PINS_COUNT]; // Determines if particular pin is occupied for PWM output

/*
* SPI Interfaces
*/
#define SPI_INTERFACES_COUNT 2

#define SPI_INTERFACE        NRF_SPI0
#define PIN_SPI_SS           (6u)
#define PIN_SPI_MOSI         (5u)
#define PIN_SPI_MISO         (3u)
#define PIN_SPI_SCK          (4u)

#define SS    PIN_SPI_SS
#define MOSI  PIN_SPI_MOSI
#define MISO  PIN_SPI_MISO
#define SCK   PIN_SPI_SCK

#define SPI_INTERFACE_2        NRF_SPI1
#define PIN_SPI_SS_2           (20u)
#define PIN_SPI_MOSI_2         (23u)
#define PIN_SPI_MISO_2         (21u)
#define PIN_SPI_SCK_2          (24u)

#define SS2    PIN_SPI_SS_2
#define MOSI2  PIN_SPI_MOSI_2
#define MISO2  PIN_SPI_MISO_2
#define SCK2   PIN_SPI_SCK_2

/*
* Wire Interfaces
*/
#define PIN_WIRE_SDA         (6u)
#define PIN_WIRE_SCL         (5u)
#define WIRE_INTERFACE       NRF_TWI1

#define PIN_WIRE2_SDA         (14u)
#define PIN_WIRE2_SCL         (13u)
#define WIRE2_INTERFACE       NRF_TWI0 

/*
* Analog pins
*/
#define ADC_RESOLUTION        10

/*
* UART/USART Interfaces
*/
#define UART_DEFAULT_RX_PIN   0
#define UART_DEFAULT_TX_PIN   1
#define UART_DEFAULT_CTS_PIN  0xff  // default: hardware flow of control disabled
#define UART_DEFAULT_RTS_PIN  0xff  // default: hardware flow of control disabled

typedef enum
{
UART0_State_NotStarted,
UART0_State_BeforeFirstTX,
UART0_State_AfterFirstTX
}  UART0_States;

extern UART0_States UART0_State;

int UART0_BaudRate();

void UART0_Start( int dwBaudRate, uint8_t rx_pin, uint8_t tx_pin, uint8_t cts, uint8_t rts );
void UART0_Stop();
void UART0_FlushTX();
void UART0_TX( const uint8_t uc_data );
void UART0_TXD( const uint8_t uc_data );

__attribute__(( always_inline ))
static int __INLINE UART0_RXReady()
{
return NRF_UART0->EVENTS_RXDRDY;
}

__attribute__(( always_inline ))
static int __INLINE UART0_TXReady()
{
return NRF_UART0->EVENTS_TXDRDY;
}

__attribute__(( always_inline ))
static uint8_t __INLINE UART0_RXData()
{
return NRF_UART0->RXD;
}

void UART0_RXReset();
int UART0_RXErrorReset();
uint8_t UART0_RX();

void UART0_TXReset();

/*
* PWM
*/
#define PWM_MAX_DUTY_CYCLE    255
#define PWM_MIN_DUTY_CYCLE    0
#define PWM_RESOLUTION        16

/*
* Miscellaneous
*/

#include "Memory.h"

// unique id for each unit
uint32_t getDeviceIdLow();
uint32_t getDeviceIdHigh();
uint64_t getDeviceId();

extern bool override_uart_limit;

#define UART_BAUDRATE_BAUDRATE_Baud31250 (0x00800000UL) /*!< 31250 baud.(MIDI)  */

#define  LPCS_RC     0
#define  LPCS_XTAL   1
#define  LPCS_SYNTH  2

void lowPowerClockSource(int lpcs);

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
*        Arduino objects - C++ only
*----------------------------------------------------------------------------*/

#ifdef __cplusplus

extern UARTClass Serial;

#endif

#endif /* _VARIANT_SIMBLEE_ */
