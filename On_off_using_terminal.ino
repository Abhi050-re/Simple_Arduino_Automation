#include "LiquidCrystal.h"
LiquidCrystal lcd(13,12,11,10,9,8);  
void setup() {
  Serial.begin(9600); 
  lcd.begin(16,2);
  lcd.setCursor(0,0); 
  lcd.print("Welcome Home");
  pinMode(7,OUTPUT); //relay 2   //bulb
  pinMode(6,OUTPUT); //relay 1  //fan
}

void loop() 
{
  if(Serial.available()>0) 
  {
    char data= Serial.read();
    Serial.println(data);

    if(data=='a')             
    {
      digitalWrite(7,HIGH);
      Serial.println("Bulb was ON ");
      lcd.setCursor(0,1);
      lcd.print(" Bulb was ON");
    }
    if(data=='b')
    {
      digitalWrite(7,LOW);
      Serial.println("Bulb was OFF");
      lcd.setCursor(0,1);
      lcd.print("Bulb was OFF");
      
    }
    //FOR FAN
    if(data=='c')  
    {
      digitalWrite(6,HIGH);    
      Serial.println("Fan was ON");   
      lcd.setCursor(0, 1);
      lcd.print("Fan was ON");
    }
    if(data=='d')
    {
      digitalWrite(6,LOW);
      Serial.println("Fan was OFF");
      lcd.setCursor(0, 1);
      lcd.print("Fan was OFF");
    }
  }


}
