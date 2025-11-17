#pragma once
#include <iostream>

class Base {
protected:
    int value;

public:
    Base();                      // default ctor
    Base(int x);                 // parameterized ctor

    Base(const Base& other);     // copy ctor
    Base& operator=(const Base& other); // copy assignment

    Base(Base&& other) noexcept; // move ctor
    Base& operator=(Base&& other) noexcept; // move assignment

    void normalMethod() const;
    virtual void virtualMethod() const;

    virtual void safeVirtualDestructor(); // demonstration only

    virtual ~Base();   // make virtual to ensure correct cleanup
};