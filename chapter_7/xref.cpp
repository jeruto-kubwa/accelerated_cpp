#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#include "../chapter_5/split.h"

using namespace std;

map<string, vector<int> > 
  xref(istream& in, 
       vector<string> find_words(const string&) = split) 
{
  int line_number = 0;
  string line;
  map<string, vector<int> > ret;

  while(getline(in, line)) {
    ++line_number;
    vector<string> words = find_words(line);

    for(vector<string>::const_iterator it = words.begin();
        it != words.end(); ++it) {

      // Only report one occurence per line 
      if(find(ret[*it].begin(), ret[*it].end(), line_number) ==
          ret[*it].end()) {
        ret[*it].push_back(line_number);
      }
    }
  }
  return ret;
}