#include "cord-utilities.hpp"

#include "cord.hpp"

std::shared_ptr<Cord> ConcatCords(std::shared_ptr<Cord> left_cord,
                                  std::shared_ptr<Cord> right_cord) {
  // TODO

  std::shared_ptr<Cord> cord1 = std::move(left_cord);
  std::shared_ptr<Cord> cord2 = std::move(right_cord);
  if (!(cord1->IsValidCord() && cord2->IsValidCord())) {
    throw std::runtime_error("");
  }
  auto ret = make_shared<Cord>(cord1, cord2);
  return ret;
}

void ReduceCords(cs128::ReferenceList<std::shared_ptr<Cord>> cords) {
  // TODO
  std::map<std::string, std::shared_ptr<Cord>> map_cord;
  for (auto i : cords) {
    std::shared_ptr<Cord>& temp = i.get();
    temp->ReduceCordHelper(map_cord, i.get());
  }
}
void Cord::ReduceCordHelper(
    std::map<std::string, std::shared_ptr<Cord>>& map_cord,
    std::shared_ptr<Cord>& cord) {
  if (map_cord[cord->ToString()] == nullptr) {
    map_cord[cord->ToString()] = cord;
  } else {
    cord = map_cord[cord->ToString()];
  }
  if (cord->left_ != nullptr) ReduceCordHelper(map_cord, cord->left_);
  if (cord->right_ != nullptr) ReduceCordHelper(map_cord, cord->right_);
}
