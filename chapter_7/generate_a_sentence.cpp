#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "grammar.h"

using namespace std;

int main()
{

  // seed the random number generator
  srand(time(NULL));

  ifstream infile("grammar.txt");

  vector<string> ret = gen_sentence(read_grammar(infile));

  vector<string>::const_iterator it = ret.begin();

  if(!ret.empty()) {
    cout << *it;
    ++it;
  }

  while(it != ret.end()) {
    cout << " " << *it;
    ++it;
  }

  cout << endl;
  return 0;
}