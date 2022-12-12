#include "student.hpp"

int main() {
  Course c1 = {"One", 3};
  Course c2 = {"Two", 3};
  std::vector<Course> vect = {c1, c2};
  Student s("name", "000000", "ike", "CS", vect, false);
  std::cout << s << std::endl;
  return 0;
}
