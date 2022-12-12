#include "dna_strand.hpp"

#include <stdexcept>

DNAstrand::~DNAstrand() {
  while (head_ != nullptr) {
    Node* next = head_->next;
    delete head_;
    head_ = next;
  }
  tail_ = nullptr;
}
void DNAstrand::Pushback(Node* n) {
  if (head_ == nullptr) {
    head_ = tail_ = n;
  } else {
    Node* temp = n;
    tail_->next = temp;
    tail_ = temp;
  }
}

void DNAstrand::SpliceIn(const char* pattern, DNAstrand& to_splice_in) {
  if (Size(pattern) == 0 || Size(to_splice_in) == 0)
    throw std::runtime_error("");
  if (&to_splice_in == this) return;

  Node* current = head_;
  char* to_ret = new char[Size(*this) + 1];
  int index = 0;
  while (current != nullptr) {
    to_ret[index] = current->data;
    index++;
    current = current->next;
  }
  to_ret[index] = '\0';
  int check = DoesPatternExist(pattern, to_ret);
  delete[] to_ret;
  if (check == -1) throw std::runtime_error("");
  if (check == 0) {
    for (unsigned int i = 0; i < Size(pattern); i++) {
      DeleteNode(check);
    }
    Node* temp = to_splice_in.head_;
    to_splice_in.head_ = temp->next;
    temp->next = head_;
    head_ = temp;
    CombineStrands(*this, to_splice_in, check + 1);
  }
  if (check > 0) {
    for (unsigned int i = 0; i < Size(pattern); i++) {
      DeleteNode(check);
    }
    CombineStrands(*this, to_splice_in, check);
  }
}

unsigned int DNAstrand::Size(const char* str) {
  unsigned int size = 0;
  while (str[size] != '\0') {
    size++;
  }
  return size;
}

unsigned int DNAstrand::Size(DNAstrand& str) {
  unsigned int size = 0;
  Node* current = str.head_;
  while (current != nullptr) {
    size++;
    current = current->next;
  }
  return size;
}
int DNAstrand::DoesPatternExist(const char* pattern, const char* list) {
  int index = -1;
  for (unsigned long i = 0; i < Size(list) - Size(pattern) + 1; i++) {
    unsigned long j = 0;
    while (j < Size(pattern)) {
      if (pattern[j] != list[i + j]) {
        break;
      }
      j++;
    }
    if (j == Size(pattern)) {
      index = (int)i;
    }
  }
  return index;
}
void DNAstrand::DeleteNode(unsigned int index) {
  if (head_ == nullptr) {
    return;
  }
  Node* current = head_;
  if (index == 0) {
    head_ = current->next;
    delete current;
    return;
  }
  Node* temp = head_;
  for (unsigned int i = 0; current != nullptr && i < index; i++) {
    temp = current;
    current = current->next;
  }
  temp->next = current->next;
  delete current;
}
void DNAstrand::CombineStrands(DNAstrand& dna,
                               DNAstrand& to_splice_in,
                               unsigned int index) {
  Node* current = dna.head_;
  for (unsigned int i = 0; i < index - 1; i++) {
    current = current->next;
  }
  Node* temp = current->next;
  Node* delet = to_splice_in.head_;
  while (delet != nullptr) {
    current->next = delet;
    current = current->next;
    to_splice_in.head_ = delet->next;
    delet = delet->next;
  }
  current->next = temp;
}