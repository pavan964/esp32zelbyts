#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Redmi Note 11S";
const char* password = "8590397077";

const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

#define RELAY_PIN 23

const char* topic = "zelbytes/bench/pavan/cmd";

void callback(char* topic, byte* payload, unsigned int length) {

  String message = "";

  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("Received: ");
  Serial.println(message);

  if (message == "IRRIGATE") {
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Relay ON");
  }

  else if (message == "STOP") {
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Relay OFF");
  }
}

void setup_wifi() {

  Serial.println();
  Serial.print("Connecting to WiFi ");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {

  while (!client.connected()) {

    Serial.print("Connecting to MQTT...");

    if (client.connect("ESP32_Pavan_123")) {

      Serial.println("Connected");

      client.subscribe(topic);

      Serial.print("Subscribed to: ");
      Serial.println(topic);

    } else {

      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Retrying in 5 seconds");

      delay(5000);
    }
  }
}

void setup() {

  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH);

  setup_wifi();

  client.setServer(mqtt_server, 1883);

  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }

  client.loop();
}