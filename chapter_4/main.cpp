#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>

#include "Student_info.h"
#include "grade.h"

using namespace std;


bool grade_compare(const Student_info& x, const Student_info& y) 
{
  return grade(x) < grade(y);
}

int main() 
{

  ifstream infile("students.txt");
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0; // length of longest name

  // read and store all of the students' data.
  while(read(infile, record)){
    students.push_back(record);
    maxlen = max(record.name.size(), maxlen);
  }

  // sort the students alphabetically
  sort(students.begin(), students.end(), grade_compare);

  map<char, vector<Student_info> > student_map = 
    students_by_grade(students);

  for(map<char, vector<Student_info> >::const_iterator i =
      student_map.begin(); i != student_map.end(); ++i) {

    cout << "Grade " << i->first << ":" << endl;

    display_students(i->second);

  }

  cout << endl; // new line to seperate input from output 
  return 0;
}