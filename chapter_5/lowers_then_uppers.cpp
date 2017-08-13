#include <string>
#include <iostream>
#include <vector>
#include "tomstrings.h"
#include "split.h"

using namespace std;

int main() {

  string s;
  getline(cin, s);
  vector<string> words = split(s);
  vector<string> uppers;
  vector<string> lowers;

  // Seperate words into uppers and lowers 
  for(vector<string>::const_iterator it=words.begin();
      it!=words.end(); ++it) {
    
    if(isupper((*it)[0])) 
      uppers.push_back((*it));
    else if(islower((*it)[0]))
      lowers.push_back((*it));
  
  }  

  // Print out lowers then uppers
  print_string_vector(lowers);
  print_string_vector(uppers);

  return 0;
}