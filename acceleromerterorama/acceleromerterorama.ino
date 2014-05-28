    #include <Wire.h>
    #include <Adafruit_LSM303.h>
    #include <Adafruit_NeoPixel.h>
    #include "musical_notes.h"
    
    int speakerPin = 9; // speaker connected to digital pin 9 
    // Parameter 1 = number of pixels in strip
    // Parameter 2 = pin number (most are valid)
    // Parameter 3 = pixel type flags, add together as needed:
    //   NEO_RGB     Pixels are wired for RGB bitstream
    //   NEO_GRB     Pixels are wired for GRB bitstream
    //   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
    //   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, 6, NEO_GRB + NEO_KHZ800);
    Adafruit_LSM303 lsm;
   

    // mess with this number to adjust TWINklitude :)
    // lower number = more sensitive
    #define MOVE_THRESHOLD 800
    
    void setup() 
    {
      Serial.begin(9600);
      
       // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM303. Check your wiring!");
    while (1);
  }
    strip.begin();
   // strip.show(); // Initialize all pixels to 'off'
      
      pinMode(speakerPin, OUTPUT); // sets the speakerPin to be an output 
    }
    
    void loop() 
    {
    
    
      armUp();
      armForward();
      armSide();
//      theaterChase(strip.Color(127, 127, 127), 50); // White
    // colorWipe(strip.Color(127, 127, 127), 200);
    }
    
    void armUp(){
      
          // Take a reading of accellerometer data
      lsm.read();
      Serial.print("Accel X: "); Serial.print(lsm.accelData.x); Serial.print(" ");
      //Serial.print("Y: "); Serial.print(lsm.accelData.y);       Serial.print(" ");
      Serial.print("Z: "); Serial.print(lsm.accelData.z);     Serial.print(" ");
  
      double storedVector = lsm.accelData.x*lsm.accelData.x;
    //storedVector += lsm.accelData.y*lsm.accelData.y;
    storedVector += lsm.accelData.z*lsm.accelData.z;
    storedVector = sqrt(storedVector);
    Serial.print("Len X Z: "); Serial.println(storedVector);
      
      // wait a bit
      delay(100);
      
      // get new data!
      lsm.read();
    double newVector = lsm.accelData.x*lsm.accelData.x;
    //newVector += lsm.accelData.y*lsm.accelData.y;
    newVector += lsm.accelData.z*lsm.accelData.z;
    newVector = sqrt(newVector);
      Serial.print("New Other Len X Z: "); Serial.println(newVector);
      
        if (abs(newVector - storedVector) > MOVE_THRESHOLD) {
        Serial.println("Twinkle!Twinkle!Twinkle!Twinkle!Twinkle!");
       
     catcall(); 
      colorWipe(strip.Color(255, 255, 0), 1000); // Yellow
        } else if (abs(newVector - storedVector) > MOVE_THRESHOLD){
      strip.Color(127, 127, 127);
    }
    }  

    void armForward(){
           // Take a reading of accellerometer data
      lsm.read();
    Serial.print("Accel X: "); Serial.print(lsm.accelData.x); Serial.print(" ");
   Serial.print("Y: "); Serial.print(lsm.accelData.y);       Serial.print(" ");
     // Serial.print("Z: "); Serial.print(lsm.accelData.z);     Serial.print(" ");
    
      // Get the magnitude (length) of the 3 axis vector
      // http://en.wikipedia.org/wiki/Euclidean_vector#Length
    double storedVector = lsm.accelData.x*lsm.accelData.x;
    storedVector += lsm.accelData.y*lsm.accelData.y;
    //newVector += lsm.accelData.z*lsm.accelData.z;
    storedVector = sqrt(storedVector);
      Serial.print("Len X Z: "); Serial.println(storedVector);
      
      // wait a bit
      delay(100);
      
      // get new data!
      lsm.read();
    double newVector = lsm.accelData.x*lsm.accelData.x;
     newVector += lsm.accelData.y*lsm.accelData.y;
    //newVector += lsm.accelData.z*lsm.accelData.z;
    newVector = sqrt(newVector);
      Serial.print("New Len X Z: "); Serial.println(newVector);
      
        if (abs(newVector - storedVector) > MOVE_THRESHOLD) {
        Serial.println("Swing!Swing!Swing!Swing!");
  
       ohhh();
        colorWipe(strip.Color(0, 0, 255), 200); // Blue
     } else if (abs(newVector - storedVector) > MOVE_THRESHOLD){
      strip.Color(127, 127, 127);
    }
      
    }
  
  void armSide(){
      
          // Take a reading of accellerometer data
      lsm.read();
      //Serial.print("Accel X: "); Serial.print(lsm.accelData.x); Serial.print(" ");
      Serial.print("Y: "); Serial.print(lsm.accelData.y);       Serial.print(" ");
      Serial.print("Z: "); Serial.print(lsm.accelData.z);     Serial.print(" ");
  
      double storedVector = lsm.accelData.y*lsm.accelData.y;
    storedVector += lsm.accelData.z*lsm.accelData.z;
    storedVector = sqrt(storedVector);
    Serial.print("Len Y Z: "); Serial.println(storedVector);
      
      // wait a bit
      delay(100);
      
      // get new data!
      lsm.read();
    double newVector = lsm.accelData.y*lsm.accelData.y;
    newVector += lsm.accelData.z*lsm.accelData.z;
    newVector = sqrt(newVector);
      Serial.print("New Other Len Y Z: "); Serial.println(newVector);
      
        if (abs(newVector - storedVector) > MOVE_THRESHOLD) {
        Serial.println("Stars!Stars!Stars!Stars!Stars!Stars!");
       
     squeak(); 
     colorWipe(strip.Color(175,75,148), 250); // Pink
    } else if (abs(newVector - storedVector) > MOVE_THRESHOLD){
      strip.Color(127, 127, 127);
    }
      
      
    }
    
    // Fill the dots one after the other with a color
    void colorWipe(uint32_t c, uint8_t wait) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, c);
          strip.show();
          delay(wait);
      }
    }

    void beep (int speakerPin, float noteFrequency, long noteDuration)
    {    
      int x;
      // Convert the frequency to microseconds
      float microsecondsPerWave = 1000000/noteFrequency;
      // Calculate how many HIGH/LOW cycles there are per millisecond
      float millisecondsPerCycle = 1000/(microsecondsPerWave * 2);
      // Multiply noteDuration * number or cycles per millisecond
      float loopTime = noteDuration * millisecondsPerCycle;
      // Play the note for the calculated loopTime.
      for (x=0;x<loopTime;x++)   
              {   
                  digitalWrite(speakerPin,HIGH); 
                  delayMicroseconds(microsecondsPerWave); 
                  digitalWrite(speakerPin,LOW); 
                  delayMicroseconds(microsecondsPerWave); 
              } 
    }     
         
    void scale() 
    {    
              beep(speakerPin, note_C7,500); //C: play the note C for 500ms 
              beep(speakerPin, note_D7,500); //D 
              beep(speakerPin, note_E7,500); //E 
              beep(speakerPin, note_F7,500); //F 
              beep(speakerPin, note_G7,500); //G 
              beep(speakerPin, note_A7,500); //A 
              beep(speakerPin, note_B7,500); //B 
              beep(speakerPin, note_C8,500); //C 
    }  
    
    void r2D2(){
              beep(speakerPin, note_A7,100); //A 
              beep(speakerPin, note_G7,100); //G 
              beep(speakerPin, note_E7,100); //E 
              beep(speakerPin, note_C7,100); //C
              beep(speakerPin, note_D7,100); //D 
              beep(speakerPin, note_B7,100); //B 
              beep(speakerPin, note_F7,100); //F 
              beep(speakerPin, note_C8,100); //C 
              beep(speakerPin, note_A7,100); //A 
              beep(speakerPin, note_G7,100); //G 
              beep(speakerPin, note_E7,100); //E 
              beep(speakerPin, note_C7,100); //C
              beep(speakerPin, note_D7,100); //D 
              beep(speakerPin, note_B7,100); //B 
              beep(speakerPin, note_F7,100); //F 
              beep(speakerPin, note_C8,100); //C 
    }
    
    void closeEncounters() {
              beep(speakerPin, note_Bb5,300); //B b
              delay(50);
              beep(speakerPin, note_C6,300); //C
              delay(50);
              beep(speakerPin, note_Ab5,300); //A b
              delay(50);
              beep(speakerPin, note_Ab4,300); //A b
              delay(50);
              beep(speakerPin, note_Eb5,500); //E b   
              delay(500);     
              
              beep(speakerPin, note_Bb4,300); //B b
              delay(100);
              beep(speakerPin, note_C5,300); //C
              delay(100);
              beep(speakerPin, note_Ab4,300); //A b
              delay(100);
              beep(speakerPin, note_Ab3,300); //A b
              delay(100);
              beep(speakerPin, note_Eb4,500); //E b   
              delay(500);  
              
              beep(speakerPin, note_Bb3,300); //B b
              delay(200);
              beep(speakerPin, note_C4,300); //C
              delay(200);
              beep(speakerPin, note_Ab3,300); //A b
              delay(500);
              beep(speakerPin, note_Ab2,300); //A b
              delay(550);
              beep(speakerPin, note_Eb3,500); //E b      
    }
    
    void ariel() {
    
              beep(speakerPin, note_C6,300); //C
              delay(50);
              beep(speakerPin, note_D6,300); //D
              delay(50);
              beep(speakerPin, note_Eb6,600); //D#
              delay(250);
              
              beep(speakerPin, note_D6,300); //D
              delay(50);
              beep(speakerPin, note_Eb6,300); //D#
              delay(50);
              beep(speakerPin, note_F6,600); //F
              delay(250);
              
              beep(speakerPin, note_C6,300); //C
              delay(50);
              beep(speakerPin, note_D6,300); //D
              delay(50);
              beep(speakerPin, note_Eb6,500); //D#
              delay(50);          
              beep(speakerPin, note_D6,300); //D
              delay(50);
              beep(speakerPin, note_Eb6,300); //D#
              delay(50);             
              beep(speakerPin, note_D6,300); //D
              delay(50);
              beep(speakerPin, note_Eb6,300); //D#
              delay(50);
              beep(speakerPin, note_F6,600); //F
              delay(50); 
    
    }
     
    
    void laugh2() {
              beep(speakerPin, note_C6,200); //C
              beep(speakerPin, note_E6,200); //E  
              beep(speakerPin, note_G6,200); //G 
              beep(speakerPin, note_C7,200); //C 
              beep(speakerPin, note_C6,200); //C
              delay(50);
              beep(speakerPin, note_C6,200); //C
              beep(speakerPin, note_E6,200); //E  
              beep(speakerPin, note_G6,200); //G 
              beep(speakerPin, note_C7,200); //C 
              beep(speakerPin, note_C6,200); //C
              delay(50);
              beep(speakerPin, note_C6,50); //C
              delay(50);
              beep(speakerPin, note_C6,50); //C
              delay(50);
              beep(speakerPin, note_C6,50); //C
              delay(50);
              beep(speakerPin, note_C6,50); //C
              delay(50);
              beep(speakerPin, note_C6,50); //C
              delay(50);
              beep(speakerPin, note_C6,50); //C
              delay(50);
              beep(speakerPin, note_C6,50); //C
              
    
              
    }
      
    void squeak() {
      for (int i=100; i<5000; i=i*1.45) {
        beep(speakerPin,i,60);
      }
      delay(10);
      for (int i=100; i<6000; i=i*1.5) {
        beep(speakerPin,i,20);
      }
    }
    
    void waka() {
      for (int i=1000; i<3000; i=i*1.05) {
        beep(speakerPin,i,10);
      }
      delay(100);
      for (int i=2000; i>1000; i=i*.95) {
        beep(speakerPin,i,10);
      }
        for (int i=1000; i<3000; i=i*1.05) {
        beep(speakerPin,i,10);
      }
      delay(100);
      for (int i=2000; i>1000; i=i*.95) {
        beep(speakerPin,i,10);
      }
        for (int i=1000; i<3000; i=i*1.05) {
        beep(speakerPin,i,10);
      }
      delay(100);
      for (int i=2000; i>1000; i=i*.95) {
        beep(speakerPin,i,10);
      }
        for (int i=1000; i<3000; i=i*1.05) {
        beep(speakerPin,i,10);
      }
      delay(100);
      for (int i=2000; i>1000; i=i*.95) {
        beep(speakerPin,i,10);
      }
    }
    
    void catcall() {
      for (int i=1000; i<5000; i=i*1.05) {
        beep(speakerPin,i,10);
      }
     delay(100);
     
      for (int i=1000; i<3000; i=i*1.03) {
        beep(speakerPin,i,10);
      }
      for (int i=3000; i>1000; i=i*.97) {
        beep(speakerPin,i,10);
      }
    }
    
    void ohhh() {
      for (int i=1000; i<2000; i=i*1.02) {
        beep(speakerPin,i,10);
      }
      for (int i=2000; i>1000; i=i*.98) {
        beep(speakerPin,i,10);
      }
    }
    
    void uhoh() {
      for (int i=1000; i<1244; i=i*1.01) {
        beep(speakerPin,i,30);
      }
      delay(200);
      for (int i=1244; i>1108; i=i*.99) {
        beep(speakerPin,i,30);
      }
    }
    
    void laugh() {
      for (int i=1000; i<2000; i=i*1.10) {
        beep(speakerPin,i,10);
      }
      delay(50);
      for (int i=1000; i>500; i=i*.90) {
        beep(speakerPin,i,10);
      }
      delay(50);
      for (int i=1000; i<2000; i=i*1.10) {
        beep(speakerPin,i,10);
      }
      delay(50);
      for (int i=1000; i>500; i=i*.90) {
        beep(speakerPin,i,10);
      }
      delay(50);
        for (int i=1000; i<2000; i=i*1.10) {
        beep(speakerPin,i,10);
      }
      delay(50);
      for (int i=1000; i>500; i=i*.90) {
        beep(speakerPin,i,10);
      }
      delay(50);
        for (int i=1000; i<2000; i=i*1.10) {
        beep(speakerPin,i,10);
      }
      delay(50);
      for (int i=1000; i>500; i=i*.90) {
        beep(speakerPin,i,10);
      }
      delay(50);
    }
    
    void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}
