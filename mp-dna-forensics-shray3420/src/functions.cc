#include "functions.hpp"

#include <cassert>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "utilities.hpp"

std::string ATTA(std::string input) {
  int longest_count = 0;
  for (unsigned int i = 0; i < input.size() - 3; i++) {
    if (input.at(i) == 'A' && input.at(i + 1) == 'T' &&
        input.at(i + 2) == 'T' && input.at(i + 3) == 'A') {
      int current_count = 1;
      for (unsigned int j = i + 4; j < input.size() - 3; j += 4) {
        if (input.at(i) != input.at(j) || input.at(i + 1) != input.at(j + 1) ||
            input.at(i + 2) != input.at(j + 2) ||
            input.at(i + 3) != input.at(j + 3)) {
          break;
        }
        current_count++;
      }
      if (current_count > longest_count) {
        longest_count = current_count;
      }
    }
  }
  return std::to_string(longest_count);
}

std::string AATG(std::string input) {
  int longest_count = 0;
  for (unsigned int i = 0; i < input.size() - 3; i++) {
    if (input.at(i) == 'A' && input.at(i + 1) == 'A' &&
        input.at(i + 2) == 'T' && input.at(i + 3) == 'G') {
      int current_count = 1;
      for (unsigned int j = i + 4; j < input.size() - 3; j += 4) {
        if (input.at(i) != input.at(j) || input.at(i + 1) != input.at(j + 1) ||
            input.at(i + 2) != input.at(j + 2) ||
            input.at(i + 3) != input.at(j + 3)) {
          break;
        }
        current_count++;
      }
      if (current_count > longest_count) {
        longest_count = current_count;
      }
    }
  }
  return std::to_string(longest_count);
}

std::string TATC(std::string input) {
  int longest_count = 0;
  for (unsigned int i = 0; i < input.size() - 3; i++) {
    if (input.at(i) == 'T' && input.at(i + 1) == 'A' &&
        input.at(i + 2) == 'T' && input.at(i + 3) == 'C') {
      int current_count = 1;
      for (unsigned int j = i + 4; j < input.size() - 3; j += 4) {
        if (input.at(i) != input.at(j) || input.at(i + 1) != input.at(j + 1) ||
            input.at(i + 2) != input.at(j + 2) ||
            input.at(i + 3) != input.at(j + 3)) {
          break;
        }
        current_count++;
      }
      if (current_count > longest_count) {
        longest_count = current_count;
      }
    }
  }
  return std::to_string(longest_count);
}

std::string AGATG(std::string input) {
  int longest_count = 0;
  const int kFIVE = 5;
  for (unsigned int i = 0; i < input.size() - 4; i++) {
    if (input.at(i) == 'A' && input.at(i + 1) == 'G' &&
        input.at(i + 2) == 'A' && input.at(i + 3) == 'T' &&
        input.at(i + 4) == 'G') {
      int current_count = 1;
      for (unsigned int j = i + kFIVE; j < input.size() - 4; j += kFIVE) {
        if (input.at(i) != input.at(j) || input.at(i + 1) != input.at(j + 1) ||
            input.at(i + 2) != input.at(j + 2) ||
            input.at(i + 3) != input.at(j + 3) ||
            input.at(i + 4) != input.at(j + 4)) {
          break;
        }
        current_count++;
      }
      if (current_count > longest_count) {
        longest_count = current_count;
      }
    }
  }
  return std::to_string(longest_count);
}

std::string TAT(std::string input) {
  int longest_count = 0;
  for (unsigned int i = 0; i < input.size() - 2; i++) {
    if (input.at(i) == 'T' && input.at(i + 1) == 'A' &&
        input.at(i + 2) == 'T') {
      int current_count = 1;
      for (unsigned int j = i + 3; j < input.size() - 2; j += 3) {
        if (input.at(i) != input.at(j) || input.at(i + 1) != input.at(j + 1) ||
            input.at(i + 2) != input.at(j + 2)) {
          break;
        }
        current_count++;
      }
      if (current_count > longest_count) {
        longest_count = current_count;
      }
    }
  }
  return std::to_string(longest_count);
}

