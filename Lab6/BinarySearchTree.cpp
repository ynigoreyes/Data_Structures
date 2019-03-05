#include "BinarySearchTree.h"
#include <iostream>

Node::Node(int dat) {
  this->datum = dat;
  this->left = 0;
  this->right = 0;
  this->parent = 0;
}

BST::BST() {
  this->root = 0;
}

BST::~BST() {
  this->destr_helper(this->root);
}

void BST::destr_helper(Node *node) {
  if (node) {
    this->destr_helper(node->left);
    this->destr_helper(node->right);

    delete node;
  }
}

void BST::Insert(int dat) {
  Node *newNode = new Node(dat);

  if (!this->root) {
    this->root = newNode;
  }
  else {
    Node *temp = this->root;

    while (true) {
      if (dat < temp->datum) {
        if (temp->left) {
          temp = temp->left;
          continue;
        }
        else {
          temp->left = newNode;
          newNode->parent = temp;
          break;
        }
      }
      else if (dat > temp->datum) {
        if (temp->right) {
          temp = temp->right;
          continue;
        }
        else {
          temp->right = newNode;
          newNode->parent = temp;
          break;
        }
      }
      else if (dat == temp->datum) {
        throw "Duplicates not allowed.";
      }
    }
  }
}


// Will print out the tree in-order
void BST::ToString() {
  this->traverse(this->root);
  std::cout << std::endl;
}

void BST::traverse(Node* node) {
  if (!node)
    return;

  this->traverse(node->left);
  std::cout << node->datum << " ";
  this->traverse(node->right);
}

Node* BST::Search(int val) {

  Node *temp = this->root;

  while (temp && temp->datum != val) {
    if (val < temp->datum) {
      temp = temp->left;
    }
    else if (val > temp->datum) {
      temp = temp->right;
    }
  }

  return temp;
}

/**
 * One child: Replace the parent with it's child
 * Two children:
 *  - Go Right
 *  - then go all the way left
 *  - move the deepest child to the deleted node
 *  or
 *  - Go Left
 *  - then go all the way right
 *  - move the deepest child to the deleted node
 */
void BST::Remove(int datum) {
  Node* searchNode = this->Search(datum);

  if (!searchNode) {
    throw "Number not found";
  }

  Node* parent = searchNode->parent;
  // No children
  if (!searchNode->left && !searchNode->right) {
    // If we are at the root
    if (!parent) {
      this->root = 0;
    //  If we are at the right child
    } else if (parent->datum < searchNode->datum) {
      parent->right = 0;
    } else {
      parent->left = 0;
    }
    searchNode->right->parent = parent;
  // Just a right child
  } else if (!searchNode->left && searchNode->right) {
    if (!parent) {
      this->root = searchNode->right;
    } else if (parent->datum < searchNode->datum) {
      parent->right = searchNode->right;
    } else {
      parent->left = searchNode->right;
    }
  // Just a left child
  } else if (searchNode->left && !searchNode->right){
    if (!parent) {
      this->root = searchNode->left;
    } else if (parent->datum < searchNode->datum) {
      parent->right = searchNode->left;
    } else {
      parent->left = searchNode->left;
    }
    searchNode->left->parent = parent;
  // We have two children
  } else {
    Node* temp = searchNode->left;

    // Traverse all the way down the right side
    while(temp->right) {
      temp = temp->right;
    }

    searchNode->datum = temp->datum;

    // Replace the parent's right pointer
    temp->parent->right = temp->left;
    searchNode = temp;
    if (temp->left) {
      temp->left->parent = temp->parent;
    }
  }

  delete searchNode;
}

