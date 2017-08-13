#include <vector>
#include <string>
#include "tomstrings.h"

using namespace std;

int main() {

  vector<string> v;
  vector<string> empty_frame = frame(v);
  display_picture(empty_frame);

  return 0;
}