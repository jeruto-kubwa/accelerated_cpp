#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

// return the maximum length of string in a vector<string>
string::size_type width(const vector<string>& v) {
  string::size_type maxlen = 0;
  for(vector<string>::size_type i = 0; i != v.size(); ++i) {
    maxlen = max(v[i].size(), maxlen);
  }
  return maxlen;
} 

// frame a string picture with a border of stars
// vector<string> frame(const vector<string>& v) {
//   vector<string> ret;
//   string::size_type maxlen = width(v);
//   string border(maxlen+4, '*');

//   ret.push_back(border);
  
//   for(vector<string>::size_type i=0; i < v.size(); ++i) {
//     ret.push_back("* " + v[i] 
//       + string(maxlen - v[i].size(), ' ')
//       + " *");
//   }
//   ret.push_back(border);
//   return ret;
// } 

// frame implementation with iterators 
vector<string> frame(const vector<string>& v) {
  vector<string> ret;
  string::size_type maxlen = width(v);
  string border(maxlen+4, '*');

  ret.push_back(border);
  
  for(vector<string>::const_iterator i = v.begin();
     i != v.end(); ++i) {
    ret.push_back("* " + *i 
      + string(maxlen - i->size(), ' ')
      + " *");
  }
  ret.push_back(border);
  return ret;
} 

// display a string picture
void display_picture(const vector<string>& v) {
  for(vector<string>::size_type i = 0; i != v.size(); ++i) {
    cout << v[i] << endl;
  }
}

// print a vector<string> with each string on a new line
void print_string_vector(const vector<string>& v) {
  for(vector<string>::size_type i = 0; i != v.size(); ++i) {
    cout << v[i] << endl;
  }
}

// vertically concatenate string pictures 
vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
  vector<string> ret = top;
  ret.insert(ret.end(), bottom.begin(), bottom.end());
  return ret;
}

// vertically concatenate string pictures 
// vector<string> hcat(const vector<string>& left, const vector<string>& right) {
//   vector<string> ret;

//   // width of left picture + 1 for padding between pictures 
//   vector<string>::size_type width1 = width(left) + 1;

//   vector<string>::size_type i=0, j=0;

//   while(i != left.size() or j != right.size()) {
//     string s;

//     if(i != left.size())
//       s += left[i++];

//     s += string(width1 - s.size(), ' ');

//     if(j != right.size())
//       s += right[j++];

//     ret.push_back(s);
//   }
//   return ret;
// }

// hcat implementation with iterators
vector<string> hcat(const vector<string>& left, const vector<string>& right) {
  vector<string> ret;

  typedef vector<string>::const_iterator iter;

  // width of left picture + 1 for padding between pictures 
  vector<string>::size_type width1 = width(left) + 1;

  iter i = left.begin(); 
  iter j = right.begin();

  while(i != left.end() or j != right.end()) {
    string s;

    if(i != left.end())
      s += *(i++);

    s += string(width1 - s.size(), ' ');

    if(j != right.end())
      s += *(j++);

    ret.push_back(s);
  }
  return ret;
}



// read a sequence of strings from input stream to vector<string>
istream& read_picture(istream& in, vector<string>& pic) {

  if(in) {  
    // clear any existing contents of the pic vector 
    pic.clear();


    string s;
    while(getline(in, s)) {
      pic.push_back(s);
    }

    // clear the stream so that input will work for the next student
    in.clear(); 
  }
  return in;
}

// concatenate all strings in a vector<string> and return it as a new string 
string joinv(const vector<string>& v) {
  string ret;
  for(vector<string>::size_type i=0; i!=v.size(); ++i) {
    ret += v[i]+" "; 
  }
  return ret;
}

// centers a picture by adding padding to either side
vector<string> center(const vector<string>& v) {
  vector<string> ret;
  string::size_type maxlen = width(v);
  
  for(vector<string>::const_iterator it=v.begin(); it!=v.end();
      ++it) {

    string row = string((maxlen - it->size())/2, ' ') 
                 + (*it);
    row += string(maxlen - row.size(), ' ');
    ret.push_back(row);
  }
  return ret;
}

// Check wether a word is a palindrome  (without using <algorithm>)
// bool is_palindrome(const string& s) {
//   bool ret = true;
//   string::size_type length = s.size();

//   for(string::size_type i=0; i!=length/2; ++i) {
//     if(s[i] != s[length-1-i]){
//       ret = false;
//       break;
//     }
//   }
//   return ret;
// }

// Check wether a word is a palindrome 
bool is_palindrome(const string& s) {
  // s.rbegin() is an iterator that starts at the end of s and moves backwards
  return equal(s.begin(), s.end(), s.rbegin());
}

bool contains_character(const string& s, char c) {
  return find(s.begin(), s.end(), c) != s.end();
}

// Check wether a word has an ascender or descender 
bool has_ascender_or_descender(const string& s) {
  bool ret = false;

  static const string chars = "bdfhkljgpqy";

  for(string::size_type i=0; i!=chars.size(); i++) {
    if(contains_character(s, chars[i])) {
      ret = true;
      break;
    }
  }
  return ret;
}

