#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "url.h"
#include "../chapter_5/tomstrings.h"

using namespace std;

int main() {
  
  ifstream infile("article.txt");
  string s;
  vector<string> urls;

  while(getline(infile, s)) {

    vector<string> new_urls = find_urls(s);
    urls.insert(urls.end(), new_urls.begin(), new_urls.end());

  }


  for(vector<string>::const_iterator i = urls.begin();
      i != urls.end(); ++i) {
    cout << (*i) << endl;
  }

  //print_string_vector(urls);

  return 0;
}