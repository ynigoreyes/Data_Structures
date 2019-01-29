#include "Adder.h"
#include <iostream>

using namespace std;

/**
 * Instantiates the Adder with 2 as both values
 */
Adder::Adder()
{
  this->x = 2;
  this->y = 2;
};

/**
 * Instantiates the Adder with x and y respectively
 * @param x1 first number
 * @param y1 second number
 */
Adder::Adder(float x1, float y1)
{
  this->x = x1;
  this->y = y1;
};

/**
 * Adds the numbers
 */
float Adder::add() {
  return this->x + this->y;
};

/**
 * Subtracts the numbers
 */
float Adder::subtract() {
  return this->x - this->y;
};

/**
 * Multiplies the numbers
 */
float Adder::multiply() {
  return this->x * this->y;
};

/**
 * Divides the numbers
 */
float Adder::divide() {
  return this->x / this->y;
};

/**
 * Gets the chosen number
 */
float Adder::get(string which) {
  if (which.compare("x") == 0) {
    return this->x;
  } else if (which.compare("y") == 0) {
    return this->y;
  } else {
    cout << "invalid option" << endl;
    return -1;
  }
}

/**
 * Sets the chosen number
 */
void Adder::set(string which, float val) {
  if (which.compare("x") == 0) {
    this->x = val;
  } else if (which.compare("y") == 0) {
    this->y = val;
  } else {
    cout << "invalid option" << endl;
  }
}
