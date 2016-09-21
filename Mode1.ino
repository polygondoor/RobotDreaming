void mode1(){
  
  if (!isDrawing) {
    readRotaryEncoders();

    // TODO: remove test code (perhaps after IR is working)
    /*
      digitalWrite(23, 255);
      sensor1pin = analogRead(23);
      message(analogRead(1) );

      Serial.print("sensor1:");
      Serial.println(sensor1pin);
      delay(100);
    */

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

    if (digitalRead(buttonMode) == LOW) {

      drawMode = (drawMode + 1) % numberOfModes;

    }

  } else {
    if (stepper1.distanceToGo() == 0) {
      // Reset the whole device (but user needs to wait till wheel bounces)
      // TODO: Use a parameter, not a value in the digitalRead param
      stepper1.moveTo(-stepper1.currentPosition());
    }
    if (stepper2.distanceToGo() == 0) {
      stepper2.moveTo(-stepper2.currentPosition());
    }
    stepper1.run();
    stepper2.run();
    if (digitalRead(buttonStop) == LOW) {
      // stop and reset
      stopAndResetSteppers();
      report();
    }
  }
}
