#include <iostream>
#include "student.h"
#include "avlTree.h"

int main() {
    AVLTree tree;

    // Test Add some Students(file, name, average rating)
    Student a1(1001, "Ana Perez",    8.5);
    Student a2(1005, "Juan Gomez",   7.2);
    Student a3(1003, "Luis Mora",    9.1);
    Student a4(1002, "Carla Ruiz",   6.8);
    Student a5(1010, "Diego Silva",  7.9);
    Student a6(1004, "Martina Diaz", 8.0);

    // Insert
    tree.insert(a1);
    tree.insert(a2);
    tree.insert(a3);
    tree.insert(a4);
    tree.insert(a5);
    tree.insert(a6);

    // Show searches
    std::cout << "Inorder:\n";
    for (const auto& a : tree.inorder()) std::cout << a << "\n";

    std::cout << "\nPreorder:\n";
    for (const auto& a : tree.preorder()) std::cout << a << "\n";

    std::cout << "\nPostorder:\n";
    for (const auto& a : tree.postorder()) std::cout << a << "\n";

    // Search
    int key = 1003;
    NodeTree* found = tree.search(key);
    if (found) {
        std::cout << "\nFound File " << key << ": " << found->data << "\n";
    } else {
        std::cout << "\nFile " << key << " no encontrado\n";
    }

    // Eliminar
    std::cout << "\nRemoving file 1005 (Juan Gomez)\n";
    tree.remove(1005);

    std::cout << "Inorder after removal:\n";
    for (const auto& a : tree.inorder()) std::cout << a << "\n";

    return 0;
}
