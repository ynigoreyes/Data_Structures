#include "Queue.cpp"
#include <iostream>

using namespace std;

int main() {
  Queue* q = new Queue;
  q->Push(10);
  q->Push(20);
  q->Push(30);
  cout << q->Pop() << endl;
  cout << q->Pop() << endl;
  cout << q->Pop() << endl;

  return 0;
}
