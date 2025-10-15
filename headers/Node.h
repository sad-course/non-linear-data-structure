//
// Created by mirla on 06/10/2025.
//

#ifndef NON_LINEAR_DATA_STRUCTURE_NODE_H
#define NON_LINEAR_DATA_STRUCTURE_NODE_H


template <typename T>
struct Node {
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(const T& value) {
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

#endif //NON_LINEAR_DATA_STRUCTURE_NODE_H