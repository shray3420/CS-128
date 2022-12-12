#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cassert>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "utilities.hpp"

std::string MainOutput(const std::string kCSV, const std::string kINPUT);
std::string AGAT(std::string input);
std::string AATG(std::string input);
std::string TATC(std::string input);
std::string AGATG(std::string input);
std::string TAT(std::string input);
std::string CACA(std::string input);
std::string CACC(std::string input);
std::string ATTA(std::string input);

#endif