#include <iostream>
#include "BSTree.h"

int main() {
    BSTree<int> bst, bst_strictly, bst_not_strictly;

    bst_strictly.insertNode(100);
    bst_strictly.insertNode(50);
    bst_strictly.insertNode(61);
    bst_strictly.insertNode(20);
    bst_strictly.insertNode(102);
    bst_strictly.insertNode(101);
    bst_strictly.insertNode(103);
    bst_strictly.insertNode(105);

    bst_not_strictly.insertNode(100);
    bst_not_strictly.insertNode(50);
    bst_not_strictly.insertNode(61);
    bst_not_strictly.insertNode(20);
    bst_not_strictly.insertNode(102);
    bst_not_strictly.insertNode(101);
    bst_not_strictly.insertNode(103);
    bst_not_strictly.insertNode(105);


    bst_not_strictly.deleteNode(100);
    bst_not_strictly.deleteNode(105);

    if (bst_not_strictly.isStrictlyBSTree()) {
        std::cout << "É estritamente binário" << std::endl;
    }else {
        std::cout << "Não é estritamente binário" << std::endl;
    }

    bst_not_strictly.inorderTraversal();
    bool isSimilar = bst_not_strictly.isBSTreeSimilarAndValues(&bst_strictly);

    printf("Similar? %s \n", (isSimilar ? "yessy" : "namm"));

    printf("BST sizee %d \n", bst_not_strictly.getSize());
    printf("BST height %d \n", bst_not_strictly.getHeight());
    return 0;
}