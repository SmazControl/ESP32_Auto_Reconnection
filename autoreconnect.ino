#include <WiFi.h>
unsigned long delay2 = millis(); // delay2 for reconnect and fail

void WiFiConnect()
{
  WiFi.mode(WIFI_OFF);
  delay(100);
  WiFi.mode(WIFI_STA);
  delay(100);
  WiFi.begin("YourWiFiSSID", "YourWiFiPassword");
  unsigned long delay1 = millis(); // delay1 time until reconnrction
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (millis()-delay1>10000) { // 10000 = 10sec
      break;
    }
  }
  if (WiFi.status() == WL_CONNECTED) {  
    Serial.println("");
    Serial.println("WiFi connected");  
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }
}

void setup()
{
  Serial.begin(115200);
  WiFiConnect();
  // Your code here
}

void loop() {
  if (WiFi.status() != WL_CONNECTED && millis()-delay2>60000) {  // 60000 = 1min
    delay2=millis();
    WiFiConnect();
  }
  // Your code here
  delay(1000);
}
