#include <iostream>
#include <string>

using namespace std;

class Adder {
  public:
    float x, y;

    /**
     * Instantiates the Adder with 2 as both values
     */
    Adder() {
      x = 2;
      y = 2;
    }

    /**
     * Instantiates the Adder with x and y respectively
     * @param x1 first number
     * @param y1 second number
     */
    Adder(int x1, int y1) {
      x = x1;
      y = y1;
    }

    /**
     * Adds the numbers
     */
    float add() {
      return x + y;
    }

    /**
     * Subtracts the numbers
     */
    float subtract() {
      return x - y;
    }

    /**
     * Multiplies the numbers
     */
    float multiply() {
      return x * y;
    }

    /**
     * Divides the numbers
     */
    float divide() {
      return x / y;
    }

    /**
     * Gets the chosen number
     */
    float get(string which) {
      if (which.compare("x") == 0) {
        return x;
      } else if (which.compare("y") == 0) {
        return y;
      } else {
        cout << "invalid option" << endl;
        return -1;
      }
    }

    /**
     * Sets the chosen number
     */
    void set(string which, float val) {
      if (which.compare("x") == 0) {
        x = val;
      } else if (which.compare("y") == 0) {
        y = val;
      } else {
        cout << "invalid option" << endl;
      }
    }
};

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
