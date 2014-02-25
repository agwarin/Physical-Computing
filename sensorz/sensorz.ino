int sensor = 0;
int sensor2 = 1;
int sensor3 = 2;
int value = 0;
int value1 = 0;
int value2 = 0;
int value3 = 0;

int red = 6;
int green = 5;
int blue = 3;

void setup () {
  Serial.begin(9600);
 pinMode (red,OUTPUT);
 pinMode (green,OUTPUT);
 pinMode (blue,OUTPUT); 
 
  analogWrite(red,255);
    analogWrite(green,255);
      analogWrite(blue,255);
}

void loop (){
  
 value = analogRead (sensor); //read value from the sensor
 value = map(value, 0, 1023, 255, 0); //maps the two number scales 
 Serial.print(value); // print the reading from the variable window
  Serial.print("\t");
  delay (20);
 analogWrite(red,value);
 
 
 

  
   value2 = analogRead (sensor2); //read value from the sensor
    value2 = map(value2, 0, 1023, 255, 0); //maps the two number scales
     Serial.print(value2); // print the reading from the variable window
       Serial.print("\t");
         delay (20);
          analogWrite(green,value2);
         
    value3 = analogRead (sensor3); //read value from the sensor
     value3 = map(value3, 0, 1023, 255, 0); //maps the two number scales
      Serial.println(value3); // print the reading from the variable window
         delay (20);
     analogWrite(blue,value3);
  
}
