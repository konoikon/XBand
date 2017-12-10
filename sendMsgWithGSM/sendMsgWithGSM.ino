/*
 * Authors: Ioannis Stamoulis: 20175042@student.anatolia.edu.gr,
 *          Konstantinos Oikonomou: 20151182@student.anatolia.edu.gr,
 *          
 * Purpose: The purpose of this arduino script is to initialize the
 *          SIM800L GSM module and send a single SMS to the target
 *          phone number.
 * 
 *                           NEEDED PINOUT
 *                _________________________________
 *                Arduino Pro Mini --> GSM Module
 *                --------------------------------
 *                          GND --> GND
 *                        RX 1  --> TX
 *                        TX 0  --> RX
 *                          RST --> RST
 *                
 *                 
 */

// TODO: We need to modify the library used, because it uses different pinout!
#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 

Sim800l gsm;  // initialize the module piece of hardware

char text="Send nudes"; //buffer to store message
char number="6996594922"; //phone number to send message
bool error; // the sendSms function returns a boolean which is true if an error occurred

void setup(){
    gsm.begin(); // initializate the library.
    error = gsm.sendSms(number, text); // by setting the bool to the function we also call it
    // the above will change as we will put the function in the "loop" part depending on when we want to
    // send the SMS messages.
}

void loop(){
  // If the sendSms function was here, we would send SMSs all the time...
  // We should do nothing...
}
