#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "course.hpp"

class Student {
public:
  Student(std::string name, std::string uin, std::string net_id);
  Student(std::string name,
          std::string uin,
          std::string net_id,
          std::string major,
          std::vector<Course> courses,
          bool graduated);
  std::string GetName() const;
  std::string GetUIN() const;
  std::string GetNetId() const;
  std::string GetMajor() const;
  bool HasGraduated() const;
  const std::vector<Course>& GetCourses() const;
  void SetName(std::string name);
  void SetMajor(std::string major);
  bool AddCourse(Course c);
  void Graduate();
  friend std::ostream& operator<<(std::ostream& os, const Student& s);
  std::string GetCredit() const;
  std::string GetGraduate() const;
  std::string CourseToString() const;

private:
  std::string name_;
  std::string uin_;
  std::string net_id_;
  std::string major_;
  bool graduated_;
  std::vector<Course> courses_;
  static const int min_credits_grad_ = 120;
};
#endif