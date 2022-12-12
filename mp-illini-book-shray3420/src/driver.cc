#include <iostream>

#include "illini_book.hpp"

int main() {
  IlliniBook test(
      "/home/vagrant/src/mp-illini-book-shray3420/example/persons.csv",
      "/home/vagrant/src/mp-illini-book-shray3420/example/relations.csv");

  std::cout << test.AreRelated(8, 7);    // t
  std::cout << test.AreRelated(15, 13);  // t
  std::cout << test.AreRelated(15, 6);   // f
  std::cout << '\n';
  std::cout << test.AreRelated(1, 2, "128");  // t
  std::cout << test.AreRelated(1, 2, "124");  // f
  std::cout << test.AreRelated(1, 6, "128");  // t
  std::cout << test.AreRelated(1, 6, "124");  // t
  std::cout << '\n';
  std::cout << test.GetRelated(1, 2) << '\n';  // 1
  std::cout << test.GetRelated(3, 2) << '\n';  // 2
  std::cout << test.GetRelated(1, 9) << '\n';  // -1
  std::cout << '\n';
  std::cout << test.GetRelated(1, 2, "128") << '\n';  // 1
  std::cout << test.GetRelated(1, 2, "124") << '\n';  // -1
  std::cout << test.GetRelated(1, 6, "128") << '\n';  // 2
  std::cout << test.GetRelated(1, 6, "124") << '\n';  // 1
  std::cout << '\n';
  std::cout << "steps: " << '\n';
  std::vector<int> t = test.GetSteps(1, 1);
  for (int i : t) {
    std::cout << i;
  }
  std::cout << '\n';

  t = test.GetSteps(1, 2);
  for (int i : t) {
    std::cout << i;
  }
  std::cout << '\n';

  t = test.GetSteps(1, 3);
  for (int i : t) {
    std::cout << i;
  }
  std::cout << '\n';

  t = test.GetSteps(7, 4);
  for (int i : t) {
    std::cout << i;
  }
  std::cout << '\n';

  std::cout << test.CountGroups(std::vector<std::string>{"128", "124", "173"})
            << '\n';  // 3

  return 0;
}