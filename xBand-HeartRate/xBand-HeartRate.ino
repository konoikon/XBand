/*
File Name: xBand.h
Licence: © Copyright 2017 xCorp Ltd. All Rights Reserved
Created: 16/11/2017
Version: 0.6 (I need the heartrate data guys)  
Author: Konstantinos Gkatzonis (20175042@student.anatolia.edu.gr)
*/
#include <Wire.h>
#include "MAX30100_PulseOximeter.h" //This is the heart rate library

PulseOximeter heartrate; //Initializes heart rate function

//Start of global variables
double restingHeartRate = 0; //The resting heart rate of the person. to be gathered when he wears the watch.
//End of global variable

void setup() {
  heartrate.begin();  //this initializes the heart rate sensor
  heartAverage(); //This gathers the resting heart rate data when the person turns the watch on.
  Serial.begin(9600);
}

void loop() {
 heartrate.update(); //From what I gathered from the examples this updates the heart rate sensor feed. We'll test exactly what it does when we actually have the sensor
 double heartR = heartrate.getHeartRate();
 Serial.println(heartR); //No real use. Just for testing the feed.
 if ((heartR / restingHeartRate)> 1.5){ //The relationship between average and current is just a sample. We have to research that more.
  Serial.println("Danger!");
 }
 delay(10);
}

void heartAverage(){           //The function for calculating heart rate
    double average = 0.0;
    for (int i; i<20; i++){
      heartrate.update();
      average += heartrate.getHeartRate();
      delay(10);
   }
    restingHeartRate = average/20.0;
  
}
