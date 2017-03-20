
#include "simple-OSC.h"

#define STATUS_PIN 7

//
// VERY IMPORTANT: Set these to the IP address and port of the receiving application.
IPAddress outIp(192, 168, 1, 4);//your computer IP
unsigned int outPort = 8000; //computer incoming port
//
//

String localIpString;
int theTime;
Timer publishTimer(2000, timedPublish);
UDP Udp;

void setup() {

    localIpString = WiFi.localIP();
    Udp.begin(0);

    pinMode(STATUS_PIN, OUTPUT);

    Particle.function("setIP", setIP);
    Particle.variable("time", theTime);
    Particle.variable("localIP", localIpString);

    publishTimer.start();
}

void loop() {

    theTime = millis();
}

int setIP(String args){
    // Doesn't do anything yet.
    // A reminder to:
    // set remote IP address;
    return 1;
}

void timedPublish(){
    OSCMessage outMessage("/timer");
    outMessage.addInt(theTime);
    outMessage.send(Udp,outIp,outPort);
    status();
}

void status(){
  digitalWrite(STATUS_PIN, HIGH);
  delay(100);
  digitalWrite(STATUS_PIN, LOW);
}
