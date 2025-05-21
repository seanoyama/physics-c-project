#include <IRremote.h>

#include <Servo.h>
// #include <LED.h>
// #include <iostream>

int pos = 0;
int ifRead;
int toggleValue = 0;
int motor1_fwdpin = 13;
int motor1_backpin = 12;
int motor1_enablepin = 5;

int motor2_fwdpin = 11;
int motor2_backpin = 10;
int motor2_enablepin = 4;

// int irReceiverPin = 4;
// IRrecv irrecv(irReceiverPin);
// decode_results results;


Servo m_servo;


void setup(){
  Serial.begin(9600);
  // pinMode(A0, INPUT);
  // m_servo.attach(7);
  // m_servo.write(90);
  // irrecv.enableIRIn();
  pinMode(motor1_fwdpin,OUTPUT);
  pinMode(motor1_backpin,OUTPUT);
  pinMode(motor1_enablepin,OUTPUT);
  
  pinMode(motor2_fwdpin,OUTPUT);
  pinMode(motor2_backpin,OUTPUT);
  pinMode(motor2_enablepin,OUTPUT);

  analogWrite(motor1_enablepin, 150);
  digitalWrite(motor1_fwdpin, HIGH);
  digitalWrite(motor1_backpin, LOW);
  
  analogWrite(motor2_enablepin, 150);
  digitalWrite(motor2_fwdpin, HIGH);
  digitalWrite(motor2_backpin, LOW);
}

void loop(){
  

  if(irrecv.decode(&results)){
      if(results.value == 5316027){
        Serial.println("Go Forward");
        // analogWrite(enablepin, 150);
        digitalWrite(motor1_fwdpin, HIGH);
        digitalWrite(motor1_backpin, LOW);
        digitalWrite(motor2_fwdpin, HIGH);
        digitalWrite(motor2_backpin, LOW);
        // m_servo.write(45);
      }
      else if(results.value == 2747854299){
        Serial.println("Go Backward");
        // analogWrite(enablepin, 150);
        digitalWrite(motor1_fwdpin, LOW);
        digitalWrite(motor1_backpin, HIGH);
        digitalWrite(motor2_fwdpin, LOW);
        digitalWrite(motor2_backpin, HIGH);
        // m_servo.write(135);
      }
      else if(results.value == 3622325019){
        Serial.println("idle");
        // analogWrite(enablepin, 0);
        digitalWrite(motor1_fwdpin, LOW);
        digitalWrite(motor1_backpin, LOW);
        digitalWrite(motor2_fwdpin, LOW);
        digitalWrite(motor2_backpin, LOW);
        // m_servo.write(90);
      }

      irrecv.resume();
      delay(100);
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