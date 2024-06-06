/*
 * StrydoLabs All Right Recived|strydolabs@gmail.com|damithrafdo@gmail.com|+94716507322|
 * IR remote controlled car for House Cleaning robot
 * Hardware Specification: Arduino Nano, H bridge Motor driver, Limit switch ir IR sensor, IR recever
 * Simulation: 
 * Github:
 */
#include<IRremote.h>
IRrecv Strydobot(10);
decode_results results;
void setup() {
  
  pinMode(4, OUTPUT);//motor Rr
  pinMode(5, OUTPUT);//mptor Rl
  pinMode(6, OUTPUT);//motor Lr
  pinMode(7, OUTPUT);//motor Ll
  //pinMode(10, INPUT);//IR Sensor
  pinMode(12, INPUT);//Sensor limit sensor

  Serial.begin(9600);
  Strydobot.enableIRIn();

}

void loop() {
  //sensor calibaretion
  if(Strydobot.decode(&results)){
    Serial.println(results.value, DEC);
    Strydobot.resume();
  }
  delay(300);
  
  //IR remort can change the mode
  long val = results.value;
  
  if(val == 04112221){ //use IR code to select the mode
    if(digitalRead (12) == LOW){
    //Mode one Auto driving
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    }
    else{
    digitalWrite(4, LOW); //backward
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(300);
    digitalWrite(4, HIGH); // turn right
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(3000);
    }
  }
  //Mode two Manual driving---------------------------------------------------------------------------------------------------------------------
   if(val == 04112231) {//use IR code to select the mode
    //forward
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(100);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
   }
  else if(val == 55441144){
    //reversed
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if(val == 55541144){
    //right
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if(val == 55441644){
    //left
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(100);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  //Else Stop,------------------------------------------------------------------------------------------------------------------------
  else{
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
}
