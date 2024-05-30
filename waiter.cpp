#include "waiter.h"
#include "car.h"
#include "external_factors.h"
#include "data_sender.h"
#include <iostream>


void Status_of_car::Set_IsAquaplaning() {
    this->isAquaplaning_ = true;
}

void Status_of_car::Set_NoAquaplaning() {
    this->isAquaplaning_ = false;
}

CarData Status_of_car::Get_status_of_car() {
    return this->car_.Get_Car_data();
}

EnvironmentData Status_of_car::Get_enviroment_data() {
    return this->environmentData_.GetEnvironmentData();
}

bool Status_of_car::isAquaplaning(const Car &car,External_factors& environmentData ) {
    CarData carData = car.Get_Car_data();
    EnvironmentData _environmentData = environmentData.GetEnvironmentData();
    car.Get_Car_data().sender_.sendData(carData);
    if (carData.speed < 60.0 || carData.waterDepth <= 0.1) {
        return false; // Если скорость низкая или глубина воды мала, то не аквапланирует
    }

    // Проверяем угол поворота руля для исключения аквапланирования во время поворота
    if (std::abs(carData.wheel_degree) > 20.0) {
        Set_IsAquaplaning();
        return true; // Если угол поворота руля большой, то аквапланирует
    }

    // Проверяем тип покрытия дороги
    if (_environmentData.roadCondition == 1) {
        Set_NoAquaplaning();
        return false; // Если дорога сухая, то не аквапланирует
    }

//    // Проверяем состояние шин
//    if (carData.tireCondition == "worn") {
//        return true; // Если шины изношены, то аквапланирует
//    }

    if (carData.car_mass / carData.weight_ratio > 3) {
        return true; // Если вес автомобиля слишком большой по сравнению с весом на оси, то аквапланирует
    }

    if (!carData.ABS_working) {
        Set_IsAquaplaning();
        return true; // Если система ABS не работает, то аквапланирует
    }


}


void Status_of_car::GettingInfo() {
    while (true) {
        bool aquaplaning = Status_of_car::isAquaplaning(this->car_, this->environmentData_);
        if (!aquaplaning) {
            break;
        }
    }
}


