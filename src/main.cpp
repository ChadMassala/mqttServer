#include <ESP8266WiFi.h>
#include <uMQTTBroker.h>

const char* ssid = "SSD"; // Replace with your WiFi SSID
const char* password = "PWD"; // Replace with your WiFi password

uint16_t custom_port = 1234; // Change to your desired port
const char* mqttUser = "admin";         // MQTT username
const char* mqttPass = "0000";          // MQTT password

class MyBroker : public uMQTTBroker {
public:
    virtual bool onConnect(IPAddress addr, uint16_t client_count) {
        Serial.println("New client connected!");
        return true;
    }
    virtual bool onAuth(String username, String password) override {
        return (username == mqttUser && password == mqttPass);
    }
};

MyBroker broker;

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) delay(500);
    Serial.println("WiFi connected. Broker IP: " + WiFi.localIP().toString());
    
    broker.init(custom_port); // Initialize the broker on the custom port
}

void loop() {
    // Handle client connections (no need for client.loop())
}