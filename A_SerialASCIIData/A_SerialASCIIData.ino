/*
THIS PROGRAM READS ONE SENSOR 
AND SENDS THE DATA OUT AS ASCII STRING TERMINATED BY '\n' (carriage return)
USE WITH P_SerialASCIIData.pde IN PROCESSING
*/


int Sensor;    // Analog Sensor Reading
boolean sendData = false;

void setup()
{
  Serial.begin(115200);
//  analogReference(EXTERNAL);
}
void loop()
{
  
  if(sendData == true){
    Sensor = analogRead(0);  // take a sensor reading
    Serial.print('S');
    Serial.println(Sensor);    
  }
    delay(10);
}

void serialEvent(){
 char inByte = Serial.read();
 if (inByte == 'a'){
   sendData = true;
  
  }
}
