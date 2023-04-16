// make sure esp8266 board is installed
#include <Wire.h>
#include "SH1106Wire.h"
SH1106Wire display(0x3c, D2, D1); // (d2-- sda) (d1--scl)

void setup() {
Serial.begin(9600);

//initalise the display
  display.init();

//flips the screen vertically
  display.flipScreenVertically();

//set the font and size
  display.setFont(ArialMT_Plain_16);

//sets the alignment to left
  display.setTextAlignment(TEXT_ALIGN_LEFT);

 }

void loop() {

// this logic below convert numbers to string as number is not supported

  // creating a variable
  int diff = 82;
  //create an empty string to store number
  char str[20];

  //used sprintf to convert number stored in diff to string
  //and then save it to str
  sprintf(str, "%d", diff);

// set font and size then clear the display
  display.setFont(ArialMT_Plain_10);
  display.clear();

//used the drawString function to draw string at cordinate (0,0)
  display.drawString(0,0, "Difference is :");

//this time we are displaying number, srt is where number is stored
  display.drawString(68,0, str); // display int

// finally displaying the contents
  display.display();

}
