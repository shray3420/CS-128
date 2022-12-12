#include "solution.hpp"

#include <iostream>
#include <queue>

Solution::Solution(
    const std::vector<std::pair<std::string, std::string>>& prerequisites) {
  // TODO : implement this!
  for (const std::pair<std::string, std::string>& edges : prerequisites) {
    if (!VertexInGraph(edges.first)) {
      AddVertex(edges.first);
    }
    if (!VertexInGraph(edges.second)) {
      AddVertex(edges.second);
    }
    GetAdjacencyList(edges.first).push_back(edges.second);
  }
}

int Solution::Solve(const std::string& start, const std::string& dest) {
  // TODO : implement this!

  // Note that since this is not a node based graph (we are using adjacency
  // lists), this will probably NOT be a recursive function
    
  return -1;
}

/////////////////////////////////////////////////////////////////////////////
// Provide function definitions (uncomment to use!)                          //
/////////////////////////////////////////////////////////////////////////////

void Solution::AddVertex(const std::string& vertex) {
  if (VertexInGraph(vertex))
    throw std::runtime_error("vertex already in graph.");
  adj_.insert(std::pair(vertex, std::list<std::string>()));
}

std::list<std::string>& Solution::GetAdjacencyList(const std::string& vertex) {
  return adj_.find(vertex)->second;
}

bool Solution::VertexInGraph(const std::string vertex) {
  return adj_.find(vertex) != adj_.end();
}

std::ostream& operator<<(std::ostream& os, const Solution& sol) {
  os << "Contents:" << std::endl;

  for (const auto& pair : sol.adj_) {
    os << "  " << pair.first << ": [ ";

    for (const auto& list_entry : pair.second) {
      os << list_entry << " ";
    }

    os << "]" << std::endl;
  }

  return os;
}