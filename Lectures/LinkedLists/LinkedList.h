#include <string>

class Node {
  public:
    Node(int);
    ~Node();
    int datum;
    Node* next;
    int get_datum();
    void set_datum(int);
    Node* get_next();
    void set_next(Node*);
};

class LinkedList {
  private:
    Node* head;
    int size;
  public:
    LinkedList();
    // ~LinkedList(int);
    ~LinkedList();
    void destr_helper(Node*);
    int rem(int);
    void insert(int index, int value);
    int get(int index);
    void set(int index, int value);
    std::string print_list();
};

