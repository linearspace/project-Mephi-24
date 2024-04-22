#pragma once

#ifndef PROJECT_MEPHI_24_WORKER_H
#define PROJECT_MEPHI_24_WORKER_H

#pragma once
#include "CarData.h"
#include "EnvironmentData.h"
#include "DriftingDetector.h"
#include "waiter.h"

class Worker {
public:
    void handleAquaplaning(const CarData& carData, const EnvironmentData& environmentData);
    void performEmergencyStop(Car& car);
    void sendEmergencySignal(const DataSender& sender);
};

#endif // PROJECT_MEPHI_24_WORKER_H
