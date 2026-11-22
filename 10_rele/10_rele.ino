#define RELAY_PIN 23 // Pino conectado ao módulo de relé  

void setup() {  
  Serial.begin(115200); // Inicializa a serial  
  pinMode(RELAY_PIN, OUTPUT); // Define o pino do relé como saída  
  digitalWrite(RELAY_PIN, LOW); // Relé desligado inicialmente  
}  

void loop() {  
  // Ativa a bomba  
  Serial.println("Bomba ligada.");  
  digitalWrite(RELAY_PIN, HIGH); // Liga o relé (bomba)  
  delay(10000); // Espera 10 segundos  

  // Desativa a bomba  
  Serial.println("Bomba desligada.");  
  digitalWrite(RELAY_PIN, LOW); // Desliga o relé (bomba)  
  delay(10000); // Espera 10 segundos  
}