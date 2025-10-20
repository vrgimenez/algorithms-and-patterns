#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include "node.h"

class HashTable {
public:
    explicit HashTable(int size);
    void insert(int key, const std::string &value);
    void remove(int key);
    std::string search(int key) const;
    void display() const;

private:
    int hashFunction(int key) const;
    int tableSize;
    std::vector<std::list<Node>> table;
};

#endif