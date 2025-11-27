#include <iostream>
#include <string>

using namespace std;

class Coffee {
public:
    virtual ~Coffee() = default;
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
};

class BasicCoffee : public Coffee {
public:
    std::string getDescription() const override {
        return "Coffee";
    }
    double cost() const override {
        return 1.50;
    }
};

class CoffeeDecorator : public Coffee {
protected:
    Coffee* wrapped;
public:
    CoffeeDecorator(Coffee* base) : wrapped(base) {}
};

class Milk : public CoffeeDecorator {
public:
    Milk(Coffee* base) : CoffeeDecorator(base) {}

    std::string getDescription() const override {
        return wrapped->getDescription() + ", Milk";
    }

    double cost() const override {
        return wrapped->cost() + 0.30;
    }
};

class Sugar : public CoffeeDecorator {
public:
    Sugar(Coffee* base) : CoffeeDecorator(base) {}

    std::string getDescription() const override {
        return wrapped->getDescription() + ", Sugar";
    }

    double cost() const override {
        return wrapped->cost() + 0.10;
    }
};

int main() {
    Coffee* coffee = new BasicCoffee();

    // Add decorators dynamically
    coffee = new Milk(coffee);
    coffee = new Sugar(coffee);
    coffee = new Sugar(coffee); // double sugar

    std::cout << coffee->getDescription() << std::endl;
    std::cout << "Total: $" << coffee->cost() << std::endl;

    delete coffee;
    return 0;
}