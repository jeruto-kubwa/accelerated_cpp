#include <vector>
#include <iostream>

#include "median.h"

using namespace std;

int main()
{

  vector<int> v;
  int d;

  cout << "Enter some int values: " << endl;

  while(cin >> d) {
    v.push_back(d);
  }

  cout << "median: " << median(v) << endl;
 
  return 0;
}