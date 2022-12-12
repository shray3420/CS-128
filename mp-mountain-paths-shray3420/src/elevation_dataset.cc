#include "elevation_dataset.hpp"

#include <cstdlib>  // for size_t
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

ElevationDataset::ElevationDataset(const std::string& filename,
                                   size_t width,
                                   size_t height) {
  width_ = width;
  height_ = height;
  min_ele_ = std::numeric_limits<int>::max();
  max_ele_ = std::numeric_limits<int>::min();
  int num = 0;
  std::ifstream file(filename);
  std::vector<std::vector<int>> data;
  if (!file.is_open()) {
    throw std::runtime_error("");
  }

  for (size_t i = 0; i < height_; i++) {
    std::vector<int> holder;
    for (size_t j = 0; j < width_; j++) {
      if (data.size() >= height_ || file.fail()) {
        throw std::runtime_error("");
      }
      file >> num;

      if (num <= min_ele_) {
        min_ele_ = num;
      }
      if (num >= max_ele_) {
        max_ele_ = num;
      }
      holder.push_back(num);
    }
    data.push_back(holder);
  }
  if (file >> num) {
    throw std::runtime_error("");
  }
  data_ = data;
}
size_t ElevationDataset::Width() const { return width_; }
size_t ElevationDataset::Height() const { return height_; }
int ElevationDataset::MaxEle() const { return max_ele_; }
int ElevationDataset::MinEle() const { return min_ele_; }
int ElevationDataset::DatumAt(size_t row, size_t col) const {
  if (row < 0 || row >= height_) {
    return std::numeric_limits<int>::max();
  }
  return data_[row][col];
}
const std::vector<std::vector<int>>& ElevationDataset::GetData() const {
  return data_;
}