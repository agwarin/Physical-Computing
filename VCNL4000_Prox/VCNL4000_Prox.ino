  
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

// end of Adafruit coding
int Pin = 6;  
int LED = 5;

void setup() {
  Serial.begin(9600);  // Begin sending information to the screen
  Serial.println("VCNL");
    Wire.begin();
    

  
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
  
    pinMode(Pin,OUTPUT);
  pinMode(LED,OUTPUT);
  
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
    
    Serial.print(pro);
    Serial.print(lux);

    if (pro < 2250){//approx 50mm from sensor
      digitalWrite (Pin, LOW);
      digitalWrite (LED, LOW);
      
    } else  { 
      
      digitalWrite(Pin, HIGH);
      digitalWrite (LED, HIGH);
      Serial.print("Magnet On");
      delay (10000);
//      digitalWrite (Pin, LOW);
//      digitalWrite (LED, LOW);
    }
    
//    if (lux < 40) {
//    digitalWrite(LED, HIGH);
//  } else {
//    digitalWrite(LED, LOW);
//  }      
    delay(100);
    

      
      // output the proximity and ambient light data to the screen
      Serial.print("Proximity = ");
      Serial.print(lux);
      Serial.print("\t\tProximity = ");
      Serial.println(pro);
     // break(); //????
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
 

