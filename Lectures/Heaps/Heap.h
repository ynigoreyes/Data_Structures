class Node {
  public:
    int datum;
    Node *left, *right, *parent;
    Node(int);
};

class Heap {
  private:
    Node *tail, *root;
    void destrHelper(Node*);
    void upHeap();
    void downHeap();
    Node* smallerChild(Node*);
  public:
    Heap();
    ~Heap();
    int Pop();
    void Push(int);
    int Peek();
    bool IsEmpty();
};
