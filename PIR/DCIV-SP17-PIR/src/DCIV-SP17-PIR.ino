/*
 * Project DCIV-SP17-BUZZER
 * Description: Read a PIR on pin D0
 * Author: Brett Ian Balogh
 * Date: March 20, 2017
 */

#define PIR_PIN 0
#define LED_PIN 7

bool pirVal = 0;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}


void loop() {
  pirVal = digitalRead(PIR_PIN);
  digitalWrite(LED_PIN, pirVal);
}
