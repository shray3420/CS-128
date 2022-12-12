#include "illini_book.hpp"

#include <fstream>
#include <queue>

#include "utilities.hpp"

// Your code here!
IlliniBook::IlliniBook(const std::string& people_fpath,
                       const std::string& relations_fpath) {
  std::ifstream people(people_fpath);
  std::ifstream relation(relations_fpath);

  if (!people.is_open()) throw std::runtime_error("people");
  int num = 0;
  while (people.good()) {
    people >> num;
    adj_list_.insert(std::pair<int, std::vector<int>>(num, std::vector<int>()));
  }
  people.close();
  if (!relation.is_open()) throw std::runtime_error("relation");
  for (std::string line; std::getline(relation, line); line = "") {
    std::vector<std::string> str = utilities::Split(line, ',');
    int uin_1 = std::stoi(str.at(0));
    int uin_2 = std::stoi(str.at(1));
    std::string r = str.at(2);
    adj_list_.at(uin_1).push_back(uin_2);
    adj_list_.at(uin_2).push_back(uin_1);
    edges_.insert(
        std::pair<std::pair<int, int>, std::string>({uin_1, uin_2}, r));
    edges_.insert(
        std::pair<std::pair<int, int>, std::string>({uin_2, uin_1}, r));
  }
}

bool IlliniBook::AreRelated(int uin_1, int uin_2) const {
  return GetRelated(uin_1, uin_2) != -1;
}

bool IlliniBook::AreRelated(int uin_1,
                            int uin_2,
                            const std::string& relationship) const {
  return GetRelated(uin_1, uin_2, relationship) != -1;
}

int IlliniBook::GetRelated(int uin_1, int uin_2) const {
  std::map<int, int> distance;
  std::vector<int> been_to;
  std::queue<int> next_vertex;

  if (!UinInGraph(uin_1) || !UinInGraph(uin_2)) return -1;
  distance.insert({uin_1, 0});
  been_to.push_back(uin_1);
  next_vertex.push(uin_1);
  while (!next_vertex.empty()) {
    int vertex = next_vertex.front();
    next_vertex.pop();
    if (!UinInGraph(vertex)) return -1;
    if (vertex == uin_2) return distance.at(vertex);

    for (const int& vert : adj_list_.at(vertex)) {
      bool found = Found(been_to, vert);
      if (!found) {
        been_to.push_back(vert);
        distance.insert({vert, distance.at(vertex) + 1});
        next_vertex.push(vert);
      }
    }
  }
  return -1;
}

int IlliniBook::GetRelated(int uin_1,
                           int uin_2,
                           const std::string& relationship) const {
  std::map<int, int> distance;
  std::map<int, int> map;
  std::vector<int> been_to;
  std::queue<int> next_vertex;

  for (const auto& v : adj_list_) {
    distance.insert({v.first, 0});
    map.insert({v.first, 0});
  }

  if (!UinInGraph(uin_1) || !UinInGraph(uin_2)) return -1;
  map.at(uin_1) = -1;
  been_to.push_back(uin_1);
  next_vertex.push(uin_1);
  while (!next_vertex.empty()) {
    int vertex = next_vertex.front();
    next_vertex.pop();
    if (!UinInGraph(vertex)) return -1;
    if (vertex == uin_2) return distance.at(vertex);

    for (const int& vert : adj_list_.at(vertex)) {
      bool found = Found(been_to, vert);
      if (!found && edges_.at({vert, vertex}) == relationship) {
        been_to.push_back(vert);
        distance.at(vert) = distance.at(vertex) + 1;
        map.at(vert) = vertex;
        next_vertex.push(vert);
      }
    }
  }
  return -1;
}

std::vector<int> IlliniBook::GetSteps(int uin, int n) const {
  std::map<int, int> distance;
  std::vector<int> been_to;
  std::queue<int> next_vertex;
  std::vector<int> vector;
  distance.insert({uin, 0});
  been_to.push_back(uin);
  next_vertex.push(uin);
  while (!next_vertex.empty()) {
    int vertex = next_vertex.front();
    next_vertex.pop();

    for (const int& vert : adj_list_.at(vertex)) {
      bool found = Found(been_to, vert);

      if (!found) {
        been_to.push_back(vert);
        distance.insert({vert, distance.at(vertex) + 1});
        next_vertex.push(vert);
      }
    }
  }

  for (const auto& i : distance) {
    if (i.second == n) vector.push_back(i.first);
  }
  return vector;
}

size_t IlliniBook::CountGroups() const {
  std::vector<int> not_visited;
  std::queue<int> next_vertex;

  for (const auto& v : adj_list_) {
    not_visited.push_back(v.first);
  }
  int count = 0;
  auto index = not_visited.begin();
  while (!not_visited.empty()) {
    next_vertex.push(not_visited.at(0));
    not_visited.erase(index);
    while (!next_vertex.empty()) {
      int vertex = next_vertex.front();
      next_vertex.pop();
      for (const int& vert : adj_list_.at(vertex)) {
        int num = Find(not_visited, vert);
        if (num != -1) {
          not_visited.erase(index + num);
          next_vertex.push(vert);
        }
      }
    }
    count++;
  }
  return count;
}

int IlliniBook::Find(const std::vector<int>& n, int uin) const {
  int num = 0;
  for (int i : n) {
    if (i == uin) return num;
    num++;
  }
  return -1;
}

size_t IlliniBook::CountGroups(const std::string& relationship) const {
  std::vector<int> not_visited;
  std::queue<int> next_vertex;

  for (const auto& v : adj_list_) {
    not_visited.push_back(v.first);
  }
  int count = 0;
  auto index = not_visited.begin();
  while (!not_visited.empty()) {
    next_vertex.push(not_visited.at(0));
    not_visited.erase(index);
    while (!next_vertex.empty()) {
      int vertex = next_vertex.front();
      next_vertex.pop();
      for (const int& vert : adj_list_.at(vertex)) {
        int num = Find(not_visited, vert);
        if (num != -1 && edges_.at({vert, vertex}) == relationship) {
          not_visited.erase(index + num);
          next_vertex.push(vert);
        }
      }
    }
    count++;
  }
  return count;
}

size_t IlliniBook::CountGroups(
    const std::vector<std::string>& relationships) const {
  std::vector<int> not_visited;
  std::queue<int> next_vertex;
  bool found = false;
  for (const auto& v : adj_list_) {
    not_visited.push_back(v.first);
  }
  int count = 0;
  auto index = not_visited.begin();
  while (!not_visited.empty()) {
    next_vertex.push(not_visited.at(0));
    not_visited.erase(index);
    while (!next_vertex.empty()) {
      int vertex = next_vertex.front();
      next_vertex.pop();
      for (const int& vert : adj_list_.at(vertex)) {
        found = false;
        for (const std::string& str : relationships) {
          if (str == edges_.at({vert, vertex})) {
            found = true;
            break;
          }
        }
        int num = Find(not_visited, vert);
        if (num != -1 && found) {
          not_visited.erase(index + num);
          next_vertex.push(vert);
        }
      }
    }
    count++;
  }
  return count;
}

bool IlliniBook::UinInGraph(int uin) const {
  for (const auto& v : adj_list_) {
    if (v.first == uin) return true;
  }
  return false;
}

bool IlliniBook::Found(const std::vector<int>& been_to, const int& uin) const {
  for (const int& seen : been_to) {
    if (seen == uin) {
      return true;
    }
  }
  return false;
}