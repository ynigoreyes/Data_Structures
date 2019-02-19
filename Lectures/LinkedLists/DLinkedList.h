#include <string>

class Node {
  public:
    Node(int);
    ~Node();
    int datum;
    Node* next;
    Node* prev;
    int get_datum();
    void set_datum(int);
    Node* get_next();
    Node* get_prev();
    void set_next(Node*);
    void set_prev(Node*);
};

class DLinkedList {
  private:
    Node* head;
    int size;
  public:
    DLinkedList();
    // ~LinkedList(int);
    ~DLinkedList();
    void destr_helper(Node*);
    int Remove(int);
    void Insert(int index, int value);
    int get(int index);
    void set(int index, int value);
    std::string PrintList();
};

