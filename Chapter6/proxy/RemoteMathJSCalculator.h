#pragma once
#include "ICalculator.h"
#include <string>

class RemoteMathJSCalculator : public ICalculator {
public:
    double evaluate(const std::string& expression) override;

private:
    std::string httpGet(const std::string& url);
};