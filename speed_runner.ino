#include <Servo.h>
#include "Ultrasonic.h"

// defines pins numbers

// 1st motor
const int front = 6;
const int reverse = 7;
// 2nd motor
const int right = 4;
const int left = 5;
// servo
const int servoPin = 3;
Servo neck;
Ultrasonic eyes(9,10);

// defines variables
long duration;
int distance , distanceR , distanceL;
unsigned long currentMillis , previousMillis = 0;

void setup() {
  pinMode(front, OUTPUT);
  pinMode(reverse, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(servoPin , OUTPUT);
  neck.attach(servoPin);
  neck.write(100);
  Serial.begin(9600); // serial monitor
}

void loop() {

  distance = eyes.read(CM);
  
  Serial.print("Front:");
  Serial.println(distance);
    
  if( distance < 10){
    nekra();
    delay(500);
    goBack();
    delay(1500);
    nekra();
    delay(500);
    distanceL = lookLeft();
    distanceR = lookRight();
    Serial.print("Right:");
    Serial.println(distanceR);
    Serial.print("Left:");
    Serial.println(distanceL);
    if(distanceR > distanceL){
      goRight();
    }
    else{
      goLeft();
    }
    delay(2000);
  }
  else{
    goFront();  
  }

  delay(500);

}

void goFront(){
  digitalWrite(front , HIGH);
  digitalWrite(reverse , LOW);
  digitalWrite(right , LOW);
  digitalWrite(left , LOW);
}

void goBack(){
  digitalWrite(reverse , HIGH);
  digitalWrite(front , LOW);  
  digitalWrite(right , LOW);
  digitalWrite(left , LOW);
}

void nekra(){
  digitalWrite(reverse , LOW);
  digitalWrite(front , LOW);
  digitalWrite(right , LOW);
  digitalWrite(left , LOW);
}

void goRight(){
  digitalWrite(front , HIGH);
  digitalWrite(reverse , LOW);
  digitalWrite(right , HIGH);
  digitalWrite(left , LOW);
}

void goLeft(){  
  digitalWrite(front , HIGH);
  digitalWrite(reverse , LOW);
  digitalWrite(right , LOW);
  digitalWrite(left , HIGH);
}

int lookRight(){
  int x;
  neck.write(50);
  delay(1800);
  x = eyes.read();
  delay(10);
  neck.write(100);
  delay(250);
  return x;
}

int lookLeft(){
  int x;
  neck.write(150);
  delay(1800);
  x = eyes.read();
  delay(10);
  neck.write(100);
  delay(250);
  return x;
}

