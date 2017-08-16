#include <vector>
#include <string>
#include <iostream>
#include "tomstrings.h"

using namespace std;

int main() {

  // Hard coded string pictures
  vector<string> top;
  vector<string> bottom;

  cout << "Please enter the top picture: " << endl;

  read_picture(cin, top);

  cout << "Please enter the bottom picture: " << endl;

  read_picture(cin, bottom);

  // bottom.push_back("THIS IS THE BOTTOM");
  // bottom.push_back("**********");
  // bottom.push_back(" ******** ");
  // bottom.push_back("  ******  ");
  // bottom.push_back("   ****   ");
  // bottom.push_back("    **    ");

  cout << "\nDisplaying the virtically concatenated picture:\n" << endl;

  top = vcat(top, bottom);
  display_picture(top);

  cout << "\nDisplaying the horizontally concatenated picture with framed picture:\n" << endl;

  top = hcat(top, frame(top));  
  display_picture(top);

  return 0;
}