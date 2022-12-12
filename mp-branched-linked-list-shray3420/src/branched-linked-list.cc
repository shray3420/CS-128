#include "branched-linked-list.hpp"

BLL::BLL(const BLL& to_copy) {
  if (to_copy.head_ == nullptr) {
    head_ = nullptr;
    return;
  }
  Node* copy_curr = to_copy.head_;
  Node* this_curr = head_;
  while (copy_curr != nullptr) {
    this_curr = PushBack(copy_curr->data_);
    if (copy_curr->next_bll_ != nullptr) {
      this_curr->next_bll_ = new BLL(*copy_curr->next_bll_);
      // auto* temp = new BLL(*copy_curr->next_bll_);
      // this_curr->next_bll_->head_ = temp->head_;
      // //*this_curr->next_bll_ = *temp;
      // delete temp;
      // temp = nullptr;
    }
    copy_curr = copy_curr->next_node_;
    this_curr = this_curr->next_node_;
  }
}

BLL::~BLL() { Clear(); }

BLL& BLL::operator=(const BLL& rhs) {
  if (this == &rhs) return *this;
  this->Clear();
  if (rhs.head_ == nullptr) {
    head_ = nullptr;
    return *this;
  }

  Node* copy_curr = rhs.head_;
  Node* this_curr = head_;
  while (copy_curr != nullptr) {
    this_curr = PushBack(copy_curr->data_);
    if (copy_curr->next_bll_ != nullptr) {
      this_curr->next_bll_ = new BLL(*copy_curr->next_bll_);
      // auto* temp = new BLL(*copy_curr->next_bll_);
      // this_curr->next_bll_->head_ = temp->head_;
      // //*this_curr->next_bll_ = *temp;
      // delete temp;
      // temp = nullptr;
    }
    copy_curr = copy_curr->next_node_;
    this_curr = this_curr->next_node_;
  }
  return *this;
}

void BLL::Clear() {
  while (head_ != nullptr) {
    delete head_->next_bll_;
    Node* temp = head_->next_node_;
    delete head_;
    head_ = temp;
  }
  // head_ = nullptr;
}

// void ConstrucorHelper(Node* new_head_) {
//   Node* curr = new_head_;
//   while (curr != nullptr) {
//     if (curr->next_node_ == nullptr && curr->next_bll_ == nullptr) {
//     }
//   }
// }

Node* BLL::PushBack(char dat) {
  auto* pb = new Node(dat);

  if (head_ == nullptr) {
    head_ = pb;
    return pb;
  }
  Node* curr = head_;
  while (curr->next_node_ != nullptr) {
    curr = curr->next_node_;
  }
  curr->next_node_ = pb;
  return pb;
}

char BLL::GetAt(size_t idx) const {
  if (idx >= Size()) throw std::runtime_error("Index is Out of Bounds");
  std::string bll_string = ToString();
  return bll_string[idx];
}

void BLL::SetAt(size_t idx, char dat) const {
  if (idx >= Size()) throw std::runtime_error("Index is Out of Bounds");
  Node* temp = SetAtHelper(idx);
  temp->data_ = dat;
}

Node* BLL::SetAtHelper(size_t idx) const {
  Node* curr = head_;
  size_t index = 0;
  while (curr != nullptr && index != idx) {
    index++;
    if (curr->next_bll_ != nullptr) {
      if (curr->next_bll_->Size() >= (idx - index)) {
        return curr->next_bll_->SetAtHelper(idx - index);
      }
      index += curr->next_bll_->Size();
    }
    curr = curr->next_node_;
  }

  return curr;
}

void BLL::Join(size_t idx, BLL* list) {
  if (idx >= Size()) throw std::runtime_error("Index is Out of Bounds");
  Node* temp = FindNode(idx, head_);
  if (temp->next_bll_ != nullptr) throw std::runtime_error("List is cylic");
  temp->next_bll_ = list;
  if (!IsBLLAcyclic()) throw std::runtime_error("List is cylic");
}

