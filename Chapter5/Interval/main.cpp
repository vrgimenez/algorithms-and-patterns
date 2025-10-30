#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int start;
    int end;
};

bool compareByEnd(const Interval& a, const Interval& b) {
    return a.end < b.end;
}

int main() {
    std::vector<Interval> intervals = {
        {1, 3}, {2, 5}, {4, 6}, {6, 7}, {5, 8}, {8, 9}
    };

    std::cout << "From total intervals:\n";
    for (const auto& it : intervals) {
        std::cout << "[" << it.start << ", " << it.end << "]\n";
    }

    std::sort(intervals.begin(), intervals.end(), compareByEnd);

    int endActual = 0;
    std::vector<Interval> selected;

    for (const auto& it : intervals) {
        if (it.start >= endActual) {
            selected.push_back(it);
            endActual = it.end;
        }
    }

    std::cout << "\nSelected intervals:\n";
    for (const auto& it : selected) {
        std::cout << "[" << it.start << ", " << it.end << "]\n";
    }

    std::cout << "Total: " << selected.size() << " intervals\n";
}