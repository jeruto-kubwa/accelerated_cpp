#include <stdexcept>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "grade.h"

using namespace std;

bool compare(const Student_info& x, const Student_info& y) 
{
  return x.name < y.name;
}

istream& read(istream& is, Student_info& s) {
  // read and store the student's name and midterm and final grades
  is >> s.name >> s.midterm >> s.final;

  read_hw(is, s.homework);
  
  return is;
}

// read a sequence of doubles from input stream to vector<double>
istream& read_hw(istream& in, vector<double>& hw) 
{
  if(in) {
    // clear any existing contents of the hw vector 
    hw.clear();

    double x;
    while(in >> x) // read elements from input stream
      hw.push_back(x);

    // clear the stream so that input will work for the next student
    in.clear(); 
  }
  return in;
}

// print students' names and overall grades to std output
void display_students(const vector<Student_info>& students) 
{
    // print out the data
    for(vector<Student_info>::size_type i=0; i<students.size(); ++i) {
      
      // bad code:: int 20 should be max length of the students names
      cout << students[i].name << string(20 - students[i].name.size(), ' ');

      try {
        double final_grade = grade(students[i]); 
        streamsize prec = cout.precision();
        cout << setprecision(3) << final_grade << setprecision(prec); 
      } catch (domain_error e) {
        cout << e.what();
      }
  
      cout << endl;
    }
}

// print students' names and overall grades to std output
void display_students(const list<Student_info>& students) 
{
    // print out the data
    for(list<Student_info>::const_iterator i=students.begin();
        i != students.end(); ++i) {
      
      // bad code:: int 20 should be max length of the students names
      cout << i->name << string(20 - i->name.size(), ' ');

      try {
        double final_grade = grade(*i); 
        streamsize prec = cout.precision();
        cout << setprecision(3) << final_grade << setprecision(prec); 
      } catch (domain_error e) {
        cout << e.what();
      }
  
      cout << endl;
    }
}


// // extract the failing students from a vector<Student_info> of students
// vector<Student_info> extract_fails(vector<Student_info>& students) {
//   vector<Student_info> fail;
//   vector<Student_info>::iterator iter = students.begin();
  
//   while(iter != students.end()){
//     if(fgrade(*iter)) {
//       fail.push_back(*iter);
//       // erase returns an iterator that is positioned on 
//       // the element that follows the one that we just erased 
//       iter = students.erase(iter); 
//     } else {
//       ++iter;
//     }
//   }
//   return fail;
// }

// lists are optimized for fast insertion and deletion anywhere 
// within the container. This method is faster for large inputs.
// list<Student_info> extract_fails(list<Student_info>& students) {
//   list<Student_info> fail;
//   list<Student_info>::iterator iter = students.begin();
  
//   while(iter != students.end()){
//     if(fgrade(*iter)) {
//       fail.push_back(*iter);
//       // erase returns an iterator that is positioned on 
//       // the element that follows the one that we just erased 
//       iter = students.erase(iter); 
//     } else {
//       ++iter;
//     }
//   }
//   return fail;
// }



// Below commented out are the two methods required to answer q5.6.
// Use failing_students_timed to test the performance of each.
// The method that adds students to the begining and then resizes is slower.

/*
vector<Student_info> extract_fails(vector<Student_info>& students) {
  vector<Student_info> fail;
  vector<Student_info>::size_type i = 0;
// invariant:elements [0, i) of students represent passing grades 
  while (i != students.size()) {
    if (fgrade(students[i])) {
      fail.push_back(students[i]);
      students.erase(students.begin() + i);
    } else ++i;
  }
  return fail;
}

vector<Student_info> extract_fails(vector<Student_info>& students) {
  vector<Student_info> fail;
  vector<Student_info>::size_type i = 0;
  vector<Student_info>::size_type initial_size = students.size();
// invariant:elements [0, i) of students represent passing grades 
  while (i != students.size()) {
    if (fgrade(students[i])) {
      fail.push_back(students[i]);
    } else {
      students.insert(students.begin(), students[i]);
      ++i;
    }
    ++i;
  }

  students.resize(initial_size - fail.size());

  return fail;
}
*/

// Below is the version of extract fails introduced in chapter 6 
// using the algorithm library

// Two passs solution:

// vector<Student_info> extract_fails(vector<Student_info>& students) {
//   vector<Student_info> fail;
//   remove_copy_if(students.begin(), students.end(),
//                  back_inserter(fail), pgrade);
//   students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());
//   return fail;
// }


// One pass solution

vector<Student_info> extract_fails(vector<Student_info>& students) 
{
  vector<Student_info>::const_iterator iter =
    stable_partition(students.begin(), students.end(), pgrade);
  vector<Student_info> fail(iter, students.end());
  students.erase(iter, students.end());
  return fail;
}

// Extract the students that did not do all the homework exercises
vector<Student_info> extract_didnt(vector<Student_info>& students)
{
  vector<Student_info>::const_iterator iter =
    stable_partition(students.begin(), students.end(), did_all_hw);
  vector<Student_info> didnt(iter, students.end());
  students.erase(iter, students.end());
  return didnt; 
}


// Convert double grade to letter grade
char get_letter_grade(double grade)
{
  if(90 <= grade && grade <= 100)
    return 'A';
  else if(80 <= grade && grade < 90)
    return 'B';
  else if(70 <= grade && grade < 80)
    return 'C';
  else if(60 <= grade && grade < 70)
    return 'D';

  return 'F';
}

// Return a map<char, vector<student> > categrising students
// by letter grade
map<char, vector<Student_info> > 
  students_by_grade(const vector<Student_info>& students)
{
  map<char, vector<Student_info> > students_by_grade; 

  for(vector<Student_info>::const_iterator i = students.begin(); 
      i != students.end(); ++i) {

    double g = grade(*i);
    students_by_grade[get_letter_grade(g)].push_back(*i);
  }
  return students_by_grade;
}
