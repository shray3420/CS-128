// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : Student Name                    Environment : ubuntu:bionic               //
//  Date ......: 2021/02/10                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#include "catch.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

#include "CharPositions.hpp"
#include "WordLocation.hpp"
#include "WordSearchSolver.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////
bool Check(WordLocation final, WordLocation test) {
  if (final.word == test.word) {
    return true;
  }
  for (unsigned long i = 0; i < final.char_positions.size(); i++) {
    if (final.char_positions[i].character == test.char_positions[i].character &&
        final.char_positions[i].row == test.char_positions[i].row &&
        final.char_positions[i].col == test.char_positions[i].col) {
      return true;
    }
  }
  return false;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("True == True", "") { REQUIRE(true == true); }
TEST_CASE("Horiz 1", "[Horizontal]") {
  std::vector<std::vector<char>> puzzle{{'d', 'e', 'a', 'o', 'u'},
                                        {'h', 'e', 'l', 'l', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'e', 't', 'a', 'u'},
                                        {'t', 'e', 't', 'o', 'u'}};
  WordLocation test = {
      "hello",
      {{'h', 1, 0}, {'e', 1, 1}, {'l', 1, 2}, {'l', 1, 3}, {'o', 1, 4}}};
  WordSearchSolver wss(puzzle);
  WordLocation final = wss.FindWord("hello");
  WordLocation empty = {};
  WordLocation other_final = wss.FindWord("hello", CheckDirection::kHorizontal);
  REQUIRE(Check(other_final, test));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kVertical)));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kLeftDiag)));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kRightDiag)));
  REQUIRE(Check(final, test));
}
TEST_CASE("Horiz 2", "[Horizontal]") {
  std::vector<std::vector<char>> puzzle{{'t', 'e', 't', 'l', 'u', 'i', 'y'},
                                        {'h', 'e', 'l', 'l', 'o', 'o', 't'},
                                        {'c', 'a', 'l', 'o', 'm', 'a', 'r'},
                                        {'a', 'e', 't', 'a', 'u', 'y', 'y'},
                                        {'a', 'u', 't', 'i', 'u', 'y', 'h'}};
  WordLocation test = {
      "hello",
      {{'h', 1, 0}, {'e', 1, 1}, {'l', 1, 2}, {'l', 1, 3}, {'o', 1, 4}}};
  WordSearchSolver wss(puzzle);
  WordLocation final = wss.FindWord("hello");
  WordLocation empty = {};
  WordLocation other_final = wss.FindWord("hello", CheckDirection::kHorizontal);
  REQUIRE(Check(other_final, test));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kVertical)));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kLeftDiag)));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kRightDiag)));
  REQUIRE(Check(final, test));
}
TEST_CASE("Horiz 3", "[Horizontal]") {
  std::vector<std::vector<char>> puzzle{{'d', 'e', 'a', 'o', 'u'},
                                        {'h', 'e', 'l', 'l', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'e', 't', 'a', 'u'},
                                        {'a', 'e', 't', 'a', 'u'},
                                        {'a', 'e', 't', 'a', 'u'},
                                        {'t', 'e', 't', 'o', 'u'}};
  WordLocation test = {
      "hello",
      {{'h', 1, 0}, {'e', 1, 1}, {'l', 1, 2}, {'l', 1, 3}, {'o', 1, 4}}};
  WordSearchSolver wss(puzzle);
  WordLocation final = wss.FindWord("hello");
  WordLocation empty = {};
  WordLocation other_final = wss.FindWord("hello", CheckDirection::kHorizontal);
  REQUIRE(Check(other_final, test));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kVertical)));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kLeftDiag)));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kRightDiag)));
  REQUIRE(Check(final, test));
}
TEST_CASE("Horiz 4", "[Horizontal]") {
  std::vector<std::vector<char>> puzzle{{'d', 'e', 'a', 'o', 'u'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'e', 't', 'a', 'u'},
                                        {'t', 'e', 't', 'o', 'u'},
                                        {'h', 'e', 'l', 'l', 'o'}};
  WordLocation test = {
      "hello",
      {{'h', 4, 0}, {'e', 4, 1}, {'l', 4, 2}, {'l', 4, 3}, {'o', 4, 4}}};
  WordSearchSolver wss(puzzle);
  WordLocation final = wss.FindWord("hello");
  WordLocation empty = {};
  WordLocation other_final = wss.FindWord("hello", CheckDirection::kHorizontal);
  REQUIRE(Check(other_final, test));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kVertical)));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kLeftDiag)));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kRightDiag)));
  REQUIRE(Check(final, test));
}
TEST_CASE("Vert 1", "[Vertical]") {
  std::vector<std::vector<char>> puzzle{{'h', 'e', 'a', 'o', 'u'},
                                        {'e', 'e', 'o', 't', 'o'},
                                        {'l', 'a', 'l', 'o', 'm'},
                                        {'l', 'e', 't', 'a', 'u'},
                                        {'o', 'e', 't', 'o', 'u'}};
  WordLocation test = {
      "hello",
      {{'h', 0, 0}, {'e', 1, 0}, {'l', 2, 0}, {'l', 3, 0}, {'o', 4, 0}}};
  WordSearchSolver wss(puzzle);
  WordLocation final = wss.FindWord("hello");
  WordLocation empty = {};
  WordLocation other_final = wss.FindWord("hello", CheckDirection::kVertical);
  REQUIRE(Check(other_final, test));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kHorizontal)));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kLeftDiag)));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kRightDiag)));
  REQUIRE(Check(final, test));
}

