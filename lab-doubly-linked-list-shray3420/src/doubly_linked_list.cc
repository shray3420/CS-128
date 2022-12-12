#include <iomanip>
#include <sstream>
#include <stdexcept>
using std::endl;
using std::ostream;
using std::ostringstream;
using std::setfill;
using std::setw;
using std::string;

#include "doubly_linked_list.hpp"

// Functions provided to you
ostream& operator<<(ostream& os, const DoublyLinkedList& ll) {
  constexpr unsigned int kWidth = 16;
  os << "Doubly Linked List" << endl;
  os << "Head: " << ll.head_ << "\t Tail: " << ll.tail_ << endl;
  os << "Size: " << ll.size_ << endl;
  if (ll.head_ == nullptr) return (os << "Empty" << endl);
  const Node* curr = ll.head_;
  os << "Nodes (accessible from head to tail):" << endl << endl;
  os << setw(kWidth) << setfill(' ') << ' ' << ' ' << Center("prev", kWidth - 1)
     << ' ' << Center("data", kWidth - 1) << ' ' << Center("next", kWidth - 1)
     << endl;
  while (curr != nullptr) {
    ostringstream oss;
    oss << (curr->prev);
    string prev = oss.str();
    oss.str("");
    oss << (curr->next);
    string next = oss.str();
    oss.str("");
    oss << (curr->data);
    string data = oss.str();
    oss.str("");
    oss << curr;
    string address = oss.str();
    os << setw(kWidth) << setfill(' ') << ' ' << '.' << setw(kWidth)
       << setfill('-') << '.' << setw(kWidth) << '.' << setw(kWidth) << '.'
       << endl;
    os << setw(kWidth) << setfill(' ') << Center(address, kWidth - 1) << '|'
       << setw(kWidth - 1) << setfill(' ') << Center(prev, kWidth - 1) << '|'
       << setw(kWidth - 1) << Center(data, kWidth - 1) << '|'
       << setw(kWidth - 1) << Center(next, kWidth - 1) << '|' << endl;
    os << setw(kWidth) << setfill(' ') << ' ' << '\'' << setw(kWidth)
       << setfill('-') << '\'' << setw(kWidth) << '\'' << setw(kWidth) << '\''
       << endl;
    os << endl;
    curr = curr->next;
  }
  return os;
}

std::string Center(const std::string& str, decltype(str.length()) col_width) {
  // quick and easy (but error-prone) implementation
  decltype(str.length()) padl = (col_width - str.length()) / 2;
  decltype(str.length()) padr = (col_width - str.length()) - padl;
  string strf = string(padl, ' ') + str + string(padr, ' ');
  return strf;
}

DoublyLinkedList::DoublyLinkedList(char val) {
  Node* temp = new Node(val);
  head_ = tail_ = temp;
  size_ = 1;
}
DoublyLinkedList::DoublyLinkedList(const std::vector<char>& values) {
  head_ = tail_ = nullptr;
  size_ = values.size();
  if (size_ == 0) return;
  if (size_ == 1) {
    head_ = new Node(values[0]);
    tail_ = head_;
    return;
  }
  head_ = new Node(values[0]);
  Node* current = head_->next;
  Node* prev = head_;
  for (size_t i = 1; i < values.size(); i++) {
    current = new Node(values[i]);
    current->prev = prev;
    prev->next = current;
    current = current->next;
    prev = prev->next;
  }
  tail_ = prev;
}
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& rhs) {
  tail_ = nullptr;
  head_ = tail_;
  size_ = 0;
  Node* current = rhs.head_;
  while (current != nullptr) {
    PushBack(current->data);
    current = current->next;
  }
}
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& rhs) {
  if (&rhs == this) {
    return *this;
  }
  tail_ = nullptr;
  head_ = tail_;
  size_ = 0;
  Clear();
  if (rhs.size_ == 0) {
    return *this;
  }
  Node* current = rhs.head_;
  while (current != nullptr) {
    PushBack(current->data);
    current = current->next;
  }
  return *this;
}
DoublyLinkedList::~DoublyLinkedList() { Clear(); }

char& DoublyLinkedList::Back() {
  if (size_ == 0) {
    throw std::runtime_error("empty");
  }
  return tail_->data;
}
char& DoublyLinkedList::Front() {
  if (size_ == 0) {
    throw std::runtime_error("empty");
  }
  return head_->data;
}

void DoublyLinkedList::PushBack(char val) {
  Node* temp = new Node(val);
  if (head_ == nullptr) {
    head_ = temp;
  }
  if (tail_ != nullptr) {
    tail_->next = temp;
  }
  size_++;
  temp->next = nullptr;
  temp->prev = tail_;
  tail_ = temp;
}

void DoublyLinkedList::PushFront(char val) {
  size_++;
  Node* temp = new Node(val);
  if (head_ == nullptr) {
    head_ = temp;
    tail_ = temp;
  } else {
    temp->next = head_;
    head_ = temp;
    temp->next->prev = temp;
  }
}
void DoublyLinkedList::InsertAt(size_t idx, char val) {
  if (size_ < idx) {
    throw std::runtime_error("index not in list");
  }
  if (size_ == idx) {
    PushBack(val);
  } else if (idx == 0) {
    PushFront(val);
  } else {
    Node* temp = new Node(val);
    Node* curr = head_;
    Node* prev = nullptr;
    size_t count = 0;
    while (curr != nullptr) {
      if (count == idx) {
        prev = curr->prev;
        temp->next = curr;
        temp->prev = prev;
        curr->prev = temp;
        prev->next = temp;
        size_++;
        break;
      }
      curr = curr->next;
      count++;
    }
  }
}
void DoublyLinkedList::PopBack() {
  if (Empty()) {
    throw std::runtime_error("empty");
  }
  size_--;
  tail_ = tail_->prev;
  if (tail_ != nullptr) {
    tail_->next = nullptr;
  } else {
    head_ = nullptr;
  }
}
void DoublyLinkedList::PopFront() {
  if (Empty()) {
    throw std::runtime_error("empty");
  }
  head_ = head_->next;
  if (head_ != nullptr) {
    head_->prev = nullptr;
    size_--;
    return;
  }
  tail_ = nullptr;
  size_--;
}
void DoublyLinkedList::EraseAt(size_t idx) {
  if (idx >= size_) {
    throw std::runtime_error("Index doesn't exist");
  }
  if (idx == size_ - 1) {
    PopBack();
  } else if (idx == 0) {
    PopFront();
  } else {
    Node* curr = head_;
    Node* after = curr->next;
    Node* previous = nullptr;
    size_t counter = 0;
    while (curr != nullptr) {
      if (counter == idx) {
        previous = curr->prev;
        delete curr;
        previous->next = after;
        after->prev = previous;
        size_--;
        break;
      }
      curr = curr->next;
      after = curr->next;
      counter++;
    }
  }
}
char& DoublyLinkedList::Find(char val) {
  Node* curr = head_;
  while (curr != nullptr) {
    if (curr->data == val) {
      return curr->data;
    }
    curr = curr->next;
  }
  throw std::runtime_error("val not found");
}
void DoublyLinkedList::Clear() {
  Node* next = nullptr;
  if (head_ != nullptr) {
    while (head_ != nullptr) {
      next = head_->next;
      delete head_;
      head_ = next;
    }
  }
  size_ = 0;
  head_ = nullptr;
  tail_ = nullptr;
}