#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {

  ifstream infile("words_alpha.txt");
  string word;
  string longest_word;
  string::size_type maxlen = 0;

  while(infile >> word) {
    if(word.size() > maxlen) {
      longest_word = word;
      maxlen = word.size();
    }
  }

  cout << "The longest english word is: " << longest_word << endl;

  return 0;
}