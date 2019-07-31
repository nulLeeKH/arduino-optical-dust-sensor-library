# arduino-optical-dust-sensor-library

## About

The library for arduino to measure dust density with optical dust sensors.

## Functions

### OpticalDustSensor

#### Constructor of OpticalDustSensor class.

```cpp
OpticalDustSensor(int ledPin, int sensorPin);
```

####  Arguments

##### ledPin

- The digital OUTPUT pin which connected with LED of sensor.

##### sensorPin

- The analog INPUT pin which connected with V<sub>O</sub> of sensor.

### Setting

#### Initial set-up function for use sensor.

```cpp
void Setting(float samplingTime, float deltaTime, float sleepTime, float voc, float sensitivity);
```

####  Arguments

##### samplingTime

- Length of time to turn on LED. [μs]

##### deltaTime

- Time from LED off to highest output value. [μs]

##### voc

- Voltage when there is no dust. [V]

##### sensitivity

- Voltage rise per 1μg/m<sup>3</sup> [V/(1μg/m<sup>3</sup>)]

### ReadValue

#### A function for read values from a sensor.

```cpp
float ReadValue();
```

####  Return

##### float

- Dust density entered into the sensor.

## Patch Note

### v1.0.0-alpha

- Initial release
