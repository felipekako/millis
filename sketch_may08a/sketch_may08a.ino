//Pinos do Arduino:
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
 //Declaração dos pinModes:
 pinMode(S0, OUTPUT);
 pinMode(S1, OUTPUT);
 pinMode(S2, OUTPUT);
 pinMode(S3, OUTPUT);
 
 pinMode(13, OUTPUT);
 pinMode(sensorOut, INPUT);
 
 // Ajusta a escola da frequência a 20%
 digitalWrite(S0, HIGH);
 digitalWrite(S1, LOW);
 Serial.begin(9600);              // Serial para visualizar dados no monitor
 calibrate();                     // Função para calibrar o sensor (olhar no serial monitor)
}

void loop() {
 readColor();                     //Leitura do sensor
 decideColor();                   //Formata os valores para cada cor
 printColor();                    //Imprimi estes valores
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
 }
 else if (redColor < 25 && greenColor < 25 && blueColor < 25) {
   color = 2;           // Preto
 }
 else if (redColor > 220 &&  greenColor > 220 && blueColor < 50) {
   color = 4;           // Amarelo
 }
 else if (redColor > 230 &&  greenColor > 120 /*&& blueColor < 100*/) {
   color = 3;           // Laranja
 }
 else if (redColor > 200 &&  greenColor < 50 && blueColor > 200) {
   color = 5;           // Roxo
 }
 else if (redColor > 250 && greenColor < 200 && blueColor < 200) {
   color = 6;           // Vermelho
 }
 else if (redColor < 200 && greenColor > 250 && blueColor < 200) {
   color = 7;           // Verde
 }
 else if (redColor < 200 /*&& greenColor < 200*/ && blueColor > 250) {
   color = 8;           // Azul
 }
 else {
   color = 0;           //  Desconhecido
 }
}

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
   case 3: Serial.println("ORANGE"); break;
   case 4: Serial.println("YELLOW"); break;
   case 5: Serial.println("PURPLE"); break;
   case 6: Serial.println("RED"); break;
   case 7: Serial.println("GREEN"); break;
   case 8: Serial.println("BLUE"); break;
   default: Serial.println("unknown"); break;
 }
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
