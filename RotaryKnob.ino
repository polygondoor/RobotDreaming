/*
  Handles the rotary controller
*/

void setupRotaryEncoder(){
  pinMode(rotaryEncoder1_set_clkPin, INPUT); // clk
  pinMode(rotaryEncoder1_set_dtPin, INPUT); // dt
  pinMode(rotaryEncoder1_set_btnPin, INPUT_PULLUP); // btn
}

/*
 * This method reads all the rotary encoders
 */
void readRotaryEncoders() {
  rotaryEncoder1_read_clkPin = digitalRead(rotaryEncoder1_set_clkPin); // orange cable, CLK
  rotaryEncoder1_read_dtPin = digitalRead(rotaryEncoder1_set_dtPin);

  // rotaryMode; // Can be 0 1 2 or 3 (depending on which value we are changing)

  if ((rotaryEncoder1_read_clkPin != rotaryEncoder1_previousRead_clkPin) && (rotaryEncoder1_read_clkPin == LOW)) { // Knob Rotated l when aVal changes, BUT use only if aVal is LOW.
    if (rotaryEncoder1_read_dtPin == LOW) {
      // INCREMENT
      if (rotaryMode == 0) {
        setting_right_wheel_distance += increment;
      }
      else if (rotaryMode == 1) {
        setting_right_wheel_speed += increment;
        if (setting_right_wheel_speed > 50) setting_right_wheel_speed = 50;
      }
      else if (rotaryMode == 2) {
        setting_left_wheel_speed += increment;
        if (setting_left_wheel_speed > 50) setting_left_wheel_speed = 50;
      }
      else {
        setting_left_wheel_distance += increment;
      }
      report();
    }
    else {
      // DECREMENT
      if (rotaryMode == 0) {
        setting_right_wheel_distance -= increment;
      }
      else if (rotaryMode == 1) {
        setting_right_wheel_speed -= increment;
      }
      else if (rotaryMode == 2) {
        setting_left_wheel_speed -= increment;
      }
      else {
        setting_left_wheel_distance -= increment;
      }
      report();
    }
  }

  rotaryEncoder1_previousRead_clkPin = rotaryEncoder1_read_clkPin; // Don’t forget this
}

