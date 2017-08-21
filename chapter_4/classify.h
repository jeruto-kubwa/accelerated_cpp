#ifndef GUARD_classify_h
#define GUARD_classify_h

#include <vector>
#include "Student_info.h"

std::vector<Student_info> classify(std::vector<Student_info>& students,
                             bool criteria(const Student_info& s));

#endif


