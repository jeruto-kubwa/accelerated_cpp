#include <vector>
#include <iostream>

using namespace std;

int main()
{
  vector<int> v;

  copy(istream_iterator<int>(cin), istream_iterator<int>(),
       back_inserter(v));

  copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));  

  return 0; 
}