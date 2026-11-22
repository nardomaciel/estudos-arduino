#include <WiFi.h>  
#include <ESPAsyncWebServer.h>  

const char* ssid = "NOME_DA_REDE";     // troque pelo nome da sua rede
const char* password = "SENHA_DA_REDE";  // e pela senha
AsyncWebServer server(80);  

void setup() {  
    Serial.begin(115200);  
    WiFi.begin(ssid, password);  
    
    while (WiFi.status() != WL_CONNECTED) {  
        delay(1000);  
        Serial.println("Conectando ao WiFi...");  
    }  
    
    Serial.println("Conectado ao WiFi!");  

    server.on("/test", HTTP_GET, [](AsyncWebServerRequest *request){  
        request->send(200, "text/plain", "Funcionando!");  
    });  

    server.begin();  
}  

void loop() {  
    // Nada aqui  
}  