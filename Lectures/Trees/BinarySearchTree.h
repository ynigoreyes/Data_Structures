class Node {
public:
	int datum;
	Node *parent, *left, *right;

	Node(int);
};

class BST {
private:
	Node *root;

	void destr_helper(Node*);
public:
	BST();
	~BST();
	
	void insert(int);
	int rem();
	Node* search(int); // tells us if an int is in the tree or not

};