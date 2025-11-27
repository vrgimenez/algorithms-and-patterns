#include "CalculatorProxy.h"
#include "RemoteMathJSCalculator.h"
#include <iostream>

int main() {
    RemoteMathJSCalculator realCalc;
    CalculatorProxy proxy(&realCalc);

    try {
        std::string expr = "2 * (7 - 3)";
        double result = proxy.evaluate(expr);
        std::cout << "Result: " << result << "\n";

        // Same expression → comes from cache
        double again = proxy.evaluate(expr);
        std::cout << "Result again (cached): " << again << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}