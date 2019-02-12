#include "LinkedList.cpp"

int main() {
  LinkedList* list = new LinkedList();
  list->Insert(0, 0);
  list->Insert(1, 1);
  list->Insert(2, 2);
  list->Insert(3, 3);
  list->Insert(4, 4);

  list->PrintList();
  list->RemoveHead();
  list->PrintList();

  return 0;
}
