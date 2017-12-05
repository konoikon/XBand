# XBand Sport Wearable

This repository will contain a large amount of the source code that will be used for the XBand project, by XBand Electronics Inc. The code is mainly written in C++. 

There are 3 Main Parts of the Project:
  1. The Wearable
  2. The Database
  3. The Computer Software

## The Wearable

The code in this part will be entirely written in C++. Scripts should be written for three specific purposes.
- Measuring heart rate (and temperature) using the MAX30102 sensor.
- Transmitting data through SMS using the GSM module (SIM800L).
- Finding the user's location using the GSM module (SIM800L.

## The Database

A database should be created that runs locally on a computer. It will log data received by the GSM module of the wearable. It should be an SQL database, with the ability to run Node.js.

## The Computer Software

This is the software that will be run by the computer at the receiving center. The greatest part will be a web-like application, which will run on a browser, despite the fact that there is no need to connect to the internet. The application is the interface with which the center's staff will interact, and it will be written in JavaScript using the React.js framework.

Another part of the center's software involves the code for the receiving arduino device which will be written in C++. It will contain two main parts:
- Reading data from the SMS that it receives
- Log data on the Computer's database
