void Dist(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn (echoPin, HIGH);

  distance = duration *0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance >= 20){
    Frente();
  }
  else{
    Parar();
    delay(400);
    Direita();
    delay(400);
    Frente();
    delay(400);
    Parar();
    delay(400);
    Esquerda();
    delay(400);
    Frente();
    delay(400);
    Parar();
    delay(400);
    Esquerda();
    delay(400);
    Frente();
    delay(400);
    Parar();
    delay(400);
    Direita();
    delay(350);
    Parar();
    delay(400);
    Frente();
    delay(400);
    Parar();
    delay(400);
  }
}
