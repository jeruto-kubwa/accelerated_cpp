/* 
  Create a program that opens a file and counts 
  the whitespace-separated words in that file.
*/ 
#include <fstream>
#include <iostream>

int main() {

  ifstream infile("some_text.txt");
  string s;
  int count = 0;

  while(cin >> s) {
    ++count;
  } 

  cout << "Total number of words in file: " << count << endl;

  return 0;
}