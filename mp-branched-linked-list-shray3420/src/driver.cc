#include <iostream>

#include "branched-linked-list.hpp"

int main() {
  /* EXAMPLE INTERACTIONS WITH BLL */
  BLL* first = new BLL();
  first->PushBack('0');
  first->PushBack('1');

  // first->SetAt(1, 'g');
  BLL* second = new BLL();
  second->PushBack('2');

  first->Join(1, second);

  BLL* third = new BLL();

  third->PushBack('3');
  second->Join(0, third);
  // third->Join(0, second);

  std::cout << "First String: " << first->ToString() << std::endl;  // hii!@
  std::cout << "First Size: " << first->Size() << std::endl;

  delete first;
  // delete second;
  // delete third;

  return 0;
}
