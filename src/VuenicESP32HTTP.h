#ifndef VuenicESP32HTTP_H
#define VuenicESP32HTTP_H
#include <Arduino.h>
#include <WiFi.h>

class VuenicESP32HTTP
{
    public:
      VuenicESP32HTTP(String apiKey);
      bool wifiConnection(String wifiSSID, String wifiPassword);
      
    private:
      String _apiKey;
      char* _wifiSSID;
      char* _wifiPass;
      String ipToString(IPAddress ip);
};

#endif