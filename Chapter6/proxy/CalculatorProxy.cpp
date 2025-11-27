#include "CalculatorProxy.h"
#include <iostream>
#include <regex>

CalculatorProxy::CalculatorProxy(ICalculator* realCalc)
    : realCalc(realCalc) {}

bool CalculatorProxy::isValidExpression(const std::string& expr) {
    std::regex valid("^[0-9+\\-*/() ]+$");
    return std::regex_match(expr, valid);
}

double CalculatorProxy::evaluate(const std::string& expr) {
    std::cout << "[Proxy] Request: " << expr << "\n";

    if (!isValidExpression(expr)) {
        throw std::runtime_error("Invalid expression");
    }

    // cache
    if (cache.count(expr)) {
        std::cout << "[Proxy] Cache hit!\n";
        return cache[expr];
    }

    std::cout << "[Proxy] Forwarding to remote MathJS API...\n";
    double result = realCalc->evaluate(expr);

    cache[expr] = result;
    return result;
}