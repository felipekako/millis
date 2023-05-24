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
void Esquerda() {
  analogWrite (ENA, 150);
  analogWrite (ENB, 150);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}
void Direita() {
  analogWrite (ENA, 150);
  analogWrite (ENB, 150);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
 }
 void Re() {
  analogWrite (ENA, 150);
  analogWrite (ENB, 150);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
 }
