#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    int key;
    std::string value;

    Node(int k, const std::string &v);
};

#endif