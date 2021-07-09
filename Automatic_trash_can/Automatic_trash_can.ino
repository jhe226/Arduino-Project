#include<Servo.h>
Servo servo;
const int trigPin = 2;
const int echoPin = 3;

void setup(){
  Serial.begin(9600);
  servo.attach(4);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop(){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);
  long distance = pulseIn(echoPin, HIGH) / 58;
  Serial.println(distance);
  if (distance < 20) {     
    servo.write(90);
    delay(10000);
    }
  else {
    servo.write(0);
    }
  delay(100);
}
