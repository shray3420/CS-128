#include "functions.hpp"

#include "cassert"
#include "cctype"
#include "functions.hpp"
#include "iostream"
#include "sstream"
#include "string"
#include "utility"
#include "vector"

std::string Check(std::string input) {
  std::string ret;
  for (unsigned long i = 0; i < input.size(); i++) {
    std::cout << i << std::endl;
    if (input.substr(i, 1) == " '") {
      continue;
    }
    if (input.substr(i, 2) == "-'") {
      continue;
    }
    if (input.substr(i, 2) == "- ") {
      continue;
    }
    if (input.substr(i, 2).empty()) {
      continue;
    }
    ret.push_back(input.at(i));
  }
  if (ret.substr(ret.size() - 1, 1) == "-") {
    ret.pop_back();
  }
  return ret;
}

std::string Hawaiian(std::string input) {
  std::string final;
  char previous_letter = 'z';
  char next_letter = 'x';
  if (IsItNotHawaiian(input)) {
    final =
        input + " contains a character not a part of the Hawaiian language.";
    ;
  } else {
    for (unsigned long i = 0; i < input.size(); i++) {
      // std::cout << i << std::endl;
      char current_letter = (char)tolower(input.at(i));
      if (i != input.size() - 1) {
        next_letter = (char)tolower(input.at(i + 1));
      }
      if (i != 0) {
        previous_letter = (char)tolower(input.at(i - 1));
      }

      if ((i != input.size() - 1) &&
          IsVowelGroup(current_letter, next_letter)) {
        final.append(VowelGroup(current_letter, next_letter));
        i++;
      } else {
        final.append(VowelSingle(current_letter));
        final.append(Consonant(current_letter, previous_letter));
      }
    }
  }
  return Check(final);
}
// class checks to see if the passed letter is a consonant or not and what to
// return
std::string Consonant(char current_letter, char previous_letter) {
  std::string pronunciation;
  if (current_letter == 'p') {
    pronunciation = "p";
  } else if (current_letter == 'k') {
    pronunciation = "k";
  } else if (current_letter == 'h') {
    pronunciation = "h";
  } else if (current_letter == 'l') {
    pronunciation = "l";
  } else if (current_letter == 'm') {
    pronunciation = "m";
  } else if (current_letter == 'n') {
    pronunciation = "n";
  } else if ((current_letter == 'w') &&
             ((previous_letter == 'a') || (previous_letter == 'u') ||
              (previous_letter == 'o') || (previous_letter == 'z'))) {
    pronunciation = "w";
  } else if ((current_letter == 'w') &&
             ((previous_letter == 'i') || (previous_letter == 'e'))) {
    pronunciation = "v";
  } else if (current_letter == '\'') {
    pronunciation = "'";
  } else if (current_letter == ' ') {
    pronunciation = " ";
  } else {
    pronunciation = "";
  }

  return pronunciation;
}
// class checks to see if passed letter is a solo vowel
std::string VowelSingle(char current_letter) {
  std::string pronunciation;
  if (current_letter == 'a') {
    pronunciation = "ah-";
  } else if (current_letter == 'e') {
    pronunciation = "eh-";
  } else if (current_letter == 'i') {
    pronunciation = "ee-";
  } else if (current_letter == 'o') {
    pronunciation = "oh-";
  } else if (current_letter == 'u') {
    pronunciation = "oo-";
  } else {
    pronunciation = "";
  }
  return pronunciation;
}
// class checks to see if passes letter is a group vowel, switches to proper
// pronunciation
std::string VowelGroup(char current_letter, char next_letter) {
  std::string pronunciation;
  if (current_letter == 'a') {
    if ((next_letter == 'i') || (next_letter == 'e')) {
      pronunciation = "eye-";
    } else if ((next_letter == 'o') || (next_letter == 'u')) {
      pronunciation = "ow-";
    } else {
      pronunciation = "";
    }
  } else if (current_letter == 'e') {
    if (next_letter == 'i') {
      pronunciation = "ay-";
    } else if (next_letter == 'u') {
      pronunciation = "eh-oo-";
    } else {
      pronunciation = "";
    }
  } else if (current_letter == 'i' && next_letter == 'u') {
    pronunciation = "ew-";
  } else if (current_letter == 'o') {
    if (next_letter == 'i') {
      pronunciation = "oy-";
    } else if (next_letter == 'u') {
      pronunciation = "ow-";
    } else {
      pronunciation = "";
    }
  } else if (current_letter == 'u' && next_letter == 'i') {
    pronunciation = "ooey-";
  } else {
    pronunciation = "";
  }
  return pronunciation;
}

bool IsVowelGroup(char current_letter, char next_letter) {
  std::string str;
  bool ret = false;
  str.push_back(current_letter);
  str.push_back(next_letter);
  if (str == "ai" || str == "ae" || str == "ao" || str == "au" || str == "ei" ||
      str == "eu" || str == "iu" || str == "oi" || str == "ou" || str == "ui") {
    ret = true;
  }
  return ret;
}

bool IsItNotHawaiian(std::string input) {
  bool var = true;
  for (unsigned long i = 0; i < input.size(); i++) {
    // std::cout << i << std::endl;
    char current_letter = (char)tolower(input.at(i));
    // std::cout << current_letter << std::endl;
    std::string str;
    str.push_back(current_letter);
    if ((current_letter == 'p') || (current_letter == 'k') ||
        (current_letter == 'h') || (current_letter == 'l') ||
        (current_letter == 'm') || (current_letter == 'n') ||
        (current_letter == 'a') || (current_letter == 'e') ||
        (current_letter == 'i') || (current_letter == 'o') ||
        (current_letter == 'u') || (current_letter == 'w') ||
        (current_letter == ' ') || (str == "'")) {
      var = false;
    } else {
      return true;
    }
  }
  return var;
}
