int v1 = 13;
int am1 = 12;
int vrd1 = 11;

int v2= 9;
int am2 = 10;
int vrd2 = 8;

int vP1 = 6;
int vrdP1 = 7;

int vP2 = 4;
int vrdP2 = 5;


void setup() {
  pinMode(v1, OUTPUT);
  pinMode(am1, OUTPUT);
  pinMode(vrd1, OUTPUT);

  pinMode(v2, OUTPUT);
  pinMode(am2, OUTPUT);
  pinMode(vrd2, OUTPUT);

  pinMode(vP1, OUTPUT);
  pinMode(vrdP1, OUTPUT);

  pinMode(vP2, OUTPUT);
  pinMode(vrdP2, OUTPUT);

}

//semaforo subindo e descendo
void semaroVrdHorizontal(){
  digitalWrite(v1, LOW);
  digitalWrite(am1, LOW);
  digitalWrite(vrd1, HIGH);
}

void semaroVrmHorizontal(){
  digitalWrite(v1, HIGH);
  digitalWrite(am1, LOW);
  digitalWrite(vrd1, LOW);
}

void semaroAmarHorizontal(){
  digitalWrite(v1, LOW);
  digitalWrite(am1, HIGH);
  digitalWrite(vrd1, LOW);
}


//semaforo da direita para esquerda e esquerda para direita
void semaroVrdVertical(){
  digitalWrite(v2, LOW);
  digitalWrite(am2, LOW);
  digitalWrite(vrd2, HIGH);
}

void semaroVrmVertical(){
  digitalWrite(v2, HIGH);
  digitalWrite(am2, LOW);
  digitalWrite(vrd2, LOW);
}

void semaroAmarVertical(){
  digitalWrite(v2, LOW);
  digitalWrite(am2, HIGH);
  digitalWrite(vrd2, LOW);
}


// pedestres subindo e descendo
void pedestreVrdHorizontal(){
  digitalWrite(vP1, LOW);
  digitalWrite(vrdP1, HIGH);
}

void pedestrePscrHorizontal(){
  digitalWrite(vP1, LOW);
  digitalWrite(vrdP1, HIGH);
  delay(1500);
   digitalWrite(vrdP1, LOW);
  delay(1150);
  digitalWrite(vrdP1, HIGH);
  delay(1000);
  digitalWrite(vrdP1, LOW);
  delay(1000);
}

void pedestreVrmHorizontal(){
  digitalWrite(vP1, HIGH);
  digitalWrite(vrdP1, LOW);
}


// pedestres da direita para esquerda e esquerda para direita
void pedestreVrdVertical(){
  digitalWrite(vP2, LOW);
  digitalWrite(vrdP2, HIGH);
}

void pedestrePscrVertical(){
  digitalWrite(vP2, LOW);
  digitalWrite(vrdP2, HIGH);
  delay(1500);
  digitalWrite(vrdP2, LOW);
  delay(1250);
  digitalWrite(vrdP2, HIGH);
  delay(1000);
  digitalWrite(vrdP2, LOW);
  delay(1000);
}

void pedestreVrmVertical(){
  digitalWrite(vP2, HIGH);
  digitalWrite(vrdP2, LOW);
}

void loop() {
  pedestreVrmVertical();
 
  pedestreVrdHorizontal();
  semaroVrdHorizontal();
  semaroVrmVertical();

  delay(10000);

  semaroAmarHorizontal();
  pedestrePscrHorizontal();

  delay(1000);

  pedestreVrmHorizontal();
   

  delay(1000);

  pedestreVrdVertical();

  delay(1000);

  semaroVrmHorizontal();
  semaroVrdVertical();

  delay(10000);

  semaroAmarVertical();
  pedestrePscrVertical();
  pedestreVrmVertical();

  delay(1000);

}
