#pragma once
#include "car.h"
#include "external_factors.h"
#ifndef PROJECT_MEPHI_24_WAITER_H
#define PROJECT_MEPHI_24_WAITER_H

class Status_of_car
{
public:
    bool isAquaplaning(const Car &car,External_factors& environmentData);
    void Set_IsAquaplaning();
    void Set_NoAquaplaning();
    CarData Get_status_of_car();
    EnvironmentData Get_enviroment_data();
    void GettingInfo();
private:
    bool isAquaplaning_;
    Car car_;
    External_factors environmentData_;
};


#endif //PROJECT_MEPHI_24_WAITER_H
