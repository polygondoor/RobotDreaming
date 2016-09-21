/*
  Handles the array of buttons
*/

void setupButtons(){
  // TODO: These pinModes need to be abstracted to variables
  // OR they should be clearly marked.
  pinMode(buttonStart, INPUT_PULLUP);
  pinMode(buttonIncrement, INPUT_PULLUP);
  pinMode(buttonStop, INPUT_PULLUP);
}

