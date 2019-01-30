#include "ArrayList.h"

using namespace std;

ArrayList::ArrayList() {
  this->arr = new int[10];
  this->size = 10;
  this->num_elements = 0;
}

ArrayList::ArrayList(int size) {
  this->arr = new int[size];
  this->size = size;
  this->num_elements = 0;
}

ArrayList::~ArrayList() {
  delete this->arr;
}

int ArrayList::Get(int index) {
  if (index >= this->num_elements) {
    throw "Index out of bounds";
  }

  return this->arr[index];
}

void ArrayList::Set(int index, int value) {
  if (index >= this->num_elements) {
    throw "Index out of bounds";
  }

  this->arr[index] = value;
}

void ArrayList::Insert(int index, int value) {
  if (index > this->num_elements) {
    throw "Index out of bounds";
  }

  if (this->num_elements == this->size) {
    this->size *= 2;
    int *newArr = new int[this->size];

    for (int i = 0; this->size; i++) {
      newArr[i] = this->arr[i];
    }

    delete this->arr;
    this->arr = newArr;
  }

  this->num_elements += 1;

  for (int i = this->num_elements; i > index; i--) {
    this->arr[i] = this->arr[i - 1];
  }

  this->arr[index] = value;
}
