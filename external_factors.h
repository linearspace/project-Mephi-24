#pragma once

#ifndef PROJECT_MEPHI_24_EXTERNALFACTORS_H
#define PROJECT_MEPHI_24_EXTERNALFACTORS_H


#include<string>

struct EnvironmentData {
    double latitude;            // Широта
    double longitude;           // Долгота
    std::string weather;        // Погодные условия (например, "дождь", "снег" и т.д.)
    double roadCondition;       // Состояние дороги (например, коэффициент сцепления)
};


class External_factors
{
public:
    External_factors(std::string serverAddress);
    EnvironmentData GetEnvironmentData();
private:
    EnvironmentData data_;
    std::string serverAddress_;
};



#endif //PROJECT_MEPHI_24_EXTERNALFACTORS_H


