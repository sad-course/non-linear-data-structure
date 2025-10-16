//
// Created by mirla on 06/10/2025.
//

#ifndef NON_LINEAR_DATA_STRUCTURE_BTREE_H
#define NON_LINEAR_DATA_STRUCTURE_BTREE_H

#include <vector>
#include "Node.h"

template <typename T>
class BSTree {
protected:
    Node<T> *root;

    void printTree() {
        Node<T> *node = root;

    }
    Node<T> *findLeftMost(Node<T> *node) {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
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
        if (root == nullptr) {
            this->root = new Node<T>(value);
        }else {
            if (value == node->data) {
                std::cout << value << " already exists\n";
                return;
            }
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
                return nullptr;
            }

            if (node->left != nullptr && node->right == nullptr) {
                Node<T> *temp = node->left;
                delete node;
                return temp;
            }
            if (node->left == nullptr && node->right != nullptr) {
                Node<T> *temp = node->right;
                delete node;
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
            return 0;
        }
        return std::max(findHeight(node->left), findHeight(node->right)) + 1;
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
    BSTree() {
        this->root = nullptr;
    };
    Node<T> *getRoot() {
        return this->root;
    }

    void insertNode(T data) {
        insertInternal(root, data);
    };

    void deleteNode(T data) {
        if (root != nullptr) {
            this->root = deleteInternal(root, data);
        }
    };

    Node<T> *search(T data) {
        return searchInternal(root, data);
    };

    int getHeight() {
        return findHeightInternal(root);
    }

    bool isStrictlyBSTree() {
        return verifyStrictlyBSTreeInternal(root);
    }

    bool isBSTreeSimilar(BSTree<T> *bs_tree) {
        return verifyBSTreeSimilarity(this->root, bs_tree->getRoot());
    };

    bool isBSTreeSimilarAndValues(BSTree<T> *bs_tree) {
        return verifyBSTreeSimilarity(this->root, bs_tree->getRoot(), true);
    }

    void inorderTraversal() {
        std::vector<T> valuesList;
        inorderTraversalInternal(root, valuesList);

        for (int value : valuesList) {
            std::cout << value << " ";
        }
    }
};

#endif //NON_LINEAR_DATA_STRUCTURE_BTREE_H
