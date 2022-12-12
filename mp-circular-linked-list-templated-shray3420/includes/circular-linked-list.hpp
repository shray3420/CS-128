#ifndef CIRCULAR_LINKED_LIST_HPP
#define CIRCULAR_LINKED_LIST_HPP

#include <iostream>

#include "node.hpp"

enum class Order { kASC, kDESC };

template <typename T>
class CircularLinkedList {
public:
  CircularLinkedList() = default;
  CircularLinkedList(const CircularLinkedList<T>& source);
  CircularLinkedList<T>& operator=(const CircularLinkedList<T>& source);
  ~CircularLinkedList();

  void InsertInOrder(const T& data);
  void Reverse();

  void Clear();
  void PushBack(T num);
  void InsertAscending(const T& data);
  void InsertDescending(const T& data);
  Node<T>* GetHead() { return head_; }

  template <typename U>
  friend std::ostream& operator<<(std::ostream& os,
                                  const CircularLinkedList<U>& cll);

private:
  Node<T>* head_ = nullptr;
  Node<T>* tail_ = nullptr;
  Order node_order_ = Order::kASC;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const CircularLinkedList<T>& cll) {
  Node<T>* iter = cll.head_;
  // empty list condition
  if (iter == nullptr) {
    os << "Empty list";
    return os;
  }
  // non-empty list condition
  do {
    os << iter->data << '\t';
    iter = iter->next;
  } while (iter != cll.head_);

  return os;
}

template <typename T>
CircularLinkedList<T>::CircularLinkedList(const CircularLinkedList<T>& source) {
  if (source.head_ == nullptr) return;
  Node<T>* curr = source.head_;
  do {
    PushBack(curr->data);
    curr = curr->next;
  } while (curr != source.head_);
  node_order_ = source.node_order_;
}

template <typename T>
void CircularLinkedList<T>::PushBack(T num) {
  auto temp = new Node<T>(num);
  if (head_ == nullptr) {
    head_ = temp;
  }
  if (tail_ != nullptr) {
    tail_->next = temp;
  }
  temp->next = head_;
  tail_ = temp;
}

template <typename T>
CircularLinkedList<T>& CircularLinkedList<T>::operator=(
    const CircularLinkedList<T>& source) {
  if (&source == this) return *this;
  if (source.head_ == nullptr) return *this;

  Node<T>* curr = source.head_;
  do {
    PushBack(curr->data);
    curr = curr->next;
  } while (curr != source.head_);
  node_order_ = source.node_order_;
  return *this;
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList() {
  Clear();
}

template <typename T>
void CircularLinkedList<T>::InsertInOrder(const T& data) {
  if (node_order_ == Order::kASC) {
    InsertAscending(data);
  }
  if (node_order_ == Order::kDESC) {
    InsertDescending(data);
  }
}

template <typename T>
void CircularLinkedList<T>::InsertAscending(const T& data) {
  auto temp = new Node<T>(data);
  if (head_ == nullptr) {
    head_ = temp;
    temp->next = head_;
    tail_ = temp;
    return;
  }

  if (head_->data >= data) {
    temp->next = tail_->next;
    tail_->next = temp;
    head_ = temp;
  } else if (tail_->data <= data) {
    temp->next = tail_->next;
    tail_->next = temp;
    tail_ = temp;
  } else {
    Node<T>* curr = head_;

    while (curr->next != head_ && curr->next->data < data) {
      curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
  }
}

template <typename T>
void CircularLinkedList<T>::InsertDescending(const T& data) {
  auto temp = new Node<T>(data);
  if (head_ == nullptr) {
    head_ = temp;
    temp->next = head_;
    tail_ = temp;
    return;
  }

  if (head_->data <= data) {
    temp->next = tail_->next;
    tail_->next = temp;
    head_ = temp;
  } else if (tail_->data >= data) {
    temp->next = tail_->next;
    tail_->next = temp;
    tail_ = temp;
  } else {
    Node<T>* curr = head_;

    while (curr->next != head_ && curr->next->data > data) {
      curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
  }
}

template <typename T>
void CircularLinkedList<T>::Reverse() {
  if (node_order_ == Order::kASC) {
    node_order_ = Order::kDESC;
  } else if (node_order_ == Order::kDESC) {
    node_order_ = Order::kASC;
  }
  if (head_ == nullptr) return;
  Node<T>* prev = NULL;
  Node<T>* curr = head_;
  Node<T>* next = nullptr;
  do {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  } while (curr != head_);
  head_->next = prev;
  head_ = prev;
  tail_ = curr;
}

template <typename T>
void CircularLinkedList<T>::Clear() {
  if (head_ == nullptr) return;
  if (head_->next == head_) {
    delete head_;
    head_ = nullptr;
    return;
  }
  tail_->next = nullptr;
  while (head_ != nullptr) {
    Node<T>* next = head_->next;
    delete head_;
    head_ = next;
  }
  tail_ = nullptr;
  node_order_ = Order::kASC;
}
#endif