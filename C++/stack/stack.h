#include <iostream>

class NStack {
private:
 int * array;
 int top;
 int size;

public:
 NStack(int size);
 void push(int value);
 int pop();

};
