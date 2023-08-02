unsigned long tempoled1 = millis();
unsigned long tempoled2 = millis();
const int led1 = 11;

const int led2 = 3;
void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop() {

  if((millis()-tempoled1 )>= 1500){
    digitalWrite(led1, LOW);
    tempoled1 = millis();
  }else{
    digitalWrite(led1,HIGH);
  }
  
  if((millis()-tempoled2) <= 2000){
    digitalWrite(led2, LOW);
    tempoled2 = millis();
  }else{
    digitalWrite(led2,HIGH);
  }}
 
  //if((
  //  ,millis()- tempo) >= 200){
  //   Serial.println("sou antes delay");
 // tempo = millis();
 // }
 // Serial.println("A");
