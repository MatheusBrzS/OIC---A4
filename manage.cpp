#include <ESP8266WiFi.h>         // Biblioteca WiFi para o ESP8266
#include <ESP8266HTTPClient.h>   // Biblioteca HTTPClient para o ESP8266

// Credenciais da rede Wi-Fi
const char* ssid = "Eleganza Modas - 5G";       // Substitua por seu SSID
const char* password = "zxasqw2K23";  // Substitua pela senha da rede Wi-Fi

// Definindo o endereço do servidor ThingSpeak e a chave de API
const char* server = "http://api.thingspeak.com/update";
String apiKey = "V7KS4WBR0W7VS39J";       // Substitua por sua chave de API do ThingSpeak

// Definindo os pinos para o sensor ultrassônico e o LED
const int trigPin = D1;              // Pino de trigger (ajuste conforme necessário)
const int echoPin = D2;              // Pino de echo (ajuste conforme necessário)
const int ledPin = D3;               // Pino onde o LED vermelho está conectado

// Variável para controlar o tempo de envio ao ThingSpeak
unsigned long lastSendTime = 0;      // Armazena o último tempo de envio
const unsigned long sendInterval = 10000; // Intervalo de envio em milissegundos (10 segundos)

// Função para inicializar o sensor ultrassônico
void setupUltrasonic() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// Função para medir a distância com o sensor ultrassônico
long readUltrasonicDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  long distance = (duration / 2) * 0.0343; // Converter para centímetros
  return distance;
}

// Função para mapear a distância medida
int mapDistance(long distance) {
  if (distance >= 30) {
    return 0;
  } else if (distance == 0) {
    return 100;
  } else {
    return map(distance, 1, 29, 100, 0);  // Mapeia os valores intermediários
  }
}

void setup() {
  Serial.begin(115200);
  setupUltrasonic();

  pinMode(ledPin, OUTPUT);     // Configura o pino do LED como saída
  digitalWrite(ledPin, LOW);   // Garante que o LED comece apagado

  // Conectando-se ao Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado ao Wi-Fi!");
}

void loop() {
  // Lê a distância a cada 1 segundo
  long distance = readUltrasonicDistance();
  int mappedValue = mapDistance(distance);

  Serial.print("Distância medida: ");
  Serial.print(distance);
  
  Serial.print(" Nível: ");
  Serial.println(mappedValue);

  // Verifica se mappedValue está acima de 90 para acender o LED
  if (mappedValue > 90) {
    digitalWrite(ledPin, HIGH);   // Acende o LED
  } else {
    digitalWrite(ledPin, LOW);    // Apaga o LED
  }

  // Envia os dados para o ThingSpeak a cada 10 segundos
  if (WiFi.status() == WL_CONNECTED && (millis() - lastSendTime >= sendInterval)) {
    lastSendTime = millis();  // Atualiza o tempo de envio

    // Enviando os dados mapeados para o ThingSpeak
    WiFiClient client;  // Cria o objeto WiFiClient
    HTTPClient http;
    String url = String(server) + "?api_key=" + apiKey + "&field1=" + String(mappedValue);

    http.begin(client, url);  // Usa o WiFiClient com a URL
    int httpResponseCode = http.GET();  // Enviando dados para ThingSpeak

    if (httpResponseCode > 0) {
      Serial.print("Código de resposta HTTP: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Erro ao enviar dados: ");
      Serial.println(http.errorToString(httpResponseCode).c_str());
    }
    http.end();
  } else if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Falha na conexão Wi-Fi. Tentando reconectar...");
    WiFi.reconnect(); // Tenta reconectar ao Wi-Fi
  }

  delay(1000);  // Aguarda 1 segundo antes de medir novamente
}
