#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool space(char c) 
{
  return isspace(c);
}

bool not_space(char c) 
{
  return !isspace(c);
}

vector<string> split(const string& s) 
{
  vector<string> ret;

  typedef string::const_iterator iter;

  iter i = s.begin();

  while(i != s.end()) {

    i = find_if(i, s.end(), not_space);

    iter j = find_if(i, s.end(), space);

    if(i != s.end()) 
      ret.push_back(string(i, j));

    i = j;
  }
  return ret;
}