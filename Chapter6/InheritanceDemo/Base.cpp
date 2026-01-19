#include "Base.h"

Base::Base() : value(0) {
    std::cout << "Base() default constructor\n";
}

Base::Base(int x) : value(x) {
    std::cout << "Base(" << x << ") parameterized constructor\n";
}

Base::Base(const Base& other) : value(other.value) {
    std::cout << "Base(const Base&) copy constructor\n";
}

Base& Base::operator=(const Base& other) {
    std::cout << "Base::operator=(const Base&) copy assignment\n";
    if (this != &other) {
        value = other.value;
    }
    return *this;
}

Base::Base(Base&& other) noexcept : value(other.value) {
    std::cout << "Base(Base&&) move constructor\n";
    other.value = 0;
}

Base& Base::operator=(Base&& other) noexcept {
    std::cout << "Base::operator=(Base&&) move assignment\n";
    if (this != &other) {
        value = other.value;
        other.value = 0;
    }
    return *this;
}

void Base::normalMethod() const {
    std::cout << "Base::normalMethod\n";
}

void Base::virtualMethod() const {
    std::cout << "Base::virtualMethod\n";
}

Base::~Base() {
    std::cout << "~Base() destructor\n";
}

void Base::safeVirtualDestructor() {
    std::cout << "Base::safeVirtualDestructor (virtual)\n";
}