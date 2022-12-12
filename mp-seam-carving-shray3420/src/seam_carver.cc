#include "seam_carver.hpp"

#include "image_ppm.hpp"
#include "pixel.hpp"
// implement the rest of SeamCarver's functions here

// given functions below, DO NOT MODIFY

SeamCarver::SeamCarver(const ImagePPM& image): image_(image) {
  height_ = image.GetHeight();
  width_ = image.GetWidth();
}

void SeamCarver::SetImage(const ImagePPM& image) {
  image_ = image;
  width_ = image.GetWidth();
  height_ = image.GetHeight();
}
const ImagePPM& SeamCarver::GetImage() const { return image_; }

int SeamCarver::GetHeight() const { return height_; }

int SeamCarver::GetWidth() const { return width_; }

int SeamCarver::GetEnergy(int row, int col) const {
  int ret = 0;

  if (row > 0 && col > 0 && row < height_ - 1 && col < width_ - 1) {
    ret = Middle(row, col);
  } else if (row > 0 && col == 0 && row < height_ - 1) {
    ret = Left(row, col);
  } else if (row > 0 && row < height_ - 1 && col == width_ - 1) {
    ret = Right(row, col);
  } else if (row == 0 && col > 0 && col < width_ - 1) {
    ret = Top(row, col);
  } else if (col > 0 && row == height_ - 1 && col < width_ - 1) {
    ret = Bottom(row, col);
  } else if (row == 0 && col == width_ - 1) {
    ret = TopRight(row, col);
  } else if (row == 0 && col == 0) {
    ret = TopLeft(row, col);
  } else if (row == height_ - 1 && col == 0) {
    ret = BottomLeft(row, col);
  } else if (row == height_ - 1 && col == width_ - 1) {
    ret = BottomRight(row, col);
  }
  return ret;
}

int SeamCarver::Top(int row, int col) const {
  int red_col = (image_.GetPixel(row, col - 1).GetRed()) -
                (image_.GetPixel(row, col + 1).GetRed());
  int green_col = (image_.GetPixel(row, col - 1).GetGreen()) -
                  (image_.GetPixel(row, col + 1).GetGreen());
  int blue_col = (image_.GetPixel(row, col - 1).GetBlue()) -
                 (image_.GetPixel(row, col + 1).GetBlue());
  int red_row = (image_.GetPixel(height_ - 1, col).GetRed()) -
                (image_.GetPixel(row + 1, col).GetRed());
  int green_row = (image_.GetPixel(height_ - 1, col).GetGreen()) -
                  (image_.GetPixel(row + 1, col).GetGreen());
  int blue_row = (image_.GetPixel(height_ - 1, col).GetBlue()) -
                 (image_.GetPixel(row + 1, col).GetBlue());
  int change_col =
      (red_col * red_col) + (green_col * green_col) + (blue_col * blue_col);
  int change_row =
      (red_row * red_row) + (green_row * green_row) + (blue_row * blue_row);
  int energy = change_col + change_row;
  return energy;
}

int SeamCarver::TopRight(int row, int col) const {
  int red_col = (image_.GetPixel(row, col - 1).GetRed()) -
                (image_.GetPixel(row, 0).GetRed());
  int green_col = (image_.GetPixel(row, col - 1).GetGreen()) -
                  (image_.GetPixel(row, 0).GetGreen());
  int blue_col = (image_.GetPixel(row, col - 1).GetBlue()) -
                 (image_.GetPixel(row, 0).GetBlue());
  int red_row = (image_.GetPixel(height_ - 1, col).GetRed()) -
                (image_.GetPixel(row + 1, col).GetRed());
  int green_row = (image_.GetPixel(height_ - 1, col).GetGreen()) -
                  (image_.GetPixel(row + 1, col).GetGreen());
  int blue_row = (image_.GetPixel(height_ - 1, col).GetBlue()) -
                 (image_.GetPixel(row + 1, col).GetBlue());
  int change_col =
      (red_col * red_col) + (green_col * green_col) + (blue_col * blue_col);
  int change_row =
      (red_row * red_row) + (green_row * green_row) + (blue_row * blue_row);
  int energy = change_col + change_row;
  return energy;
}

