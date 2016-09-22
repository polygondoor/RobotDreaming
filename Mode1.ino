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
      // increment preset_index
      preset_index = preset_index + 1;

      // check if at end of preset length, wrap
      if (preset_index >= (sizeof (presets) / sizeof (*presets)) ){
        preset_index = 0;
      }

      // make sure preset values are captured
      setting_left_wheel_distance = presets[preset_index][0]; 
      setting_left_wheel_speed = presets[preset_index][1];   // in mm
      setting_right_wheel_speed = presets[preset_index][2];  // arbitrary scale
      setting_right_wheel_distance = presets[preset_index][3]; // in mm

      delay(200);
      // display new settings on little screen
      report();
    }

    // Change increment.
    if (digitalRead(buttonIncrement) == LOW) {
      cycleRotaryIncrement();
      // TODO: display rotary increment somehow
      report();
      delay(150);
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
