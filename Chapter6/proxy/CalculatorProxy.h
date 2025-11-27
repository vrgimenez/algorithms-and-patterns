#pragma once
#include "ICalculator.h"
#include <unordered_map>
#include <string>

class CalculatorProxy : public ICalculator {
public:
    CalculatorProxy(ICalculator* realCalc);

    double evaluate(const std::string& expression) override;

private:
    ICalculator* realCalc;
    std::unordered_map<std::string, double> cache;
    bool isValidExpression(const std::string& expr);
};