Node* BLL::FindNode(size_t idx, Node* new_head_) {
  Node* curr = new_head_;
  size_t index = 0;
  while (curr != nullptr) {
    if (curr->next_node_ == nullptr && curr->next_bll_ == nullptr) {
      return curr;
    }
    if (index == idx) return curr;
    if (curr->next_bll_ != nullptr) {
      index++;
      curr = FindNode(idx, curr->next_bll_->head_);
    }
    curr = curr->next_node_;
    index++;
  }

  return curr;
}

std::string BLL::ToString() const {
  if (head_ == nullptr) return "";
  return ToStringHelper(head_);
}

std::string BLL::ToStringHelper(Node* new_head_) const {
  std::string str;
  str.push_back(new_head_->data_);
  Node* curr = new_head_;

  while (curr != nullptr) {
    if (curr->next_node_ == nullptr && curr->next_bll_ == nullptr) {
      return str;  // returns count of SLL
    }
    if (curr->next_bll_ != nullptr) {
      str.append(ToStringHelper(curr->next_bll_->head_));
      if (curr->next_node_ != nullptr) {
        str.push_back(curr->next_node_->data_);
      }
      curr = curr->next_node_;
      continue;
    }
    curr = curr->next_node_;
    str.push_back(curr->data_);
  }
  return str;
}

size_t BLL::Size() const {
  if (head_ == nullptr) {
    return 0;
  }
  return SizeHelper(head_);
}

size_t BLL::SizeHelper(Node* new_head_) const {
  size_t count = 0;
  Node* curr = new_head_;

  while (curr != nullptr) {
    if (curr->next_node_ == nullptr && curr->next_bll_ == nullptr) {
      return count + 1;  // returns count of SLL
    }
    if (curr->next_bll_ != nullptr) {
      count += SizeHelper(curr->next_bll_->head_);
    }
    curr = curr->next_node_;
    count++;
  }
  return count;
}

bool BLL::IsBLLAcyclic() const {
  if (head_ == nullptr) {
    return true;
  }
  Node* oogway = head_;
  Node* shifu = head_->next_node_;
  while (oogway != nullptr && shifu != nullptr &&
         shifu->next_node_ != nullptr) {
    if (oogway == shifu) return false;

    if (oogway->next_bll_ != nullptr) {
      oogway = oogway->next_bll_->head_;
    } else {
      oogway = oogway->next_node_;
    }
    if (shifu->next_bll_ != nullptr) {
      shifu = shifu->next_bll_->head_;
      if (shifu != nullptr && shifu->next_bll_ != nullptr) {
        shifu = shifu->next_node_;
      }
    } else {
      if (shifu->next_node_->next_bll_ != nullptr) {
        shifu = shifu->next_node_->next_bll_->head_;
      } else {
        shifu = shifu->next_node_->next_node_;
      }
    }
  }
  return true;
}

// bool BLL::AcyclyicHelper(Node*& slower, Node*& faster) const {
//   Node* oogway = slower;
//   Node* shifu = faster;
//   while (oogway != nullptr && shifu != nullptr &&
//          shifu->next_node_ != nullptr) {
//     if (oogway == shifu) return false;

//     if (oogway->next_bll_ != nullptr) {
//       oogway = oogway->next_bll_->head_;
//     } else {
//       oogway = oogway->next_node_;
//     }
//     if (shifu->next_bll_ != nullptr) {
//       shifu = shifu->next_bll_->head_;
//       if (shifu != nullptr && shifu->next_bll_ != nullptr) {
//         shifu = shifu->next_node_;
//       }
//     } else {
//       if (shifu->next_node_->next_bll_ != nullptr) {
//         shifu = shifu->next_node_->next_bll_->head_;
//       } else {
//         shifu = shifu->next_node_->next_node_;
//       }
//     }
//   }
//   return true;
// }
