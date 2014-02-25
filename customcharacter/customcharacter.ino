
#include <SoftwareSerial.h>
SoftwareSerial LCD (11, 12);
byte zero = 0; // using this in place of 0x00, which somehow doesn't compile on my machine...

void setup(){
  
LCD.begin(9600);
LCD.write(0x0C); //clears the screen 
delay(5);
LCD.write(0x11);

 LCD.write(217);                // Select the 4th scale (A = 440Hz)
  /* 
  Scale  A    A#  B    C    C#   D    D#   E    F    F#   G    G#
  4      440  466 494  523  554  587  622  659  698  740  784  831 
  */

for (int i=1; i<15; i++){
LCD.write(148+i);
  LCD.write(0x5e);//carrot

    }
  
 for (int i=1; i<9; i++){
    
   whale(); 
   LCD.write(148+i);
  LCD.write(zero);
  LCD.write(147+i);
  LCD.write(0x5e);//carrot
  
//    LCD.write(0x0C); //clears the screen
  }
  
}

void loop (){
  //water spout 1
  LCD.write(136); 
 water(); 
  LCD.write(0x01);
  LCD.write(136); 
  delay(200);
  LCD.write(0x20);//space
  
  //music
  
  LCD.write(210);                // 1/8 note
  LCD.write(223);                // C tone
  LCD.write(224);                // C# tone
  
  //water spout 2
   LCD.write(137);
  water1();
   LCD.write(0x02);
   LCD.write(135);
  water1();
   LCD.write(0x02);
  delay(200);
    LCD.write(137);
    
    LCD.write(0x20);//space
      LCD.write(135);
   LCD.write(0x20);//space
   
   //music 2  
  LCD.write(210);                
  LCD.write(225);                // D tone
  LCD.write(226);                // D# tone
 
 //water spout 3 
   LCD.write(138);
  water2();
    LCD.write(0x03);

   LCD.write(134);
  water3();
    LCD.write(0x04);
  delay(200);
       LCD.write(138);
   LCD.write(0x20);//space
       LCD.write(134);
   LCD.write(0x20);//space
   
   //music 3  
  LCD.write(210);                // 1/4 note
  LCD.write(227);                // C tone


 
}//void loop closer


void customCharacter(){
  LCD.write(0xF8);
   LCD.write(zero);  
   
  LCD.write(0x1b);
  LCD.write(0x1f);
  LCD.write(0x1f);
  LCD.write(0x1f);
  LCD.write(0xe);
  LCD.write(0x4);
  LCD.write(zero); 
  
  LCD.write(135);
  LCD.write(zero);
  
}

void heart(){
  LCD.write(0xF8);
   LCD.write(zero);  
   
  LCD.write(0x1b);
  LCD.write(0x1f);
  LCD.write(0x1f);
  LCD.write(0x1f);
  LCD.write(0xe);
  LCD.write(0x4);
  LCD.write(zero); 
  
}




void whale(){
  LCD.write(0xF8); 
   LCD.write(zero);
    
   
  LCD.write(0x10); 
  delay (100);
 
  LCD.write(0x1c);
  delay (100);
  LCD.write(0x18);
  delay (100);
  LCD.write(0x1f);
  delay (100);
  LCD.write(0x1f);
  delay (100);
  LCD.write(0x1b);
  delay (100);
  LCD.write(0xf); 
  
}


void water()
{
LCD.write(0xF9); 
LCD.write(zero);
LCD.write(zero);
LCD.write(zero);
LCD.write(0x11);
LCD.write(0xa);
LCD.write(0x4);
LCD.write(0x4);
LCD.write(0x4);


}

void water1()
{
LCD.write(0xFA); 
LCD.write(zero);
LCD.write(0x4);
LCD.write(0xa);
LCD.write(0x11);
LCD.write(zero);
LCD.write(zero);
LCD.write(zero);
LCD.write(zero);


}
	

void water2()
{
LCD.write(0xFB); 

LCD.write(zero);
LCD.write(zero);
LCD.write(zero);
LCD.write(0x10);
LCD.write(0xc);
LCD.write(0x6);
LCD.write(0x2);
LCD.write(0x3);


}
	

void water3()
{
LCD.write(0xFC); 
LCD.write(zero);
LCD.write(zero);
LCD.write(zero);
LCD.write(0x1);
LCD.write(0x6);
LCD.write(0xc);
LCD.write(0x8);
LCD.write(0x18);

}

void water4()
{
LCD.write(0xF9); 
LCD.write(zero);
LCD.write(zero);
LCD.write(zero);
LCD.write(0x11);
LCD.write(0xa);
LCD.write(0x4);
LCD.write(0x4);
LCD.write(0x4);

}
