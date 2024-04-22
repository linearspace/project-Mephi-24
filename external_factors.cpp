#include "external_factors.h"
#include <iostream>
#include <curl/curl.h>
#include <json/json.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *data) {
    data->append((char *)contents, size * nmemb);
    return size * nmemb;
}

External_factors::External_factors(std::string serverAddress) :
serverAddress_(serverAddress){}


EnvironmentData External_factors::GetEnvironmentData() {
    EnvironmentData envData;

    CURL *curl;
    CURLcode res;
    std::string data;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, serverAddress_);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            // Парсинг JSON
            Json::CharReaderBuilder builder;
            Json::CharReader *reader = builder.newCharReader();
            Json::Value root;
            std::string errors;
            bool parsingSuccessful = reader->parse(data.c_str(), data.c_str() + data.size(), &root, &errors);
            delete reader;

            if (!parsingSuccessful) {
                std::cerr << "Failed to parse JSON: " << errors << std::endl;
            } else {
                // Извлечение данных из JSON и заполнение структуры EnvironmentData
                envData.latitude = root["latitude"].asDouble();
                envData.longitude = root["longitude"].asDouble();
                envData.weather = root["weather"].asString();
                envData.roadCondition = root["roadCondition"].asDouble();
                // Другие данные о погоде и окружающей среде можно добавить аналогичным образом
            }
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return envData;
}