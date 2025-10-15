#include <iostream>
#include "BSTree.h"

int main() {
    BSTree<int> bst;

    bst.insertNode(100);
    bst.insertNode(50);
    bst.insertNode(60);
    bst.insertNode(20);
    bst.insertNode(5);


    bst.insertNode(10);
    bst.insertNode(61);
    bst.insertNode(62);

    bst.insertNode(104);
    bst.insertNode(103);
    bst.insertNode(102);

    bst.deleteNode(100);
    return 0;
}