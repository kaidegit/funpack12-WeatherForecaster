#include "main.h"
#include "weather.h"
#include "network.h"
#include "HTTPClient.h"
#include "stdio.h"
#include "ArduinoJson.h"
#include "gui.h"

const char *locationAPI = "http://ip-api.com/json/?lang=zh-CN";
// weather API 格式为 title + '/' + token + '/' + 经度(lon) + ',' + 纬度(lat) + '/' + ways(daily,realtime,etc.)
const char *weatherAPI_Title = "http://api.caiyunapp.com/v2.5";
const char *weatherAPI_Realtime = "realtime.json";
const char *weatherAPI_Daily = "daily.json";
const char *weatherAPI_Token = "LJ4UQACgblNIo8Ca";

location GetLocationByIP()
{
    location loca;
    HTTPClient http;
    int httpCode;
    String jsonData;
    DynamicJsonDocument jsonBuffer(1024);

    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.printf("Wifi err:");
        Serial.println(WiFi.status());
        goto err_handle;
    }

    http.begin(locationAPI);
    httpCode = http.GET();
    if (httpCode != HTTP_CODE_OK)
    {
        Serial.printf("http GET err:");
        Serial.println(httpCode);
        http.end();
        goto err_handle;
    }
    jsonData = http.getString();
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

void GetWeather(location loca)
{
    HTTPClient http;
    int httpCode;
    String jsonData;
    DynamicJsonDocument jsonBuffer(4096);
    char weatherAPI[100];
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.printf("Wifi err:");
        Serial.println(WiFi.status());
        return;
    }
    sprintf(weatherAPI,
            "%s/%s/%f,%f/%s",
            weatherAPI_Title, weatherAPI_Token,
            loca.lon, loca.lat,
            weatherAPI_Realtime);
    Serial.println(weatherAPI);
    delay(100);
    http.begin(weatherAPI);
    httpCode = http.GET();
    if (httpCode != HTTP_CODE_OK)
    {
        Serial.printf("http GET err:");
        Serial.println(httpCode);
        http.end();
        return;
    }
    jsonData = http.getString();
    Serial.println(jsonData);
    deserializeJson(jsonBuffer, jsonData);
    EnumParser parser;
    String skyconString = jsonBuffer["result"]["realtime"]["skycon"];
    weatherState skycon = parser.ParseSomeEnum(skyconString);
    float temperature = jsonBuffer["result"]["realtime"]["temperature"];
    float humidity = jsonBuffer["result"]["realtime"]["humidity"];
    int air = jsonBuffer["result"]["realtime"]["air_quality"]["aqi"]["chn"];
    // Serial.println(skyconString);
    // Serial.println(temperature);
    // Serial.println(humidity);
    // Serial.println(air);
    char temp[10];
    lv_label_set_text(guider_ui.screen_label_3, skyconString.c_str());
    sprintf(temp, "%.2f", temperature);
    lv_label_set_text(guider_ui.screen_temp_label, temp);
    sprintf(temp, "%.2f", humidity);
    lv_label_set_text(guider_ui.screen_humi_label, temp);
    sprintf(temp, "%d", air);
    lv_label_set_text(guider_ui.screen_air_label, temp);

    http.end();
}
