#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
  
String voice;
       
int relay1 = 2;
int relay2 = 3;
int relay3 = 4;
int relay4 = 5;
        
void setup() {
           
     lcd.init();
     lcd.backlight();
Serial.begin(9600); 
           
pinMode(relay1, OUTPUT);    
pinMode(relay2, OUTPUT);   
pinMode(relay3, OUTPUT);   
pinMode(relay4, OUTPUT);             
 
}

void loop() {
while(Serial.available()){
  delay(10);
  char c=Serial.read();
  
  if(c=='#')
  {
    break;
  }
  voice += c; 
}
if (voice.length() > 0){
  lcd.clear();

if(voice == "a" || voice == "light one on")
{
lcd.print("light1 is now ON ");
delay(100);
digitalWrite(relay1, HIGH);
delay(100);
 

}

else if(voice == "a" || voice == "light one off")
{
 
lcd.print("light1 is now OFF ");
delay(100);
digitalWrite(relay1, LOW);
delay(100);
}
 

else if(voice == "B" || voice == "light two on")
{
 
 
lcd.print("light2 is now ON ");
delay(100);
digitalWrite(relay2, HIGH);
delay(100);

}
 
else if(voice == "b" || voice == "light two off")
{
 
lcd.print("light2 is now OFF ");
delay(100);
digitalWrite(relay2, LOW);
delay(100);
}
 

else if(voice == "C" || voice == "lamp on")
{

 
lcd.print("lamp is now ON ");
delay(100);
digitalWrite(relay3, HIGH);
delay(100);
}


else if(voice == "c" || voice == "lamp off")
{

 
lcd.print("lamp is now OFF ");
delay(100);
digitalWrite(relay3, LOW);
delay(100);
}


else if(voice == "D" || voice == "Fun on")
{
 
 
lcd.print("fan is now ON ");
delay(100);
digitalWrite(relay4, HIGH);
delay(100);
}
 

else if(voice == "d" || voice == "Fun off")
{
  
 
lcd.print("fan is now OFF ");
delay(100);
digitalWrite(relay4, LOW);
delay(100);
}
  
else if(voice == "on")
{
 
lcd.print("all is ON ");
delay(100);
digitalWrite(relay1, HIGH);
digitalWrite(relay2, HIGH);
digitalWrite(relay3, HIGH);
digitalWrite(relay4, HIGH);
delay(100);
}


 
else if(voice == "off")
{

 
lcd.print("all is OFF ");
delay(100);
digitalWrite(relay1, LOW);
digitalWrite(relay2, LOW);
digitalWrite(relay3, LOW);
digitalWrite(relay4, LOW);
delay(100);
}
 
}

{
 voice="";
}


}
