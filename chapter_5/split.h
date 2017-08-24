#ifndef GUARD_split_h
#define GUARD_split_h

#include <vector>
#include <list>
#include <string>

bool space(char);

bool not_space(char);

std::vector<std::string> split(const std::string&);

std::list<std::string> split_list(const std::string& s);

#endif
