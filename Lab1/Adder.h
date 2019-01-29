#include <string>
#ifndef ADDER_H
#define ADDER_H

using namespace std;

class Adder {
  public:
    float x, y;
    Adder();
    Adder(float x1, float y1);
    float add();
    float subtract();
    float multiply();
    float divide();
    float get(string which);
    void set(string which, float val);
  protected:
  private:
};

#endif
