#include <iostream>
#include <string>
using namespace std;

#ifndef LL
#define LL

template <typename T> class Node {
public:
  T data;
  Node *next;
  Node() {
    this->data = 0;
    this->next = nullptr;
  };
  Node(T data) {
    this->data = data;
    this->next = nullptr;
  };
  Node(T data, Node *next) {
    this->data = data;
    this->next = next;
  };
};

template <typename T> class Linkl {
private:
  Node<T> head;
  Node<T> tail;

public:
  int size;
  Linkl() : head(0, nullptr), tail(0, nullptr), size(0){};
  ~Linkl() {
    Node<T> *temp = head.next;
    while (temp != nullptr) {
      Node<T> *temp2 = temp->next;
      delete temp;
      temp = temp2;
    }
  }

  void display() {
    Node<T> *temp = head.next;
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "null";
    cout << " (Size: " << size << ")" << endl;
  }
  
  void insertFirst(T data) {
    Node<T> *temp = new Node<T>(data);
    temp->next = head.next;
    head.next = temp;
    if (tail.next == nullptr) {
      tail = head; // reassign tail to the newly inputted variable
    }
    size++;
  }

  void insertLast(T data) {
    Node<T> *newnode = new Node<T>(data);
    if (head.next == nullptr) {
      head.next = newnode;
    }
    Node<T> *val = head.next;
    Node<T> *temp = head.next;
    while (head.next != nullptr) {
      temp = head.next;
      head = *(head.next);
    }
    temp->next = newnode;
    head.next = val;
    size++;
  }

  void insertAt(int index, T data) {
    Node<T> *newnode = new Node<T>(data);
    Node<T> *temp = head.next; // hold the first node
    Node<T> *ftemp = nullptr;
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

  Node<T> popLast() {
    Node<T> *temp = head.next;
    while (temp->next->next != nullptr) {
      temp = temp->next;
    }
    Node<T> *penultimatetemp = temp;
    temp = temp->next;
    Node<T> last = *(temp);
    penultimatetemp->next = nullptr;
    size--;
    delete temp;
    return last;
  }

  Node<T> popFirst() {
    Node<T> *temp = head.next->next;
    Node<T> initialhead = *(head.next);
    delete head.next;
    head.next = temp;
    size--;
    return initialhead;
  }

  void reverse(Linkl &newobj) {
    Node<T> *temp = head.next;
    Node<T> *temp2 = nullptr;
    while (temp != nullptr) {
      newobj.insertFirst(temp->data);
      temp = temp->next;
      this->popFirst();
    }
    cout << "Reverse Linkedlist: ";
  }

  void reverseInPlace() {
    Node<T> *temp = head.next;
    Node<T> *lastnode = nullptr;
    Node<T> *next = nullptr;
    Node<T> *dlast = nullptr;
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

  int length() {
    cout << size << endl;
    return size;
  }
  
};

#endif

int main() {
  Linkl<int> obj;
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
