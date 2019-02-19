#include "Queue.h"

Node::Node(int datum) {
  this->datum = datum;
  this->next = 0;
  this->prev = 0;
}

/**
 * 0 is kind of like null
 */
Queue::Queue() {
  this->head = 0;
  this->tail = 0;
}

Queue::~Queue() {
  this->destr_helper(this->head);
}

void Queue::destr_helper(Node* node) {
  if (node) {
    destr_helper(node->next);
    delete node; // Deletes node after recurrsion
  }
}


void Queue::Push(int datum) {
  Node* newNode = new Node(datum);

  if (this->head) {
    this->head->prev = newNode;
  }

  // Connects the new Node to the current head and
  // then makes the node we just created the new head
  newNode->next = this->head;
  this->head = newNode;

  if (!this->tail) {
    this->tail = newNode;
  }
}

int Queue::Pop() {
  if (!this->head) {
    throw "Queue is empty";
  }

  int retVal = this->tail->datum;
  Node* oldTail = this->tail;
  this->tail = this->tail->prev;

  if (this->tail) {
    this->tail->next = 0;
  }

  delete oldTail;

  return retVal;
}

int Queue::Peek() {
  if (!this->head) {
    throw "Queue is Empty";
  }

  return this->tail->datum;
}

bool Queue::IsEmpty() {
  return !this->head;
}
