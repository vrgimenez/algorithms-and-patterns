#include "Base.h"
#include "Derived.h"

int main() {

    std::cout << "\n=== Construction Order ===\n";
    Derived d1;

    std::cout << "\n=== Param Construction ===\n";
    Derived d2(10, 20);

    std::cout << "\n=== Copy Constructor ===\n";
    Derived d3 = d2;

    std::cout << "\n=== Copy Assignment ===\n";
    d3 = d1;

    std::cout << "\n=== Move Constructor ===\n";
    Derived d4 = std::move(d3); // d3 becomes "moved-from"

    std::cout << "\n=== Move Assignment ===\n";
    d4 = std::move(d2);

    std::cout << "\n=== Methods (no polymorphism) ===\n";
    d2.normalMethod();    // calls Derived version
    d2.virtualMethod();   // calls Derived version

    std::cout << "\n=== Polymorphism ===\n";
    Base* ptr = new Derived(); // Base pointer to Derived object
    ptr->normalMethod();       // non-virtual → Base version called
    ptr->virtualMethod();      // virtual → Derived version called

    std::cout << "\n=== Destruction (without virtual destructor) ===\n";
    delete ptr; // Only Base destructor called (!!!) → BAD

    std::cout << "\n=== Correct destruction via virtual method ===\n";
    Base* ptr2 = new Derived();
    ptr2->safeVirtualDestructor(); // calls Derived? No override: Base only
    delete ptr2; // still wrong because Base destructor isn't virtual

    std::cout << "\n=== Correct destruction using virtual destructor (manually) ===\n";
    // Demonstration: Use virtual destructor in Base
    // (Modify Base::~Base() to `virtual ~Base()` to fix)
    
    return 0;
}