#include "news_agent.hpp"

// no need to modify this function
Location::Location(std::string name): name_(name) {}

// no need to modify this function
std::string Location::GetName() const { return name_; }

void Location::AddAgent(NewsAgent* agent) {
  // TODO : implement
  agents_.push_back(agent);
}

void Location::RemoveAgent(NewsAgent* agent) {
  // TODO : implement
  std::vector<NewsAgent*> vector;
  for (const auto& i : agents_) {
    if (i != agent) {
      vector.push_back(i);
    }
  }
  agents_ = vector;
}

void Location::Event(std::string date,
                     std::string subject,
                     std::string action) {
  // TODO : implement
  for (const auto& i : agents_) {
    i->NotifyNews(date, subject, action);
  }
}
