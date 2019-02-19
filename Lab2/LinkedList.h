#include <string>

class Node {
  public:
    Node(int);
    Node* next;
    int val;
};

class LinkedList {
  private:
    Node* head;
    int size;
  public:
    /**
     * Creates a new, empty linked list
     */
    LinkedList();
    /**
     * Removes the head of the linked list
     */
    void RemoveHead();
    /**
     * Inserts a new node at the given index
     */
    void Insert(int index, int value);
    /**
     * Will print out the linked list from head to tail
     */
    void PrintList();
};

