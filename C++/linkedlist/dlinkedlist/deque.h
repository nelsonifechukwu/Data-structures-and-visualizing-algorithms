#include <iostream>
using namespace std;

template <typename T> class Node {
public:
  Node *prev;
  Node *next;
  T data;

  Node() {
    prev = nullptr;
    next = nullptr;
  };
  Node(T data) : data(data) {
    prev = nullptr;
    next = nullptr;
  }
};

template <typename T> class Deque {
  Node<T> *head;
  Node<T> *tail;

public:
  Deque() {
    head = nullptr;
    tail = nullptr;
  }
  void pushFront(T value) {
    Node<T> *new_node = new Node<T>(value);

    if (head == nullptr) {
      head = new_node;
      tail = new_node;
    } else {
      new_node->next = head;
      head->prev = new_node;
      head = new_node;

      // Node<T> * temp = head;
      // head = new_node;
      // head->next = temp;
      // temp->prev = head;
    }
  }

  void pushBack(T value) {
    Node<T> *new_node = new Node<T>(value);

    if (head == nullptr) {
      head = new_node;
      tail = new_node;
    } else {
      new_node->prev = tail;
      tail->next = new_node;
      tail = new_node;
    }
  }

  void printDeque() {
    Node<T> *temp = head;
    while (temp != nullptr) {
      cout << temp->data << "\n";
      temp = temp->next;
    }
  }
};