std::string AGAT(std::string input) {
  int longest_count = 0;
  for (unsigned int i = 0; i < input.size() - 3; i++) {
    if (input.at(i) == 'A' && input.at(i + 1) == 'G' &&
        input.at(i + 2) == 'A' && input.at(i + 3) == 'T') {
      int current_count = 1;
      for (unsigned int j = i + 4; j < input.size() - 3; j += 4) {
        if (input.at(i) != input.at(j) || input.at(i + 1) != input.at(j + 1) ||
            input.at(i + 2) != input.at(j + 2) ||
            input.at(i + 3) != input.at(j + 3)) {
          break;
        }
        current_count++;
      }
      if (current_count > longest_count) {
        longest_count = current_count;
      }
    }
  }
  return std::to_string(longest_count);
}

std::string CACC(std::string input) {
  int longest_count = 0;
  for (unsigned int i = 0; i < input.size() - 3; i++) {
    if (input.at(i) == 'C' && input.at(i + 1) == 'A' &&
        input.at(i + 2) == 'C' && input.at(i + 3) == 'C') {
      int current_count = 1;
      for (unsigned int j = i + 4; j < input.size() - 3; j += 4) {
        if (input.at(i) != input.at(j) || input.at(i + 1) != input.at(j + 1) ||
            input.at(i + 2) != input.at(j + 2) ||
            input.at(i + 3) != input.at(j + 3)) {
          break;
        }
        current_count++;
      }
      if (current_count > longest_count) {
        longest_count = current_count;
      }
    }
  }
  return std::to_string(longest_count);
}

std::string CACA(std::string input) {
  int longest_count = 0;
  for (unsigned int i = 0; i < input.size() - 3; i++) {
    if (input.at(i) == 'C' && input.at(i + 1) == 'A' &&
        input.at(i + 2) == 'C' && input.at(i + 3) == 'A') {
      int current_count = 1;
      for (unsigned int j = i + 4; j < input.size() - 3; j += 4) {
        if (input.at(i) != input.at(j) || input.at(i + 1) != input.at(j + 1) ||
            input.at(i + 2) != input.at(j + 2) ||
            input.at(i + 3) != input.at(j + 3)) {
          break;
        }
        current_count++;
      }
      if (current_count > longest_count) {
        longest_count = current_count;
      }
    }
  }
  return std::to_string(longest_count);
}

std::string MainOutput(const std::string kCSV, const std::string kINPUT) {
  std::string atta = ATTA(kINPUT);
  std::string aatg = AATG(kINPUT);
  std::string tatc = TATC(kINPUT);
  std::string agatg = AGATG(kINPUT);
  std::string tat = TAT(kINPUT);
  std::string agat = AGAT(kINPUT);
  std::string cacc = CACC(kINPUT);
  std::string caca = CACA(kINPUT);
  std::string matched_name = "No match";
  std::ifstream ifs(kCSV);
  bool first = false;
  bool second = false;
  for (std::string line; std::getline(ifs, line); line = "") {
    std::vector<std::string> csv_vector = utilities::GetSubstrs(line, ',');
    if (csv_vector.at(1) == "AGAT") {
      first = true;
    } else if (csv_vector.at(1) == "AGATG") {
      second = true;
    }
    if (first) {
      if (csv_vector.at(1) == agat && csv_vector.at(2) == aatg &&
          csv_vector.at(3) == tatc) {
        matched_name = csv_vector.at(0);
      }
    } else if (second) {
      if (csv_vector.at(1) == agatg && csv_vector.at(2) == aatg &&
          csv_vector.at(3) == tat) {
        matched_name = csv_vector.at(0);
      }
    } else {
      if (csv_vector.at(1) == caca && csv_vector.at(2) == cacc &&
          csv_vector.at(3) == atta) {
        matched_name = csv_vector.at(0);
      }
    }
  }
  return matched_name;
}
