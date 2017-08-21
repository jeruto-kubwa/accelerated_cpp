#include <string>
#include <vector>
#include <iostream>
#include "split.h"
#include "../chapter_5/tomstrings.h"

using namespace std;

int main() 
{

  cout << "Enter a sentence to be split: " << endl;

  string s;
  while(getline(cin, s)) {

    vector<string> words = split(s);

    print_string_vector(words);
  }

   return 0;
}