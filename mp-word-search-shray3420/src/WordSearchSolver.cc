#include "WordSearchSolver.hpp"

#include <cassert>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "CharPositions.hpp"
#include "WordLocation.hpp"

WordSearchSolver::WordSearchSolver(
    const std::vector<std::vector<char>>& puzzle) {
  puzzle_ = puzzle;
  puzzle_height_ = puzzle_.size();
  puzzle_width_ = puzzle_[0].size();
}
WordLocation WordSearchSolver::FindWord(const std::string& word) {
  if (!FindWord(word, CheckDirection::kHorizontal).word.empty()) {
    return FindWord(word, CheckDirection::kHorizontal);
  }
  if (!FindWord(word, CheckDirection::kRightDiag).word.empty()) {
    return FindWord(word, CheckDirection::kRightDiag);
  }
  if (!FindWord(word, CheckDirection::kLeftDiag).word.empty()) {
    return FindWord(word, CheckDirection::kLeftDiag);
  }
  if (!FindWord(word, CheckDirection::kVertical).word.empty()) {
    return FindWord(word, CheckDirection::kVertical);
  }
  return WordLocation{};
}
WordLocation WordSearchSolver::FindWord(const std::string& word,
                                        CheckDirection direction) {
  if (direction == CheckDirection::kHorizontal) {
    return CheckHorizontal(word);
  }
  if (direction == CheckDirection::kRightDiag) {
    return CheckRightDiag(word);
  }
  if (direction == CheckDirection::kLeftDiag) {
    return CheckLeftDiag(word);
  }
  if (direction == CheckDirection::kVertical) {
    return CheckVertical(word);
  }
  return WordLocation{};
}
WordLocation WordSearchSolver::CheckHorizontal(const std::string& word) {
  WordLocation w;
  for (unsigned long i = 0; i < puzzle_height_; i++) {
    for (unsigned long j = 0; j < puzzle_width_ - (word.size() - 1); j++) {
      std::string holder;
      std::vector<CharPositions> characters;
      for (unsigned long index = 0; index < word.size(); index++) {
        holder += puzzle_[i][j + index];
        CharPositions current = {};
        current.character = puzzle_[i][j + index];
        current.row = i;
        current.col = j + index;
        characters.push_back(current);
      }

      if (holder == word) {
        w.word = word;
        w.char_positions = characters;
        break;
      }
    }
  }
  return w;
}
WordLocation WordSearchSolver::CheckRightDiag(const std::string& word) {
  WordLocation w;
  for (unsigned long i = 0; i < puzzle_height_ - (word.size() - 1); i++) {
    for (unsigned long j = 0; j < puzzle_width_ - (word.size() - 1); j++) {
      std::string holder;
      std::vector<CharPositions> characters;
      for (unsigned long index = 0; index < word.size(); index++) {
        holder += puzzle_[i + index][j + index];
        CharPositions current = {};
        current.character = puzzle_[i + index][j + index];
        current.row = i + index;
        current.col = j + index;
        characters.push_back(current);
      }

      if (holder == word) {
        w.word = word;
        w.char_positions = characters;
        break;
      }
    }
  }
  return w;
}
WordLocation WordSearchSolver::CheckLeftDiag(const std::string& word) {
  WordLocation w;
  for (unsigned long i = 0; i < puzzle_height_ - (word.size() - 1); i++) {
    for (unsigned long j = puzzle_width_;
         j != std::numeric_limits<size_t>::max();
         j--) {
      std::string holder;
      std::vector<CharPositions> characters;
      for (unsigned long index = 0; index < word.size(); index++) {
        holder += puzzle_[i + index][j - index];
        CharPositions current = {};
        current.character = puzzle_[i + index][j - index];
        current.row = i + index;
        current.col = j - index;
        characters.push_back(current);
        // std::cout << current.row << " " << current.col << std::endl;
      }

      if (holder == word) {
        w.word = word;
        w.char_positions = characters;
        break;
      }
    }
  }
  return w;
}
WordLocation WordSearchSolver::CheckVertical(const std::string& word) {
  WordLocation w;
  for (unsigned long i = 0; i < puzzle_height_ - (word.size() - 1); i++) {
    for (unsigned long j = 0; j < puzzle_width_; j++) {
      std::string holder;
      std::vector<CharPositions> characters;
      for (unsigned long index = 0; index < word.size(); index++) {
        holder += puzzle_[i + index][j];
        CharPositions current = {};
        current.character = puzzle_[i + index][j];
        current.row = i + index;
        current.col = j;
        characters.push_back(current);
      }

      if (holder == word) {
        w.word = word;
        w.char_positions = characters;
        break;
      }
    }
  }
  return w;
}
bool WordSearchSolver::LocationInBounds(size_t row, size_t col) const {
  return ((row < puzzle_height_) && (col < puzzle_width_));
}