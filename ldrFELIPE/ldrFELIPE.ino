int valorLDR = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(10,OUTPUT);
Serial.begin(9600);
}
void loop() {
  valorLDR = analogRead (A0);
  
  Serial.print(valorLDR);
 Serial.print("/t");
 Serial.println(500);
 if(valorLDR <400) {
  digitalWrite(10,HIGH);
 }else{
  digitalWrite(10,LOW);
 }
 delay(10);
}
