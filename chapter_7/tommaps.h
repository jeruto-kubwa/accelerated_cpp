#ifndef GUARD_tommaps_h
#define GUARD_tommaps_h

#include <map>
#include <string>
#include <vector>

bool compare(const std::pair<std::string, int>& x,
             const std::pair<std::string, int>& y);

std::vector<std::pair<std::string, int> > 
  sort_freq_map(const std::map<std::string, int>& sort_map,
                bool pred(const std::pair<std::string, int>&,
                             const std::pair<std::string, int>&) = 
                                compare);

std::map<int, std::vector<std::string> > 
  keys_by_freq(const std::map<std::string, int>& freq_map); 

#endif