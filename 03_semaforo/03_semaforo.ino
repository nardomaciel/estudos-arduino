#define led_Vermelho  8
#define led_Amarelo  9
#define led_Verde 10


void setup() {
  pinMode(led_Vermelho, OUTPUT);
  pinMode(led_Amarelo, OUTPUT);
  pinMode(led_Verde, OUTPUT);

}
void vermelho(int tmp){ //tmp tempo que o sinal (led) ficara aceso
  digitalWrite(led_Vermelho, HIGH);
  digitalWrite(led_Amarelo, LOW);
  digitalWrite(led_Verde, LOW);
  delay(tmp*1000);
}

void amarelo(int tmp){
  digitalWrite(led_Vermelho, LOW);
  digitalWrite(led_Amarelo, HIGH);
  digitalWrite(led_Verde, LOW);
  delay(tmp*1000);

}

void verde(int tmp){
  digitalWrite(led_Vermelho, LOW);
  digitalWrite(led_Amarelo, LOW);
  digitalWrite(led_Verde, HIGH);
  delay(tmp*1000);
}

void loop() {
  vermelho(7);
  verde(9);
  amarelo(2);

}
