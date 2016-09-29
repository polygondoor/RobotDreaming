/* Polygon Door Artbot */
#include "RobotDreaming.h"

/*
 * A Custom mode example 
 */ 
void customDrawingMode(){

  // Displays a message on Artbot's little screen
  message("Custom Mode. Press Start");

  // Wait for the start button to be pressed.
  // This code also makes sure that it is possible to return to the default drawing mode
  while ( waitForStartButton() ) {
    readModeButton();
    if (drawingMode != 1) return;
  }

  // Turn both wheels in the same directiom
  turn_wheels_mm(250, 250);

  // Pivot by turning both wheels in opposite directions
  turn_wheels_mm(250, -250);

  // Use a loop to draw a spiral
  for (int i = 20 ; i > 0 ; i--) {
    turn_wheels_mm(20, i);
  }

  // Display another message
  message("DONE!");

  // And wait 2 seconds, so that people may see the "Done" display message
  delay(2000);

}