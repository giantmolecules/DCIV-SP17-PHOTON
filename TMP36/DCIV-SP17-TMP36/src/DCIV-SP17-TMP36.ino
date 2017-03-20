/*
 * Project DCIV-SP17-BUZZER
 * Description: Read a temp sensor on Pin A0
 * Author: Brett Ian Balogh
 * Date: March 20, 2017
 */

#define TEMP_PIN 0

int tempVal = 0;
int colorVal = 0;

void setup() {
  RGB.control(true);
  RGB.brightness(255);
  RGB.color(255,255,255);
}


void loop() {
  tempVal = analogRead(TEMP_PIN);
  colorVal = map(tempVal, 0, 4095, 0, 255);
  RGB.color(colorVal, 0, 255-colorVal);
}
