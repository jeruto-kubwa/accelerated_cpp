#include <map>
#include <iostream>
#include <string>
#include <fstream>

#include "tommaps.h"

using namespace std;

// Ordered by word occurence - using book answers
int main() {

  ifstream infile("paragraph.txt");

  map<string, int> counters;

  string s;
  while(infile >> s) {
    counters[s]++;
  }

  map<int, vector<string> > words_by_freq = keys_by_freq(counters);
  
  
  for(map<int, vector<string> >::const_iterator i = 
      words_by_freq.begin(); i != words_by_freq.end(); ++i) {

    cout << "Frequency: " << i->first << endl;

    for(vector<string>::const_iterator j = i->second.begin(); 
        j != i->second.end(); ++j) {
      cout << *j << endl;
    }
  }  

  return 0;
}
