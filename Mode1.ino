// holds the increment amount that the rotary controller uses
int rotary_increment = 1;

// Allows knowing if the steppers are currently activated or just waiting.
boolean isDrawing = false;

void mode1_loop(){
  
  if (!isDrawing) {
    readRotaryEncoders();

    // Choose parameter. This controls which value will be modified by the knob
    if (digitalRead(rotaryEncoder1_set_btnPin) == LOW) {
      rotaryMode = (rotaryMode + 1) % 4;
      report();
      delay(500);
    }

    // Choose preset
    if (digitalRead(buttonPresets) == LOW) {
      // change preset

      // increment preset number

      // check if at end of preset length

      // display new settings on little screen
      report();
    }

    // Change increment.
    if (digitalRead(buttonIncrement) == LOW) {
      if (rotary_increment == 1) {
        rotary_increment = 10;
        message("Increment 10");
      }
      else if (rotary_increment == 10) {
        rotary_increment = 100; message("Increment 100");
      }
      else if (rotary_increment == 100) {
        rotary_increment = 1000; message("Increment 1000");
      }
      else if (rotary_increment == 1000) {
        rotary_increment = 1; message("Increment 1");
      }
      delay(500);
      report();
    }

    // Push to start
    if (digitalRead(buttonStart) == LOW) {
      isDrawing = true;
      displayStartMessage();
      captureSettings();
    }

  } else {
    if (stepper_r.distanceToGo() == 0) {
      // Bounce the right wheel direction
      stepper_r.moveTo(-stepper_r.currentPosition());
    }
    if (stepper_l.distanceToGo() == 0) {
      // Bounce the left wheel direction
      stepper_l.moveTo(-stepper_l.currentPosition());
    }
    stepper_r.run();
    stepper_l.run();

    // Push to stop
    if (digitalRead(buttonStart) == LOW) {
      message("Stop!");
      stopAndResetSteppers();
      report();
    }

  }
}
