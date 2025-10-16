//
// Created by mirla on 16/10/2025.
//
#ifndef NON_LINEAR_DATA_STRUCTURE_BTREE_H
#define NON_LINEAR_DATA_STRUCTURE_BTREE_H
#include <stack>
#include <vector>

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
template <typename T>
class BTree {
protected:
    Node<T> *root;
    int size;

    void incrementSize() noexcept { ++size; }
    void decrementSize() noexcept { --size; }

    void destroy(Node<T> *rootNode) {
        if (rootNode == nullptr) return;

        std::stack<Node<T>*> s;
        s.push(rootNode);

        while (!s.empty()) {
            Node<T>* node = s.top();
            s.pop();

            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);

            delete node;
        }
    };

    void inorderTraversalInternal(Node<T> *node, std::vector<T> &list) {
        if (node == nullptr) {
            return;
        }

        inorderTraversalInternal(node->left, list);

        list.push_back(node->data);

        inorderTraversalInternal(node->right, list);
    }


    void insertInternal(Node<T> *node, const T& value) {
        //unordered method insertion
    }

public:
    BTree() {
        this->root = nullptr;
        this->size = 0;
    };

    virtual ~BTree() {
        destroy(this->root);
    }

    Node<T> *getRoot() {
        return this->root;
    }

    int getSize() {
        return this->size;
    }

    void inorderTraversal() {
        std::vector<T> valuesList;
        inorderTraversalInternal(root, valuesList);

        for (int value : valuesList) {
            printf("%d ", value);
        }
        printf("\n");
    }

    virtual void insertNode(T data) {
        insertInternal(root, data);
    }
};
#endif //NON_LINEAR_DATA_STRUCTURE_BTREE_H