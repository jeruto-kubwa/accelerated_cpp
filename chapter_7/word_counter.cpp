#include <map>
#include <iostream>

using namespace std;

int main() {

  map<string, int> counters;

  cout << "Please enter some words: " << endl;

  string s;
  while(cin >> s) {
    counters[s]++;
  }

  for(map<string, int>::const_iterator it = counters.begin();
      it != counters.end(); ++it) {
    cout << it->first << " appeared " << it->second 
         << " times."  << endl;
  }  

  return 0;
}