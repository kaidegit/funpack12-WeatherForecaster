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

location GetLocationByIP();

void GetWeather(location loca);

class EnumParser
{
    std::map<String, weatherState> enumMap;

public:
    EnumParser()
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

    weatherState ParseSomeEnum(const String &value)
    {
        std::map<String, weatherState>::const_iterator iValue = enumMap.find(value);
        if (iValue == enumMap.end())
            ;
        return iValue->second;
    }
};