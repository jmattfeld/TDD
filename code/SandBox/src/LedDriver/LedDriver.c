/***
 * Excerpted from "Test-Driven Development for Embedded C",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/jgade for more book information.
***/
/*- ------------------------------------------------------------------ -*/
/*-    Copyright (c) James W. Grenning -- All Rights Reserved          -*/
/*-    For use by owners of Test-Driven Development for Embedded C,    -*/
/*-    and attendees of Renaissance Software Consulting, Co. training  -*/
/*-    classes.                                                        -*/
/*-                                                                    -*/
/*-    Available at http://pragprog.com/titles/jgade/                  -*/
/*-        ISBN 1-934356-62-X, ISBN13 978-1-934356-62-3                -*/
/*-                                                                    -*/
/*-    Authorized users may use this source code in your own           -*/
/*-    projects, however the source code may not be used to            -*/
/*-    create training material, courses, books, articles, and         -*/
/*-    the like. We make no guarantees that this source code is        -*/
/*-    fit for any purpose.                                            -*/
/*-                                                                    -*/
/*-    www.renaissancesoftware.net james@renaissancesoftware.net       -*/
/*- ------------------------------------------------------------------ -*/

#include "LedDriver.h"
#include <stdlib.h>
#include <memory.h>

#define ALL_LEDS_ON 0xffff
#define ALL_LEDS_OFF 0x0000


static uint16_t * pVirtLeds;
static uint16_t ledsImage;

static void updateHardware()
{
	*pVirtLeds = ledsImage;
}

static uint16_t convertLedNumToBit(int nLed)
{
	return 1 << (nLed - 1);
}

void LedDriver_Create(uint16_t *address)
{
	pVirtLeds = address;
	ledsImage = ALL_LEDS_OFF;
	updateHardware();
}

void LedDriver_TurnOn(uint16_t nLed)
{
	if (nLed <= 0 || nLed > 16)
		return;

	ledsImage |= convertLedNumToBit(nLed);
	updateHardware();
}

void LedDriver_TurnAllOn()
{
	ledsImage = ALL_LEDS_ON;
	updateHardware();
}

void LedDriver_TurnOff(uint16_t nLed)
{
	if (nLed <= 0 || nLed > 16)
		return;

	ledsImage &= ~(convertLedNumToBit(nLed));
	updateHardware();
}

void LedDriver_Destroy(void)
{
}


