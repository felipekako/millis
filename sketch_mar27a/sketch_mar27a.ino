#include <Servo.h> 
Servo myservo;
Servo myservo2;
Servo myservo3;
void setup() {
  myservo.attach(6);
  myservo2.attach(3);
  myservo3.attach(10);
}

void loop() {
 
  myservo.write(1);
  delay(500);
  myservo.write(180);
  delay(500);
  myservo2.write(1);
  delay(500);
  myservo2.write(180);
  delay(500);
  myservo3.write(1);
  delay(500);
  myservo3.write(180);
  delay(500);
}
