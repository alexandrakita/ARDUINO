int optoPin=0;
int opto=0;                 

int ledPin=6;      
int ledpwm=0; 
int ledprint=0;

int thermoPin=1;
float thermo=0;
float temp=0;
int tempint=0;
int tempmotor=0;

int motorPin=5;      
int motorpwm=0; 
int motorprint=0;

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);


void setup(){
lcd.begin(20, 4);
lcd.setCursor(0, 0);
lcd.print("Piraeus University");
lcd.setCursor(0, 1);
lcd.print("Temperature:       C");
lcd.setCursor(0, 2);
lcd.print("Air Condition:     %");
lcd.setCursor(0, 3);
lcd.print("Lights:            %");


pinMode(ledPin, OUTPUT); 
pinMode(motorPin, OUTPUT); 
}



void loop(){
opto=analogRead(optoPin); 
thermo=analogRead(thermoPin); 


if (opto>=200){
opto=200;
}
if(opto<=10){
opto=0;
}
ledpwm=map(opto, 0, 200, 255, 0);
analogWrite(ledPin,ledpwm); 


temp=(thermo*500)/1023;
tempint = (int) temp;
tempmotor=tempint;
if (tempmotor>=50){
tempmotor=50;
}
if(tempmotor<=30){
tempmotor=30;
}
motorpwm=map(tempmotor, 30, 50, 0, 255);
analogWrite(motorPin,motorpwm); 


lcd.setCursor(17,1);
lcd.print(tempint);


ledprint=map(ledpwm, 0, 255, 0, 100);
if (ledprint<10){
lcd.setCursor(16,3);
lcd.print("  ");    
lcd.setCursor(18,3);
lcd.print(ledprint);  
}
else if (ledprint<100){
lcd.setCursor(16,3);
lcd.print(" ");    
lcd.setCursor(17,3);
lcd.print(ledprint); 
}
else{
lcd.setCursor(16,3);
lcd.print(ledprint); 
}


motorprint=map(motorpwm, 0, 255, 0, 100);
if (motorprint<10){
lcd.setCursor(16,2);
lcd.print("  ");    
lcd.setCursor(18,2);
lcd.print(motorprint);  
}
else if (motorprint<100){
lcd.setCursor(16,2);
lcd.print(" ");    
lcd.setCursor(17,2);
lcd.print(motorprint); 
}
else{
lcd.setCursor(16,2);
lcd.print(motorprint); 
}


}
