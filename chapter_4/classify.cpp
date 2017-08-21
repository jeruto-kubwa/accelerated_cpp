#include <vector>
#include "Student_info.h"

using std::vector;

vector<Student_info> classify(vector<Student_info>& students,
                             bool criteria(const Student_info& s))
{
  vector<Student_info>::const_iterator iter =
    stable_partition(students.begin(), students.end(), criteria);
  vector<Student_info> didnt(iter, students.end());
  students.erase(iter, students.end());
  return didnt; 
}