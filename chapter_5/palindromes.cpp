#include <string>
#include <iostream>
#include <fstream>
#include "tomstrings.h"

using namespace std;

int main() {

  ifstream infile("words_alpha.txt");
  vector<string> palindromes;

  string s;
  while(infile >> s) {
    if(is_palindrome(s))
      palindromes.push_back(s);
  }

  print_string_vector(palindromes);

  string::size_type maxlen = 0;
  string longest;
  for(vector<string>::size_type i=0; i!=palindromes.size(); ++i) {
    if(palindromes[i].size() > maxlen) {
      maxlen = palindromes[i].size();
      longest = palindromes[i];  
    }
  }

  cout << "\nLongest english palindrome: " << longest << endl;

  return 0;
}