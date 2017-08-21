#include <vector>
#include "Student_info.h"
#include "average.h"

using std::vector;      using std::cout;
using std::endl;        using std::cin;

int main() 
{
  cout << "Please enter a list of doubles folloed by an EOF character: " << endl;
  vector<double> nums;

  read_hw(cin, nums);

  cout << "\nThe mean value of the double is: " << mean(nums) << endl;

  return 0;
}