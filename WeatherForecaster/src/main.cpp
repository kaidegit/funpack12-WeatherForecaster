#include "main.h"
#include "rpcWiFi.h"
#include "gui.h"
#include "gui_guider.h"

lv_ui guider_ui;

void setup()
{
    Serial.begin(115200);

    pinMode(WIO_KEY_A, INPUT_PULLUP);
    pinMode(WIO_KEY_B, INPUT_PULLUP);
    pinMode(WIO_KEY_C, INPUT_PULLUP);

    GUI_Init();
    setup_ui(&guider_ui);
    xTaskCreate(GUI_Run, "GUI_Task", 4096, NULL, 2, NULL);

    vTaskStartScheduler();
}

void loop()
{
    Serial.println("This is Loop");
    delay(100);
}