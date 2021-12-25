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
    loca.lon = jsonBuffer["lon"];
    loca.lat = jsonBuffer["lat"];
    Serial.printf("location:(%f,%f)", loca.lon, loca.lat);
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
    deserializeJson(jsonBuffer, jsonData);

    String2Enum parser1;
    Enum2CharArr parser2;

    weatherState skycon = parser1.Parse(jsonBuffer["result"]["realtime"]["skycon"]);
    float temperature = jsonBuffer["result"]["realtime"]["temperature"];
    float humidity = jsonBuffer["result"]["realtime"]["humidity"];
    int air = jsonBuffer["result"]["realtime"]["air_quality"]["aqi"]["chn"];

    char temp[10];
    lv_label_set_text(guider_ui.screen_skycon_label, parser2.Parse(skycon));
    sprintf(temp, "%.2f", temperature);
    lv_label_set_text(guider_ui.screen_temp_label, temp);
    sprintf(temp, "%.2f", humidity);
    lv_label_set_text(guider_ui.screen_humi_label, temp);
    sprintf(temp, "%d", air);
    lv_label_set_text(guider_ui.screen_air_label, temp);

    http.end();
}

void GetForecast(location loca)
{
    HTTPClient http;
    int httpCode;
    String jsonData;
    DynamicJsonDocument jsonBuffer(8192);
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
            weatherAPI_Daily);
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
    deserializeJson(jsonBuffer, jsonData);

    String2Enum parser1;
    Enum2CharArr parser2;

    dailyWeather weatherForecasr[3];
    weatherForecasr[0].temperature_max = jsonBuffer["result"]["daily"]["temperature"][0]["max"];
    weatherForecasr[0].temperature_min = jsonBuffer["result"]["daily"]["temperature"][0]["min"];
    weatherForecasr[0].air = jsonBuffer["result"]["daily"]["air_quality"]["aqi"][0]["avg"]["chn"];
    weatherForecasr[0].skycon = parser1.Parse(jsonBuffer["result"]["daily"]["skycon"][0]["value"]);

    weatherForecasr[1].temperature_max = jsonBuffer["result"]["daily"]["temperature"][1]["max"];
    weatherForecasr[1].temperature_min = jsonBuffer["result"]["daily"]["temperature"][1]["min"];
    weatherForecasr[1].air = jsonBuffer["result"]["daily"]["air_quality"]["aqi"][1]["avg"]["chn"];
    weatherForecasr[1].skycon = parser1.Parse(jsonBuffer["result"]["daily"]["skycon"][1]["value"]);

    weatherForecasr[2].temperature_max = jsonBuffer["result"]["daily"]["temperature"][2]["max"];
    weatherForecasr[2].temperature_min = jsonBuffer["result"]["daily"]["temperature"][2]["min"];
    weatherForecasr[2].air = jsonBuffer["result"]["daily"]["air_quality"]["aqi"][2]["avg"]["chn"];
    weatherForecasr[2].skycon = parser1.Parse(jsonBuffer["result"]["daily"]["skycon"][2]["value"]);

    char temp[15];
    lv_label_set_text(guider_ui.screen_first_skycon_label, parser2.Parse(weatherForecasr[0].skycon));
    sprintf(temp, "%.1f-%.1f", weatherForecasr[0].temperature_min, weatherForecasr[0].temperature_max);
    lv_label_set_text(guider_ui.screen_first_temper_label, temp);
    sprintf(temp, "AQI:%d", weatherForecasr[0].air);
    lv_label_set_text(guider_ui.screen_first_air_label, temp);

    lv_label_set_text(guider_ui.screen_second_skycon_label, parser2.Parse(weatherForecasr[1].skycon));
    sprintf(temp, "%.1f-%.1f", weatherForecasr[1].temperature_min, weatherForecasr[1].temperature_max);
    lv_label_set_text(guider_ui.screen_second_temper_label, temp);
    sprintf(temp, "AQI:%d", weatherForecasr[1].air);
    lv_label_set_text(guider_ui.screen_second_air_label, temp);

    lv_label_set_text(guider_ui.screen_third_skycon_label, parser2.Parse(weatherForecasr[2].skycon));
    sprintf(temp, "%.1f-%.1f", weatherForecasr[2].temperature_min, weatherForecasr[2].temperature_max);
    lv_label_set_text(guider_ui.screen_third_temper_label, temp);
    sprintf(temp, "AQI:%d", weatherForecasr[2].air);
    lv_label_set_text(guider_ui.screen_third_air_label, temp);

    http.end();
}
