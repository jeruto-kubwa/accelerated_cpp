#include <vector>
#include <iostream>
#include <fstream>

#include "reimplementations.h"

using namespace std;

void print_int_vector(const vector<int>& v) {
  for(vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
    cout << *i << " ";
  }
  cout << endl;
}

int main() 
{
  ifstream infile("vector_of_ints.txt");
  vector<int> v;

  int num;
  while(infile >> num)
    v.push_back(num);

  // 1 2 3 4 5 6 7 8 9 10

  // max
  cout << max_tom(10, 11) << endl;

  // find
  // vector<int>::const_iterator i = find(v.begin(), v.end(), 4);
  // vector<int>::const_iterator j = find_tom(v.begin(), v.end(), 8); 
  // cout << *i << endl;
  // cout << *j << endl; 

  // copy
  // vector<int> new_v;
  // copy_tom(v.begin(), v.end(), back_inserter(new_v));
  // print_int_vector(new_v);

  // replace
  // replace_tom(v.begin(), v.end(), 3, 110);
  // print_int_vector(v);

  // reverse 
  // reverse_tom(v.begin(), v.end());
  // print_int_vector(v);

  // binary_search
  //cout << binary_search_tom(v.begin(), v.end(), -18) << endl;


  return 0;
}