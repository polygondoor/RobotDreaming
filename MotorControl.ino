/* 
 * Handles the motors
 */
 
// register the number of steps by processing the captured settings
long steps = 0;

/*
 * This method captures all the knob settings
 * and gives them to the steppers.
 */
void captureSettings() {

  // so if I make the the knob think in mm, then
  // 1 turn is  (wheelDiam * 3.1416)
  // So, if someone says 100mm, then how many turns is that?
  // turns = configuredDistance / (wheelDiam * 3.1416)
  // given that 1 turn is 2048 steps then
  // turns in steps = 2048 * configuredDistance / (wheelDiam * 3.1416)

  // RIGHT WHEEL (knobs 1 and 2 (speed))
  stepper1.setMaxSpeed(rotaryEncoder2_positionCount * 10); // max 400
  stepper1.setAcceleration(accelerationRight);
  // calculate how many steps to go (here we divide by 2 because the bounce goes fowards and backwards)
  steps = (rotaryEncoder1_positionCount * 2048 / (wheelDiam * 3.1416) / 2);
  stepper1.moveTo(steps);
  // message(String(steps) );

  // LEFT WHEEL (knobs 4 and 3(speed))
  stepper2.setMaxSpeed(rotaryEncoder3_positionCount * 10); // max 400
  stepper2.setAcceleration(accelerationLeft);
  steps = (rotaryEncoder4_positionCount * 2048 / (wheelDiam * 3.1416) / 2);
  stepper2.moveTo(steps);
}

/*
 * Utility to stop steppers, and set them back to a 0 position
 */
void stopAndResetSteppers() {
  // stop everything
  stepper1.stop(); // Stop as fast as possible: sets new target
  stepper1.runToPosition();
  stepper2.stop(); // Stop as fast as possible: sets new target
  stepper2.runToPosition();

  // reset the steppers to position 0
  stepper1.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);

  // tell the system that we are no longer drawing
  isDrawing = false;
  delay(1000);
}
