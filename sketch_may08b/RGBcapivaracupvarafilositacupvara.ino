void calibrate() {
 Serial.println("Calibrating...");
 Serial.println("White");               //Posicionar o sensor no Branco
 
 // Ajuste de valores da calibração

 digitalWrite(13, HIGH);
 delay(2000);
 digitalWrite(S2, LOW);
 digitalWrite(S3, LOW);
 redMin = pulseIn(sensorOut, LOW);
 delay(100);
 digitalWrite(S2, HIGH);
 digitalWrite(S3, HIGH);
 greenMin = pulseIn(sensorOut, LOW);
 delay(100);
 digitalWrite(S2, LOW);
 digitalWrite(S3, HIGH);
 blueMin = pulseIn(sensorOut, LOW);
 delay(100);
 Serial.println("next...");              //Posicionar o sensor no Branco
 digitalWrite(13, LOW);
 delay(2000);
 Serial.println("Black");

 // Ajuste de valores da calibração
 
 digitalWrite(13, HIGH);
 delay(2000);
 digitalWrite(S2, LOW);
 digitalWrite(S3, LOW);
 redMax = pulseIn(sensorOut, LOW);
 delay(100);
 digitalWrite(S2, HIGH);
 digitalWrite(S3, HIGH);
 greenMax = pulseIn(sensorOut, LOW);
 delay(100);
 digitalWrite(S2, LOW);
 digitalWrite(S3, HIGH);
 blueMax = pulseIn(sensorOut, LOW);
 delay(100);
 Serial.println("Done calibrating.");
 digitalWrite(13, LOW);
}
void readColor() {              // Função que captura os dados lidos do sensor
 
 //red:
 digitalWrite(S2, LOW);
 digitalWrite(S3, LOW);
 redFrequency = pulseIn(sensorOut, LOW);
 redColor = map(redFrequency, redMin, redMax, 255, 0);
 delay(100);

 //green:
 digitalWrite(S2, HIGH);
 digitalWrite(S3, HIGH);
 greenFrequency = pulseIn(sensorOut, LOW);
 greenColor = map(greenFrequency, greenMin, greenMax, 255, 0);
 delay(100);

 //blue:
 digitalWrite(S2, LOW);
 digitalWrite(S3, HIGH);
 blueFrequency = pulseIn(sensorOut, LOW);
 blueColor = map(blueFrequency, blueMin, blueMax, 255, 0);
 delay(100);
}

void decideColor() {              //Função p/ formatar os valores das cores

 
 //Atribui um limite max para as cores:
 redColor = constrain(redColor, 0, 255);
 greenColor = constrain(greenColor, 0, 255);
 blueColor = constrain(blueColor, 0, 255);
 //-----------------------------------------------------------------------------------------------------------

 //encontra a cor com mais brilho:
 int maxVal = max(redColor, blueColor);
 maxVal = max(maxVal, greenColor);
 
 //mapei os novos valores
 redColor = map(redColor, 0, maxVal, 0, 255);
 greenColor = map(greenColor, 0, maxVal, 0, 255);
 blueColor = map(blueColor, 0, maxVal, 0, 255);
 redColor = constrain(redColor, 0, 255);
 greenColor = constrain(greenColor, 0, 255);
 blueColor = constrain(blueColor, 0, 255);
 //-----------------------------------------------------------------------------------------------------------


 //decisão para identificar a cor lida (Você pode alterar alguns valores para melhor precisão):
 if (redColor > 250 && greenColor > 250 && blueColor > 250) {
   color = 1;           // Branco
   Abrir();
 }
 else if (redColor < 25 && greenColor < 25 && blueColor < 25) {
   color = 2;           // Preto
   Abrir();
 }
 else if (redColor > 250 && greenColor < 200 && blueColor < 200) {
   color = 3;           // Vermelho
   Fechar();
 }
 else if (redColor < 200 && greenColor > 250 && blueColor < 200) {
   color = 4;           // Verde
   Abrir();
 }
 else {
   color = 0;           //  Desconhecido
   Abrir();
 }
}

void printColor() {                     // Função que imprime os valores da cor lida
 Serial.print("R = ");
 Serial.print(redColor);
 Serial.print(" G = ");
 Serial.print(greenColor);
 Serial.print(" B = ");
 Serial.print(blueColor);
 Serial.print(" Color: ");
 switch (color) {
   case 1: Serial.println("WHITE"); break;
   case 2: Serial.println("BLACK"); break;
   case 3: Serial.println("RED"); break;
   case 4: Serial.println("GREEN"); break;
   default: Serial.println("unknown"); break;
 }
}
