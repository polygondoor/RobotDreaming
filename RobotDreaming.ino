/* Polygon Door Robot Dreaming */
#include "RobotDreaming.h"

void setup()
{
  setupDisplay();  
  setupRotaryEncoder();
  setupButtons();
}

void loop() {
  mode1();
}
