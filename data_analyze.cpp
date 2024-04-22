#include "data_analyze.h"
#include <cmath>

DriftingDetector::DriftingDetector(double threshold, double angularThreshold)
    : threshold_(threshold), angularThreshold_(angularThreshold) {}

bool DriftingDetector::isDrifting(const CarData& carData, const EnvironmentData& environmentData) {
    if (!carData.ABS_working) {
        double lateralAcceleration = carData.speed * carData.wheel_degree;
        double angularVelocity = carData.angular_velocity;
        
        lateralAccelerationHistory_.push_back(lateralAcceleration);
        angularVelocityHistory_.push_back(angularVelocity);
        
        if (lateralAccelerationHistory_.size() > historySize) {
            lateralAccelerationHistory_.pop_front();
            angularVelocityHistory_.pop_front();
        }
        
        if (std::abs(lateralAcceleration) > threshold_ || std::abs(angularVelocity) > angularThreshold_) {
            return true;
        }
    }
    return false;
}