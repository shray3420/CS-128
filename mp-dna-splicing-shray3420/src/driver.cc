#include <iostream>

#include "dna_strand.hpp"

void PrintList(DNAstrand& s) {
  Node* n = s.GetHead();
  while (n != nullptr) {
    std::cout << n->data << " ";
    n = n->next;
  }
}

int main() {
  DNAstrand test;
  DNAstrand t;
  t.Pushback(new Node('0'));
  t.Pushback(new Node('0'));
  t.Pushback(new Node('0'));
  t.Pushback(new Node('0'));
  test.Pushback(new Node('c'));
  test.Pushback(new Node('t'));
  test.Pushback(new Node('g'));
  test.Pushback(new Node('a'));
  test.Pushback(new Node('a'));
  test.Pushback(new Node('t'));
  test.Pushback(new Node('t'));
  test.Pushback(new Node('c'));
  test.Pushback(new Node('g'));

  PrintList(test);
  std::cout << '\n';
  PrintList(t);
  std::cout << '\n';

  test.SpliceIn("ctga", t);

  PrintList(test);
  std::cout << '\n';

  return 0;
}