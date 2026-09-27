#define do 34
#define re 35
#define mi 32
#define fa 33
#define sol 25
#define la 26
#define si 27

volatile bool toqueDo = false;
volatile bool toqueRe = false;
volatile bool toqueMi = false;
volatile bool toqueFa = false;
volatile bool toqueSol = false;
volatile bool toqueLa = false;
volatile bool toqueSi = false;

volatile unsigned long ultimoToqueDo = 0;
volatile unsigned long ultimoToqueRe = 0;
volatile unsigned long ultimoToqueMi = 0;
volatile unsigned long ultimoToqueFa = 0;
volatile unsigned long ultimoToqueSol = 0;
volatile unsigned long ultimoToqueLa = 0;
volatile unsigned long ultimoToqueSi = 0;

void IRAM_ATTR tocarDo() {
  unsigned long agora = millis();
  if (agora - ultimoToqueDo > 100) {
    ultimoToqueDo = agora;
    toqueDo = true;
  }
}

void IRAM_ATTR tocarRe() {
  unsigned long agora = millis();
  if (agora - ultimoToqueRe > 100) {
    ultimoToqueRe = agora;
    toqueRe = true;
  }
}

void IRAM_ATTR tocarMi() {
  unsigned long agora = millis();
  if (agora - ultimoToqueMi > 100) {
    ultimoToqueMi = agora;
    toqueMi = true;
  }
}

void IRAM_ATTR tocarFa() {
  unsigned long agora = millis();
  if (agora - ultimoToqueFa > 100) {
    ultimoToqueFa = agora;
    toqueFa = true;
  }
}

void IRAM_ATTR tocarSol() {
  unsigned long agora = millis();
  if (agora - ultimoToqueSol > 100) {
    ultimoToqueSol = agora;
    toqueSol = true;
  }
}

void IRAM_ATTR tocarLa() {
  unsigned long agora = millis();
  if (agora - ultimoToqueLa > 100) {
    ultimoToqueLa = agora;
    toqueLa = true;
  }
}

void IRAM_ATTR tocarSi() {
  unsigned long agora = millis();
  if (agora - ultimoToqueSi > 100) {
    ultimoToqueSi = agora;
    toqueSi = true;
  }
}

void setup () {
  ledcAttach(5, 2000, 8);

  pinMode(do, INPUT);
  pinMode(re, INPUT);
  pinMode(mi, INPUT);
  pinMode(fa, INPUT);
  pinMode(sol, INPUT);
  pinMode(la, INPUT);
  pinMode(si, INPUT);

  attachInterrupt(digitalPinToInterrupt(do), tocarDo, RISING);
  attachInterrupt(digitalPinToInterrupt(re), tocarRe, RISING);
  attachInterrupt(digitalPinToInterrupt(mi), tocarMi, RISING);
  attachInterrupt(digitalPinToInterrupt(fa), tocarFa, RISING);
  attachInterrupt(digitalPinToInterrupt(sol), tocarSol, RISING);
  attachInterrupt(digitalPinToInterrupt(la), tocarLa, RISING);
  attachInterrupt(digitalPinToInterrupt(si), tocarSi, RISING);
}

void loop () {
  if (toqueDo) {
    toqueDo = false;
    ledcWriteTone(5,262);
    delay(100);
    ledcWriteTone(5,0);
  }

  if (toqueRe) {
    toqueRe = false;
    ledcWriteTone(5,294);
    delay(100);
    ledcWriteTone(5,0);
  }

  if (toqueMi) {
    toqueMi = false;
    ledcWriteTone(5,330);
    delay(100);
    ledcWriteTone(5,0);
  }

  if (toqueFa) {
    toqueFa = false;
    ledcWriteTone(5,349);
    delay(100);
    ledcWriteTone(5,0);
  }

  if (toqueSol) {
    toqueSol = false;
    ledcWriteTone(5,392);
    delay(100);
    ledcWriteTone(5,0);
  }

  if (toqueLa) {
    toqueLa = false;
    ledcWriteTone(5,440);
    delay(100);
    ledcWriteTone(5,0);
  }

  if (toqueSi) {
    toqueSi = false;
    ledcWriteTone(5,494);
    delay(100);
    ledcWriteTone(5,0);
  }
}