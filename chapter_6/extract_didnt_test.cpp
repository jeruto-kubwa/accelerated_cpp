#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>

#include "../chapter_4/Student_info.h"

using namespace std;

int main() {

  ifstream infile("10000_students.txt");

  typedef vector<Student_info> student_container;

    // Fist initilise a student_container
  student_container students;
  Student_info record;

  cout << "Reading in students from file." << endl;

  // read and store all of the students' data.
  while(read(infile, record)){
    students.push_back(record);
  }

  cout << "number of students: " << students.size() << endl;

  cout << "Done." << endl;

  cout << "Extracting didnts." << endl;
  clock_t start = clock();
  student_container didnt = extract_didnt(students);
  clock_t elapsed = clock() - start;
  cout << "Done." << endl;

  cout << "Elapsed: " << elapsed << endl;

  cout << "Number of students that did not do all hw: " << didnt.size() << endl;
  cout << "Number of students that did all hw: " << students.size() << endl;

  return 0;
}