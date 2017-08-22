/*
  Program to test different grading schemes with different ways
  of handling students who have not completed all the hw tasks.
*/
#include <vector>
#include <fstream>
#include <iostream>
#include "../chapter_4/grade.h"
#include "../chapter_4/classify.h"
#include "../chapter_4/Student_info.h"

using namespace std;

int main() 
{
  vector<Student_info> did;
  ifstream infile("students.txt");

  // read in students to did/didnt do all hw vectors
  Student_info s;
  while(read(infile, s)) {
    did.push_back(s);
  }

  // extract students that did not do all hw
  vector<Student_info> didnt = classify(did, did_all_hw);

  // verify that the analyses will show us something
  if(did.empty()) {
    cout << "No s tudents did all the homework." << endl;
    return 1;
  }
  if(didnt.empty()) {
    cout << "All students did all the homework." << endl;
    return 1;
  }

  // write the analysis of three grading schemes to the console
  write_analysis(cout, "median", grade_aux, did, didnt);
  write_analysis(cout, "average", average_grade, did, didnt);
  write_analysis(cout, "optimistic_median", optimistic_median, did, didnt);

  return 0;
}

// did_all_hw - in grade
// write_analysis(cout, "median", median_analysis, did, didnt); - in grade
// median_analysis - in grade
// grade_aux. - in grade