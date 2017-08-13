#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

#include "tomstrings.cpp"
#include "split.h"

using namespace std;

// object that stores a vector<string> of words and keeps 
// track of the first word
struct Rotation {
  vector<string>::size_type first;
  vector<string> words;
};

// read in lines from std in
vector<string> read_lines() {
  vector<string> lines;
  string s;
  while(getline(cin, s)) {
    lines.push_back(s); 
  }
  return lines;
}

// return all rotations of a single line
vector<Rotation> rotate_line(const string& line) {
  vector<Rotation> rotations;
  vector<string> words = split(line);

  for(vector<string>::size_type i=0; i!=words.size(); ++i) {
    Rotation rot = {words.size()-i, words};
    rotations.push_back(rot);
    // in the rotate algorithm, the middle argument becomes the new first element
    rotate(words.begin(), words.begin()+1, words.end());
  }
  return rotations;
}

// return all rotations of a vector<string> of lines
vector<Rotation> rotate_lines(const vector<string>& lines) {
  vector<Rotation> rotations;

  for(vector<string>::size_type i=0; i!=lines.size(); ++i) {
    vector<Rotation> new_rotations = rotate_line(lines[i]);
    rotations.insert(rotations.end(), new_rotations.begin(), new_rotations.end());
  }

  return rotations;
}

// compare Rotation objects lexicographically
bool compare(const Rotation& a, const Rotation& b) {
  return a.words < b.words;
}

// print rotations with formatting to highlight key word in context
void print_rotations(const vector<Rotation>& rotations) {
  vector<string> first_halves;
  vector<string> second_halves; 

  string::size_type max_first_half_width=0;

  for(vector<Rotation>::size_type i=0; i!=rotations.size(); ++i) {

    Rotation rot = rotations[i];
    string first_half, second_half;

    for(vector<string>::size_type j=rot.first; j!=rot.words.size(); ++j) {
      first_half += rot.words[j] + " ";
    }
    first_halves.push_back(first_half);

    max_first_half_width = max(max_first_half_width, first_half.size());

    for(vector<string>::size_type j=0; j!=rot.first; ++j) {
      second_half += rot.words[j] + " ";
    }
    second_halves.push_back(second_half);

  }

  for(vector<string>::size_type i=0; i!=first_halves.size(); ++i) {
    cout << setw(max_first_half_width);
    cout << first_halves[i];
    cout << "      ";
    cout << second_halves[i];
    cout << endl;
  }
}

int main() {

  vector<string> lines = read_lines();
  vector<Rotation> rotations = rotate_lines(lines);
  sort(rotations.begin(), rotations.end(), compare);
  cout << "\n\n" << endl;
  print_rotations(rotations);

  return 0;
}
