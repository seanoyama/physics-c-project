#include <IRremote.h>

#include <Servo.h>
#include <LED.h>
// #include <iostream>

int pos = 0;
int ifRead;
int toggleValue = 0;
int motor1_fwdpin = 2;
int motor1_backpin = 3;
int enablepin = 5;

int irReceiverPin = 4;
IRrecv irrecv(irReceiverPin);
decode_results results;


Servo m_servo;


void setup(){
  Serial.begin(9600);
  // pinMode(A0, INPUT);
  // m_servo.attach(2);
  // m_servo.write(90);
  irrecv.enableIRIn();
  pinMode(motor1_fwdpin,OUTPUT);
  pinMode(motor1_backpin,OUTPUT);
  pinMode(enablepin,OUTPUT);

  analogWrite(enablepin, 150);
  digitalWrite(motor1_fwdpin, HIGH);
  digitalWrite(motor1_backpin, LOW);
}

void loop(){
  

  // if(irrecv.decode(&results)){
  //     if(results.value == 5316027){
  //       Serial.println("Go Forward");
  //       digitalWrite(motor1_fwdpin, HIGH);
  //       digitalWrite(motor1_backpin, LOW);
  //       // m_servo.write(45);
  //     }
  //     else if(results.value == 2747854299){
  //       Serial.println("Go Backward");
  //       digitalWrite(motor1_fwdpin, LOW);
  //       digitalWrite(motor1_backpin, HIGH);
  //       // m_servo.write(135);
  //     }
  //     else if(results.value == 3622325019){
  //       Serial.println("idle");
  //       digitalWrite(motor1_fwdpin, LOW);
  //       digitalWrite(motor1_backpin, LOW);
  //       // m_servo.write(90);
  //     }

  //     irrecv.resume();
  //     delay(100);
  // }
  
  
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