#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <vector>
class Room {
public:
  Room();
  Room(std::string room_name);
  std::string GetName() const;
  const std::vector<std::string>& GetPeople() const;
  virtual void AddPerson(std::string name);
  virtual void RemovePerson(std::string name);

private:
  std::string name_;

protected:
  std::vector<std::string> people_;
  virtual bool CanAddPerson() const = 0;
};
#endif  // ROOM_HPP