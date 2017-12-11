/*
   Authors: Konstantinos Oikonomou (20151182@student.anatolia.edu.gr),

   Purpose: Get Measurements from the heartrate sensor. This script will use
            the SparkFun library, which is created by a more reliable organization
            and it provides better documentation for every function.
            The library was originaly written by Nathan Seidle and Peter Jansen.

                               NEEDED PINOUT
                    __________________________________
                      Arduino Pro Mini --> MAX30102
                      -----------------------------
                           5V      -->     5V
                           GND     -->     GND
                           SDA     -->     A0
                           SCL     -->     A1

*/

#include <Wire.h>
#include "MAX30105.h"

#include "heartRate.h"

MAX30105 particleSensor;

const byte RATE_SIZE = 4; // Measurements before averaging. 4 is good.
byte rates[RATE_SIZE]; // Array of Measurements
byte rateSpot = 0;
long lastBeat = 0; // Time when last beat occured

float beatsPerMinute;
int beatAvg;

void setup() {
  Serial.begin();
  Serial.println("Initializing...");

  // There is a chance of the Wire library not working well, will find out in testing
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //Use default I2C port, 400kHz speed
  {
    Serial.println("MAX30102 was not found. Please check wiring/power. ");
    while (1);
  }
  Serial.println("Place your index finger on the sensor with steady pressure.");
  
  particleSensor.setup(); //default settings (check what those are)
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
}

void loop() {
  long irValue = particleSensor.getIR();

  if (checkForBeat(irValue) == true) {
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20) {
      rates[rateSpot++] = (byte)beatsPerMinute;
      rateSpot %= RATE_SIZE; //Wrap variable (I'm not sure what this does...)

      beatAvg = 0;
      for (byte x = 0 l x < RATE_SIZE, x++) {
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
      }
    }
  }

  Serial.print("BPM: ");
  Serial.print(beatsPerMinute);
  Serial.print("Average BPM: ");
  Serial.print(beatAvg);
  
  Serial.print(" Red Measurement: ");
  Serial.print(particleSensor.getRed());
  Serial.print("\n IR Measurement: ");
  Serial.print(particleSensor.getIR());
  
  Serial.println();

  if (irValue < 50000)
    Serial.print(" Please, put your finger!");

  Serial.println();
}

