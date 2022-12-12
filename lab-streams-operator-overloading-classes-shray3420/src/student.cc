
#include "student.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "course.hpp"

Student::Student(std::string name, std::string uin, std::string net_id):
    name_(name), uin_(uin), net_id_(net_id) {
  major_ = "Undeclared";
  graduated_ = false;
}
Student::Student(std::string name,
                 std::string uin,
                 std::string net_id,
                 std::string major,
                 std::vector<Course> courses,
                 bool graduated) {
  name_ = name;
  uin_ = uin;
  net_id_ = net_id;
  major_ = major;
  courses_ = courses;
  graduated_ = graduated;
}
std::string Student::GetName() const { return name_; }
std::string Student::GetUIN() const { return uin_; }
std::string Student::GetNetId() const { return net_id_; }
std::string Student::GetMajor() const { return major_; }
bool Student::HasGraduated() const { return graduated_; }
const std::vector<Course>& Student::GetCourses() const { return courses_; }
void Student::SetName(std::string name) { name_ = name; }
void Student::SetMajor(std::string major) { major_ = major; }
bool Student::AddCourse(Course c) {
  bool var = true;
  for (unsigned long i = 0; i < courses_.size(); i++) {
    if (courses_.at(i).name == c.name) {
      var = false;
    }
  }
  if (var) {
    courses_.push_back(c);
  }
  return var;
}
std::string Student::GetCredit() const {
  int total = 0;
  for (unsigned long i = 0; i < courses_.size(); i++) {
    total += courses_.at(i).credits;
  }
  return std::to_string(total);
}
std::string Student::GetGraduate() const {
  if (graduated_) {
    return "True";
  }
  return "False";
}
std::string Student::CourseToString() const {
  std::string courses_string;
  for (unsigned long i = 0; i < courses_.size(); i++) {
    if (i == courses_.size() - 1) {
      courses_string.append(courses_.at(i).name);
    } else {
      courses_string.append(courses_.at(i).name + ", ");
    }
  }
  return courses_string;
}

void Student::Graduate() {
  int total = 0;
  for (unsigned long i = 0; i < courses_.size(); i++) {
    total += courses_.at(i).credits;
  }
  if (total >= min_credits_grad_) {
    graduated_ = true;
  }
}
std::ostream& operator<<(std::ostream& os, const Student& s) {
  os << "Name: " + s.GetName() << '\n';
  os << "UIN: " + s.GetUIN() << '\n';
  os << "Net Id: " + s.GetNetId() << '\n';
  os << "Major: " + s.GetMajor() << '\n';
  os << "Credits: " + s.GetCredit() << '\n';
  os << "Courses: " + s.CourseToString() << '\n';
  os << "Graduated: " + s.GetGraduate();
  return os;
}
