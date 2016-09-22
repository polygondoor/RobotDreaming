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
      cycleRotaryIncrement();
      // TODO: display rotary increment somehow
      report();
      delay(100);
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
