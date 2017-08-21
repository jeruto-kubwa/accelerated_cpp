#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "average.h"
#include "Student_info.h"

using namespace std;

double grade(double midterm, double final, double homework) 
{
  return 0.2 * midterm  + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw) 
{
  if(hw.size() == 0)
      throw domain_error("Student has done no hw.");

  return grade(midterm, final, median(hw));
}

double grade(const Student_info& s) 
{
  return grade(s.midterm, s.final, s.homework);
}

// predicate to determine whether a student failed
bool fgrade(const Student_info& s) 
{
  return grade(s) < 60;
}

bool pgrade(const Student_info& s) 
{
  return !fgrade(s);
}

bool did_all_hw(const Student_info& s) 
{
  return find(s.homework.begin(), s.homework.end(), 0) == s.homework.end();
}

double grade_aux(const Student_info& s) 
{
  try {
    return grade(s);
  } catch(domain_error) {
    return grade(s.midterm, s.final, 0.0);
  }
} 

double average_grade(const Student_info& s) 
{
  return grade(s.midterm, s.final, mean(s.homework));
}

// scheme that uses meadian of only non-zero hws
double optimistic_median(const Student_info& s) 
{
  vector<double> nonzero;
  // remove all 0s from s.homework and copy the remaining elements to nonzero
  remove_copy(s.homework.begin(), s.homework.end(),
              back_inserter(nonzero), 0);
  if(nonzero.empty())
    return grade(s.midterm, s.final, 0);
  else 
    return grade(s.midterm, s.final, median(nonzero));
}

// double median_analysis(const vector<Student_info>& v) {
//   vector<double> grades;

//   // Apply grade_aux to elements in sequence v.begin() to v.end()
//   // and append them to grades. We need to define grade_aux to 
//   // avoid ambiguity of the overloaded grade function, secondly 
//   // we catch the exception where the student has done no homework 
//   // and use a different function specifying their hw grade to be 0.
//   transform(v.begin(), v.end(), back_inserter(grades), grade_aux); 

//   return median(grades);
// }

// double average_analysis(const vector<Student_info>& v) {
//   vector<double> grades;
//   transform(v.begin(), v.end(), back_inserter(grades), average_grade); 
//   return median(grades);
// }

// double optimistic_median_analysis(const vector<Student_info>& v) {
//   vector<double> grades;
//   transform(v.begin(), v.end(), back_inserter(grades), optimistic_median); 
//   return median(grades);
// }

double analysis(const vector<Student_info>& v, 
                double grading_function(const Student_info&))
{
  vector<double> grades;
  transform(v.begin(), v.end(), back_inserter(grades), grading_function); 
  return median(grades);  
}

void write_analysis(ostream& out, const string& name,
                    double grading_function(const Student_info&), 
                    const vector<Student_info>& did, 
                    const vector<Student_info>& didnt) 
{
  out << name << "(did): " << analysis(did, grading_function) << ", " << 
  name << "(didnt): " << analysis(didnt, grading_function) << endl; 

}

