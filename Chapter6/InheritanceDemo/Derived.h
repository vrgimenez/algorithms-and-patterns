#pragma once
#include "Base.h"

class Derived : public Base {
    int extra;

public:
    Derived();
    Derived(int x, int y);

    Derived(const Derived& other);             // copy ctor
    Derived& operator=(const Derived& other);  // copy assignment

    Derived(Derived&& other) noexcept;         // move ctor
    Derived& operator=(Derived&& other) noexcept; // move assignment

    void normalMethod() const;
    void virtualMethod() const override;

    ~Derived();
};