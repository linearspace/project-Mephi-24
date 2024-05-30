#include "data_sender.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <curl/curl.h>
DataSender::DataSender(const std::string& serverAddress) : serverAddress_(serverAddress) {}

size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *data) {
    size_t totalSize = size * nmemb;
    data->append((char *)contents, totalSize);
    return totalSize;
}

void DataSender::sendData(const Car car_) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, car_.Get_Car_data());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, car_.Get_Car_data());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, car_.Get_Car_data());

        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Response from server: %s\n", response.c_str());
        }

        curl_easy_cleanup(curl);
    }
}