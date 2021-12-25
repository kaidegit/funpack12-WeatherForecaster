#pragma once

#include "main.h"
// #include <iostream>
#include <map>

typedef struct
{
    float lat;
    float lon;
} location;

typedef enum
{
    CLEAR_DAY,
    CLEAR_NIGHT,
    PARTLY_CLOUDY_DAY,
    PARTLY_CLOUDY_NIGHT,
    CLOUDY,
    LIGHT_HAZE,
    MODERATE_HAZE,
    HEAVY_HAZE,
    LIGHT_RAIN,
    MODERATE_RAIN,
    HEAVY_RAIN,
    STORM_RAIN,
    FOG,
    LIGHT_SNOW,
    MODERATE_SNOW,
    HEAVY_SNOW,
    STORM_SNOW,
    DUST,
    SAND,
    WIND
} weatherState;

typedef struct
{
    float temperature_min, temperature_max;
    int air;
    weatherState skycon;
} dailyWeather;

location GetLocationByIP();

void GetWeather(location loca);

void GetForecast(location loca);

class String2Enum
{
    std::map<String, weatherState> enumMap;

public:
    String2Enum()
    {
        enumMap["CLEAR_DAY"] = CLEAR_DAY;
        enumMap["CLEAR_NIGHT"] = CLEAR_NIGHT;
        enumMap["PARTLY_CLOUDY_DAY"] = PARTLY_CLOUDY_DAY;
        enumMap["PARTLY_CLOUDY_NIGHT"] = PARTLY_CLOUDY_NIGHT;
        enumMap["CLOUDY"] = CLOUDY;
        enumMap["LIGHT_HAZE"] = LIGHT_HAZE;
        enumMap["MODERATE_HAZE"] = MODERATE_HAZE;
        enumMap["HEAVY_HAZE"] = HEAVY_HAZE;
        enumMap["LIGHT_RAIN"] = LIGHT_RAIN;
        enumMap["MODERATE_RAIN"] = MODERATE_RAIN;
        enumMap["HEAVY_RAIN"] = HEAVY_RAIN;
        enumMap["STORM_RAIN"] = STORM_RAIN;
        enumMap["FOG"] = FOG;
        enumMap["LIGHT_SNOW"] = LIGHT_SNOW;
        enumMap["MODERATE_SNOW"] = MODERATE_SNOW;
        enumMap["HEAVY_SNOW"] = HEAVY_SNOW;
        enumMap["STORM_SNOW"] = STORM_SNOW;
        enumMap["DUST"] = DUST;
        enumMap["SAND"] = SAND;
        enumMap["WIND"] = WIND;
    };

    weatherState Parse(const String &value)
    {
        std::map<String, weatherState>::const_iterator iValue = enumMap.find(value);
        if (iValue == enumMap.end())
            ;
        return iValue->second;
    }
};

class Enum2CharArr
{
    std::map<weatherState, char *> enumMap;

public:
    Enum2CharArr()
    {
        enumMap[CLEAR_DAY] = "晴";
        enumMap[CLEAR_NIGHT] = "晴";
        enumMap[PARTLY_CLOUDY_DAY] = "多云";
        enumMap[PARTLY_CLOUDY_NIGHT] = "多云";
        enumMap[CLOUDY] = "阴";
        enumMap[LIGHT_HAZE] = "轻度雾霾";
        enumMap[MODERATE_HAZE] = "中度雾霾";
        enumMap[HEAVY_HAZE] = "重度雾霾";
        enumMap[LIGHT_RAIN] = "小雨";
        enumMap[MODERATE_RAIN] = "中雨";
        enumMap[HEAVY_RAIN] = "大雨";
        enumMap[STORM_RAIN] = "暴雨";
        enumMap[FOG] = "雾";
        enumMap[LIGHT_SNOW] = "小雪";
        enumMap[MODERATE_SNOW] = "中雪";
        enumMap[HEAVY_SNOW] = "大雪";
        enumMap[STORM_SNOW] = "暴雪";
        enumMap[DUST] = "浮尘";
        enumMap[SAND] = "沙尘";
        enumMap[WIND] = "大风";
    };

    char * Parse(weatherState &value)
    {
        std::map<weatherState, char *>::const_iterator iValue = enumMap.find(value);
        if (iValue == enumMap.end())
            ;
        return iValue->second;
    }
};