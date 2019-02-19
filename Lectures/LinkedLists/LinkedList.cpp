#include "LinkedList.h"
#include <string>

// Node class
Node::Node(int dat) {
	this->datum = dat;
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

void Node::set_next(Node *next) {
	this->next = next;
}

// LinkedList class
LinkedList::LinkedList() {
	this->size = 0;
}

LinkedList::~LinkedList() {
	this->destr_helper(this->head);
}

void LinkedList::destr_helper(Node *node) {
	if (node->get_next() != nullptr) {
		this->destr_helper(node->get_next());
	}

	delete node;
}

int LinkedList::get(int index) {
	if (index >= this->size || index < 0) {
		throw "Index out of bounds";
	}

	Node *temp = this->head;

	for (int i = 0; i < index; i++) {
		temp = temp->get_next();
	}

	return temp->get_datum();

}

void LinkedList::set(int index, int value) {
	if (index >= this->size || index < 0) {
		throw "Index out of bounds";
	}

	Node *temp = this->head;

	for (int i = 0; i < index; i++) {
		temp = temp->get_next();
	}

	temp->set_datum(value);

}

void LinkedList::insert(int index, int value) {
  if (index > this->size) {
    throw "Index out of bounds";
  }

  Node *newNode = new Node(value);
  Node *temp = this->head;

  if (index == 0) {
    this->head = newNode;
  } else {
    for (int i = 1; i < index; i++) {
      temp = temp->get_next();
    }

    newNode->set_next(temp->get_next());
    temp->set_next(newNode);
  }

  this->size++;
}

int LinkedList::rem(int) {

}

std::string LinkedList::print_list() {

}

