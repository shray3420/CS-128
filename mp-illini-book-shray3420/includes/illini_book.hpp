#ifndef ILLINI_BOOK_HPP
#define ILLINI_BOOK_HPP

#include <map>
#include <string>
#include <vector>

class IlliniBook {
public:
  IlliniBook(const std::string& people_fpath,
             const std::string& relations_fpath);
  IlliniBook(const IlliniBook& rhs) = delete;
  IlliniBook& operator=(const IlliniBook& rhs) = delete;
  ~IlliniBook() = default;

  bool AreRelated(int uin_1, int uin_2) const;
  bool AreRelated(int uin_1, int uin_2, const std::string& relationship) const;

  int GetRelated(int uin_1, int uin_2) const;
  int GetRelated(int uin_1, int uin_2, const std::string& relationship) const;

  std::vector<int> GetSteps(int uin, int n) const;

  size_t CountGroups() const;
  size_t CountGroups(const std::string& relationship) const;
  size_t CountGroups(const std::vector<std::string>& relationships) const;
  bool UinInGraph(int uin) const;

  int Find(const std::vector<int>& n, int uin) const;
  bool Found(const std::vector<int>& been_to, const int& uin) const;

private:
  std::map<std::pair<int, int>, std::string> edges_;
  std::map<int, std::vector<int>> adj_list_;
};

#endif
