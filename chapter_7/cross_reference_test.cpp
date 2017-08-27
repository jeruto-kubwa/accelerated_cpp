#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#include "xref.h"
#include "../chapter_5/split.h"
#include "../chapter_6/url.h"

using namespace std;

int main() 
{
  const int LINE_LENGTH = 80;

  ifstream infile("paragraph_with_urls.txt");
  map<string, vector<int> > ret = xref(infile, find_urls);

  // loop through map pairs
  for(map<string, vector<int> >::const_iterator it =
        ret.begin(); it != ret.end(); ++it) {

    stringstream ss;
  
    ss  << "\n\"" << it->first << "\" occurs on "
        << ((it->second.size() > 1) ? "lines" : "line") << ":\n";

    vector<int>::const_iterator line_it = it->second.begin();

    ss << *line_it;
    ++line_it;

    while(line_it != it->second.end()) {
      ss << ", " << *line_it;
      ++line_it;
    }

    string output = ss.str();

    for(string::size_type i = 0; i != output.size(); ++i) {
      cout << output[i];

      if((i + 1) % LINE_LENGTH == 0)
        cout << endl;

    }

    cout << endl;
  }

  return 0;
}