#include "weather.h"
#include "network.h"
#include "HTTPClient.h"
#include "stdio.h"
#include "ArduinoJson.h"

const char *ip2location = "http://ip-api.com/json/?lang=zh-CN";

location GetLocationByIP()
{
    location loca;
    HTTPClient http;
    int httpCode;
    String jsonData;
    DynamicJsonDocument jsonBuffer(1024);
    JsonObject jsonRoot;

    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.printf("Wifi err:");
        Serial.println(WiFi.status());
        goto err_handle;
    }

    http.begin(ip2location);
    httpCode = http.GET();
    if (httpCode != HTTP_CODE_OK)
    {
        Serial.printf("http GET err:");
        Serial.println(httpCode);
        http.end();
        goto err_handle;
    }
    jsonData = http.getString();
    Serial.println(jsonData);
    deserializeJson(jsonBuffer, jsonData);
    loca.lat = jsonBuffer["lat"];
    loca.lon = jsonBuffer["lon"];
    http.end();
    return loca;

err_handle:
    loca.lat = 0;
    loca.lon = 0;
    return loca;
}