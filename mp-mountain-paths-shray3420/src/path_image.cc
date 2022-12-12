#include "path_image.hpp"

#include <cstdlib>  // for size_t
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

#include "color.hpp"
#include "elevation_dataset.hpp"
#include "grayscale_image.hpp"
#include "path.hpp"

PathImage::PathImage(const GrayscaleImage& image,
                     const ElevationDataset& dataset) {
  width_ = dataset.Width();
  height_ = dataset.Height();
  path_image_ = image.GetImage();
  std::vector<Path> paths;

  paths_ = Initialize(dataset, paths);
}
std::vector<Path> PathImage::Initialize(const ElevationDataset& dataset,
                                        std::vector<Path>& paths) {
  Path least_resistance(0, 0);
  least_resistance.IncEleChange(std::numeric_limits<int>::max());
  static const Color kRED = Color(252, 25, 63);
  for (size_t r = 0; r < height_; r++) {
    Path holder = Path(width_, r);
    holder.SetLoc(0, r);
    size_t row = r;
    path_image_[row][0] = kRED;

    for (size_t j = 0; j < width_ - 1; j++) {
      size_t fwd_down =
          abs(dataset.DatumAt(row, j) - dataset.DatumAt(row + 1, j + 1));
      size_t fwd = abs(dataset.DatumAt(row, j) - dataset.DatumAt(row, j + 1));
      size_t fwd_up =
          abs(dataset.DatumAt(row, j) - dataset.DatumAt(row - 1, j + 1));
      if (fwd <= fwd_up && fwd <= fwd_down) {
        holder.IncEleChange(fwd);
        holder.SetLoc(j + 1, row);
      } else if (fwd_down < fwd && fwd_down <= fwd_up) {
        holder.IncEleChange(fwd_down);
        row++;
        holder.SetLoc(j + 1, row);
      } else {
        holder.IncEleChange(fwd_up);
        row--;
        holder.SetLoc(j + 1, row);
      }
      path_image_[row][j + 1] = kRED;
    }

    if (least_resistance.EleChange() > holder.EleChange()) {
      least_resistance = holder;
    }
    paths.push_back(holder);
  }
  SetColor(path_image_, least_resistance.GetPath());

  return paths;
}
void SetColor(std::vector<std::vector<Color>>& path_image,
              const std::vector<size_t>& least) {
  static const Color kGreen = Color(31, 253, 13);
  for (size_t i = 0; i < least.size(); i++) {
    path_image[least[i]][i] = kGreen;
  }
}
size_t PathImage::Width() const { return width_; }
size_t PathImage::Height() const { return height_; }
unsigned int PathImage::MaxColorValue() const { return kMaxColorValue; }
const std::vector<Path>& PathImage::Paths() const { return paths_; }
const std::vector<std::vector<Color>>& PathImage::GetPathImage() const {
  return path_image_;
}
void PathImage::ToPpm(const std::string& name) const {
  std::ofstream file(name);
  file << "P3" << '\n';
  file << width_ << ' ' << height_ << '\n';
  file << kMaxColorValue << '\n';
  for (size_t i = 0; i < height_; i++) {
    for (size_t j = 0; j < width_; j++) {
      file << path_image_[i][j].Red() << ' ' << path_image_[i][j].Green() << ' '
           << path_image_[i][j].Blue() << ' ';
    }
    file << '\n';
  }
}
