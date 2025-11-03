#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Generic template for any vector type
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i + 1 < vec.size())
            os << ", ";
    }
    os << "]";
    return os;
}

template <typename T>
bool isSorted(const std::vector<T> &array) {
    T previous;
    for (auto &item: array) {
        if (item < previous) {
            return false;
        }
        previous = item;
    }
    return true;
}

template <typename T>
int find(const std::vector<T> &array, const T &value, int &iterations) {
    if (isSorted(array)) {
        std::cout << "Sorted array, using binary search" << std::endl;
        int low = 0;
        int high = static_cast<int>(array.size()) - 1;
        iterations = 0;

        while (low <= high) {
            std::cout << "Index low= " << low << ", high=" << high << std::endl;
            iterations++;
            int mid = low + (high - low) / 2;

            if (array[mid] == value)
                return mid;  // Found!
            else if (array[mid] < value)
                low = mid + 1;
            else
                high = mid - 1;
        }
    } else {
        std::cout << "Unsorted array, using sequential search" << std::endl;
        iterations = 0;
        for (auto &item: array) {
            iterations++;
            if (item == value) {
                return iterations - 1; // Found!
            }
        }
    }
    return -1;
}

int main() {  
    std::vector<std::string> names =  {
    "Elena", "Amber", "Felix", "Charlotte", "Angela", "Carmen", "Connor", "Craig", "Aisha", "Bryan",
    "Beatrice", "Evelyn", "Cynthia", "Amanda", "Ethan", "Douglas", "Carlos", "Faith", "Ashley", "Dennis",
    "Emily", "Eleanor", "Claudia", "Caleb", "Anita", "Allan", "Courtney", "Christian", "David", "Emma",
    "Christine", "Blake", "Daniel", "Eddie", "Ann", "Dominic", "Brittany", "Clara", "Ellen", "Catherine",
    "Chloe", "Caroline", "Donna", "Fiona", "Elijah", "Bethany", "Alyssa", "Alice", "Brenda", "Cameron",
    "Beverly", "Austin", "Anthony", "Albert", "Doris", "Evelyn", "Erik", "Adrian", "Cindy", "April",
    "Benjamin", "Eva", "Brandon", "Carl", "Alicia", "Daphne", "Eric", "Diana", "Alex", "Bryan",
    "Amy", "Barbara", "Arthur", "Clarence", "Abigail", "Cole", "Erica", "Aaron", "Antonio", "Edward",
    "Ellen", "Andre", "Crystal", "Caleb", "Caroline", "Bruce", "Derek", "Daniel", "Clara", "Gabriel",
    "Eleanor", "Erin", "Elena", "Elizabeth", "Donna", "Charlotte", "Colin", "Elaine", "Emma", "Fiona", 
    "Jorge", "Walter", "Carlos", "Gustavo", "Nahuel", "Marcelo", "Gabriel", "Sebastian"
    };

    cout << (isSorted(names) ? "Ordered collection: " : "Unordered collection: ") << names << endl;

    int iterations = 0;
    int position = find(names, std::string("Gabriel"), iterations);

    std::sort(names.begin(), names.end());
    cout << "Position : " << position << ", iterations: " << iterations << endl;
    
    cout << ( isSorted(names) ? "Ordered collection: " : "Unordered collection: ") << names << endl;

    iterations = 0;
    position = find(names, std::string("Gabriel"), iterations);
    cout << "Position : " << position << ", iterations: " << iterations << endl;

    return 0;
}