/*
 * main.cpp
 *
 *  Created on: Aug 18, 2016
 *      Author: robin
 */

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <USBAPI.h>
#include <Wire.h>

#include <stdint.h>

#include "Adafruit_FONA.h"

#define FONA_RX  9
#define FONA_TX  8
#define FONA_RST 4
#define FONA_RI  7

static SoftwareSerial fonaSS = SoftwareSerial(FONA_TX, FONA_RX);
// static SoftwareSerial *fonaSerial = &fonaSS;

void setup(void) {
	fonaSS.begin(4800);
	Wire.begin(8);
	Serial.begin(115200);
}

void loop(void) {
	bool wait = true;
	if(Serial.available()) {
		fonaSS.write(Serial.read());
		wait = false;
	}
	if(fonaSS.available()) {
		Serial.write(fonaSS.read());
		wait = false;
	}
	if(wait)
		delay(10);
}
