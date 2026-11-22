#include <WiFi.h>  
#include <WiFiUdp.h>  
#include <NTPClient.h>  
#include <TimeLib.h>  
#include <Timezone.h>  
 
// Substitua com suas credenciais Wi-Fi  
const char* ssid = "NOME_DA_REDE";     // troque pelo nome da sua rede
const char* password = "SENHA_DA_REDE";  // e pela senha

// Configuração do NTP  
WiFiUDP ntpUDP;  
NTPClient timeClient(ntpUDP, "pool.ntp.org", 0, 60000); // GMT offset é 0 aqui  

// Defina o fuso horário  
TimeChangeRule brasilia = {"BRT", Last, Sun, Mar, -180}; // Horário de Brasília (UTC-3), sem horário de verão  
Timezone myTZ(brasilia, brasilia);  

void setup() {  
    Serial.begin(115200);  
    WiFi.begin(ssid, password);  
    
    while (WiFi.status() != WL_CONNECTED) {  
        delay(1000);  
        Serial.println("Conectando ao WiFi...");  
    }  
    
    Serial.println("Conectado ao WiFi");  
    timeClient.begin();  
}  

void loop() {  
    timeClient.update();  
    
    // Define a hora atual  
    setTime(timeClient.getEpochTime());  
    
    // Obtenha a hora local com o fuso horário  
    time_t localTime = myTZ.toLocal(now());  

    Serial.print("Hora Local: ");  
    Serial.print(hour(localTime));  
    Serial.print(":");  
    Serial.print(minute(localTime));  
    Serial.print(":");  
    Serial.println(second(localTime));  
    
    Serial.print("Data Local: ");  
    Serial.print(day(localTime));  
    Serial.print("/");  
    Serial.print(month(localTime));  
    Serial.print("/");  
    Serial.println(year(localTime));  

    // Obtenha e imprima o dia da semana  
    int weekDay = dayOfWeek(localTime);  
    Serial.print("Dia da Semana: ");  
    switch (weekDay) {  
        case 0: Serial.println("Domingo"); break;  
        case 1: Serial.println("Segunda-feira"); break;  
        case 2: Serial.println("Terça-feira"); break;  
        case 3: Serial.println("Quarta-feira"); break;  
        case 4: Serial.println("Quinta-feira"); break;  
        case 5: Serial.println("Sexta-feira"); break;  
        case 6: Serial.println("Sábado"); break;  
    }  
    
    delay(10000); // Atualiza a cada 10 segundos  
}