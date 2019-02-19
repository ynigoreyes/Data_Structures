class Node {
  public:
    int datum;
    Node* next;
    Node(int);
};

class Stack {
  private:
    void destr_helper(Node*);
  public:
    Node* head;
    Stack();
    ~Stack();
    void Push(int);
    int Pop();
    int Peek();
    bool IsEmpty();
};

