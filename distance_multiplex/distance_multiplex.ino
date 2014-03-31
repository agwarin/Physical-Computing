/*


 
 The circuit:
 * CD4067 multiplexer attached as follows:
 - address pin A: digital I/O 2
 - address pin B: digital I/O 3
 - address pin C: digital I/O 4
 - address pin D: digital I/O 5
 - input pin: digital I/O pin 6
 - LEDs attached from each of the CD4067's output channels
 to ground
 
 created 21 May 2009
 by Tom Igoe
 
 Added in a Sharp IR distance sensor to trigger the LEDs. 
 -Niki Selken - 2014
 
 http://www.tigoe.net/pcomp/code/category/arduinowiring/540 for more
 
 */

// put the address pin numbers in an array
// so they're easier to iterate over:
const int channel[] = {
  2, 3, 4, 5};
  int lightPin = 0;

// the output pin channel (mux's input):
const int outputPin = 6;

#include <DistanceGP2Y0A21YK.h>
DistanceGP2Y0A21YK Dist;
int distance;

void setup() {
  Serial.begin(9600);
  Dist.begin(A0);
  
  // set up all pins as output:
  for (int thisPin = 2; thisPin < 7; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  // iterate over the 16 channels of the multiplexer:
  for (int thisChannel = 0; thisChannel < 16; thisChannel++) {
    // set the channel pins based on the channel you want:
    muxWrite(thisChannel);

    // fade the current channel up:
    for (int brightness = 0; brightness < 256; brightness++) {
      analogWrite(outputPin, brightness);
      delay(15);
    }
  }
   
   distance = Dist.getDistanceCentimeter();
   
  Serial.print("\nDistance in centimers: ");
  Serial.print(distance);  
  delay(500); //make it readable
  
}//end loop



void muxWrite(int whichChannel) {
  // iterate over the number of pins you're using:
  for (int thisPin = 0; thisPin < 4; thisPin++) {
    // calculate the state of this pin based on 
    // its bit value in whichChannel:
    int pinState = bitRead(whichChannel, thisPin);
    // turn the pin on or off:
    digitalWrite(channel[thisPin],pinState);
  }
}
