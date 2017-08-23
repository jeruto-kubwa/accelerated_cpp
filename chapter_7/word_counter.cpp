#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "tommaps.h"

using namespace std;

int main() 
{
  ifstream infile("paragraph.txt");

  map<string, int> counters;

  string s;
  while(infile >> s) {
    counters[s]++;
  }
  
  vector<pair<string, int> > vec_of_pairs = sort_freq_map(counters);

  int occurence_group;
  for(vector<pair<string, int> >::const_iterator it = 
        vec_of_pairs.begin(); it != vec_of_pairs.end(); ++it) {

    if(it->second > occurence_group) {
      occurence_group = it->second;
      cout << "\n" << occurence_group << " occurence(s):" << endl;
    }

    cout << "  " << it->first << endl;
  }  

  return 0;
}