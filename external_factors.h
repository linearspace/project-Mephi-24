#pragma once

#ifndef PROJECT_MEPHI_24_EXTERNALFACTORS_H
#define PROJECT_MEPHI_24_EXTERNALFACTORS_H


#include<string>

struct EnvironmentData {
    double latitude;            // Широта
    double longitude;           // Долгота
    std::string weather;        // Погодные условия (например, "дождь", "снег" и т.д.)
    double roadCondition;       // Состояние дороги (например, коэффициент сцепления)
    // Другие параметры окружающей среды, которые могут быть важными для аквапланирования
    // Например, тип покрытия дороги, температура окружающего воздуха и т.д.
};


class External_factors
{
    EnvironmentData GetEnvironmentData();
private:
    EnvironmentData data_;
};



#endif //PROJECT_MEPHI_24_EXTERNALFACTORS_H


