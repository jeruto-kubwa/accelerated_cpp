#include <stdexcept>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include "grade.h"

using namespace std;

bool compare(const Student_info& x, const Student_info& y) {
  return x.name < y.name;
}

istream& read(istream& is, Student_info& s) {
  // read and store the student's name and midterm and final grades
  double midterm;
  double final;
  vector<double> homework;
 
  is >> s.name >> midterm >> final;

  read_hw(is, homework);
  
  try {
    s.overall_grade = grade(midterm, final, homework); 
  } catch(domain_error e) {
    s.overall_grade = -1;
  }

  return is;
}

// read a sequence of doubles from input stream to vector<double>
istream& read_hw(istream& in, vector<double>& hw) {
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
void display_students(const vector<Student_info>& students) {
    // print out the data
    for(vector<Student_info>::size_type i=0; i<students.size(); ++i) {
      
      // bad code:: int 20 should be max length of the students names
      cout << students[i].name << string(20 - students[i].name.size(), ' ');

      streamsize prec = cout.precision();
      cout << setprecision(3) << students[i].overall_grade << setprecision(prec);
        
      cout << endl;
    }
}

// print students' names and overall grades to std output
void display_students(const list<Student_info>& students) {
    // print out the data
    for(list<Student_info>::const_iterator iter = students.begin(); 
         iter!=students.end(); ++iter) {
      
      // bad code:: int 20 should be max length of the students names
      // N.B. (*iter).name is equivalent to iter->name
      cout << iter->name << string(20 - (iter->name).size(), ' ');

      streamsize prec = cout.precision();
      cout << setprecision(3) << iter->overall_grade << setprecision(prec);
        
      cout << endl;
    }
}


// // extract the failing students from a vector<Student_info> of students
vector<Student_info> extract_fails(vector<Student_info>& students) {
  vector<Student_info> fail;
  vector<Student_info>::iterator iter = students.begin();
  
  while(iter != students.end()){
    if(fgrade(*iter)) {
      fail.push_back(*iter);
      // erase returns an iterator that is positioned on 
      // the element that follows the one that we just erased 
      iter = students.erase(iter); 
    } else {
      ++iter;
    }
  }
  return fail;
}

// lists are optimized for fast insertion and deletion anywhere 
// within the container. This method is faster for large inputs.
list<Student_info> extract_fails(list<Student_info>& students) {
  list<Student_info> fail;
  list<Student_info>::iterator iter = students.begin();
  
  while(iter != students.end()){
    if(fgrade(*iter)) {
      fail.push_back(*iter);
      // erase returns an iterator that is positioned on 
      // the element that follows the one that we just erased 
      iter = students.erase(iter); 
    } else {
      ++iter;
    }
  }
  return fail;
}



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

