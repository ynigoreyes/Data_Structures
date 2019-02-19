#include "Stack.h"

Node::Node(int datum) {
  this->datum = datum;
  this->next = 0;
}

/**
 * 0 is kind of like null
 */
Stack::Stack() {
  this->head = 0;
}

Stack::~Stack() {
  this->destr_helper(this->head);
}

void Stack::destr_helper(Node* node) {
  if (node) {
    destr_helper(node->next);
    delete node; // Deletes node after recurrsion
  }
}


void Stack::Push(int datum) {
  Node* newNode = new Node(datum);

  // Connects the new Node to the current head and
  // then makes the node we just created the new head
  newNode->next = this->head;
  this->head = newNode;
}

int Stack::Pop() {
  if (!this->head) {
    throw "Stack is empty";
  }

  int retVal = this->head->datum;
  Node* oldHead = this->head;
  this->head = oldHead->next;

  delete oldHead;

  return retVal;
}

int Stack::Peek() {
  if (!this->head) {
    throw "Stack is Empty";
  }

  return this->head->datum;
}

bool Stack::IsEmpty() {
  return !this->head;
}
