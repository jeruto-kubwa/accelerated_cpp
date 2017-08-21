#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{

  vector<int> u(10, 100); // 10 ints of value 100
  vector<int> v;
  
  // copy contents of u to front of v (front_inserter only works for list type)
  //copy(u.begin(), u.end(), front_inserter(v)); 

  copy(u.begin(), u.end(), inserter(v, v.begin()));

  // print out copied vector contents
  for(vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
    cout << *i << endl;
  }

  return 0;
}