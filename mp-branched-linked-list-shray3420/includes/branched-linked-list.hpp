#ifndef BRANCHED_LINKED_LIST_HPP
#define BRANCHED_LINKED_LIST_HPP

#include <cstddef>
#include <stdexcept>
#include <string>

#include "node.hpp"

class BLL {
public:
  BLL() = default;
  BLL(const BLL& to_copy);
  ~BLL();
  void Clear();
  // BLL& ConstrucorHelper(Node* new_head_);
  BLL& operator=(const BLL& rhs);
  Node* PushBack(char dat);

  char GetAt(size_t idx) const;
  // char GetAtHelper(size_t idx, Node* new_head_) const;

  void SetAt(size_t idx, char dat) const;
  Node* SetAtHelper(size_t idx) const;

  void Join(size_t idx, BLL* list);
  Node* FindNode(size_t idx, Node* new_head_);

  std::string ToString() const;
  std::string ToStringHelper(Node* new_head_) const;

  size_t Size() const;
  size_t SizeHelper(Node* new_head_) const;

  // bool AcyclyicHelper(Node*& slower, Node*& faster) const;

private:
  Node* head_ = nullptr;
  bool IsBLLAcyclic() const;
};

#endif
