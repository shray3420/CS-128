#ifndef DNA_STRAND_HPP
#define DNA_STRAND_HPP

#include "node.hpp"

class DNAstrand {
public:
  DNAstrand() = default;
  DNAstrand(const DNAstrand& rhs) = delete;
  DNAstrand& operator=(const DNAstrand& rhs) = delete;
  ~DNAstrand();
  void Pushback(Node* n);
  Node* GetHead() { return head_; }
  void SpliceIn(const char* pattern, DNAstrand& to_splice_in);
  unsigned int Size(const char* str);
  unsigned int Size(DNAstrand& str);
  int DoesPatternExist(const char* pattern, const char* list);
  void DeleteNode(unsigned int index);
  void CombineStrands(DNAstrand& dna,
                      DNAstrand& to_splice_in,
                      unsigned int index);

private:
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

#endif