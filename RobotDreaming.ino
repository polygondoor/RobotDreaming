/* Polygon Door Robot Dreaming */
#include "RobotDreaming.h"

void setup()
{
  setupDisplay();  
  setupRotaryEncoder();
  setupButtons();
}

void loop() {
  mode1_loop();

  /*
  // A custom mode example
  message("Custom Mode. Press Start");

  while (digitalRead(buttonStart) == HIGH) {
  	// wait for Start button to be pressed
  }

  // go forwards
  turn_wheels_mm(250, 250);

  // turn
  turn_wheels_mm(250, -250);

  // make a spiral!
  for (int i = 20 ; i > 0 ; i--) {
  	turn_wheels_mm(20, i);
  }

  message("DONE!");
  */
  
}
