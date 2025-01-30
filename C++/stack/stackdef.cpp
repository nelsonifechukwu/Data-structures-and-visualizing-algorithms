#include "stack.h"

NStack::NStack(int size) : top(-1), size(size) { array = new int[size]; }

void NStack::push(int value) {
  if (top < size - 1) {
    array[top++] = value;
  } else {
    std::cout << "ERROR: StackOverflow" << '\n';
  }
}

int NStack::pop() {
  int val = array[top];
  array[top] = '\0';
  top--;
  return val;
}
