#include <string>
#include <vector>
#include <iostream>

#include "tomstrings.h"
#include "split.h"

using namespace std;

int main() {
  string s;

  cout << "Please enter a sentence to be framed." << endl;

  while(getline(cin, s)) {
    vector<string> v = split(s);

    vector<string> framed_picture = frame(v);
    display_picture(framed_picture);
    
  }

  return 0;
}