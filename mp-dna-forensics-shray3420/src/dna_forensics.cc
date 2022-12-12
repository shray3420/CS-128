#include <iostream>

#include "functions.hpp"
#include "utilities.hpp"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " [input_file] [dna_sequence]"
              << std::endl;
    return 1;
  }
  std::string file = argv[1];
  std::string input = argv[2];
  std::string out = MainOutput(file, input);
  std::cout << out << std::endl;
  return 0;
}