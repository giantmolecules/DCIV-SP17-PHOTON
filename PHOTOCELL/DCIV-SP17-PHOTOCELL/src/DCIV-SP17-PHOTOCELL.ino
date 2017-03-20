/*
 * Project DCIV-SP17-BUZZER
 * Description: Read a light sensor attached to pin A0
 * Author: Brett Ian Balogh
 * Date: March 20, 2017
 */

int lightVal = 0;
int brightness = 0;

void setup() {
  RGB.control(true);
  RGB.brightness(255);
  RGB.color(255,255,255);
}


void loop() {
  lightVal = analogRead(0);
  brightness = map(lightVal, 0, 4095, 255,0);
  RGB.brightness(brightness);
}
