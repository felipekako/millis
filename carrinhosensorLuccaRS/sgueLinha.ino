void Leituras() {
  bool valorLidoDF = digitalRead(sdF);
  bool valorLidoDD = digitalRead(sdD);
  bool valorLidoED = digitalRead(seD);
  bool valorLidoEF = digitalRead(seF);

  if (valorLidoEF) {
    Serial.println("Virar Esquerda");
    Esquerda();
    delay(1000);
  }
  if (valorLidoED) {
    Serial.println("Virar um pouco para a Esquerda");
    Esquerda();
    delay(300);
  }
  if (valorLidoDF) {
    Serial.println("Virar Direita");
    Direita();
    delay(1000);
  }
  if (valorLidoDD) {
    Serial.println("Virar um pouco para a Direita");
    Direita();
    delay(300);
  } 
  if (!valorLidoEF && !valorLidoED && !valorLidoDF && !valorLidoDD){
    Serial.println("Siga em frente, olhe para o lado");
    Frente();
    delay(2000);
  }
}
