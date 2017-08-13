#include <string>
#include <iostream>
#include <fstream>
#include "tomstrings.h"

using namespace std;

int main() {

  ifstream infile("words_alpha.txt");
  vector<string> no_ascenders_or_descenders;

  string s;
  while(infile >> s) {
    if(!has_ascender_or_descender(s))
      no_ascenders_or_descenders.push_back(s);
  }

  print_string_vector(no_ascenders_or_descenders);

  string::size_type maxlen = 0;
  string longest;
  for(vector<string>::size_type i=0; i!=no_ascenders_or_descenders.size(); ++i) {
    if(no_ascenders_or_descenders[i].size() > maxlen) {
      maxlen = no_ascenders_or_descenders[i].size();
      longest = no_ascenders_or_descenders[i];  
    }
  }

  cout << "\nLongest english word with no ascenders or descenders: "
       << longest 
       << endl;

  return 0;
}