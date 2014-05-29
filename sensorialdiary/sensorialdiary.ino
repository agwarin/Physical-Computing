  
#include <Wire.h>
// the i2c address
#define VCNL4000_ADDRESS 0x13

// commands and constants
#define VCNL4000_COMMAND 0x80
#define VCNL4000_PRODUCTID 0x81
#define VCNL4000_IRLED 0x83
#define VCNL4000_AMBIENTPARAMETER 0x84
#define VCNL4000_AMBIENTDATA 0x85
#define VCNL4000_PROXIMITYDATA 0x87
#define VCNL4000_SIGNALFREQ 0x89
#define VCNL4000_PROXINITYADJUST 0x8A

#define VCNL4000_3M125 0
#define VCNL4000_1M5625 1
#define VCNL4000_781K25 2
#define VCNL4000_390K625 3

#define VCNL4000_MEASUREAMBIENT 0x10
#define VCNL4000_MEASUREPROXIMITY 0x08
#define VCNL4000_AMBIENTREADY 0x40
#define VCNL4000_PROXIMITYREADY 0x20
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define PIN9 9
#define PIN12 12

// end of Adafruit coding
//int Pin = 6;  
//int LED = 5;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_b = Adafruit_NeoPixel(60, PIN9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_c = Adafruit_NeoPixel(60, PIN12, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);  // Begin sending information to the screen
  Serial.println("VCNL");
    Wire.begin();
      strip.begin();
      strip_b.begin();
     strip_c.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip_b.show(); // Initialize all pixels to 'off'
    strip_c.show(); // Initialize all pixels to 'off'

  
  // check to see if the board has recognized that
  // the proximity sensor is connected/capable of
  //communicating
  uint8_t rev = read8(VCNL4000_PRODUCTID);

  if ((rev & 0xF0) != 0x10) {
    Serial.println("Sensor not found :(");
    while (1);
  }
  // The following section is meant to provide the programmer
  // with some sort of idea of the signal being sent to and received
  // from the sensor
  write8(VCNL4000_IRLED, 20);        // sending 20 * 10mA = 200mA of current to IR light
  Serial.print("IR LED current = ");
  Serial.print(read8(VCNL4000_IRLED) * 10, DEC);
  Serial.println(" mA");

  //write8(VCNL4000_SIGNALFREQ, 3);
  Serial.print("Proximity measurement frequency = ");
  
  uint8_t freq = read8(VCNL4000_SIGNALFREQ);
  if (freq == VCNL4000_3M125) Serial.println("3.125 MHz");
  if (freq == VCNL4000_1M5625) Serial.println("1.5625 MHz");
  if (freq == VCNL4000_781K25) Serial.println("781.25 KHz");
  if (freq == VCNL4000_390K625) Serial.println("390.625 KHz");

  write8(VCNL4000_PROXINITYADJUST, 0x81);
  Serial.print("Proximity adjustment register = ");
  Serial.println(read8(VCNL4000_PROXINITYADJUST), HEX);
  
//    pinMode(Pin,OUTPUT);
//  pinMode(LED,OUTPUT);
  
}

uint16_t readAmbient(){
  write8(VCNL4000_COMMAND, VCNL4000_MEASUREAMBIENT);
  while (1)
  {
    uint8_t result = read8(VCNL4000_COMMAND);
    if (result & VCNL4000_AMBIENTREADY)
    {
      return read16(VCNL4000_AMBIENTDATA);
    }
    delay(1);
  }  
}
// Adafruit function to let the sensor know we'll be retrieving
// a proximity value from it and then returning that value
uint16_t readProximity() {
  write8(VCNL4000_COMMAND, VCNL4000_MEASUREPROXIMITY);
  while (1) {
    uint8_t result = read8(VCNL4000_COMMAND);
    //Serial.print("Ready = 0x"); Serial.println(result, HEX);
    if (result & VCNL4000_PROXIMITYREADY) {
      return read16(VCNL4000_PROXIMITYDATA);  // the value we're after
    }  
    delay(1);
  }
}

void loop(){
  
   int lux = readAmbient() * 0.25;
    int pro = readProximity();
      Serial.print("light = ");
      Serial.print(lux);
      Serial.print("\t\tProximity = ");
      Serial.println(pro);
     // break(); //????
//    Serial.print(pro);
//    Serial.print(lux);
    lighton();
//
////    if (lux > 300){//approx 50mm from sensor
////      digitalWrite (Pin, LOW);
////      digitalWrite (LED, LOW);
////       strip.show(); // Initialize all pixels to 'off'
////      
////    } else  { 
////      
////      digitalWrite(Pin, HIGH);
////      digitalWrite (LED, HIGH);
////      Serial.print("Magnet On");
////      colorWipe(strip.Color(255, 0, 255), 50); // Purple
////      delay (100);
//      
////      digitalWrite (Pin, LOW);
////      digitalWrite (LED, LOW);
    }

      
