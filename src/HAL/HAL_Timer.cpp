//
// Created by Administrator on 2024/11/29.
//
#include "main.h"

hw_timer_t *timer=NULL;

/*timer*/
typedef struct {
    uint8_t Flag;
    uint8_t TIMER_2sFlag;
    uint16_t TIMER;
}tim_t;

tim_t tim={false,false,0};

void ARDUINO_ISR_ATTR Timer_Callback()
{
    tim.Flag= true;
    if(++tim.TIMER>=200)//2s查询一次蓝牙
    {
        tim.TIMER=0;
        tim.TIMER_2sFlag= true;
    }
}

void HAL::timer_init() {

    timer = timerBegin(0,160, true);
    timerAttachInterrupt(timer,Timer_Callback, false);
    timerAlarmWrite(timer,10*1000, true); // 10*1000 =10ms  闹钟频率 = (1 / 1MHz) * 1000000 = 1s
    timerAlarmEnable(timer);
}

void HAL::timerUpdate() {

    /*10ms进入中断*/
    if (tim.Flag==true) {
        tim.Flag= false;
        HAL::Encoder_Update();
    }
    if(tim.TIMER_2sFlag == true)
    {
        tim.TIMER_2sFlag= false;
        //HAL::BLE_Update();
        //Serial.printf("BLE 2s\r\n");
    }
}