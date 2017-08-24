#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

bool space(char c) {
  return isspace(c);
}

bool not_space(char c) {
  return !isspace(c);
}

// implementation with <algorithm>
vector<string> split(const string& s) {
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

// version for list<string>
list<string> split_list(const string& s) {
  list<string> ret;

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

// Implementation with index access only

// split a string into withspace seperated words
// vector<string> split(const string& s) {
//   vector<string> ret; 
//   typedef string::size_type string_size;

//   string_size i = 0;
//   while(i != s.size()) {
    
//     while(i!=s.size() and isspace(s[i]))
//       ++i;
    
//     string_size j = i;
    
//     while(j!=s.size() and !isspace(s[j]))
//       ++j;

//     if(j!=i) {
//       ret.push_back(s.substr(i, j-i));
//       i = j;      
//     }
//   }
//   return ret;
// }

