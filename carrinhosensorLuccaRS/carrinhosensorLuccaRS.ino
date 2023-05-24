  //sensor
#define sdF 12
#define sdD 11
#define seD 10
#define seF 9

#define ENA A3
#define ENB A4

#define echoPin 3
#define trigPin 2

long duration;
int distance;

//direita
int IN1 = 7;
int IN2 = 6;
//esquerda
int IN3 = 5;
int IN4 = 4;

void setup() {
  // sensor
  Serial.begin(9600);
  pinMode(sdF, INPUT);
  pinMode(sdD, INPUT);
  pinMode(seD, INPUT);
  pinMode(seF, INPUT);
  // motor
  pinMode (ENA, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENB, OUTPUT);
  analogWrite (ENA, 255);
  analogWrite (ENB, 255);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, OUTPUT);
}

void loop() {
  //Leituras();
  //delay( 500);                                                                                                                                                                                                                                                                          
  Dist();
}
