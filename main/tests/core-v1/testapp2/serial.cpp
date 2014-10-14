/**
 ******************************************************************************
 * @file    serial.cpp
 * @authors Satish Nair
 * @version V1.0.0
 * @date    7-Oct-2014
 * @brief   SERIAL test application
 ******************************************************************************
  Copyright (c) 2013-14 Spark Labs, Inc.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************
 */

#include "application.h"
#include "unit-test/unit-test.h"

test(SERIAL_ReadWriteSucceedsWithUserIntervention) {
    //The following code will test all the important USB Serial routines
    char test[] = "hello";
    char message[10];
    // when
    Serial.print("Type the following message and press Enter : ");
    Serial.println(test);
    serialReadLine(&Serial, message, 9, 10000);//10 sec timeout
    Serial.println("");
    // then
    assertTrue(strncmp(test, message, 5)==0);
}

test(SERIAL1_ReadWriteSucceedsInLoopbackWithTxRxShorted) {
    //The following code will test all the important USART Serial routines
    char test[] = "hello";
    char message[10];
    // when
    Serial1.begin(9600);
    Serial1.println(test);
    serialReadLine(&Serial1, message, 9, 1000);//1 sec timeout
    // then
    assertTrue(strncmp(test, message, 5)==0);
}
