#include <list>
#include "../chapter_4/Student_info.h"

using namespace std;

int main() {

  // Fist initilise a list<Student_info>
  list<Student_info> students;
  Student_info record;

  cout << "Please enter some students each on a new line. The information" 
       << "will be stored in a list<Student_info> od stuents." << endl;

  // read and store all of the students' data.
  while(read(cin, record)){
    students.push_back(record);
  }

  cout << "Displaying student names and scores:" << endl;
  display_students(students);

  list<Student_info> failiures = extract_fails(students);

  cout << "These are the failures:" << endl;
  display_students(failiures);

  cout << "These are the remaining students:" << endl;
  display_students(students);

  return 0;
}