# 使用Wio Terminal制作一个天气预报仪

## 开发板介绍

本次我使用的开发板是一块来自矽递科技的Wio Terminal。

Wio Terminal 基于来自ATEML的SAMD51系列微控制器。这颗处理器可以运行在120MHz的主频上，同时可以超频至200MHz。这颗处理器带有192KB RAM, 496KB Flash，矽递也为它通过QSPI接口扩展了4MB的Flash，尽管它不支持XiP。

同时，Wio Terminal带有一个 Realtek RTL8720DN模块来连结无线连接。这个无线模块支持2.4GHz和5GHz的Wifi网络，也支持BLE。

## 实现的功能

本次我选择任务二：使用Wio Terminal制作一个天气预报仪

程序主要分为以下几个部分：

* GUI
* WiFi连接和HTTP访问
* Json解析与数据填入GUI

程序首先初始化屏幕和LVGL，开启LVGL心跳，然后连接网络，访问各个API来获取当前地址、当前天气和未来天气，并显示在屏幕上。循环中每隔一小时进行一次天气的更新。

## 具体实现

### GUI

本次GUI我主要使用了LVGL进行实现。由于GUI-Guider(1.2.1)目前似乎只支持LVGL7，故本次使用的依然是LVGL7.11.0。

TFT接口函数Wio Terminal已帮我们使用TFT_eSPI做好，直接调用即可。

```c++
TFT_eSPI tft;
static lv_disp_buf_t disp_buf;
static lv_color_t buf[TFT_HEIGHT * 10] = {0};

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);

void GUI_Init()
{
    lv_init(); // 初始化LVGL

    lv_log_register_print_cb((lv_log_print_g_cb_t)my_print); // 注册log输出组件

    tft.begin();
    tft.setRotation(3);
    tft.fillScreen(TFT_WHITE);

    lv_disp_buf_init(&disp_buf, buf, NULL, TFT_HEIGHT * 10); // 注册buffer

    // 注册屏幕组件
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = TFT_HEIGHT;
    disp_drv.ver_res = TFT_WIDTH;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.buffer = &disp_buf;
    lv_disp_drv_register(&disp_drv);
}

void GUI_Run(void *parm)
{
    while (true){
        lv_task_handler();
        delay(10);
    }
}

void my_print(lv_log_level_t level, const char *file, uint32_t line, const char *fn_name, const char *dsc)
{
    Serial.printf("%s(%s)@%d->%s", file, fn_name, line, dsc);
    Serial.println("");
    Serial.flush();
}

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}
```

main中开一个线程调用LVGL保持心跳即可：

```c++
// 新建一个全局变量以运行GUI-Guider的UI
lv_ui guider_ui;
// 初始化LVGL后新建一个线程保持LVGL的心跳
	GUI_Init();
    setup_ui(&guider_ui);
    xTaskCreate(GUI_Run, "GUI_Task", 4096, NULL, 2, NULL);
```

### Wi-Fi连接及HTTP访问

WiFi的初始化在seeed的Wiki中有示例进行介绍。需要注意的是，初始化WiFi后就无需使用`vTaskStartScheduler();`进行开启线程调度。

```c++
void Network_Init()
{
    uint8_t retry = 0;
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    WiFi.begin(WiFi_SSID, WiFi_PASSWORD);
    while ((WiFi.status() != WL_CONNECTED) && (retry < 10))
    {
        retry++;
        delay(500);
        Serial.println("Connecting to WiFi..");
        WiFi.begin(WiFi_SSID, WiFi_PASSWORD);
    }
    if (retry == 10)
    {
        Serial.println("Failed to connect to WiFi");
    }
    else
    {
        Serial.println("Connected to the WiFi network");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP()); // prints out the device's IP address
    }
}
```

HTTP的访问，也有相应api可以调用：

```c++
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
    http.end();
```

### Json解析与数据填入GUI

Json解析我使用了ArduinoJson这个库。根据说明文档编写即可。

下面是一个例子：

```c++
    jsonData = http.getString();
    deserializeJson(jsonBuffer, jsonData);

    String2Enum parser1;
    Enum2CharArr parser2;

    weatherState skycon = parser1.Parse(jsonBuffer["result"]["realtime"]["skycon"]);
    float temperature = jsonBuffer["result"]["realtime"]["temperature"];
    float humidity = jsonBuffer["result"]["realtime"]["humidity"];
    int air = jsonBuffer["result"]["realtime"]["air_quality"]["aqi"]["chn"];
```

然后将这些数据转化成字符串写入LVGL设计好的标签中即可

```c++
    char temp[10];
    lv_label_set_text(guider_ui.screen_skycon_label, parser2.Parse(skycon));
    sprintf(temp, "%.2f", temperature);
    lv_label_set_text(guider_ui.screen_temp_label, temp);
    sprintf(temp, "%.2f", humidity);
    lv_label_set_text(guider_ui.screen_humi_label, temp);
    sprintf(temp, "%d", air);
    lv_label_set_text(guider_ui.screen_air_label, temp);
```

## 功能展示

![pic](C:\Users\yekai\Documents\GitHub\funpack12-WeatherForecaster\pic.JPG)

## 心得体会

* platformIO+arduino开发方式，能让我们更注重于功能的实现而不是底层，这对快速开发很有优势。

* Seeed对Wio Terminal进行了很多适配，出了很多的基于开源库的专用的库，但有时候platformIO对库的索引和编译会导致一些问题。
* 学习arduino打的同时，我同时也在学习c++的一些特点及用法。