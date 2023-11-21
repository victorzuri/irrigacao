#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <thingProperties.h>

const char* ssid = "TISAFE-LAB";
const char* password = "Tisafe23@#";

const long utcOffsetInSeconds = -3 * 3600;  // Ajuste de fuso horário (-3 horas para o horário de Brasília)
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);


void setup() {
  pinMode(14, OUTPUT);
  Serial.begin(115200);

  // Conecta-se à rede Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conexão ao Wifi bem sucedida!");
  // Inicia o cliente de tempo (NTP)
  timeClient.begin();
  timeClient.setTimeOffset(utcOffsetInSeconds);
}

void initProperties() {
  ArduinoCloud.setThingId("709959d9-b5d9-43a9-9a44-fa432f7ce0c6");
  ArduinoCloud.addProperty(led, WRITE, ON_CHANGE, onLedChange);
  ArduinoCloud.addProperty(seconds, READ, ON_CHANGE);
}
/* ... */
WiFiConnectionHandler ArduinoIoTPreferredConnection("SECRET_SSID", "SECRET_PASS");

void loop() {
  timeClient.update();
  Serial.println(timeClient.getFormattedTime());
  // Verifica se é 6:00 da manhã
  if (timeClient.getHours() == 10) {
    digitalWrite(14, HIGH);  // Acende o LED
    Serial.println("LED aceso!");
    // Aguarde 10 segundos (ou o tempo desejado)
    delay(10000);
  } else {
    digitalWrite(14, LOW);  // Mantém o LED apagado
  }

  delay(1000);  // Aguarde 1 segundo antes de verificar novamente
}
