#include "RemoteMathJSCalculator.h"
#include <curl/curl.h>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <iomanip>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string RemoteMathJSCalculator::httpGet(const std::string& url) {
    CURL* curl = curl_easy_init();
    if (!curl) throw std::runtime_error("curl init failed");

    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK)
        throw std::runtime_error("HTTP request failed");

    return response;
}

double RemoteMathJSCalculator::evaluate(const std::string& expression) {
    // URL encoding needed (e.g. +, spaces)
    std::ostringstream encoded;
    encoded << std::hex << std::uppercase;

    for (unsigned char c : expression) {
        if (isalnum(c) || c == '*' || c == '/' || c == '(' || c == ')')
            encoded << c;
        else {
            encoded << '%' << std::setw(2) << int(c);
        }
    }

    std::string url = "https://api.mathjs.org/v4/?expr=" + encoded.str();

    std::string result = httpGet(url);

    return atof(result.c_str());
}