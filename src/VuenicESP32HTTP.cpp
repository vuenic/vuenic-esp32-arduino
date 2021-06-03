#include "VuenicESP32HTTP.h"

VuenicESP32HTTP::VuenicESP32HTTP(String apiKey) {
    _apiKey = apiKey;
}

// String Value
void VuenicESP32HTTP::add(String key, String value) {
    DynamicJsonDocument doc(256);
    deserializeJson(doc, jsonString);    
    doc[String(key)] = value;
    String newInsert;
    serializeJson(doc, newInsert);
    jsonString = newInsert;
}

// Integer Value
void VuenicESP32HTTP::add(String key, int value) {
    DynamicJsonDocument doc(256);
    deserializeJson(doc, jsonString);    
    doc[String(key)] = value;
    String newInsert;
    serializeJson(doc, newInsert);
    jsonString = newInsert;
}

// Float Value
void VuenicESP32HTTP::add(String key, float value) {
    DynamicJsonDocument doc(256);
    deserializeJson(doc, jsonString);    
    doc[String(key)] = value;
    String newInsert;
    serializeJson(doc, newInsert);
    jsonString = newInsert;
}

// Double Value
void VuenicESP32HTTP::add(String key, double value) {
    DynamicJsonDocument doc(256);
    deserializeJson(doc, jsonString);    
    doc[String(key)] = value;
    String newInsert;
    serializeJson(doc, newInsert);
    jsonString = newInsert;
}

bool VuenicESP32HTTP::wifiConnection(String wifiSSID, String wifiPassword) {
    char wifiSSIDChar[wifiSSID.length()+1];
    char wifiPasswordChar[wifiPassword.length()+1];

    wifiSSID.toCharArray(wifiSSIDChar, wifiSSID.length()+1);
    wifiPassword.toCharArray(wifiPasswordChar, wifiPassword.length()+1);

    _wifiSSID = wifiSSIDChar;
    _wifiPass = wifiPasswordChar;

    WiFi.begin(_wifiSSID, _wifiPass);
    Serial.println("Connecting to " + wifiSSID + "...");

    int counter = 0;
    while(WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println(".");
        counter++;
        if(counter >= 10) {
            counter = 0;
            Serial.println("Could not connect to " + wifiSSID + "! Retrying...");
        }
    }

    Serial.println("WiFi Connected!");
    Serial.println("IP Address: " + ipToString(WiFi.localIP()));
    return true;
}

String VuenicESP32HTTP::ipToString(IPAddress ip){
    String s="";
    for (int i=0; i<4; i++)
        s += i  ? "." + String(ip[i]) : String(ip[i]);
    return s;
}