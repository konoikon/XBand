/*
File Name: xBand.h
Licence: © Copyright 2017 xCorp Ltd. All Rights Reserved
Created: 16/11/2017
Version: 0.1 (Not even finished half of it. I need the heartrate data guys)  
Author: Konstantinos Gkatzonis (20175042@student.anatolia.edu.gr)
*/
#include <Wire.h>
#include "MAX30100_PulseOximeter.h" //This is the heart rate library
#include <GSM.h> //This is the Sim library
#include <SoftwareSerial.h>
//Start of setup of sim card (Taken from the arduino example
#define PINNUMBER ""
#define GPRS_APN       "GPRS_APN" // replace your GPRS APN
#define GPRS_LOGIN     "login"    // replace with your GPRS login
#define GPRS_PASSWORD  "password" // replace with your GPRS password
GSMClient client;
GPRS gprs;
GSM gsmAccess;
//End of setup of sim card

PulseOximeter heartrate; //Initializes heart rate function

//Start of global variables
double restingHeartRate = 0; //The resting heart rate of the person. to be gathered when he wears the watch.
//End of global variable

void setup() {
  heartrate.begin();  //this initializes the heart rate sensor
  heartCalc("Setup"); //This gathers the resting heart rate data when the person turns the watch on. The setup string may be changed into a number for ease of use purposes but for now we'll leave it like that to understand eachother.

}

void loop() {
  heartrate.update(); //From what I gathered from the examples this updates the heart rate sensor feed. We'll test exactly what it does when we actually have the sensor

}

void heartCalc(String type){           //The function for calculating heart rate
  if (type == "Setup"){
    int average = 0;
    for (int i; i<20; i++){
      heartrate.update();
      average += heartrate.getHeartRate();
      delay(10);
    }
  restingHeartRate = average/20;
  }
}
//The report code is unfinished
/*void report(){ //This function works independently of the arduino GSM library. It is based on the example in https://circuitdigest.com/microcontroller-projects/send-data-to-web-server-using-sim900a-arduino
      String url="GET /input/";
      url+=publicKey;
      url+="?private_key=";
      url+=pvtKey;
      url+="&log=";
      url+=msg;
      url+=" HTTP/1.0\r\n\r\n";
      String svr=Start+","+ip+","+port;
      delay(1000);
}*/

