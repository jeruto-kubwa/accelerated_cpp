#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

vector<double> f()
{
  vector<double> nums;
  nums.push_back(1.0);
  nums.push_back(2.0);
  nums.push_back(3.0);
  return nums;
}

int main() 
{
  double d = f()[1];
  cout << d << endl;
  return 0;
}