#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>

#include "Student_info.h"
#include "average.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info& s);
bool fgrade(const Student_info&);
bool pgrade(const Student_info&);
bool did_all_hw(const Student_info&);
double grade_aux(const Student_info&);
double average_grade(const Student_info&);
double optimistic_median(const Student_info&);

// double median_analysis(const std::vector<Student_info>&);
// double average_analysis(const std::vector<Student_info>&);
// double optimistic_median_analysis(const std::vector<Student_info>&);

//double analysis(const std::vector<Student_info>&, 
  //              double grading_function(const Student_info&));

// void write_analysis(std::ostream& out, 
//                     const std::string& name,
//                     double grading_function(const Student_info&), 
//                     const std::vector<Student_info>& did, 
//                     const std::vector<Student_info>& didnt);

template<class Function>
double analysis(const std::vector<Student_info>& v, Function grading_function)
{
  std::vector<double> grades;
  transform(v.begin(), v.end(), back_inserter(grades), grading_function);
  return median(grades);    
}

template<class Function>
void write_analysis(std::ostream& out, const std::string& name,
                    Function grading_function, 
                    const std::vector<Student_info>& did, 
                    const std::vector<Student_info>& didnt) 
{
  out << name << "(did): " << analysis(did, grading_function) << ", " << 
  name << "(didnt): " << analysis(didnt, grading_function) << std::endl; 

}

#endif
