#include <iostream>

#include "circular-linked-list.hpp"

template <typename T>
void Print(CircularLinkedList<T>& source) {
  if (source.GetHead() == nullptr) {
    std::cout << "Empty";
    return;
  }
  Node<T>* temp = source.GetHead();

  do {
    std::cout << temp->data << " ";
    temp = temp->next;
  } while (temp != source.GetHead());
}

int main() {
  CircularLinkedList<int> list;

  list.InsertInOrder(5);
  list.InsertInOrder(27);
  list.InsertInOrder(37);
  list.InsertInOrder(8);
  list.InsertInOrder(7);
  list.InsertInOrder(69);
  // list.Reverse();
  // list.Clear();
  Print(list);
  std::cout << '\n';

  CircularLinkedList<int> copy = list;
  Print(copy);
  std::cout << '\n';

  return 0;
}
