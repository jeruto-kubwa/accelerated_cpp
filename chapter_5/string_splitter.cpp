#include <string>
#include <iostream>
#include <vector>
#include "split.h"

using namespace std;

int main() {

  string s;

  while(getline(cin, s)) {
    vector<string> result = split(s);

    cout << "The words are: " << endl;

    for(vector<string>::size_type i=0; i!=result.size(); ++i) {
      cout << result[i] << endl;
    }
  }
  
  return 0;
}