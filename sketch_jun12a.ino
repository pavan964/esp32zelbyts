#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float temp = NAN;
  float hum = NAN;

  // Retry up to 3 times if NaN
  for (int i = 0; i < 3; i++) {
    temp = dht.readTemperature();
    hum = dht.readHumidity();

    if (!isnan(temp) && !isnan(hum))
      break;

    delay(2000);
  }

  bool ok = (!isnan(temp) && !isnan(hum));

  Serial.print("{\"temp\":");
  if (ok) Serial.print(temp);
  else Serial.print("null");

  Serial.print(",\"humidity\":");
  if (ok) Serial.print(hum);
  else Serial.print("null");

  Serial.print(",\"ok\":");
  Serial.print(ok ? "true" : "false");
  Serial.println("}");

  delay(5000);
}