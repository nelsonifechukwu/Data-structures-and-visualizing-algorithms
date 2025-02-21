#include "ll.h"
Node::Node() {
  this->data = 0;
  this->next = nullptr;
}
Node::Node(int data) {
  this->data = data;
  this->next = nullptr; 
}
Node::Node(int data, Node *next) {
  this->data = data;
  this->next = next;
}
Linkl::Linkl() : head(0, nullptr), tail(0, nullptr), size(0) {}
Linkl::~Linkl() {
  Node *temp = head.next;
  while (temp != nullptr) {
    Node *temp2 = temp->next;
    delete temp;
    temp = temp2;
  }
}
void Linkl::display() {
  Node *temp = head.next;
  while (temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "null";
  cout << " (Size: " << size << ")" << endl;
}

void Linkl::insertFirst(int data) {
  Node *temp = new Node(data);
  temp->next = head.next;
  head.next = temp;
  if (tail.next == nullptr) {
    tail = head; // reassign tail to the newly inputted variable
  }
  size++;
}

void Linkl::insertLast(int data) {
  Node *newnode = new Node(data);
  if (head.next == nullptr) {
    head.next = newnode;
    size++;
    return;
  }
// Traverse to the last node
  Node *temp = head.next;
  while (temp->next != nullptr) {
      temp = temp->next;
  }
  // Insert at the end
  temp->next = newnode;
  size++;
}

void Linkl::insertAt(int index, int data) {
  Node *newnode = new Node(data);
  Node *temp = head.next; // hold the first node
  Node *ftemp = nullptr;
  if (index == 1) {
    insertFirst(data);
  } else if (index > 1 && index < size) {
    int i = {1};
    while (i < index - 1) {
      temp = temp->next; // node before the inserted node
      i++;
    }
    ftemp = temp->next; // node after the inserted node
    temp->next = newnode;
    newnode->next = ftemp;
    size++;
  } else if (index == size) {
    insertLast(data);
  } else {
    cout << "Index out of bounds" << endl;
  }
}
Node Linkl::popLast() {
  Node *temp = head.next;
  while (temp->next->next != nullptr) {
    temp = temp->next;
  }
  Node *penultimatetemp = temp;
  temp = temp->next;
  Node last = *(temp);
  penultimatetemp->next = nullptr;
  size--;
  delete temp;
  return last;
}
Node Linkl::popFirst() {
  Node *temp = head.next->next;
  Node initialhead = *(head.next);
  delete head.next;
  head.next = temp;
  size--;
  return initialhead;
}
void Linkl::reverse(Linkl &newobj) {
  Node *temp = head.next;
  Node *temp2 = nullptr;
  while (temp != nullptr) {
    newobj.insertFirst(temp->data);
    temp = temp->next;
    this->popFirst();
  }
  cout << "Reverse Linkedlist: ";
}
void Linkl::reverseInPlace() {
    Node *temp = head.next;
    Node *lastnode = nullptr;
    Node *next = nullptr;
    Node *dlast = nullptr;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    lastnode = temp;
    temp = head.next;
    bool first = true;
    while (1) {
      if (first) {
        temp = head.next->next;
        head.next->next = nullptr;
        lastnode->next = head.next;
        head.next = temp;
        first = false;

      } else {
        if (head.next != lastnode) {
          next = head.next->next;
          temp = head.next;
          dlast = lastnode->next;
          lastnode->next = temp;
          temp->next = dlast;
          head.next = next;
        } else {
          return;
        }
      }
    }
  }
  int Linkl::length() {
    cout << size << endl;
    return size;
  }
  
