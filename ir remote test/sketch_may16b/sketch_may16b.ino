#include <Servo.h>
#include <LED.h>
// #include <iostream>

int pos = 0;
int ifRead;
int arraySize = 10;
int signals[10] = {1,2,3,4,5,6,7,8,9,10};
int toggleValue = 0;

Servo m_servo;


void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  m_servo.attach(2);
  m_servo.write(90);
}

void loop(){
  ifRead = analogRead(A0);
  Serial.println(ifRead);
  if(ifRead > 2){
    Serial.println(ifRead);
    toggleValue = toggleAction(toggleValue);
    delay(500);
  }  
}

int toggleAction(int t){
  if(t == 0){
    m_servo.write(45);
    Serial.println("t = 0");
  }
  else if(t == 1){
    m_servo.write(135);
    Serial.println("t = 1");
  }
  else{
    m_servo.write(90);
    Serial.println("t = 2");
  }
  
  if(t >= 2){
    return 0;
  }
  return t+1;
}