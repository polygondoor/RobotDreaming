/*
  Handles the OLED display objects
*/

Adafruit_SSD1306 OLEDScreen(4); //OLED_RESET

void setupDisplay(){
  // Initialise the OLED display
  // Note: it is necessary to change a value in the Adafruit_SSD1306 library to set the screen size to 128x64
  OLEDScreen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  OLEDScreen.clearDisplay();

  // Set some default values for writing to the OLED screen
  OLEDScreen.setTextColor(WHITE);

  // Write "ARTBOT" in big
  OLEDScreen.setTextSize(3);
  OLEDScreen.setCursor(10, 10); // this moves our cursor right back to the top left pixel.. we should talk about this.
  OLEDScreen.print("ARTBOT"); //this copies some text to the screens memory

  // Write "Hello" in small
  OLEDScreen.setTextSize(2);
  OLEDScreen.setCursor(20, 45);
  OLEDScreen.print("Hello :)"); //this copies some text to the screens memory
  OLEDScreen.display();

  // TODO: Can we remove this?
  OLEDScreen.setTextSize(3);
}

/*
 *
 *  SCREEN HANDLING
 *
 */

void report() {
  OLEDScreen.clearDisplay();

  OLEDScreen.setTextSize(1);
  OLEDScreen.setCursor(30 , 0);
  OLEDScreen.print("Speed: 0-40");
  OLEDScreen.setCursor(25 , 36);
  OLEDScreen.print("Distance: mm");

  OLEDScreen.setTextSize(2);

  OLEDScreen.setCursor(70, 50);

  // mat working on mouse over for 1 encoder
  if (rotaryMode == 0) {
    OLEDScreen.setTextColor(0);
    OLEDScreen.fillRect(68, 48, 62, 26, 1);
    OLEDScreen.print(setting_right_wheel_distance); //this copies some text to the screens memory
    OLEDScreen.setTextColor(1);
    OLEDScreen.setCursor(70, 12);
    OLEDScreen.print(setting_right_wheel_speed); //this copies some text to the screens memory
    OLEDScreen.setCursor(0, 12);
    OLEDScreen.print(setting_left_wheel_speed); //this copies some text to the screens memory
    OLEDScreen.setCursor(0, 50);
    OLEDScreen.print(setting_left_wheel_distance); //this copies some text to the screens memory

  } else if (rotaryMode == 1) {
    
    OLEDScreen.print(setting_right_wheel_distance); //this copies some text to the screens memory
    OLEDScreen.setCursor(70, 12);
    OLEDScreen.fillRect(68,12, 62, 16, 1);
    OLEDScreen.setTextColor(0);
    OLEDScreen.print(setting_right_wheel_speed); //this copies some text to the screens memory
    OLEDScreen.setTextColor(1);
    OLEDScreen.setCursor(0, 12);
    OLEDScreen.print(setting_left_wheel_speed); //this copies some text to the screens memory
    OLEDScreen.setCursor(0, 50);
    OLEDScreen.print(setting_left_wheel_distance); //this copies some text to the screens memory

  } else if (rotaryMode == 2) {
    
    OLEDScreen.print(setting_right_wheel_distance); //this copies some text to the screens memory
    OLEDScreen.setTextColor(1);
    OLEDScreen.setCursor(70, 12);
    OLEDScreen.print(setting_right_wheel_speed); //this copies some text to the screens memory
    OLEDScreen.setCursor(0, 12);
    OLEDScreen.fillRect(0,12,62,16, 1);
    OLEDScreen.setTextColor(0);
    OLEDScreen.print(setting_left_wheel_speed); //this copies some text to the screens memory
    OLEDScreen.setTextColor(1);
    OLEDScreen.setCursor(0, 50);
    OLEDScreen.print(setting_left_wheel_distance); //this copies some text to the screens memory

  } else if (rotaryMode == 3) {
   
    OLEDScreen.print(setting_right_wheel_distance); //this copies some text to the screens memory
    OLEDScreen.setTextColor(1);
    OLEDScreen.setCursor(70, 12);
    OLEDScreen.print(setting_right_wheel_speed); //this copies some text to the screens memory
    OLEDScreen.setCursor(0, 12);
    OLEDScreen.print(setting_left_wheel_speed); //this copies some text to the screens memory
    OLEDScreen.setCursor(0, 50);
    OLEDScreen.fillRect(0, 46 , 62, 20, 1);
    OLEDScreen.setTextColor(0);
    OLEDScreen.print(setting_left_wheel_distance); //this copies some text to the screens memory
    OLEDScreen.setTextColor(1);
    
  }

  OLEDScreen.display();
}

void message(String text) {
  OLEDScreen.clearDisplay();
  OLEDScreen.setTextSize(1);
  OLEDScreen.setCursor(20, 40);
  OLEDScreen.print(text); //this copies some text to the screens memory
  OLEDScreen.display();
}

void message(int text) {
  OLEDScreen.clearDisplay();
  OLEDScreen.setTextSize(1);
  OLEDScreen.setCursor(20, 40);
  OLEDScreen.print(text); //this copies some text to the screens memory
  OLEDScreen.display();
}

void displayStartMessage() {
  displayCountDown(3);
  delay(1000);
  displayCountDown(2);
  delay(1000);
  displayCountDown(1);
  delay(1000);

  OLEDScreen.clearDisplay();
  OLEDScreen.setTextSize(4);
  OLEDScreen.setCursor(40, 20);
  OLEDScreen.print(":)"); //this copies some text to the screens memory

  OLEDScreen.setTextSize(1);
  OLEDScreen.setCursor(0, 0);
  OLEDScreen.print(setting_left_wheel_speed); //this copies some text to the screens memory
  OLEDScreen.setCursor(110, 0);
  OLEDScreen.print(setting_right_wheel_speed); //this copies some text to the screens memory

  OLEDScreen.setCursor(0, 50);
  OLEDScreen.print(setting_left_wheel_distance); //this copies some text to the screens memory

  OLEDScreen.setCursor(110, 50);
  OLEDScreen.print(setting_right_wheel_distance); //this copies some text to the screens memory

  OLEDScreen.display();
}

void displayCountDown(int count) {
  OLEDScreen.clearDisplay();
  OLEDScreen.setTextSize(2);
  OLEDScreen.setCursor(10 , 5);
  OLEDScreen.print("STEP BACK");

  OLEDScreen.setTextSize(1);
  OLEDScreen.setCursor(10 , 40);
  OLEDScreen.print("Starting in: "); //this copies some text to the screens memory

  OLEDScreen.setTextSize(4);
  OLEDScreen.setCursor(94 , 30);
  OLEDScreen.print(count); //this copies some text to the screens memory
  OLEDScreen.display();
}


