#include "../chapter_4/Student_info.h"
#include <vector>

using namespace std;

int main() {

  // Fist initilise a vector<Student_info>
  vector<Student_info> students;
  Student_info record;

  cout << "Please enter some students each on a new line. The information" 
       << "will be stored in a vector<Student_info> od stuents." << endl;

  // read and store all of the students' data.
  while(read(cin, record)){
    students.push_back(record);
  }

  cout << "Printing out names of students:" << endl;

  for(vector<Student_info>::const_iterator iter = students.begin();
      iter != students.end(); ++iter) {
    cout << iter->name << endl;
  }

  return 0;
}