#include "ll.h"
int main() {
  Linkl obj;
  obj.insertFirst(10);
  obj.insertFirst(20);
  obj.insertFirst(3);
  obj.insertFirst(40);
  obj.insertFirst(50);
  obj.insertFirst(60);
  obj.insertLast(96);
  obj.display();
  cout << "Initial First Data: " << obj.popFirst().data;
  cout << " Initial Last Data: " << obj.popLast().data << endl;
  obj.display();
  obj.insertAt(4, 123);
  obj.display();
  obj.length();
  // Linkl newobj;
  // obj.reverse(newobj);
  // newobj.display();
  obj.reverseInPlace();
  obj.display();
  return 0;
}
