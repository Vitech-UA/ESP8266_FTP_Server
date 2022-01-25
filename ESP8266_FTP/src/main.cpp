#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <FS.h>
#include "ESP8266FtpServer.h"

const char* ssid     = "Nata";
const char* password = "L12q38w2";

FtpServer ftpSrv;


void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
  Serial.print("\n\nLocal IP: ");
  Serial.print(WiFi.localIP());

  SPIFFS.begin();
  ftpSrv.begin("vitech-ua", "bizolla_1994");

}

void loop() {
  ftpSrv.handleFTP();
}