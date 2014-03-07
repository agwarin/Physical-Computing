 
  const int wheel1A = 11;    // H-bridge leg 1 (pin 2, 1A)
  const int wheel2A = 12;    // H-bridge leg 2 (pin 7, 2A)
  const int enablePin12 = 6;    // H-bridge enable pin

  const int wheel4A = 9;    // H-bridge leg 1 (pin 2, 1A)
  const int wheel3A = 10;    // H-bridge leg 2 (pin 7, 2A)
  const int enablePin34 = 5;    // H-bridge enable pin
  
  
   void setup() {
 

    // set all the other pins you're using as outputs:
    pinMode(wheel1A, OUTPUT); 
    pinMode(wheel2A, OUTPUT); 
    pinMode(enablePin12, OUTPUT);
    
    //2nd wheel  
    pinMode(wheel4A, OUTPUT); 
    pinMode(wheel3A, OUTPUT); 
    pinMode(enablePin34, OUTPUT);


    // set enablePin high so that motor can turn on:
    digitalWrite(enablePin12, HIGH); 
    digitalWrite(enablePin34, HIGH); 
  }
  
  void loop() {
    // if the switch is high, motor will turn on one direction:

      digitalWrite(wheel1A, LOW);   // set leg 1 of the H-bridge low
      digitalWrite(wheel2A, HIGH);  // set leg 2 of the H-bridge high
 
    // if the switch is low, motor will turn in the other direction:
//    else {
      digitalWrite(wheel4A, HIGH);  // set leg 1 of the H-bridge high
      digitalWrite(wheel3A, LOW);   // set leg 2 of the H-bridge low
   
  }
