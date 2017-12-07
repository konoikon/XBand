#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 
Sim800l Sim800l;  //to declare the library
char text="Send nudes"; //buffer to store message
char number="6996594922"; //phone number to send message
int cnt;
bool error; //to catch the response of sendSms

void setup(){
    Sim800l.begin(); // initializate the library. 
    
}

void loop(){

      Sim800l.sendSms(number, text);

      
}
