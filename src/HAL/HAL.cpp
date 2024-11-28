//
// Created by Administrator on 2024/11/28.
//
#include "main.h"

/*** Component objects ***/
Pixel rgb;
static MillisTaskManager taskManager;

void HAL::HAL_Init() {

    rgb.init();
    rgb.setBrightness(0.1).setRGB(0, 0, 16, 204).setRGB(1, 0, 122, 104);
    Serial.begin(115200);
}

void HAL::HAL_Update()
{
    taskManager.Running(millis());
}