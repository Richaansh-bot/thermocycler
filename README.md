# Thermocycler Motor Driver with Peltier Module

This code is designed to control the temperature of a thermocycler using a motor driver and Peltier module. It includes functions for setting and maintaining the desired temperature, as well as for running thermal cycling protocols. The code is written in C++ and has been tested on an Arduino.

## Hardware Requirements

-   Arduino board
-   Motor driver
-   Peltier module
-   Thermocouple

## Pin Configuration

The following pins are used in the code:

-   thermoDO: Pin 4
-   thermoCS: Pin 5
-   thermoCLK: Pin 6
-   RPWM: Pin 10
-   LPWM: Pin 11
-   REN: Pin 8
-   LEN: Pin 9

## Functions

The main function in the code is the `loop()` function, which runs continuously. This function reads the current temperature from the thermocouple and calculates the error between the set temperature and the current temperature. It then uses a PID control algorithm to adjust the output to the motor driver and maintain the desired temperature.

Other functions in the code include:

-   `setup()`: This function sets the pin modes and initializes the serial communication.

## Variables

The following variables are used in the code:

-   `set`: The desired temperature (in Celsius)
-   `cur`: The current temperature (in Celsius)
-   `error`: The difference between the set temperature and the current temperature
-   `prev_err`: The error in the previous loop iteration
-   `Time`: The current time (in milliseconds)
-   `P`: The proportional term of the PID control algorithm
-   `I`: The integral term of the PID control algorithm
-   `D`: The derivative term of the PID control algorithm
-   `kp`: The proportional gain of the PID control algorithm
-   `kd`: The derivative gain of the PID control algorithm
-   `ki`: The integral gain of the PID control algorithm

## Additional Notes

The code includes a number of constants and variables that can be adjusted to fine-tune the performance of the thermocycler. The PID gains (`kp`, `kd`, and `ki`) can be modified to achieve the desired level of control over the temperature. The `delay` in the `loop()` function can also be adjusted to change the frequency at which the temperature is measured and the motor driver is adjusted.
