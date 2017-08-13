#include <iostream>
#include <vector>
#include <string>

#include "tomstrings.h"

using namespace std;

int main() {

  vector<string> pic;

  cout << "Please enter a picture row by row:" << endl;
  read_picture(cin, pic);

  cout << "\nPicture before centering:\n" << endl;
  display_picture(pic);

  vector<string> centered_pic = center(pic);

  cout << "\nPicture after centering:\n" << endl;
  display_picture(centered_pic);

  return 0;
}