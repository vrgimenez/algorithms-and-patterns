#include <iostream>
#include <string>
#include <map>

using namespace std;


class Logger {
public:
    void info(const std::string &msg) {
        cout << "[info] " << msg << endl;
    }

    void warn(const std::string &msg) {
        cout << "[warn] " << msg << endl;
    }

    static Logger* getInstance() {
        if (instance == nullptr) {
            cout << "[Logger] Instance created" << endl;
            instance = new Logger();
        }

        cout << "[Logger] return instance" << endl;

        return instance;
    }

private:
    Logger() = default;
    static Logger* instance;
};

void funcOne(void) {
    Logger *logger = Logger::getInstance();
    logger->info("Func One ran");
}

void funcTwo(void) {
    Logger *logger = Logger::getInstance();
    logger->info("Func Two ran");
}

Logger* Logger::instance = nullptr;

int main(int argc, char **argv) {
    Logger *logger = Logger::getInstance();

    bool error = true;
    if (error) {
        logger->warn("initialization failed");
    }

    funcOne();
    funcTwo();
    

    return 0;
}