#include "hashTable.h"
#include <iostream>

HashTable::HashTable(int size)
    : tableSize(size), table(size) {}

int HashTable::hashFunction(int key) const {
    auto index = key % tableSize;
    std::cout << "function index = " << index << std::endl;
    return index;
}

void HashTable::insert(int key, const std::string &value) {
    int index = hashFunction(key);
    for (auto &node : table[index]) {
        if (node.key == key) {
            node.value = value;
            return;
        }
    }
    table[index].emplace_back(key, value);
}

void HashTable::remove(int key) {
    int index = hashFunction(key);
    table[index].remove_if([key](const Node &n) { return n.key == key; });
}

std::string HashTable::search(int key) const {
    int index = hashFunction(key);
    for (const auto &node : table[index]) {
        if (node.key == key)
            return node.value;
    }
    return "No encontrado";
}

void HashTable::display() const {
    for (int i = 0; i < tableSize; ++i) {
        std::cout << "[" << i << "] ";
        for (const auto &node : table[i]) {
            std::cout << " -> (" << node.key << ", " << node.value << ")";
        }
        std::cout << "\n";
    }
}