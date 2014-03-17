
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_8x8matrix matrix[2] = {
  Adafruit_8x8matrix(), Adafruit_8x8matrix()};
static const uint8_t matrixAddr[] = { 0x70, 0x71};


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
{B00000000,
B00000000,
B00000000,
B10000001,
B11000001,
B01111110,
B01010100,
B01010100},

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


  
  
void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");  delay(1000);
  
 for(uint8_t i=0; i<2; i++) {
    matrix[i] = Adafruit_8x8matrix();
    matrix[i].begin(0x70 + i);
  }
}//setup bracket

void loop() {
  
//   matrix[0].clear();
//  matrix[0].drawBitmap(0, 0, look, 8, 8, LED_GREEN);
//  matrix[0].writeDisplay();
  
//  
//  matrix[0].clear();
//  matrix.drawBitmap(0, 0, left, 8, 8, LED_GREEN);
//  matrix.writeDisplay();
//  delay(500);
//  
//  matrix[0].clear();
//  matrix.drawBitmap(0, 0, look, 8, 8, LED_GREEN);
//  matrix.writeDisplay();
//  delay(500);
//
//  matrix[0].clear();
//  matrix.drawBitmap(0, 0, right, 8, 8, LED_GREEN);
//  matrix.writeDisplay();
//  delay(500);
//  
//   matrix[0].clear();
//  matrix.drawBitmap(0, 0, look, 8, 8, LED_GREEN);
//  matrix.writeDisplay();
//  delay(500);
//
//  matrix[0].clear();
//  matrix.drawBitmap(0, 0, right, 8, 8, LED_GREEN);
//  matrix.writeDisplay();
//  delay(500);
//  
//   matrix[0].clear();
//  matrix.drawBitmap(0, 0, blinkleft, 8, 8, LED_RED);
//  matrix.writeDisplay();
//  delay(500);
//  
//  
//     matrix[0].clear();
//  matrix.drawBitmap(0, 0, look, 8, 8, LED_GREEN);
//  matrix.writeDisplay();
//  delay(1000);
//  
//  matrix[1].clear();
//  matrix.drawBitmap(0, 0, left, 8, 8, LED_GREEN);
//  matrix.writeDisplay();
//  delay(500);
//  
//  matrix[1].clear();
//  matrix.drawBitmap(0, 0, look, 8, 8, LED_GREEN);
//  matrix.writeDisplay();
//  delay(500);
//
//  matrix[1].clear();
//  matrix.drawBitmap(0, 0, right, 8, 8, LED_GREEN);
//  matrix.writeDisplay();
//  delay(500);
//  
//   matrix[1].clear();
//  matrix.drawBitmap(0, 0, look, 8, 8, LED_GREEN);
//  matrix.writeDisplay();
//  delay(500);
//
//  matrix[1].clear();
//  matrix.drawBitmap(0, 0, right, 8, 8, LED_GREEN);
//  matrix.writeDisplay();
//  delay(500);
//  
//   matrix[1].clear();
//  matrix.drawBitmap(0, 0, notblinkright, 8, 8, LED_RED);
//  matrix.writeDisplay();
//  delay(500);
//  
//
//  matrix[0].setRotation(0);
//  matrix[1].setRotation(0);

}//loop end



