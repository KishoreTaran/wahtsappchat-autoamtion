#include <ESP8266WiFi.h>
#include <ThingESP.h>

ThingESP8266 thing("technicalaj", "nodemcuwhatsapp", "987654");  //yout thongESP credentials

int Relay1 = D1;
int Relay2 = D2;

unsigned long previousMillis = 0;
const long INTERVAL = 6000;  

void setup()
{
  Serial.begin(115200);
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  thing.SetWiFi("Test2","789321456@#"); //your Wifi SSID,Password
  thing.initDevice();
}


String HandleResponse(String query)
{
  if (query == "relay1 on") {
    digitalWrite(Relay1, 1);
    return "Done: Relay1 Turned ON";
  }

  else if (query == "relay1 off") {
    digitalWrite(Relay1, 0);
    return "Done: Relay1 Turned OFF";
  }

  else if (query == "relay2 on") {
    digitalWrite(Relay2, 1);
    return "Done: Relay2 Turned ON";
  }

  else if (query == "relay2 off") {
    digitalWrite(Relay2, 0);
    return "Done: Relay2 Turned OFF";
  }
  else return "Your command invalid..";
} 
void loop()
  {
  thing.Handle();

  }
