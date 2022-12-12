#include "grayscale_image.hpp"

#include <cmath>
#include <cstdlib>  // for size_t
#include <fstream>
#include <iostream>
#include <vector>

#include "color.hpp"
#include "elevation_dataset.hpp"
GrayscaleImage::GrayscaleImage(const ElevationDataset& dataset) {
  std::vector<std::vector<Color>> image;
  std::vector<Color> holder;
  const int kNum = 255;
  width_ = dataset.Width();
  height_ = dataset.Height();
  for (size_t i = 0; i < height_; i++) {
    for (size_t j = 0; j < width_; j++) {
      if (dataset.MaxEle() == dataset.MinEle()) {
        Color temp(0, 0, 0);
        holder.push_back(temp);
        continue;
      }
      int shade_of_gray =
          (int)std::round(1.0 * (dataset.DatumAt(i, j) - dataset.MinEle()) /
                          (dataset.MaxEle() - dataset.MinEle()) * kNum);
      Color temp(shade_of_gray, shade_of_gray, shade_of_gray);
      holder.push_back(temp);
    }
    image.push_back(holder);
    holder.clear();
  }
  image_ = image;
}
GrayscaleImage::GrayscaleImage(const std::string& filename,
                               size_t width,
                               size_t height) {
  width_ = width;
  height_ = height;
  std::vector<std::vector<Color>> image;
  std::vector<Color> holder;
  const ElevationDataset& dataset = ElevationDataset(filename, width_, height_);
  for (size_t i = 0; i < height_; i++) {
    for (size_t j = 0; j < width_; j++) {
      if (dataset.MaxEle() == dataset.MinEle()) {
        Color temp(0, 0, 0);
        holder.push_back(temp);
        continue;
      }
      int shade_of_gray = (int)std::round(
          1.0 * (dataset.DatumAt(i, j) - dataset.MinEle()) /
          (dataset.MaxEle() - dataset.MinEle()) * kMaxColorValue);
      Color temp(shade_of_gray, shade_of_gray, shade_of_gray);
      holder.push_back(temp);
    }
    image.push_back(holder);
    holder.clear();
  }
  image_ = image;
}

size_t GrayscaleImage::Width() const { return width_; }
size_t GrayscaleImage::Height() const { return height_; };
unsigned int GrayscaleImage::MaxColorValue() const { return kMaxColorValue; }
const Color& GrayscaleImage::ColorAt(int row, int col) const {
  return image_[row][col];
}
const std::vector<std::vector<Color>>& GrayscaleImage::GetImage() const {
  return image_;
}
void GrayscaleImage::ToPpm(const std::string& name) const {
  std::ofstream file(name);
  file << "P3" << '\n';
  file << width_ << ' ' << height_ << '\n';
  file << kMaxColorValue << '\n';
  for (size_t i = 0; i < height_; i++) {
    for (size_t j = 0; j < width_; j++) {
      file << image_[i][j].Red() << ' ' << image_[i][j].Green() << ' '
           << image_[i][j].Blue() << ' ';
    }
    file << '\n';
  }
}