#ifndef AVLTREE_H
#define AVLTREE_H

#include "nodeTree.h"
#include <functional>
#include <vector>

class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    // operaciones principales
    void insert(const Student& a);
    void remove(int legajo);               // elimina por legajo
    NodeTree* search(int legajo) const;    // busca por legajo (retorna puntero o nullptr)

    // recorridos (devuelven vector de Student en el orden pedido)
    std::vector<Student> inorder() const;
    std::vector<Student> preorder() const;
    std::vector<Student> postorder() const;

    // utilitario para vaciar
    void clear();

private:
    NodeTree* root;

    // helpers recursivos
    NodeTree* insertRec(NodeTree* node, const Student& a);
    NodeTree* removeRec(NodeTree* node, int legajo);
    NodeTree* minValueNode(NodeTree* node) const;
    NodeTree* searchRec(NodeTree* node, int legajo) const;
    void clearRec(NodeTree* node);

    // recorridos recursivos
    void inorderRec(NodeTree* node, std::vector<Student>& out) const;
    void preorderRec(NodeTree* node, std::vector<Student>& out) const;
    void postorderRec(NodeTree* node, std::vector<Student>& out) const;

    // utilidades AVL
    int height(NodeTree* n) const;
    int balanceFactor(NodeTree* n) const;
    NodeTree* rotateRight(NodeTree* y);
    NodeTree* rotateLeft(NodeTree* x);
};

#endif // AVLTREE_H