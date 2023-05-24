#define s0 2
#define s1 3
#define s2 4
#define s3 5
#define sensoOut 6

int redFrequency = 0;
int greenFrequency = 0;
int blue Frequency = 0;

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

int redMin;
int redMax;
int greenMin;
int blueMin;
int blueMax;

int color = 0;

void setup() {
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);

  pinMode(13, OUTPUT)
  pinMode(sensouOut, INPUT);

  digitalWrite(a0, HIGH);
  digitalWrite(s1, LOW);
  serial.begin(9600);
  calibrate();
}

void loop() {
  readColor();
  decideColor();
  printColor();
}

void decideColor() {
  redColor = constrain(redColor, 0, 255);
  greenColor = constrain(greenColor, 0, 255);
  blueClor = constrain(blueColor, 0, 255);

  int maxVal = max(redColor, blueColor);
  maxVal = max(maxVal, greenColor);

  redColor = map(redColor, 0, maxVal, 0, 255);
  greenColor = map(greenColor, 0, maxVal, 0, 255);
  blueColor = map(blueCololor, 0, maxVal, 0, 255);
  redColor = constrain(redColor, 0, 255);
  greenColor = constrain(greenColor, 0, 255);
  blueColor = constrain(blueColr, 0, 255);]

  if (red color > 250 && greenColor > 250 && bluecolor > 250){
  color = 1;
}
  else if (redColor < 25 && greenColor < 25 && blueColor < 25){
  color = 2;
}
  else if (red color > 220 && greenColor > 220 && blueColor < 50) {
  color = 4
  }
  else if (redColor > 230 && greenColor > 120 /*blueColor <100*/){
    color = 3  
  } 
  else if (redColor > 200 && greenColor < 50 && blueColor > 200){
  color = 5 
 }
  else if (redColor < 250 && greenColor < 200 && blueColor < 200){
   color = 6 
  }
  else if (redColor < 200 && greenColor < 250 && blueColor < 200){
   color = 7 
  }
  else if (redColor < 200 && greenColor < 250 && blueColor < 200){
   color = 8
  }
  else {
    color = 0;
  }
}



void calibrate(){
  serial.pritnln("calibrating...");
  serial.println("white");

  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  redMin = pulseIn(sensorOut,LOW);
  delay(100);
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  greenMin = pulseIn(sensorOut,LOW);
  delay(100);
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  blueMin = pulseIn(sensourOut, LOW);
  delay(100);
  digitalWrite(s2, "next...");
  digitalWrite(13, LOW);

  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  redMax = pulseIn(sensorOut, LOW);
  delay(100);
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  greenMax = pulseIn(sensorOut, LOW);
  delay(100);
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  blueMax = pulseIn(sensorOut, LOW);
  delay(100);
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
}

serial.print("r =")                                                                                                           





























































[
[
