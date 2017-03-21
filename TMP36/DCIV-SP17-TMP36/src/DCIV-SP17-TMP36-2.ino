int analogVal = 0;
double voltsPerDiv = 0.0;
double voltage = 0.0;
double temperatureC = 0.0;
int tempVal = 0;
int rgbVal = 0;

void setup(){
    Particle.variable("TEMP", analogVal);
    Particle.variable("VoltsPerDiv", voltsPerDiv);
    Particle.variable("Voltage", voltage);
    Particle.variable("TemperatureC", temperatureC);
    RGB.control(true);
}

void loop(){
    analogVal = analogRead(0);
    voltsPerDiv = 3.3 / 4096;
    voltage = analogVal * voltsPerDiv;
    temperatureC = (voltage - 0.5) * 100;
    tempVal = constrain(analogVal, 960, 1000);
    rgbVal = map(tempVal, 960, 1000, 0, 255);
    RGB.color(rgbVal, 0, 255-rgbVal);
}
