//
// Created by Administrator on 2024/11/28.
//
#include "main.h"

/*** Component objects ***/

static MillisTaskManager taskManager;

void HAL::HAL_Init() {

    Serial.begin(115200);


    /*注册定时器中断*/
    HAL::Encoder_Init();
    HAL::timer_init();
    HAL::RGB_init();
    HAL::BLE_init();

    //注册任务
    taskManager.Register(BLE_Update, 2000);
    taskManager.Register(timerUpdate, 10);

    Serial.printf("init ok\r\n");
}

void HAL::HAL_Update()
{
    taskManager.Running(millis());
}

