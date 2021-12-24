#include "main.h"
#include "rpcWiFi.h"
#include "gui.h"
#include "gui_guider.h"
#include "network.h"
#include "weather.h"

lv_ui guider_ui;

void setup()
{
    Serial.begin(115200);

    GUI_Init();
    setup_ui(&guider_ui);
    xTaskCreate(GUI_Run, "GUI_Task", 4096, NULL, 2, NULL);

    vNopDelayMS(1000);

    pinMode(WIO_KEY_A, INPUT_PULLUP);
    pinMode(WIO_KEY_B, INPUT_PULLUP);
    pinMode(WIO_KEY_C, INPUT_PULLUP);

    Net_Init();

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

    location temp = GetLocationByIP();
    // Serial.printf("%f %f\n", temp.lat, temp.lon);

    // vTaskStartScheduler();
}

void loop()
{
    // Serial.printf("This is Loop\n");
    // GUI_Run(nullptr);
    delay(10);
}