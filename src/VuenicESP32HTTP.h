#ifndef VuenicESP32HTTP_H
#define VuenicESP32HTTP_H
#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>

class VuenicESP32HTTP
{
    public:
      VuenicESP32HTTP(String apiKey);
      void begin();
      void add(String key, String value);
      void add(String key, int value);
      void add(String key, float value);
      void add(String key, double value);
      bool wifiConnection(String wifiSSID, String wifiPassword);
      
    private:
      String _apiKey;
      char* _wifiSSID;
      char* _wifiPass;
      String ipToString(IPAddress ip);
};

#endif