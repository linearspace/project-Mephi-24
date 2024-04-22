#pragma once

#ifndef PROJECT_MEPHI_24_DATA_ANALYZE_H
#define PROJECT_MEPHI_24_DATA_ANALYZE_H

#include "CarData.h"
#include "EnvironmentData.h"
#include <deque>

class DriftingDetector
{
private:
     std::deque<double> lateralAccelerationHistory_;
     std::deque<double> angularVelocityHistory_;
     static constexpr size_t historySize = 10;
     double threshold_;
     double angularThreshold_;

public:
     DriftingDetector(double threshold = 0.1, double angularThreshold = 0.1);
     bool isDrifting(const CarData &carData, const EnvironmentData &environmentData);
};

#endif
