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

//#define ARDUINO_MAIN
#include "Arduino.h"

//extern void init(void);

/*
 * \brief Main entry point of Arduino application
 */
int main( void )
{
    init();

    Serial.begin(9600);

//    setup();

    for (;;)
    {
        Serial.println("Hello World!");
//        Serial.flush();
//        Serial.print("Y");
//        Serial.println("Z");
//        Serial.print("Hello World!");
        delay(1000);
//        loop();

//        while(app_uart_put('X') != NRF_SUCCESS) ;
    }

    return 0;
}