//************The light turning on function************************
void lighton(){
   int lux = readAmbient() * 0.25;
    int pro = readProximity();
    
    if (lux < 50){//approx 50mm from sensor
      Serial.print("Magnet On");
//      colorWipe(strip.Color(255, 0, 0), 500); // Red
//  rainbow(500);
  strip_b.setPixelColor(0, 255, 0, 255); //purple
 strip_c.setPixelColor(0, 200, 200, 0); //greenish
  strip.setPixelColor(0, 0, 0, 255); //blue
  strip.setBrightness(200);
  strip_b.setBrightness(200);
  strip_c.setBrightness(200);
  strip_c.show(); // Initialize all pixels to 'off'
  strip_b.show(); // Initialize all pixels to 'off'
  strip.show(); // Initialize all pixels to 'off'
  delay (5000);
     
    }
    else if (lux > 100){
      
//       colorWipe(strip.Color(0, 0, 0), 50); // Red
//       colorWipe(strip_b.Color(0, 0, 0), 50); // Red
//       colorWipe(strip_c.Color(0, 0, 0), 50); // Red
  strip_b.setPixelColor(0, 0, 0, 0); //purple
 strip_c.setPixelColor(0, 0, 0, 0);
  strip.setPixelColor(0, 0, 0, 0);
      strip_b.show(); // Initialize all pixels to 'off'
  strip.show(); // Initialize all pixels to 'off'
   strip_c.show(); // Initialize all pixels to 'off'
      
    }
    
}
//      delay (100);
//  }
//  
// Read 1 byte from the VCNL4000 at 'address'
uint8_t read8(uint8_t address)
{
  uint8_t data;

  Wire.beginTransmission(VCNL4000_ADDRESS);
#if ARDUINO >= 100
  Wire.write(address);
#else
  Wire.send(address);
#endif
  Wire.endTransmission();

  delayMicroseconds(170);  // delay required

  Wire.requestFrom(VCNL4000_ADDRESS, 1);
  while(!Wire.available());

#if ARDUINO >= 100
  return Wire.read();
#else
  return Wire.receive();
#endif
}


// Read 2 byte from the VCNL4000 at 'address'
uint16_t read16(uint8_t address)
{
  uint16_t data;

  Wire.beginTransmission(VCNL4000_ADDRESS);
#if ARDUINO >= 100
  Wire.write(address);
#else
  Wire.send(address);
#endif
  Wire.endTransmission();

  Wire.requestFrom(VCNL4000_ADDRESS, 2);
  while(!Wire.available());
#if ARDUINO >= 100
  data = Wire.read();
  data <<= 8;
  while(!Wire.available());
  data |= Wire.read();
#else
  data = Wire.receive();
  data <<= 8;
  while(!Wire.available());
  data |= Wire.receive();
#endif
  
  return data;
}

// write 1 byte
void write8(uint8_t address, uint8_t data)
{
  Wire.beginTransmission(VCNL4000_ADDRESS);
#if ARDUINO >= 100
  Wire.write(address);
  Wire.write(data);  
#else
  Wire.send(address);
  Wire.send(data);  
#endif
  Wire.endTransmission();

}

//// Fill the dots one after the other with a color
//void colorWipe(uint32_t c, uint8_t wait) {
//  for(uint16_t i=0; i<strip.numPixels(); i++) {
//      strip.setPixelColor(i, c);
//      strip.show();
//      delay(wait);
//  }
//}
//
//void rainbow(uint8_t wait) {
//  uint16_t i, j;
//
//  for(j=0; j<256; j++) {
//    for(i=0; i<strip.numPixels(); i++) {
//      strip.setPixelColor(i, Wheel((i+j) & 255));
//    }
//    strip.show();
//    delay(wait);
//  }
//}
//
//
//// Input a value 0 to 255 to get a color value.
//// The colours are a transition r - g - b - back to r.
//uint32_t Wheel(byte WheelPos) {
//  if(WheelPos < 85) {
//   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
//  } else if(WheelPos < 170) {
//   WheelPos -= 85;
//   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
//  } else {
//   WheelPos -= 170;
//   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
//  }
//}
//
// 

