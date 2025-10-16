//
// Created by mirla on 06/10/2025.
//

#ifndef NON_LINEAR_DATA_STRUCTURE_BSTREE_H
#define NON_LINEAR_DATA_STRUCTURE_BSTREE_H

#include <vector>
#include <stack>

#include "BTree.h"

template <typename T>
class BSTree : public BTree<T> {
private:
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

    Node<T> *findLeftMost(Node<T> *node) {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    };

    void insertInternal(Node<T> *node, const T& value) {
        if (this->root == nullptr) {
            this->root = new Node<T>(value);
            this->incrementSize();
        }else {
            if (value == node->data) {
                std::cout << value << " already exists\n";
                return;
            }
            if (value < node->data) {
                if (node->left == nullptr) {
                    node->left = new Node<T>(value);
                    this->incrementSize();

                }else {
                    insertInternal(node->left, value);
                }
            }
            if (value > node->data) {
                if (node->right == nullptr) {
                    node->right = new Node<T>(value);
                    this->incrementSize();
                }else {
                    insertInternal(node->right, value);
                }
            }
        }
    }

    Node<T> *searchInternal(Node<T> *node, const T& value) {
        if (node == nullptr) {
            return nullptr;
        }
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
        if (value < node->data && node->left != nullptr) {
            node->left = deleteInternal(node->left, value);
        }
        if (value > node->data && node->right != nullptr) {
            node->right = deleteInternal(node->right, value);
        }

        if (value == node->data) {

            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                this->decrementSize();
                return nullptr;
            }

            if (node->left != nullptr && node->right == nullptr) {
                Node<T> *temp = node->left;
                delete node;
                this->decrementSize();
                return temp;
            }
            if (node->left == nullptr && node->right != nullptr) {
                Node<T> *temp = node->right;
                delete node;
                this->decrementSize();
                return temp;
            }

            Node<T> *successor = findLeftMost(node->right);
            node->data = successor->data;
            node->right = deleteInternal(node->right, successor->data);
        }

        return node;
    }

    int findHeightInternal(Node<T> *node) {
        if (node == nullptr) {
            return -1;
        }
        return std::max(findHeightInternal(node->left), findHeightInternal(node->right)) + 1;
    }

    bool verifyStrictlyBSTreeInternal(Node<T> *node) {
        if (node == nullptr) {
            return true;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return true;
        }
        if (node->left != nullptr || node->right != nullptr) {
            return false;
        }
        bool leftSubtree = verifyStrictlyBSTreeInternal(node->left);
        bool rightSubtree = verifyStrictlyBSTreeInternal(node->right);

        return leftSubtree && rightSubtree;
    }

    bool verifyBSTreeSimilarity(Node<T> *rootBT1, Node<T> *rootBT2, bool isToCompareValue=false) {
        if (rootBT1 == nullptr && rootBT2 == nullptr) {
            return true;
        }
        if (rootBT1 == nullptr || rootBT2 == nullptr) {
            return false;
        }
        if (isToCompareValue && rootBT1->data != rootBT2->data) {
            return false;
        }

        bool leftSubtrees = verifyBSTreeSimilarity(rootBT1->left, rootBT2->left, isToCompareValue);
        bool rightSubtrees = verifyBSTreeSimilarity(rootBT1->right, rootBT2->right, isToCompareValue);

        return leftSubtrees && rightSubtrees;
    }

public:
    void insertNode(T data) {
        insertInternal(this->root, data);
    };

    void deleteNode(T data) {
        if (this->root != nullptr) {
            this->root = deleteInternal(this->root, data);
        }
    };

    Node<T> *search(T data) {
        return searchInternal(this->root, data);
    };

    int getHeight() {
        return findHeightInternal(this->root);
    }

    bool isStrictlyBSTree() {
        return verifyStrictlyBSTreeInternal(this->root);
    }

    bool isBSTreeSimilar(BSTree<T> *bs_tree) {
        return verifyBSTreeSimilarity(this->root, bs_tree->getRoot());
    };

    bool isBSTreeSimilarAndValues(BSTree<T> *bs_tree) {
        return verifyBSTreeSimilarity(this->root, bs_tree->getRoot(), true);
    }


};

#endif //NON_LINEAR_DATA_STRUCTURE_BSTREE_H
