#include <LiquidCrystal.h>                // Include Header file for LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //LCD pins connected to arduino
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

#define echo 8            //echo pin of Ultrasonic connected to pin 8 of arduino
#define trig 9            //trig pin of Ultrasonic connected to pin 9 of arduino

long duration;
int distance;

void setup () {
          pinMode (trig, OUTPUT);
          pinMode (echo, INPUT);
}
void loop () {
          digitalWrite (trig, LOW);   // generate pulse of 2 microsec low and 10 microsec high and low
          delayMicroseconds (2);
          digitalWrite (trig, HIGH);
          delayMicroseconds (10);
          digitalWrite (trig, LOW);
          
          duration = pulseIn (echo, HIGH)    //read echo pin
          distance = (duration/2)*0.034;    //to measure distance
          
          lcd.clear ();
          lcd.begin (16,2);
          lcd.setCursor (4,0);
          lcd.print (“HC-SR04”);
          lcd.setCursor (0,1);
          lcd.print (“Distance= “);       
          lcd.print (distance);         //print the value of distance
          lcd.print (“cm”);
          delay (500);
}
