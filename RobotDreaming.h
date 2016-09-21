// Include libraries for drawing to the OLED screen
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

// Include libraries for the stepper motors
#include <AccelStepper.h>
#include <AFMotor.h>

// Declare the motors (for AFMotor lib)
AF_Stepper motor1(2048, 1);
AF_Stepper motor2(2048, 2);

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
AccelStepper stepper_r(forwardstep1, backwardstep1);
AccelStepper stepper_l(forwardstep2, backwardstep2);

// These are settings captured by the UI settings
long setting_right_wheel_distance = 93;	// in mm
long setting_right_wheel_speed = 25;	// arbitrary scale
long setting_left_wheel_speed = 35;		// in mm
long setting_left_wheel_distance = 100;	// arbitrary scale

// Many values are required for the action of the rotary controllers
// TODO: Can these be abstracted out to a separate class or file?
int rotaryEncoder1_set_clkPin = 49;
int rotaryEncoder1_set_dtPin = 47;
int rotaryEncoder1_set_btnPin = 45;
int rotaryEncoder1_read_clkPin;
int rotaryEncoder1_read_dtPin;
int rotaryEncoder1_previousRead_clkPin;

// TODO: better nomenclature and explanation
int sensor1pin;
// TODO: explain
int rotaryMode = 0;

// see notes in UserInterfaceControl - wheel diameter of robot
float wheelDiam = 79;

