#include "news_agent.hpp"

// no need to modify this function
NewsAgent::NewsAgent(): location_(nullptr) {}

// no need to modify this function
void NewsAgent::ChangeLocation(Location* loc) {
  if (location_) {
    location_->RemoveAgent(this);
  }

  location_ = loc;

  if (location_) {
    location_->AddAgent(this);
  }
}

void NewsAgent::AddNewsChannelClient(NewsChannel* client) {
  // TODO : implement
  channels_.push_back(client);
}

void NewsAgent::RemoveNewsChannelClient(NewsChannel* client) {
  // TODO : implement

  std::vector<NewsChannel*> vector;
  for (const auto& i : channels_) {
    if (i != client) {
      vector.push_back(i);
    }
  }
  channels_ = vector;
}

void NewsAgent::NotifyNews(std::string date,
                           std::string subject,
                           std::string action) {
  News news{location_->GetName(), date, subject, action};

  // TODO : implement
  for (const auto& i : channels_) {
    i->NotifyNews(news);
  }
}