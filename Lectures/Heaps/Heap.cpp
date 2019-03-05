#include "Heap.h"
// Min Heap

Node::Node(int datum) {
  this->datum = datum;
  this->left = 0;
  this->right = 0;
  this->parent = 0;
}

Heap::Heap() {
  this->tail = 0;
  this->root = 0;
}

Heap::~Heap() {
  this->destrHelper(this->root);
}

void Heap::destrHelper(Node *node) {
  if (!node) return;

  this->destrHelper(node->left);
  this->destrHelper(node->right);
  delete node;
}

void Heap::upHeap() {
  Node *temp = this->tail;
  int swapNum;

  // Swaps the parent and its child's values, but not the pointers
  while (temp->parent && temp->datum < temp->parent->datum) {
    swapNum = temp->datum;
    temp->datum = temp->parent->datum;
    temp->parent->datum = swapNum;
    temp = temp->parent;
  }
}

void Heap::downHeap() {
  Node *temp = this->root;
  Node *checkNode = this->smallerChild(this->root);
  int swapNum;

  while (checkNode && temp->datum > checkNode->datum) {
    if (checkNode->datum < temp->datum) {
      swapNum = temp->datum;
      temp->datum = checkNode->datum;
      checkNode->datum = swapNum;
    }
    temp = checkNode;
  }
}

// returns the smaller of the children or null
Node* Heap::smallerChild(Node *node) {
  if (!node) return nullptr;

  if (node->left && !node->right) {
    node = node->left;
  } else if (node->right && !node->left) {
    node = node->right;
  } else if (node->right && node->left) {
    if (node->right->datum < node->left->datum) {
      node = node->right;
    } else {
      node = node->left;
    }
  }

  return node;
}

bool Heap::IsEmpty() {
  return !this->root;
}

int Heap::Peek() {
  if (!this->root) {
    throw "This is empty...";
  } else {
    return this->root->datum;
  }
}

void Heap::Push(int val) {
  Node *newNode = new Node(val);
  Node *temp = this->tail;
  this->tail = newNode;

  if (this->IsEmpty()) {
    this->root = newNode;
  } else {
    // Insert at next position
    // go up until in root or a left
    while( temp->parent && temp->parent->right == temp) {
      temp = temp->parent;
    }

    if (temp->parent) {
      temp = temp->parent;
      if (temp->right) {
        temp = temp->right;
      } else {
        temp->right = newNode;
        newNode->parent = temp;
        this->upHeap();
        return;
      }
    }
  }

  // Go left as far a possible
  while(temp->left) {
    temp = temp->left;
  }

  temp->left = newNode;
  newNode->parent = temp;

  // upHeap
  this->upHeap();
}


int Heap::Pop() {
  if (this->IsEmpty()) {
    throw "Heap is empty...";
  }

  int retNum = this->root->datum;
  // swap the root with the tail
  this->root->datum = this->tail->datum;
  Node *delNode = this->tail;

  // move tail to previous position
  while (this->tail->parent && this->tail->parent->left == this->tail) {
    this->tail = this->tail->parent;
  }

  if (this->tail->parent) {
    this->tail = this->tail->parent->left;
  }

  while(this->tail->right) {
    this->tail = this->tail->right;
  }

  if (delNode == delNode->parent->left) {
    delNode->parent->left = 0;
  } else {
    delNode->parent->right = 0;
  }

  this->downHeap();
  delete delNode;
  return retNum;
}
