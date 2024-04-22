#include "worker.h"

void Worker::handleAquaplaning(const CarData& carData, const EnvironmentData& environmentData) {
    DriftingDetector detector;
    bool isDrifting = detector.isDrifting(carData, environmentData);
    if (isDrifting) {
        Status_of_car status;
        status.Set_IsAquaplaning();
    } else {
        Status_of_car status;
        status.Set_NoAquaplaning();
    }
}

void Worker::performEmergencyStop(Car& car) {
    car.decelerate(10.0);
}

void Worker::sendEmergencySignal(const DataSender& sender) {
    sender.sendData(Car());
}