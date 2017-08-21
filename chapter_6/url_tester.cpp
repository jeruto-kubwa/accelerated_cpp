#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "url.h"
#include "../chapter_5/tomstrings.h"

using namespace std;

int main() 
{
  
  ifstream infile("article.txt");
  string s;
  vector<string> urls;

  while(getline(infile, s)) {

    vector<string> new_urls = find_urls(s);
    urls.insert(urls.end(), new_urls.begin(), new_urls.end());

  }

  print_string_vector(urls);

  return 0;
}