/*
ON/OFF control
up and down push button change the value
left adn right change the variable
 */
#include <LiquidCrystal.h>  //adding the library code of the LCD to this code
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //all the pin locations fro the LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //initialize the library to the pin numbers to the LCD

int Leftpb=10; //location of pin number for Push button
int Uppb=9; //location of pin number for Push button
int Downpb=8; //location of pin number for Push button
int Rightpb=7; //location of pin number for Push button
int LED =6;//LED pin location
int sen =A0;//Sensors pin location

int Screen=0; //creating variable for the screen
int pv=0; //process varible value
int co; //control output value
int setpoint=500; 
int hys=50;


void setup() {
 pinMode(Leftpb, INPUT_PULLUP); //making it so that the push button is an input
 pinMode(Uppb, INPUT_PULLUP); //making it so that the push button is an input
 pinMode(Downpb, INPUT_PULLUP); //making it so that the push button is an input
 pinMode(Rightpb, INPUT_PULLUP); //making it so that the push button is an input
 pinMode (LED,  OUTPUT); //making the LED as an OUTPUT
 lcd.begin(16,2); // setting the peramiters for how big the LCD screen is
Serial.begin(9600); //set the Arduino speed for serial
}

void loop() { 
 pv = analogRead (A0); //reading value setting it to pv
 analogWrite (LED, co); //writing the co to the LED

int LeftpbState  = digitalRead(Leftpb); //reading the value of the push button
int UppbState    = digitalRead(Uppb);   //reading the value of the push button
int DownpbState  = digitalRead(Downpb);  //reading the value of the push button
int RightpbState = digitalRead(Rightpb);  //reading the value of the push button

if (pv<(setpoint-hys)){ //setting a limit for CO with math
  co=255;
}
if (pv>(setpoint+hys)){ //setting a limit for CO with math
  co=0;
}

if (RightpbState == 0){
    Screen=Screen+1; // adds value of increments of 1
    delay(100); // wait to prevent errors 
  }
else if (LeftpbState==0){
    Screen=Screen-1; // adds value of increments of -1
    delay(100); // wait to prevent errors 
}
if (Screen==-1){ //if screen value goes under 0 it will go to 2
    Screen=2; 
}
if (Screen==3){ //if screen value goes over 2 it will go to 0
    Screen=0;
}
Serial.print (pv); //Serial printing this value for plotter
//Serial.print("\t"); 
//Serial.print(co);
Serial.print("\t");
Serial.println(setpoint); //Serial printing this value for plotter

if(Screen==0){
   lcd.setCursor(0,0); 
   //is the location of where you will start, (0,0) is the first row begening of the screen
   lcd.print("SP="); //this will print the word SP= in the LCD screen
   lcd.print(setpoint); //this will print the value of the setpoint on the LCD screen
delay(30); //a fast delay
  lcd.clear(); //clears everything on the LCD screen
if (UppbState==0){
  setpoint=setpoint+5;  //increasing value of setpoint by 5
  }
 if (DownpbState==0){
  setpoint=setpoint-5; //decreasing value of setpoint by 5
  } 
}

if (Screen==1){
lcd.setCursor(0,0);
//is the location of where you will start, (0,0) is the first row begening of the screen
lcd.print("Hys="); //this will print the word Hys= in the LCD screen
lcd.print(hys); //this will print the value of the hys on the LCD screen
delay(30); //a fast delay
  lcd.clear(); //clears everything on the LCD screen
if (DownpbState==0){
 hys=hys-5; //decreasing value of Hys by 5
 }
 if (UppbState==0){
  hys=hys+5; //increasing value of Hys by 5
  }
}

if (Screen==2){           
 lcd.setCursor(0,0); 
 //is the location of where you will start, (0,0) is the first row begening of the screen
 lcd.print("PV="); //this will print the word PV= in the LCD screen, PV min =68  pv max=967
 lcd.print (pv); //this will print the value of the pv on the LCD screen
  lcd.setCursor(0,1);
  //is the location of where you will start, (0,1) is the second row begening of the screen 
  lcd.print("CO="); //this will print the word CO= in the LCD screen
  lcd.print(co); //this will print the value of the co on the LCD screen
  delay(30); //a fast delay
  }
}
