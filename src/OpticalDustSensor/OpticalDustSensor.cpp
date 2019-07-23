/*
version : v1.0.0-alpha

MIT License

Copyright (c) 2019 Kyung-ha Lee <i_am@nulleekh.com>

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

#include "Arduino.h"
#include "OpticalDustSensor.h"

OpticalDustSensor::OpticalDustSensor(int ledPin, int sensorPin) {
    _ledPin = ledPin;
    _sensorPin = sensorPin;

    pinMode(_ledPin, OUTPUT);
}

void OpticalDustSensor::Setting(float samplingTime, float deltaTime, float sleepTime, float voc, float sensitivity) {
    _samplingTime = samplingTime;
    _deltaTime = deltaTime;
    _sleepTime = sleepTime;
    _voc = voc;
    _sensitivity = sensitivity;
}

float OpticalDustSensor::ReadValue() {
    digitalWrite(_ledPin, LOW);
    delayMicroseconds(_samplingTime);
    sensorInput = analogRead(_sensorPin);
    delayMicroseconds(_deltaTime);
    digitalWrite(_ledPin, HIGH);
    delayMicroseconds(_sleepTime);
    //Measure dust density in air

    sensorInput = ((sensorInput*5.0/1024.0)-_voc)/_sensitivity;
    //Change the unit to V and change the unit to ug/m^3

    return sensorInput;
    //Return result
}
