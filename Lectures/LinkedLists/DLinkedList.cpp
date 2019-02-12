#include "DLinkedList.h"
#include <string>

// Node class
Node::Node(int dat) {
  this->datum = dat;
  this->next = nullptr;
  this->prev = nullptr;
}

Node::~Node() {

}

int Node::get_datum() {
  return this->datum;
}

void Node::set_datum(int dat) {
  this->datum = dat;
}

Node* Node::get_next() {
  return this->next;
}

Node* Node::get_prev() {
  return this->prev;
}

void Node::set_next(Node *next) {
  this->next = next;
}

void Node::set_prev(Node* prev) {
  this->prev = prev;
}

// DLinkedList class
DLinkedList::DLinkedList() {
  this->size = 0;
}

DLinkedList::~DLinkedList() {
  this->destr_helper(this->head);
}

void DLinkedList::destr_helper(Node *node) {
  if (node->get_next() != nullptr) {
    this->destr_helper(node->get_next());
  }

  delete node;
}

int DLinkedList::get(int index) {
  if (index >= this->size || index < 0) {
    throw "Index out of bounds";
  }

  Node *temp = this->head;

  for (int i = 0; i < index; i++) {
    temp = temp->get_next();
  }

  return temp->get_datum();

}

void DLinkedList::set(int index, int value) {
  if (index >= this->size || index < 0) {
    throw "Index out of bounds";
  }

  Node *temp = this->head;

  for (int i = 0; i < index; i++) {
    temp = temp->get_next();
  }

  temp->set_datum(value);

}

void DLinkedList::Insert(int index, int value) {
  if (index > this->size) {
    throw "Index out of bounds";
  }

  Node *newNode = new Node(value);
  Node *temp = this->head;

  if (index == 0) {
    newNode->set_next(this->head);
    if (this->head) {
      this->head->set_prev(newNode);
    }
  } else {
    for (int i = 1; i < index; i++) {
      temp = temp->get_next();
    }

    newNode->set_next(temp->get_next());
    newNode->set_next(temp);

    if (newNode->get_next()) {
      newNode->get_next()->set_prev(newNode);
    }

    temp->set_next(newNode);
  }

  this->size++;
}

int DLinkedList::Remove(int index) {
  if (index >= this->size) {
    throw "Index out of Bounds";
  }

  int retVal;
  Node* temp = this->head;
  if (index == 0) {
    this->head = temp->get_next();
    if (this->head) {
      this->head->set_prev(nullptr);
    }
  } else {
    for (int i = 0; i < index; i++) {
      temp = temp->get_next();
    }

    temp->get_prev()->set_next(temp->get_next());
    if(temp->get_next()) {
      temp->get_next()->set_prev(temp->get_prev());
    }
  }

  retVal = temp->get_datum();
  delete temp;
  this->size--;
  return retVal;
}

std::string DLinkedList::PrintList() {

}