int SeamCarver::TopLeft(int row, int col) const {
  int red_col = (image_.GetPixel(row, width_ - 1).GetRed()) -
                (image_.GetPixel(row, col + 1).GetRed());
  int green_col = (image_.GetPixel(row, width_ - 1).GetGreen()) -
                  (image_.GetPixel(row, col + 1).GetGreen());
  int blue_col = (image_.GetPixel(row, width_ - 1).GetBlue()) -
                 (image_.GetPixel(row, col + 1).GetBlue());
  int red_row = (image_.GetPixel(height_ - 1, col).GetRed()) -
                (image_.GetPixel(row + 1, col).GetRed());
  int green_row = (image_.GetPixel(height_ - 1, col).GetGreen()) -
                  (image_.GetPixel(row + 1, col).GetGreen());
  int blue_row = (image_.GetPixel(height_ - 1, col).GetBlue()) -
                 (image_.GetPixel(row + 1, col).GetBlue());
  int change_col =
      (red_col * red_col) + (green_col * green_col) + (blue_col * blue_col);
  int change_row =
      (red_row * red_row) + (green_row * green_row) + (blue_row * blue_row);
  int energy = change_col + change_row;
  return energy;
}

int SeamCarver::Bottom(int row, int col) const {
  int red_col = (image_.GetPixel(row, col - 1).GetRed()) -
                (image_.GetPixel(row, col + 1).GetRed());
  int green_col = (image_.GetPixel(row, col - 1).GetGreen()) -
                  (image_.GetPixel(row, col + 1).GetGreen());
  int blue_col = (image_.GetPixel(row, col - 1).GetBlue()) -
                 (image_.GetPixel(row, col + 1).GetBlue());
  int red_row = (image_.GetPixel(row - 1, col).GetRed()) -
                (image_.GetPixel(0, col).GetRed());
  int green_row = (image_.GetPixel(row - 1, col).GetGreen()) -
                  (image_.GetPixel(0, col).GetGreen());
  int blue_row = (image_.GetPixel(row - 1, col).GetBlue()) -
                 (image_.GetPixel(0, col).GetBlue());
  int change_col =
      (red_col * red_col) + (green_col * green_col) + (blue_col * blue_col);
  int change_row =
      (red_row * red_row) + (green_row * green_row) + (blue_row * blue_row);
  int energy = change_col + change_row;
  return energy;
}

int SeamCarver::BottomRight(int row, int col) const {
  int red_col = (image_.GetPixel(row, col - 1).GetRed()) -
                (image_.GetPixel(row, 0).GetRed());
  int green_col = (image_.GetPixel(row, col - 1).GetGreen()) -
                  (image_.GetPixel(row, 0).GetGreen());
  int blue_col = (image_.GetPixel(row, col - 1).GetBlue()) -
                 (image_.GetPixel(row, 0).GetBlue());
  int red_row = (image_.GetPixel(row - 1, col).GetRed()) -
                (image_.GetPixel(0, col).GetRed());
  int green_row = (image_.GetPixel(row - 1, col).GetGreen()) -
                  (image_.GetPixel(0, col).GetGreen());
  int blue_row = (image_.GetPixel(row - 1, col).GetBlue()) -
                 (image_.GetPixel(0, col).GetBlue());
  int change_col =
      (red_col * red_col) + (green_col * green_col) + (blue_col * blue_col);
  int change_row =
      (red_row * red_row) + (green_row * green_row) + (blue_row * blue_row);
  int energy = change_col + change_row;
  return energy;
}

int SeamCarver::BottomLeft(int row, int col) const {
  int red_col = (image_.GetPixel(row, width_ - 1).GetRed()) -
                (image_.GetPixel(row, col + 1).GetRed());
  int green_col = (image_.GetPixel(row, width_ - 1).GetGreen()) -
                  (image_.GetPixel(row, col + 1).GetGreen());
  int blue_col = (image_.GetPixel(row, width_ - 1).GetBlue()) -
                 (image_.GetPixel(row, col + 1).GetBlue());
  int red_row = (image_.GetPixel(row - 1, col).GetRed()) -
                (image_.GetPixel(0, col).GetRed());
  int green_row = (image_.GetPixel(row - 1, col).GetGreen()) -
                  (image_.GetPixel(0, col).GetGreen());
  int blue_row = (image_.GetPixel(row - 1, col).GetBlue()) -
                 (image_.GetPixel(0, col).GetBlue());
  int change_col =
      (red_col * red_col) + (green_col * green_col) + (blue_col * blue_col);
  int change_row =
      (red_row * red_row) + (green_row * green_row) + (blue_row * blue_row);
  int energy = change_col + change_row;
  return energy;
}

