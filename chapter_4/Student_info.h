#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream> 
#include <string>
#include <vector>
#include <list>

struct Student_info {
  std::string name; // Do not use using -declarations in header files
  double overall_grade;
};

bool compare(const Student_info&, const Student_info&); // const Student_info& is a reference without intent to change the value
std::istream& read(std::istream&, Student_info&); // Student_info& is a reference with intent to change value
std::istream& read_hw(std::istream&, std::vector<double>&);
void display_students(const std::vector<Student_info>&); // Print all students names and scores to std out
void display_students(const std::list<Student_info>&); // Print all students names and scores to std out
std::vector<Student_info> extract_fails(std::vector<Student_info>&);
std::list<Student_info> extract_fails(std::list<Student_info>&);

#endif 