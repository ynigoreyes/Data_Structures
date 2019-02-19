#include "BinarySearchTree.h"

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

void BST::insert(int dat) {
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
			else if (dat = temp->datum) {
				throw "Duplicates not allowed.";
			}
		}
	}
}

int BST::rem() {
	
}

Node* BST::search(int val) {

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