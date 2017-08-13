#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iostream>
#include <iomanip>
#include "Student_info.h"
#include "grade.h"

using std::string;        using std::vector;
using std::cin;           using std::cout;
using std::endl;          using std::domain_error;
using std::setprecision;  using std::streamsize;
using std::max;


int main() {
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0; // length of longest name

  // read and store all of the students' data.
  while(read(cin, record)){
    students.push_back(record);
    maxlen = max(record.name.size(), maxlen);
  }

  // sort the students alphabetically
  sort(students.begin(), students.end(), compare);

  cout << endl; // new line to seperate input from output 

  // print students' names and overall grades to std output
  display_students(students); 

  return 0;
}