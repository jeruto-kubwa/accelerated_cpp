#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "xref.h"
#include "../chapter_5/split.h"

using namespace std;

int main() 
{
  ifstream infile("paragraph.txt");
  map<string, vector<int> > ret = xref(infile);

  // loop through map pairs
  for(map<string, vector<int> >::const_iterator it =
        ret.begin(); it != ret.end(); ++it) {
    
    cout  << "\"" << it->first << "\" appears on line(s): ";

    vector<int>::const_iterator line_it = it->second.begin();

    cout << *line_it;
    ++line_it;

    while(line_it != it->second.end()) {
      cout << ", " << *line_it;
      ++line_it;
    }
    cout << endl;
  }

  return 0;
}