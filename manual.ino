/*
manual mode 
good for truble shooting,good for finding max andmin, there is no set point
*/
#include <LiquidCrystal.h>  //adding the library code of the LCD to this code
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //all the pin locations fro the LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //initialize the library to the pin numbers to the LCD

int LED =6;  //LED pin location
int sen =A0; //Sensors pin location
int var =A5; //Potentiometer pin location

int pv =0;  //process varible value
int co=0;   //control output value
int val=0;  // value from the potentiometer

void setup() {
pinMode (LED,  OUTPUT); //making the LED as an OUTPUT
Serial.begin(9600); //set the Arduino speed for serial
lcd.begin(16,2); // setting the peramiters for how big the LCD screen is
}

void loop() {
 pv = analogRead (sen); //reading value setting it to pv
 val = analogRead (var); //reading value setting it to val
 co =map (val,0,1023,0,255); //maping the co to the four values
 analogWrite (LED, co); //writing the co to the LED
 
 Serial.print (pv); //Serial printing this value for plotter
 Serial.print("\t");
Serial.print(co);//Serial printing this value for plotter
Serial.print("\t");
Serial.println(val);//Serial printing this value for plotter

lcd.setCursor(0,0); 
//is the location of where you will start, (0,0) is the first row begening of the screen
lcd.print("PV="); //this will print the word PV= in the LCD screen, PV min =68  pv max=967
lcd.print (pv); //this will print the value of the pv on the LCD screen
/************************************************************/
lcd.setCursor(8,0); 
//is the location of where you will start, (8,0) is the second row,in the middle of the screen
lcd.print("CO="); //this will print the word CO= in the LCD screen
lcd.print(co); //this will print the value of the co on the LCD screen
/***********************************************************/
lcd.setCursor(0,1);
//is the location of where you will start, (0,1) is the second row begening of the screen
lcd.print("input="); //this will print the word input= in the LCD screen
lcd.print(val); //this will print the value of the val on the LCD screen
delay(30); //a fast delay
lcd.clear();  //clears everything on the LCD screen
}
