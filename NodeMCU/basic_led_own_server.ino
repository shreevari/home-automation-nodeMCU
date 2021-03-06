#define _DISABLE_TLS_
#define THINGER_SERVER "server_ip_address"

#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>

#define USERNAME "your_user_name"
#define DEVICE_ID "your_device_id"
#define DEVICE_CREDENTIAL "your_device_credential"

#define SSID "your_wifi_ssid"
#define SSID_PASSWORD "your_wifi_ssid_password"

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  thing.add_wifi(SSID, SSID_PASSWORD);

  
  thing["led"] << digitalPin(LED_BUILTIN); // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)

  
  thing["millis"] >> outputValue(millis()); // resource output example (i.e. reading a sensor value)

}

void loop() {
  thing.handle();
}
