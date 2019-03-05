#include "BinarySearchTree.cpp"

int main() {
  BST* tree = new BST;
  tree->Insert(15);
  tree->Insert(10);
  tree->Insert(20);
  tree->Insert(8);
  tree->Insert(12);
  tree->Insert(18);
  tree->Insert(25);
  tree->Insert(16);
  tree->Insert(19);
  tree->Insert(30);
  tree->ToString();

  tree->Remove(25);
  tree->ToString();
  return 0;
}
