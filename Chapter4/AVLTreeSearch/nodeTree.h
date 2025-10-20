#ifndef NODETREE_H
#define NODETREE_H

#include "student.h"

struct NodeTree {
    Student data;
    NodeTree* left;
    NodeTree* right;
    int height;

    NodeTree(const Student& a)
        : data(a), left(nullptr), right(nullptr), height(1) {}
};

#endif // NODETREE_H