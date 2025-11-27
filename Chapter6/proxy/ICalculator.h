#pragma once
#include <string>

class ICalculator {
public:
    virtual ~ICalculator() = default;
    virtual double evaluate(const std::string& expression) = 0;
};