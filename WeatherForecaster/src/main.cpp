#include "main.h"
#include "rpcWiFi.h"
#include "gui.h"
#include "gui_guider.h"
#include "network.h"
#include "weather.h"

lv_ui guider_ui;
bool refresh_flag;

void btn_callback()
{
    // Serial.printf("This is Btn Callback\n");
    refresh_flag = true;
}

void setup()
{
    Serial.begin(115200);

    GUI_Init();
    setup_ui(&guider_ui);
    xTaskCreate(GUI_Run, "GUI_Task", 4096, NULL, 2, NULL);

    vNopDelayMS(1000);

    Network_Init();

    if (WiFi.status() == WL_CONNECTED)
    {
        lv_scr_load(guider_ui.screen);
    }
    else
    {
        lv_scr_load(guider_ui.fail);
        while (1)
            ;
    }

    RefreshWeather();

    pinMode(WIO_KEY_C, INPUT_PULLUP);
    attachInterrupt(WIO_KEY_C, btn_callback, FALLING);
    refresh_flag = false;

    // Serial.printf("%f %f\n", temp.lat, temp.lon);

    // vTaskStartScheduler();
}

void loop()
{
    // Serial.printf("This is Loop\n");
    // GUI_Run(nullptr);
    // delay(10);

    //延时1s*60*60=1h
    for (uint8_t i = 0; i < 60; i++)
    {
        for (uint8_t j = 0; j < 60; j++)
        {
            delay(1000);
            if (refresh_flag)
            {
                while (digitalRead(WIO_KEY_C) == LOW)
                    ;
                RefreshWeather();
                refresh_flag = false;
            }
        }
    }
    RefreshWeather();
}