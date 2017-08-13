#include <vector>
#include "Student_info.h"
#include "average.h"

using std::cout;        using std::cin;
using std::endl;        using std::vector; 

int main() {
  cout << "Please enter a list of doubles followed by an EOF character." << endl;
  vector<double> nums;
  read_hw(cin, nums);
  cout << "The average value is: " << mean(nums) << endl;
  return 0;
}