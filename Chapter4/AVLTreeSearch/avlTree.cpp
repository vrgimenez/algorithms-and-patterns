#include "avlTree.h"
#include <algorithm>
#include <iostream>

AVLTree::AVLTree() : root(nullptr) {}
AVLTree::~AVLTree() { clear(); }

int AVLTree::height(NodeTree* n) const {
    return n ? n->height : 0;
}

int AVLTree::balanceFactor(NodeTree* n) const {
    if (!n) return 0;
    return height(n->left) - height(n->right);
}

NodeTree* AVLTree::rotateRight(NodeTree* y) {
    NodeTree* x = y->left;
    NodeTree* T2 = x->right;

    // rotación
    x->right = y;
    y->left = T2;

    // actualizar alturas
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

NodeTree* AVLTree::rotateLeft(NodeTree* x) {
    NodeTree* y = x->right;
    NodeTree* T2 = y->left;

    // rotación
    y->left = x;
    x->right = T2;

    // actualizar alturas
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

NodeTree* AVLTree::insertRec(NodeTree* node, const Student& a) {
    if (!node) return new NodeTree(a);

    if (a < node->data)
        node->left = insertRec(node->left, a);
    else if (a > node->data)
        node->right = insertRec(node->right, a);
    else {
        // legajo ya existe: actualizar datos (si querés) o ignorar
        // Aquí actualizamos el registro con la nueva info.
        node->data = a;
        return node;
    }

    // actualizar altura
    node->height = 1 + std::max(height(node->left), height(node->right));

    // balancear
    int bf = balanceFactor(node);

    // LL
    if (bf > 1 && a < node->left->data)
        return rotateRight(node);

    // RR
    if (bf < -1 && a > node->right->data)
        return rotateLeft(node);

    // LR
    if (bf > 1 && a > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // RL
    if (bf < -1 && a < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insert(const Student& a) {
    root = insertRec(root, a);
}

NodeTree* AVLTree::minValueNode(NodeTree* node) const {
    NodeTree* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

NodeTree* AVLTree::removeRec(NodeTree* node, int legajo) {
    if (!node) return node;

    if (legajo < node->data.file)
        node->left = removeRec(node->left, legajo);
    else if (legajo > node->data.file)
        node->right = removeRec(node->right, legajo);
    else {
        // nodo encontrado
        if (!node->left || !node->right) {
            NodeTree* temp = node->left ? node->left : node->right;
            if (!temp) {
                // sin hijos
                temp = node;
                node = nullptr;
            } else {
                // un hijo
                *node = *temp; // copiar contenido
            }
            delete temp;
        } else {
            // dos hijos: obtener sucesor inorden
            NodeTree* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = removeRec(node->right, temp->data.file);
        }
    }

    if (!node) return node;

    // actualizar altura
    node->height = 1 + std::max(height(node->left), height(node->right));

    int bf = balanceFactor(node);

    // LL
    if (bf > 1 && balanceFactor(node->left) >= 0)
        return rotateRight(node);

    // LR
    if (bf > 1 && balanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // RR
    if (bf < -1 && balanceFactor(node->right) <= 0)
        return rotateLeft(node);

    // RL
    if (bf < -1 && balanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::remove(int legajo) {
    root = removeRec(root, legajo);
}

NodeTree* AVLTree::searchRec(NodeTree* node, int legajo) const {
    if (!node) return nullptr;
    if (legajo == node->data.file) return node;
    if (legajo < node->data.file) return searchRec(node->left, legajo);
    return searchRec(node->right, legajo);
}

NodeTree* AVLTree::search(int legajo) const {
    return searchRec(root, legajo);
}

void AVLTree::inorderRec(NodeTree* node, std::vector<Student>& out) const {
    if (!node) return;
    inorderRec(node->left, out);
    out.push_back(node->data);
    inorderRec(node->right, out);
}

void AVLTree::preorderRec(NodeTree* node, std::vector<Student>& out) const {
    if (!node) return;
    out.push_back(node->data);
    preorderRec(node->left, out);
    preorderRec(node->right, out);
}

void AVLTree::postorderRec(NodeTree* node, std::vector<Student>& out) const {
    if (!node) return;
    postorderRec(node->left, out);
    postorderRec(node->right, out);
    out.push_back(node->data);
}

std::vector<Student> AVLTree::inorder() const {
    std::vector<Student> out;
    inorderRec(root, out);
    return out;
}

std::vector<Student> AVLTree::preorder() const {
    std::vector<Student> out;
    preorderRec(root, out);
    return out;
}

std::vector<Student> AVLTree::postorder() const {
    std::vector<Student> out;
    postorderRec(root, out);
    return out;
}

void AVLTree::clearRec(NodeTree* node) {
    if (!node) return;
    clearRec(node->left);
    clearRec(node->right);
    delete node;
}

void AVLTree::clear() {
    clearRec(root);
    root = nullptr;
}