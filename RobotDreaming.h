// Include libraries for drawing to the OLED screen
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

// Include libraries for the stepper motors
#include <AccelStepper.h>
#include <AFMotor.h>

// Declare the OLED screen
Adafruit_SSD1306 OLEDScreen(4); //OLED_RESET

// Declare the motors (for AFMotor lib)
AF_Stepper motor1(2048, 1);
AF_Stepper motor2(2048, 2);

// Default configurations for stepper motor control
float maxSpeedLeft = 400;
float accelerationLeft = 100;
float moveToLeft = 100000;

float maxSpeedRight = 400;
float accelerationRight = 100;
float moveToRight = 1000000;

// These methods are used as 'wrappers' so that we can use 2 motor libraries together
// Note that each step can be SINGLE, DOUBLE, INTERLEAVE or MICROSTEP
void forwardstep1() {
  motor1.onestep(FORWARD, DOUBLE);
}
void backwardstep1() {
  motor1.onestep(BACKWARD, DOUBLE);
}
// wrappers for the second motor!
void forwardstep2() {
  motor2.onestep(BACKWARD, DOUBLE);
}
void backwardstep2() {
  motor2.onestep(FORWARD, DOUBLE);
}

// Declare the AccelStepper motors (which 'wrap' the AFMotor lib motors)
AccelStepper stepper1(forwardstep1, backwardstep1);
AccelStepper stepper2(forwardstep2, backwardstep2);

// Many values are required for the action of the rotary controllers
// TODO: Can these be abstracted out to a separate class or file?
int rotaryEncoder1_set_clkPin = 49;
int rotaryEncoder1_set_dtPin = 47;
int rotaryEncoder1_set_btnPin = 45;
int rotaryEncoder1_read_clkPin;
int rotaryEncoder1_read_dtPin;
long rotaryEncoder1_positionCount = 93;
int rotaryEncoder1_previousRead_clkPin;

long rotaryEncoder2_positionCount = 25;
long rotaryEncoder3_positionCount = 35;
long rotaryEncoder4_positionCount = 100;

int buttonStart = 23;
int buttonStop = 27;
int buttonIncrement = 25;
int buttonMode = 27;

int drawMode = 1;
int numberOfModes = 2; //number of draw modes

// TODO: this needs a clearer name
int increment = 1;
// TODO: this needs either a clearer name or better expanation
boolean isDrawing = false;
// TODO: better nomenclature and explanation
int sensor1pin;
// TODO: explain
int rotaryMode = 0;

// see notes in UserInterfaceControl - wheel diameter of robot
float wheelDiam = 79;

