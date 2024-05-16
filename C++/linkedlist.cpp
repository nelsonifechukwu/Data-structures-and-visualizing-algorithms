#include <iostream>
class Car {

public:
  int size;
  class Node {
    int val;
    Node *next;
  };
  Car(): size(0) {};
};

int main() {
  Car mazda;
  std::cout << mazda.size << std::endl;
}