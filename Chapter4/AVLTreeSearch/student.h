#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
public:
    int file;
    std::string name;
    double average;

    Student() : file(0), name(""), average(0.0) {}
    Student(int file, const std::string& name, double average)
        : file(file), name(name), average(average) {}

    // Comparaciones por file (como en tu Java: compareTo usa file)
    bool operator<(const Student& other) const { return file < other.file; }
    bool operator>(const Student& other) const { return file > other.file; }
    bool operator==(const Student& other) const { return file == other.file; }

    friend std::ostream& operator<<(std::ostream& os, const Student& a) {
        os << "[" << a.file << "] " << a.name << " (prom: " << a.average << ")";
        return os;
    }
};

#endif // STUDENT_H