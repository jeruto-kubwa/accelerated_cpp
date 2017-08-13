#include <vector>
#include <stdexcept>
#include "average.h"
#include "Student_info.h"

using std::vector;      using std::domain_error;

double grade(double midterm, double final, double homework) {
  return 0.2 * midterm  + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw) {
  if(hw.size() == 0)
      throw domain_error("Student has done no hw.");

  return grade(midterm, final, median(hw));
}

bool fgrade(const Student_info& s) {
  return s.overall_grade < 60;
}