#include <iostream>
#include <string>
#include <map>

using namespace std;

class Car {
private:
    int breaks;
public:
    Car(int breaks = 0)  : breaks(breaks) { }
    virtual void honk() = 0;
    virtual void run() = 0;
    void stop() {
        // THIS CODE IS IN THE INSTANCE
        cout << "Generic Stop with " << breaks << " breaks" << endl;
    }
};

class Fiat600: public Car {
public:
    Fiat600() : Car(2) {}
    virtual void honk() {
        // THIS CODE IS IN THE VTABLE
        cout << "Honk like a Fiat600" << endl;
    }
    virtual void run() {
        // THIS CODE IS IN THE VTABLE
        cout << "Run like a Fiat600" << endl;
    }
};


class Torino: public Car {
public:
    Torino() : Car(4) {}
    virtual void honk() {
        // THIS CODE IS IN THE VTABLE
        cout << "Honk like a Torino" << endl;
    }
    virtual void run() {
        // THIS CODE IS IN THE VTABLE
        cout << "Run like a Torino" << endl;
    }
};

class CarFactory {
public:
    static Car* getCarByName(string name) { 
        // Method getCarByName is located IN THE CLASS NOT in the CLASS
        if (name == "Fiat600") {
            return new Fiat600();
        } 
        if (name == "Torino") {
            return new Torino();
        } 

        return nullptr;
    }
};

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Pass the name of the car" << endl;
        return 0;
    }
 
    string carName(argv[argc-1]);
    cout << "Building Car by name " << carName << endl;
    Car* car = CarFactory::getCarByName(carName);

    if (car == nullptr) {
        cout << "Error, no Car class instance for name " << carName << endl;
        return -1;
    }

    // Honk
    car->honk();

    // Run
    car->run();

    // Stop
    car->stop();

    return 0;
}