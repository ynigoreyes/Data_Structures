class Node {
  public:
    int datum;
    Node* next;
    Node* prev;
    Node(int);
};

class Queue {
  private:
    Node* head;
    Node* tail;
    void destr_helper(Node*);
  public:
    Queue();
    ~Queue();
    void Push(int);
    int Pop();
    int Peek();
    bool IsEmpty();
};