int SeamCarver::Left(int row, int col) const {
  int red_col = (image_.GetPixel(row, width_ - 1).GetRed()) -
                (image_.GetPixel(row, col + 1).GetRed());
  int green_col = (image_.GetPixel(row, width_ - 1).GetGreen()) -
                  (image_.GetPixel(row, col + 1).GetGreen());
  int blue_col = (image_.GetPixel(row, width_ - 1).GetBlue()) -
                 (image_.GetPixel(row, col + 1).GetBlue());
  int red_row = (image_.GetPixel(row - 1, col).GetRed()) -
                (image_.GetPixel(row + 1, col).GetRed());
  int green_row = (image_.GetPixel(row - 1, col).GetGreen()) -
                  (image_.GetPixel(row + 1, col).GetGreen());
  int blue_row = (image_.GetPixel(row - 1, col).GetBlue()) -
                 (image_.GetPixel(row + 1, col).GetBlue());
  int change_col =
      (red_col * red_col) + (green_col * green_col) + (blue_col * blue_col);
  int change_row =
      (red_row * red_row) + (green_row * green_row) + (blue_row * blue_row);
  int energy = change_col + change_row;
  return energy;
}

int SeamCarver::Right(int row, int col) const {
  int red_col = (image_.GetPixel(row, col - 1).GetRed()) -
                (image_.GetPixel(row, 0).GetRed());
  int green_col = (image_.GetPixel(row, col - 1).GetGreen()) -
                  (image_.GetPixel(row, 0).GetGreen());
  int blue_col = (image_.GetPixel(row, col - 1).GetBlue()) -
                 (image_.GetPixel(row, 0).GetBlue());
  int red_row = (image_.GetPixel(row - 1, col).GetRed()) -
                (image_.GetPixel(row + 1, col).GetRed());
  int green_row = (image_.GetPixel(row - 1, col).GetGreen()) -
                  (image_.GetPixel(row + 1, col).GetGreen());
  int blue_row = (image_.GetPixel(row - 1, col).GetBlue()) -
                 (image_.GetPixel(row + 1, col).GetBlue());
  int change_col =
      (red_col * red_col) + (green_col * green_col) + (blue_col * blue_col);
  int change_row =
      (red_row * red_row) + (green_row * green_row) + (blue_row * blue_row);
  int energy = change_col + change_row;
  return energy;
}

int SeamCarver::Middle(int row, int col) const {
  int red_col = (image_.GetPixel(row, col - 1).GetRed()) -
                (image_.GetPixel(row, col + 1).GetRed());
  int green_col = (image_.GetPixel(row, col - 1).GetGreen()) -
                  (image_.GetPixel(row, col + 1).GetGreen());
  int blue_col = (image_.GetPixel(row, col - 1).GetBlue()) -
                 (image_.GetPixel(row, col + 1).GetBlue());
  int red_row = (image_.GetPixel(row - 1, col).GetRed()) -
                (image_.GetPixel(row + 1, col).GetRed());
  int green_row = (image_.GetPixel(row - 1, col).GetGreen()) -
                  (image_.GetPixel(row + 1, col).GetGreen());
  int blue_row = (image_.GetPixel(row - 1, col).GetBlue()) -
                 (image_.GetPixel(row + 1, col).GetBlue());
  int change_col =
      (red_col * red_col) + (green_col * green_col) + (blue_col * blue_col);
  int change_row =
      (red_row * red_row) + (green_row * green_row) + (blue_row * blue_row);
  int energy = change_col + change_row;
  return energy;
}

int* SeamCarver::GetHorizontalSeam() const {
   int** seam = new int*[height_];
  for (int col = 0; col < width_; col++) {
    seam[col] = new int[width_];
  }
}

int* SeamCarver::GetVerticalSeam() const {
 
}

void SeamCarver::RemoveHorizontalSeam() {}

void SeamCarver::RemoveVerticalSeam() {}

SeamCarver SeamCarver::CalculateVerticalSeam() const {
 
}

SeamCarver SeamCarver::CalculateHorizontalSeam() const {}