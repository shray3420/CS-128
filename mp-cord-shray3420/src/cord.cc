#include "cord.hpp"

#include "cord-utilities.hpp"

Cord::Cord(const std::string& dat) {
  data_ = dat;
  length_ = dat.length();
}

Cord::Cord(const std::shared_ptr<Cord>& left_cord,
           const std::shared_ptr<Cord>& right_cord) {
  // TODO
  right_ = right_cord;
  left_ = left_cord;
  length_ = right_cord->Length() + left_cord->Length();
}

size_t Cord::Length() const { return length_; }

std::shared_ptr<Cord> Cord::GetLeft() const { return left_; }

std::shared_ptr<Cord> Cord::GetRight() const { return right_; }

const std::string& Cord::GetData() const { return data_; }

std::string Cord::ToString() const {
  // TODO
  if (left_ == nullptr && right_ == nullptr) return data_;
  return left_->ToString() + right_->ToString();
}

std::shared_ptr<Cord> Cord::SubString(size_t lower_idx, size_t upper_idx) {
  // TODO
  if (lower_idx == upper_idx) return right_;
  return nullptr;
}

char Cord::At(size_t idx) const {
  // TODO
  if (idx > length_ - 1 || idx < 0) throw std::runtime_error("out of bounds");
  if (left_ == nullptr && right_ == nullptr) return data_.at(idx);
  if (idx < left_->Length()) return left_->At(idx);
  size_t num = idx - left_->Length();
  return right_->At(num);
}

bool Cord::IsValidCord() const {
  // TODO
  if (!data_.empty() && left_ == nullptr && right_ == nullptr &&
      length_ == data_.length())
    return true;
  if (data_.empty() && left_ != nullptr && right_ != nullptr &&
      right_->Length() < length_ && left_->Length() < length_ &&
      length_ == (right_->Length() + left_->Length()))
    return left_->IsValidCord() && right_->IsValidCord();

  return false;
}
