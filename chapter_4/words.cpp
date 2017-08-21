#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::istream;      using std::vector;
using std::string;       using std::cin;
using std::cout;         using std::endl;

// read words from stream into a vector
istream& read_words(istream& in, vector<string>& words) 
{
  if(in) {
    words.clear(); // clear any contents of words

    string w; // read words in one by one
    while(in >> w)
      words.push_back(w);

    in.clear(); // clear the input stream so that read_words works for the next vector
  }
  return in;
}

// Finds the distinct words in a vector of strings and writes the results 
// into a new vector<string> and a correspoding vector<int> with the word frequencies 
void count_words(vector<string> words, vector<string>& distinct_words, vector<int>& word_counts) 
{

  distinct_words.clear(); // ensure results vectors are clear
  word_counts.clear();

  sort(words.begin(), words.end()); // sorts strings in alphabetical order

  int count = 0;

  distinct_words.push_back(words[0]); // add the fist word to distinct words vector
  
  for(int i=0; i<words.size(); ++i) { // for the rest of the words 
    // if word is not the same as the most recently added to distinct words 
    // then add it and add the word count to the end of the word_counts vector
    // reset word count to 1 for the current word
    if(words[i] != distinct_words[distinct_words.size()-1]) { 
      word_counts.push_back(count);
      distinct_words.push_back(words[i]);
      count = 1;
    } else {
      count += 1; // else increase the word count by 1
    }
  }
  // add the word count if the end of the words vector is reached
  word_counts.push_back(count); 
}

// print a vector<string> of words to std out
void display_words(const vector<string>& words) 
{
   for(vector<string>::size_type i=0; i<words.size()-1; ++i) {
    cout << words[i] << ", ";
  }
  cout << words[words.size()-1] << endl;
}

// print a vector<string> of words and corresponding word counts to std out
void display_word_counts(const vector<string>& words, 
                         const vector<int>& word_counts) 
{
   for(vector<string>::size_type i=0; i<words.size(); ++i) {
    cout << words[i] << " occured " << word_counts[i] << " times." << endl;
  }
}
