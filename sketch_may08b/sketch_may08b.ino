#include <Servo.h>
Servo servoBase;

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6

//Output dos sensores:
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

//Valores respectivos - RGB:
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

//Valores utilizados para calibração
int redMin;
int redMax;
int greenMin;
int greenMax;
int blueMin;
int blueMax;

int color = 0;

void setup() {
  servoBase.attach(10);
  servoBase.write(0);
  Serial.begin(9600);


 pinMode(S0, OUTPUT);
 pinMode(S1, OUTPUT);
 pinMode(S2, OUTPUT);
 pinMode(S3, OUTPUT);
 
 pinMode(13, OUTPUT);
 pinMode(sensorOut, INPUT);
 
 // Ajusta a escola da frequência a 20%
 digitalWrite(S0, HIGH);
 digitalWrite(S1, LOW);
 calibrate();

}
void loop() {
 readColor();                     //Leitura do sensor
 decideColor();                   //Formata os valores para cada cor
 printColor(); 
}
