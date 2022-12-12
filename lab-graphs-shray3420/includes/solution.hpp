#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

class Solution {
public:
  Solution(
      const std::vector<std::pair<std::string, std::string>>& prerequisites);
  int Solve(const std::string& start, const std::string& dest);

  // provided public functions
  void AddVertex(const std::string& vertex);
  friend std::ostream& operator<<(std::ostream& os, const Solution& sol);

private:
  // provided private functions
  bool VertexInGraph(const std::string vertex);
  std::list<std::string>& GetAdjacencyList(const std::string& vertex);
  // data members
  std::map<std::string, std::list<std::string>> adj_;
};

// std::ostream& operator<<(std::ostream& os, const Solution& sol);

#endif
