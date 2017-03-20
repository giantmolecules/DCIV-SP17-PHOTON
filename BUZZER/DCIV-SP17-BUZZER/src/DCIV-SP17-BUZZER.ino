/*
 * Project DCIV-SP17-BUZZER
 * Description: Makes some noise with a piezo buzzer on pin D3
 * Author: Brett Ian Balogh
 * Date: March 20, 2017
 */

#define BUZZ_PIN 3

void setup() {

  pinMode(BUZZ_PIN, OUTPUT);

}


void loop() {

for(int i = 0; i < 5; i++){
  tone(BUZZ_PIN, i*1000, 200);
  delay(500);
  }

}
