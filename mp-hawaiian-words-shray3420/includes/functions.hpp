#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <string>
// Your function declarations should go in this header file.

// converts word to hawaiian pronunciation
std::string Hawaiian(std::string input);

// converts consonants
std::string Consonant(char current_letter, char previous_letter);

// converts single vowels
std::string VowelSingle(char current_letter);

// converts vowel groups
std::string VowelGroup(char current_letter, char next_letter);

bool IsVowelGroup(char current_letter, char next_letter);
// using booleans to verify if letter actually is what it is being checked for
bool IsItNotHawaiian(std::string input);
std::string Check(std::string input);
#endif