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
	void traverse(Node*);
public:
	BST();
	~BST();
	void Insert(int);
	void Remove(int);
	void ToString();
	Node* Search(int); // tells us if an int is in the tree or not
};
