
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

#define Matrix_left 0
#define Matrix_right 1

Adafruit_BicolorMatrix matrix [2] = {
  Adafruit_BicolorMatrix(), Adafruit_BicolorMatrix()
};

static const uint8_t matrixAddr[] = { 0x70, 0x71 };


void setup() {
  
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  
  
  
//  matrix.begin(0x70);  // pass in the address
//Adafruit_8x8matrix matrix[2];


 for(uint8_t i=0; i<2; i++) {
   // matrix[i] = Adafruit_BicolorMatrix();
    matrix[i].begin(matrixAddr [i]);
  }
}
static const uint8_t PROGMEM
   
   blinkleft[] =
{B00000000,
B00000000,
B00000000,
B10000001,
B11000001,
B01111110,
B01010100,
B01010100},

notblinkright[] =
 {B00111100,
B01111110,
B11111111,
B11100111,
B11100111,
B11111111,
B01111110,
B00111100},

right[] =

{B00111100,
B01111110,
B11111111,
B11110011,
B11110011,
B11111111,
B01111110,
B00111100},

left[] =

{B00111100,
B01111110,
B11111111,
B11001111,
B11001111,
B11111111,
B01111110,
B00111100},

   look[] =
 
 {B00111100,
B01111110,
B11111111,
B11100111,
B11100111,
B11111111,
B01111110,
B00111100};


void loop() {
 
//1a
   matrix[0].clear();
  matrix[0].drawBitmap(0, 0, look, 8, 8, LED_GREEN);
  matrix[0].writeDisplay();
  //delay(500);
  
  //2a
    matrix[1].clear();
  matrix[1].drawBitmap(0, 0, look, 8, 8, LED_GREEN);
 matrix[1].writeDisplay();
  delay(500);
  
 //1b 
  matrix[0].clear();
  matrix[0].drawBitmap(0, 0, left, 8, 8, LED_GREEN);
  matrix[0].writeDisplay();
 // delay(500);
 //2b 
  matrix[1].clear();
  matrix[1].drawBitmap(0, 0, left, 8, 8, LED_GREEN);
 matrix[1].writeDisplay();
  delay(500);
  
  
 //1c 
  matrix[0].clear();
  matrix[0].drawBitmap(0, 0, look, 8, 8, LED_GREEN);
  matrix[0].writeDisplay();
  //delay(500);
  
  //2c
  matrix[1].clear();
  matrix[1].drawBitmap(0, 0, look, 8, 8, LED_GREEN);
 matrix[1].writeDisplay();
  delay(500);
  
  
//1d
  matrix[0].clear();
  matrix[0].drawBitmap(0, 0, right, 8, 8, LED_GREEN);
  matrix[0].writeDisplay();
  //delay(500);
  
  //2d
   matrix[1].clear();
  matrix[1].drawBitmap(0, 0,right, 8, 8, LED_GREEN);
 matrix[1].writeDisplay();
  delay(500);
  
  
 //1e 
   matrix[0].clear();
  matrix[0].drawBitmap(0, 0, look, 8, 8, LED_GREEN);
  matrix[0].writeDisplay();
  //delay(100);
  //2e
  matrix[1].clear();
  matrix[1].drawBitmap(0, 0, look, 8, 8, LED_GREEN);
  matrix[1].writeDisplay();
  delay(100);
  
  
//1f
  matrix[0].clear();
  matrix[0].drawBitmap(0, 0, right, 8, 8, LED_GREEN);
  matrix[0].writeDisplay();
  //delay(500);
   //2f 
   matrix[1].clear();
  matrix[1].drawBitmap(0, 0, right, 8, 8, LED_GREEN);
  matrix[1].writeDisplay();
  delay(500);
  
 //1g 
   matrix[0].clear();
  matrix[0].drawBitmap(0, 0, blinkleft, 8, 8, LED_RED);
  matrix[0].writeDisplay();
  delay(100);
//2g  
     matrix[1].clear();
  matrix[1].drawBitmap(0, 0, look, 8, 8, LED_GREEN);
 matrix[1].writeDisplay();
  delay(100);

  }
