#define sdF 12
#define sdD 11
#define seD 10
#define seF 9

void setup() {
  Serial.begin(9600);
  pinMode(sdF, INPUT);
  pinMode(sdD, INPUT);
  pinMode(seD, INPUT);
  pinMode(seF, INPUT);
}

void Leituras() {
  bool valorLidoDF = digitalRead(sdF);
  bool valorLidoDD = digitalRead(sdD);
  bool valorLidoED = digitalRead(seD);
  bool valorLidoEF = digitalRead(seF);

  if (valorLidoEF) {
    Serial.println("Sensor Esquerdo Fora");
  }
  if (valorLidoED) {
    Serial.println("Sensor Esquerdo Dentro");
  }
  if (valorLidoDF) {
    Serial.println("Sensor Direito Fora");
  }
  if (valorLidoDD) {
    Serial.println("Sensor Direito Dentro");
  } 
}

void loop() {
  Leituras();
  delay(500);
}
