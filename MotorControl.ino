/* 
 * Handles the motors
 */

// Default configurations for stepper motor control
float maxSpeedLeft = 400;
float accelerationLeft = 100;

float maxSpeedRight = 400;
float accelerationRight = 100;
 
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

  // RIGHT WHEEL 
  stepper_r.setMaxSpeed(setting_right_wheel_speed * 10); // max 400
  stepper_r.setAcceleration(accelerationRight);
  // calculate how many steps to go (here we divide by 2 because the bounce goes fowards and backwards)
  steps = (setting_right_wheel_distance * 2048 / (wheelDiam * 3.1416) / 2);
  stepper_r.moveTo(steps);
  // message(String(steps) );

  // LEFT WHEEL 
  stepper_l.setMaxSpeed(setting_left_wheel_speed * 10); // max 400
  stepper_l.setAcceleration(accelerationLeft);
  steps = (setting_left_wheel_distance * 2048 / (wheelDiam * 3.1416) / 2);
  stepper_l.moveTo(steps);
}

void arc(int d_left, int d_right, int time){
  //stepper.setMaxSpeed(50);     
  //stepper.setSpeed(50);        

  //stepper.runSpeed();
}

/*
 * Utility to stop steppers, and set them back to a 0 position
 */
void stopAndResetSteppers() {
  // stop everything
  stepper_r.stop(); // Stop as fast as possible: sets new target
  stepper_r.runToPosition();
  stepper_l.stop(); // Stop as fast as possible: sets new target
  stepper_l.runToPosition();

  // reset the steppers to position 0
  stepper_r.setCurrentPosition(0);
  stepper_l.setCurrentPosition(0);

  // tell the system that we are no longer drawing
  isDrawing = false;
  delay(1000);
}
