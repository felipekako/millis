void Abrir(){
  servoBase.write(0);
  Serial.println("Abriu");
  delay(2000);
}

void Fechar(){
  servoBase.write(180);
  Serial.println("Fechou");
  delay(2000);
}
