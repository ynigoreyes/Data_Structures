#include <iostream>
#include <string>
#include "Adder.cpp"

using namespace std;

int main() {
  Adder firstAdder;
  if (firstAdder.add() != 4) {
    cout << "Addition for first adder incorrect" << endl;
  }

  if (firstAdder.subtract() != 0) {
    cout << "Subtraction for first adder incorrect" << endl;
  }

  if (firstAdder.multiply() != 4) {
    cout << "Multiplication for first adder incorrect" << endl;
  }

  if (firstAdder.divide() != 1) {
    cout << "Division for first adder incorrect" << endl;
  }

  if (firstAdder.get("x") != 2) {
    cout << "Get method for adder incorrect" << endl;
  }

  if (firstAdder.get("y") != 2) {
    cout << "Get method for adder incorrect" << endl;
  }

  firstAdder.set("x", 4);
  firstAdder.set("y", 8);

  if (firstAdder.get("x") != 4 || firstAdder.get("y") != 8) {
    cout << "Set method for adder incorrect" << endl;
  }

  Adder secondAdder(3, 4);

  if (secondAdder.add() != 7) {
    cout << "Addition for second adder incorrect" << endl;
  }

  if (secondAdder.subtract() != -1) {
    cout << "Subtraction for second adder incorrect" << endl;
  }

  if (secondAdder.multiply() != 12) {
    cout << "Multiplication for second adder incorrect" << endl;
  }

  if (secondAdder.divide() != 0.75) {
    cout << "Division for second adder incorrect" << endl;
  }

  return 0;
}
