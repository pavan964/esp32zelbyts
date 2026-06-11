#include <WiFi.h>

void setup() {
  Serial.begin(115200);

  Serial.println("Scanning WiFi...");

  int n = WiFi.scanNetworks();

  if (n == 0) {
    Serial.println("No networks found");
  } else {
    for (int i = 0; i < n; i++) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.println(WiFi.SSID(i));
    }
  }
}

void loop() {}
