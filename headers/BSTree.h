//
// Created by mirla on 06/10/2025.
//

#ifndef NON_LINEAR_DATA_STRUCTURE_BTREE_H
#define NON_LINEAR_DATA_STRUCTURE_BTREE_H
#include "Node.h"

template <typename T>
class BSTree {
protected:
    Node<T> *root;

    Node<T> *inorderSucessor(Node<T> *node) {
        node = node->right;
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    };

    void insertInternal(Node<T> *node, const T& value) {
        if (value < node->data) {
            if (node->left == nullptr) {
                node->left = new Node<T>(value);
            }else {
                insertInternal(node->left, value);
            }
        }
        if (value > node->data) {
            if (node->right == nullptr) {
                node->right = new Node<T>(value);
            }else {
                insertInternal(node->right, value);
            }
        }

    }

    Node<T> *searchInternal(Node<T> *node, const T& value) {
        if (value == node->data) {
            return node;
        }
        if (value < node->data) {
            if (node->left != nullptr) {
                return searchHelper(node->left, value);
            }
        }else {
            if (node->right != nullptr) {
                return searchHelper(node->right, value);
            }
        }
        return nullptr;
    }

    Node<T> *deleteInternal(Node<T> *node, const T& value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->data && node->left != nullptr) {
            node->left = deleteInternal(node->left, value);
        }
        if (value > node->data && node->right != nullptr) {
            node->right = deleteInternal(node->right, value);
        }

        if (value == node->data) {

            //se for nó folha
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }

            //se possuir filho a esquerda
            if (node->left != nullptr && node->right == nullptr) {
                Node<T> *temp = node->left;
                delete node;
                return temp;
            }
            //se possuir filho a direita
            if (node->left == nullptr && node->right != nullptr) {
                Node<T> *temp = node->right;
                delete node;
                return temp;
            }

            //se possuir dois filhos -> busca pelo menos node da sub-árvore direita
            Node<T> *sucessor = inorderSucessor(node);
            node->data = sucessor->data;
            node->right = deleteInternal(node->right, sucessor->data);
        }

        return node;
    }

    int findHeightInternal(Node<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        return std::max(findHeight(node->left), findHeight(node->right)) + 1;
    }

public:
    BSTree() {
        this->root = nullptr;
    };

    void insertNode(T data) {
        if (root == nullptr) {
            this->root = new Node<T>(data);
        }else {
            insertInternal(root, data);
        }
    };
    void deleteNode(T data) {
        if (root != nullptr) {
            this->root = deleteInternal(root, data);
        }
    };
    Node<T> *parent(Node<T>* node) {

    }
    Node<T> *search(T data) {
        if (root == nullptr) {
            return nullptr;
        }
        return searchInternal(root, data);
    };

    int getHeight() {
        return findHeightInternal(root);
    }
};

#endif //NON_LINEAR_DATA_STRUCTURE_BTREE_H
