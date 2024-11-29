//
// Created by Administrator on 2024/11/28.
//

#ifndef ESP32C3_BLE_HAL_H
#define ESP32C3_BLE_HAL_H

#include "HAL_Def.h"

namespace HAL
{
    /**/
    void HAL_Init();
    void HAL_Update();

    /*RGB*/
    void RGB_init();
    void RGB_Update();
    void RGBrandom(int id);

    /* Encoder */
    void Encoder_Init();
    void Encoder_Update();
    int32_t Encoder_GetDiff();
    bool Encoder_GetIsPush();
    void Encoder_SetEnable(bool en);

    /*timer*/
    void timer_init();
    void timerUpdate();

    /*BLE*/
    void BLE_init();
    void BLE_Update();

}
#endif //ESP32C3_BLE_HAL_H
