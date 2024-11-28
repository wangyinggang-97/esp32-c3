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


    /* Encoder */
    void Encoder_Init();
    void Encoder_Update();
    int32_t Encoder_GetDiff();
    bool Encoder_GetIsPush();
    void Encoder_SetEnable(bool en);
}
#endif //ESP32C3_BLE_HAL_H
