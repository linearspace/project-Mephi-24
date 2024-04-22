
#ifndef PROJECT_MEPHI_24_DATA_SENDER_H
#define PROJECT_MEPHI_24_DATA_SENDER_H
#pragma once
#include "waiter.h"
#include <string>

class DataSender {
public:
    DataSender(const std::string& serverAddress);
    void sendData(const Car car_);
private:
    std::string serverAddress_;
};
#endif //PROJECT_MEPHI_24_DATA_SENDER_H
