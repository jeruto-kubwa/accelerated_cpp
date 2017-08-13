#include "../chapter_4/Student_info.h"
#include <vector>

using namespace std;

int main() {

  // Fist initilise a vector<Student_info>
  vector<Student_info> students;
  Student_info record;

  cout << "Please enter some students adn their scores each on a new line. The information" 
       << " will be stored in a vector<Student_info> of students." << endl;

  // read and store all of the students' data.
  while(read(cin, record)){
    students.push_back(record);
  }

  cout << "Displaying student names and scores:" << endl;

  display_students(students);

  vector<Student_info> failiures = extract_fails(students);

  cout << "These are the failures:" << endl;

  display_students(failiures);

  cout << "These are the remaining students:" << endl;

  display_students(students);

  return 0;
}