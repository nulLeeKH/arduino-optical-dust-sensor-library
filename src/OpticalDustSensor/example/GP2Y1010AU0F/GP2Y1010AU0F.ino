/*
version : v1.0.0-alpha

MIT License

Copyright (c) 2019-2020 Lee Kyung-ha <i_am@nulleekh.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

#include <OpticalDustSensor.h>

OpticalDustSensor dSensor(2, 0);
//Create dustsensor object to get data from dustsensor
//Attach the dustsensor on D2 to LED and A0 to Vo

float dustDensity;

void setup() {
  Serial.begin(9600);
  //Start serial communication with 9600 bitrate
  
  dSensor.Setting(280, 40, 9680, 0.9, 0.0005);
  //Set measuring time for sensor (Use GP2Y1010AU0F)
}

void loop() {
  dustDensity = dSensor.ReadValue();
  //Get data from dustsensor
  
  Serial.println(dustDensity);
  //Print dust density value received from the sensor into the serial
  
  delay(1000);
  //Get data every 1 seconds
}
