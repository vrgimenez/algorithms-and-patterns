#include "Derived.h"
#include <iostream>

Derived::Derived()
    : Base(), extra(0)
{
    std::cout << "Derived() default constructor\n";
}

Derived::Derived(int x, int y)
    : Base(x), extra(y)
{
    std::cout << "Derived(" << x << ", " << y << ") constructor\n";
}

Derived::Derived(const Derived& other)
    : Base(other), extra(other.extra)
{
    std::cout << "Derived(const Derived&) copy constructor\n";
}

Derived& Derived::operator=(const Derived& other)
{
    std::cout << "Derived::operator=(const Derived&) copy assignment\n";
    if (this != &other) {
        Base::operator=(other);
        extra = other.extra;
    }
    return *this;
}

Derived::Derived(Derived&& other) noexcept
    : Base(std::move(other)), extra(other.extra)
{
    std::cout << "Derived(Derived&&) move constructor\n";
    other.extra = 0;
}

Derived& Derived::operator=(Derived&& other) noexcept
{
    std::cout << "Derived::operator=(Derived&&) move assignment\n";
    if (this != &other) {
        Base::operator=(std::move(other));
        extra = other.extra;
        other.extra = 0;
    }
    return *this;
}

void Derived::normalMethod() const {
    std::cout << "Derived::normalMethod (hides Base)\n";
}

void Derived::virtualMethod() const {
    std::cout << "Derived::virtualMethod (override)\n";
}

Derived::~Derived() {
    std::cout << "~Derived() destructor\n";
}