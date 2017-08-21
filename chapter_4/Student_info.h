#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <iostream> 
#include <string>
#include <vector>
#include <list>

// struct Student_info {
//   std::string name; // Do not use using -declarations in header files
//   double overall_grade;
// };

struct Student_info { 
  std::string name;
  double midterm, final;
  std::vector<double> homework;
}; 

bool compare(const Student_info&, const Student_info&); // const Student_info& is a reference without intent to change the value
std::istream& read(std::istream&, Student_info&); // Student_info& is a reference with intent to change value
std::istream& read_hw(std::istream&, std::vector<double>&);
void display_students(const std::vector<Student_info>&); // Print all students names and scores to std out
void display_students(const std::list<Student_info>&); // Print all students names and scores to std out
std::vector<Student_info> extract_fails(std::vector<Student_info>&);
std::list<Student_info> extract_fails(std::list<Student_info>&);
std::vector<Student_info> extract_didnt(std::vector<Student_info>& students);

#endif 
