/* Polygon Door Robot Dreaming */
#include "RobotDreaming.h"

void mode_1(){

  // A custom mode example
  message("Custom Mode. Press Start");

  while ( waitForStartButton() ) {
    readModeButton();
    if (drawingMode != 1) return;
  }

  // go forwards
  turn_wheels_mm(250, 250);

  // turn
  turn_wheels_mm(250, -250);

  // do a spiral
  for (int i = 20 ; i > 0 ; i--) {
    turn_wheels_mm(20, i);
  }

  message("DONE!");

}