#pragma once
#ifndef PROJECT_MEPHI_24_CAR_H
#define PROJECT_MEPHI_24_CAR_H
#include <string>
#include "data_sender.h"
struct CarData {
    double speed;       // Скорость автомобиля в км/ч
    double waterDepth;  // Глубина воды на дороге в метрах
    double wheel_degree;
    double car_mass;
    bool ABS_working;
    double weight_ratio;
    DataSender sender_;
    // Другие параметры, которые могут потребоваться для определения аквапланирования
    // Например, тип и состояние шин, наличие системы контроля стабильности и т.д.
};


class Car
{
public:
    CarData Get_Car_data() const;
private:
    CarData data_;
};

#endif //PROJECT_MEPHI_24_CAR_H
 