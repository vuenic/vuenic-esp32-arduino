#ifndef VuenicESP32HTTP_H
#define VuenicESP32HTTP_H
#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>

class VuenicESP32HTTP
{
    public:
      VuenicESP32HTTP(String apiKey);
      void begin();
      void add(int key, String value);
      void add(int key, int value);
      void add(int key, float value);
      void add(int key, double value);
      String send();
      bool wifiConnection(String wifiSSID, String wifiPassword);
      
    private:
      String _apiKey;
      String _server = "http://api.vuenic.com/v1/devices/";
      String _port = "80";
      String jsonString = "{}";
      char* _wifiSSID;
      char* _wifiPass;
      String ipToString(IPAddress ip);
};

#endif