const int sensorPin = 34; // Pino onde o sensor de umidade está conectado  
const int relePin = 2; // Pino onde o relé está conectado  

// Defina os limites de umidade  
const int umidadeMinima = 40; // Umidade mínima para ligar o relé  
const int umidadeMaxima = 60; // Umidade máxima para desligar o relé  

void setup() {  
    Serial.begin(115200); // Inicializa a comunicação serial  
    pinMode(relePin, OUTPUT); // Configura o pino do relé como saída  
    digitalWrite(relePin, LOW); // Inicializa o relé desligado  
}  

void loop() {  
    int valorUmidade = analogRead(sensorPin); // Lê o valor do sensor de umidade  
    // Mapeia o valor lido para o intervalo de umidade desejado (0-1023 para 0-100%)  
    int umidade = map(valorUmidade, 0, 4095, 100, 0); // ADC do ESP32 vai de 0 a 4095  

    Serial.print("Umidade: ");  
    Serial.println(umidade); // Mostra a umidade lida no monitor serial  

    if (umidade < umidadeMinima) {  
        digitalWrite(relePin, HIGH); // Liga o relé  
        Serial.println("Relé Ativado (Bomba Ligada)");  
    } else if (umidade > umidadeMaxima) {  
        digitalWrite(relePin, LOW); // Desliga o relé  
        Serial.println("Relé Desativado (Bomba Desligada)");  
    }  

    delay(1000); // Espera 1 segundo antes de ler novamente  
}  