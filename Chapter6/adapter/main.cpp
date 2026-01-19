#include <iostream>
#include <string>


using namespace std;

class IPrinter {
public:
    virtual ~IPrinter() = default;
    virtual void print(const std::string& text) = 0;
};

class LegacyPrinter {
public:
    void oldPrint(const std::string& msg) {
        std::cout << "[LegacyPrinter] " << msg << std::endl;
    }
};

class PrinterAdapter : public IPrinter {
public:
    PrinterAdapter(LegacyPrinter* legacy)
        : legacy(legacy) {}

    void print(const std::string& text) override {
        // Translate new method → old method
        legacy->oldPrint(text);
    }

private:
    LegacyPrinter* legacy;
};

int main() {
    LegacyPrinter oldPrinter;

    // Wrap the old object in an adapter
    PrinterAdapter adapted(&oldPrinter);

    // Use it as a modern printer
    adapted.print("Hello through the adapter!");

    return 0;
}