/*
 * FileName: locationGSM.ino
 * Author: Konstantinos Oikonomou (20151182@student.anatolia.edu.gr)
 * Purpose: This script receives the user's location utilizing the GSM module
 *          with AT Commands given from the SIM800 manual (url bellow).
 *          
 * XBand Copyright (c) 2017. All Rights Reserved.
 * 
 * Documentation used:
 * http://www.ayomaonline.com/programming/quickstart-sim800-sim800l-with-arduino/
 * https://www.elecrow.com/download/SIM800%20Series_GSM%20Location_Application%20Note_V1.01.pdf
 * 
 */
#include <SoftwareSerial.h>

// TODO: the numbers in the defines below should be changed, according to
//       the Arduino Pro Mini pinout.
#define SIM_TX 8
#define SIM_RX 7

SoftwareSerial moduleSerial(SIM_TX, SIM_RX); // initialize the module

void setup() {
  Serial.begin(9600);
  moduleSerial.begin(9600);
  delay(1000);

  Serial.println("Serial Initialized...");
  Serial.println("Getting User Location...");

  moduleSerial.write("AT+CLBS=1,1");

  Serial.println("Location Received")
  if (modelSerial.available()) {
    Serial.write(modelSerial.read())
  }
  else {
    Serial.write("Problem with the Location received.")
  }
  // TODOS: Take each location characteristic using a substring
  //        Then pass it to the SMS sending script.
}

void loop() {
}
