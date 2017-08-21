#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include "../chapter_5/tomstrings.h"

using namespace std;

string target = "";

void cat(string s) 
{
  target += s + " ";
}

int main() 
{
  vector<string> words = vector<string>(5, "Ho");

  //string combined = accumulate(words.begin(), words.end(), string(""));

  for_each(words.begin(), words.end(), cat);

  cout << target << endl;

  return 0;
}