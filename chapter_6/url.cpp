#include <vector>
#include <string>
#include <cctype>

using namespace std;

bool not_url_char(char c) 
{
  const static string url_ch = "~;/?:@=&$-_.+!*'(),";

  return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end()); 
}


// find beginning of a url in range [b,e)
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e){

  static const string sep = "://";
  typedef string::const_iterator iter;
  iter i = b; 

  while((i = search(i, e, sep.begin(), sep.end())) != e) {
    // check not at beginning or end
    if(i != b && i + sep.size() != e) {
      
      iter beg = i;
      while(beg != b && isalpha(beg[-1]))
        --beg;

      // check that protocol name is non-zero length 
      // and there is at least one url valid char after sep
      if(beg != i && !not_url_char(i[sep.size()]))
        return beg;
    }
    // if not a valid URL, skip out the sep
    i += sep.size();
  }
  return e;
}

// find end of a url in range [b,e)
string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
  return find_if(b, e, not_url_char);
}

// remove trailing fullstop
void remove_fullstop(string& s) 
{
  if(s.back() == '.') 
    s.pop_back();
}

// find urls in a block of text
vector<string> find_urls(const string& s) 
{
  vector<string> ret;

  typedef string::const_iterator iter;

  iter b = s.begin(), e = s.end();

  while(b != e) {

    b = url_beg(b, e);

    if(b != e) {
      iter after = url_end(b, e);
      string url(b, after);
      remove_fullstop(url);
      ret.push_back(url);
      b = after;
    }
  } 
  return ret;
}



