#define LED1 4
#define LED2 6
#define LED3 8
static unsigned long tempoAnteriorL1 =0;
const long intervaloL1 = 250;

static unsigned long tempoAnteriorL2 =0;
const long intervaloL2 = 1000;

static unsigned long tempoAnteriorL3 =0;
const long intervaloL3 = 4000;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
 unsigned long tempoAtual =millis();

  //-----------------------------LED1-------------------------
 if ((tempoAtual - tempoAnteriorL1) < intervaloL1) {
  digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }
  
 if ((tempoAtual - tempoAnteriorL1) >= (intervaloL1*2)) {
  tempoAnteriorL1 =millis();
}

 //-----------------------------LED2-------------------------
 if ((tempoAtual - tempoAnteriorL2) < intervaloL2) {
  digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }
  
 if ((tempoAtual - tempoAnteriorL2) >= (intervaloL2*2)) {
  tempoAnteriorL2 =millis();
}
 //-----------------------------LED3-------------------------
 if ((tempoAtual - tempoAnteriorL3) < intervaloL3) {
  digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }
  
 if ((tempoAtual - tempoAnteriorL3) >= (intervaloL3*2)) {
  tempoAnteriorL3 =millis();
}
}