TEST_CASE("LeftDiag 1", "[LeftDiag]") {
  std::vector<std::vector<char>> puzzle{{'y', 'e', 'a', 'o', 'h'},
                                        {'e', 'e', 'o', 'e', 'o'},
                                        {'t', 'a', 'l', 'o', 'm'},
                                        {'l', 'l', 't', 'a', 'u'},
                                        {'o', 'e', 't', 'o', 'u'}};
  WordLocation test = {
      "hello",
      {{'h', 0, 4}, {'e', 1, 3}, {'l', 2, 2}, {'l', 3, 1}, {'o', 4, 0}}};
  WordSearchSolver wss(puzzle);
  WordLocation final = wss.FindWord("hello");
  WordLocation empty = {};
  WordLocation other_final = wss.FindWord("hello", CheckDirection::kLeftDiag);
  REQUIRE(Check(other_final, test));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kHorizontal)));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kVertical)));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kRightDiag)));
  REQUIRE(Check(final, test));
}
TEST_CASE("RightDiag 1", "[RightDiag]") {
  std::vector<std::vector<char>> puzzle{{'h', 'e', 'a', 'o', 't'},
                                        {'e', 'e', 'o', 'e', 'o'},
                                        {'t', 'a', 'l', 'o', 'm'},
                                        {'l', 'u', 't', 'l', 'u'},
                                        {'o', 'e', 't', 'o', 'o'}};
  WordLocation test = {
      "hello",
      {{'h', 0, 0}, {'e', 1, 1}, {'l', 2, 2}, {'l', 3, 3}, {'o', 4, 4}}};
  WordSearchSolver wss(puzzle);
  WordLocation final = wss.FindWord("hello");
  WordLocation empty = {};
  WordLocation other_final = wss.FindWord("hello", CheckDirection::kRightDiag);
  REQUIRE(Check(other_final, test));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kHorizontal)));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kVertical)));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kLeftDiag)));
  REQUIRE(Check(final, test));
}
TEST_CASE("Empty", "[Empty]") {
  std::vector<std::vector<char>> puzzle{{'h', 'e', 'a', 'o', 't'},
                                        {'e', 'e', 'o', 'e', 'o'},
                                        {'t', 'a', 'p', 'o', 'm'},
                                        {'l', 'u', 't', 'l', 'u'},
                                        {'o', 'e', 't', 'o', 't'}};
  WordLocation test = {};
  WordSearchSolver wss(puzzle);
  WordLocation final = wss.FindWord("hello");
  WordLocation empty = {};
  WordLocation other_final = wss.FindWord("hello", CheckDirection::kRightDiag);
  REQUIRE(Check(other_final, test));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kHorizontal)));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kVertical)));
  REQUIRE(Check(empty, wss.FindWord("hello", CheckDirection::kLeftDiag)));
  REQUIRE(Check(final, test));
}
/////////////////////////////////////////////////////////////////////////////////////////////