#include "LinkedList.h"
#include <iostream>

using namespace std;

// Node class
Node::Node(int val) {
  this->val = val;
}
// LinkedList class
LinkedList::LinkedList() {
  this->size = 0;
}

void LinkedList::Insert(int index, int value) {
  if (index > this->size) {
    throw "Index out of bounds";
  }

  Node* newNode = new Node(value);
  Node* temp = this->head;

  if (index == 0) {
    this->head = newNode;
  } else {
    for (int i = 1; i < index; i++) {
      temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
  }

  this->size++;
}

void LinkedList::RemoveHead() {
  this->head = this->head->next;
  this->size--;
}

void LinkedList::PrintList() {
  Node* temp = this->head;
  int i = 0;
  while (i < this->size) {
    cout<< temp->val;
    if (temp->next != nullptr) {
      temp = temp->next;
    }
    i++;
  }

  cout << endl;
}

