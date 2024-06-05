#include <iostream>
#include <string>
using namespace std;

#ifndef LL
#define LL

class Node {
public:
  int data;
  Node *next;
  Node();
  Node(int data);
  Node(int data, Node *next);
};

class Linkl {
private:
  Node head;
  Node tail;
public:
  int size;
  Linkl();
  ~Linkl();
  void display();
  void insertFirst(int data);
  void insertLast(int data);
  void insertAt(int index, int data);
  Node popLast();
  Node popFirst();
  void reverse(Linkl &newobj);
  void reverseInPlace();
  int length();
  // void insertLast(int data) {
  //   Node *newnode = new Node(data);
  //   Node *temp = head.next;
  //   while (temp->next != nullptr) {
  //     temp = temp->next;
  //   }
  //   temp->next = newnode;
  //   size++;
  // }
};

#endif 