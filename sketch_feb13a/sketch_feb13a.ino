int ENA = 8;
int IN1 = 7;
int IN2 = 6;
int IN3 = 5;
int IN4 = 4;
int ENB = 3;
  
void setup() {
  pinMode (ENA, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENB, OUTPUT);
  analogWrite (ENA, 255);
  analogWrite (ENB, 255);
}

void Frente() {
  analogWrite (ENA, 150);
  analogWrite (ENB, 150);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}

void Parar() {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
}

void loop() {
  Frente();
  delay(2000);
  Parar();
  delay(1000);
}
