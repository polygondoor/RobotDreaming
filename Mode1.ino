// TODO: this needs a clearer name
int increment = 1;

// Allows knowing if the steppers are currently activated or just waiting.
boolean isDrawing = false;

void mode1_loop(){
  
  if (!isDrawing) {
    readRotaryEncoders();

    // See if mode button has been pressed
    // This controls which value will be modified by the knob
    if (digitalRead(rotaryEncoder1_set_btnPin) == LOW) {
      rotaryMode = (rotaryMode + 1) % 4;
      report();
      delay(500);
    }

    // push button to change increment
    // TODO: Use a parameter, not a value in the digitalRead param
    if (digitalRead(buttonIncrement) == LOW) {
      if (increment == 1) {
        increment = 10;
        message("Increment 10");
      }
      else if (increment == 10) {
        increment = 100; message("Increment 100");
      }
      else if (increment == 100) {
        increment = 1000; message("Increment 1000");
      }
      else if (increment == 1000) {
        increment = 1; message("Increment 1");
      }
      delay(500);
      report();
    }

    // Push button to start
    // TODO: Use a parameter, not a value in the digitalRead param
    if (digitalRead(buttonStart) == LOW) {
      isDrawing = true;
      displayStartMessage();
      captureSettings();
    }

  } else {
    if (stepper_r.distanceToGo() == 0) {
      // Reset the whole device (but user needs to wait till wheel bounces)
      // TODO: Use a parameter, not a value in the digitalRead param
      stepper_r.moveTo(-stepper_r.currentPosition());
    }
    if (stepper_l.distanceToGo() == 0) {
      stepper_l.moveTo(-stepper_l.currentPosition());
    }
    stepper_r.run();
    stepper_l.run();

    if (digitalRead(buttonStart) == LOW) {
      message("Stop!");
      // stop and reset
      stopAndResetSteppers();
      report();
    }

  }
}
