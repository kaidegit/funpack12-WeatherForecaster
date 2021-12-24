#pragma once

#include "main.h"

typedef struct{
    float lat;
    float lon;
} location;

location GetLocationByIP();