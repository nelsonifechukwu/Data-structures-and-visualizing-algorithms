#include "stack.h"

int main(){
     NStack stack(5); // create a stack with 5 elements
     stack.push(10);
     stack.push(20);
     stack.push(30);
     stack.push(40);
     stack.push(50);

     std::cout << "Top element is: " << stack.pop() << '\n';

     return 0;
}
