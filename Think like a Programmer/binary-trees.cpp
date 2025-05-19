#include <iostream>
#include <stdlib.h>
#include <string.h>

class binaryTree {
public:
  int countLeaves();

private:
  struct binaryTreeNode {
    int data;
    binaryTreeNode *right;
    binaryTreeNode *left;
  };
  typedef binaryTreeNode *treePtr;
  treePtr _root;
  int privateCountLeaves(treePtr rootPtr);
};

int binaryTree::privateCountLeaves(treePtr rootPtr) {
  if (rootPtr == NULL)
    return 0;
  if (rootPtr->right == NULL && rootPtr->left == NULL)
    return 1;
  int leftCount = privateCountLeaves(rootPtr->left);
  int rightCount = privateCountLeaves(rootPtr->right);
  return leftCount + rightCount;
}

int binaryTree::countLeaves() { return privateCountLeaves(_root); }
int main() { return 0; }