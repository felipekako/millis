#include <Servo.h>
Servo myservo;
#define LED1 5
#define LED2 6 
void setup() {
  myservo.attach(7); 
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}
void loop() {
  digitalWrite(LED1, HIGH);
  delay(500);
  myservo.write(180);
  delay(500) ; 
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(500); 
  myservo.write(0); 
  delay(500); 
  digitalWrite(LED2, LOW);     
}
