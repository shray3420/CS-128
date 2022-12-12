#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include <catch/catch.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "sandwich.hpp"

using std::string;
using std::vector;

// A helper method for you to visualize what the contents of a vector are. You
// are welcome to modify this method or create additional helper methods.
//
// Example usage:
//  vector<string> my_vec;
//  my_vec.push_back("hello");
//  my_vec.push_back("world"):
//  PrintVector(my_vec);
// Prints:
//  [hello, world]
void PrintVector(const vector<string>& vec) {
  std::cout << "[";
  bool first = true;
  for (const auto& it : vec) {
    if (!first) {
      std::cout << ", ";
    } else {
      first = false;
    }

    std::cout << it;
  }

  std::cout << "]" << std::endl;
}

TEST_CASE("Sandwich::AddTopping test", "[AddTopping]") {
  // your tests for Sandwich::AddTopping here
  Sandwich sandwich1;
  sandwich1.Sandwich::AddTopping("cheese");
  REQUIRE_FALSE(sandwich1.Sandwich::AddTopping("cheese"));
}

TEST_CASE("Sandwich::RemoveTopping test", "[RemoveTopping]") {
  // your tests for Sandwich::RemoveTopping here
  SECTION("Topping not present") {
    Sandwich sandwich2;
    REQUIRE_FALSE(sandwich2.Sandwich::RemoveTopping("tomato"));
  }
  SECTION("Removing a topping after dressing is added") {
    Sandwich sandwich3;
    sandwich3.Sandwich::AddTopping("cheese");
    sandwich3.Sandwich::AddDressing("mayo");
    REQUIRE_FALSE(sandwich3.Sandwich::RemoveTopping("cheese"));
  }
}

TEST_CASE("Sandwich::AddDressing test", "[AddDressing]") {
  // your tests for Sandwich::AddDressing here
  SECTION("Duplicate Dressings") {
    Sandwich sandwich4;
    sandwich4.Sandwich::AddTopping("cheese");
    sandwich4.Sandwich::AddDressing("mayo");
    REQUIRE_FALSE(sandwich4.Sandwich::AddDressing("mayo"));
  }
  SECTION("Adding without topping") {
    Sandwich sandwich5;
    REQUIRE_FALSE(sandwich5.Sandwich::AddDressing("mayo"));
  }
}
