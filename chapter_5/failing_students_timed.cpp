#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <ctime>

#include "../chapter_4/Student_info.h"

using namespace std;

int main() {

  ifstream infile("1000_students.txt");

// Ammend this * * * * * * * * * * * * * * * * * *
  //typedef list<Student_info> student_container; 
  typedef vector<Student_info> student_container;
// * * * * * * * * * * * * * * * * * * * * * * * * 

    // Fist initilise a student_container
  student_container students;
  Student_info record;

  cout << "Reading in students from file." << endl;

  // read and store all of the students' data.
  while(read(infile, record)){
    students.push_back(record);
  }

  cout << "Done." << endl;

  cout << "Extracting fails." << endl;
  clock_t start = clock();
  student_container failiures = extract_fails(students);
  clock_t elapsed = clock() - start;
  cout << "Done." << endl;

  cout << "Elapsed: " << elapsed << endl;

  cout << "Number of fails: " << failiures.size() << endl;
  cout << "Number of successes: " << students.size() << endl;

  return 0;
}