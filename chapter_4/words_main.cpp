// This code is for counting the number of words in an input stream
// and the number of occurences oof each word.

#include <iostream>
#include <vector>
#include "words.h"

using std::cin;       using std::cout;
using std::endl;      using std::vector;
using std::string;

int main(){

  vector<string> words;

  cout << "Please enter a sentence of sequence of space-seperated words." 
          " followed by an EOF character." << endl;

  read_words(cin, words);

  cout << endl; // space before output

  display_words(words); 

  cout << "Counting words..." << endl;

  // empty vectors to store the distinct words and their corresponding frequencies 
  vector<string> distinct_words; 
  vector<int> word_counts;

  count_words(words, distinct_words, word_counts); 

  cout << "\nDisplaying word counts in alphabetical order:\n" << endl;

  display_word_counts(distinct_words, word_counts);

  return 0;
} 