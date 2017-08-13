#include <vector>
#include <string>
#include <iomanip>
#include "Student_info.h"
#include "digits.h"

using std::cout;        using std::cin;
using std::max;         using std::string;
using std::endl;        using std::setw;
using std::streamsize;  using std::setprecision;

void q01() {
  string::size_type maxlen = 10;
  Student_info s;
    // read and store all of the students' data.
  read(cin, s);  
  cout << max(maxlen, s.name.size()) << endl;
}

void q02() {
  for(int i=0; i<1000; ++i) { 
    cout << setw(4) << i << setw(7) << i*i << endl;
  }
}

void q03() {
  cout << "Please enter the boundaries of an asymmetric range of ints: " << endl;
  int a, b;
  cin >> a >> b;

  if(b < a) {
    cout << "End integer must be larger than initial integer." << endl;
    return;
  }

  // argument of first setw should be no. of characters of largest i + 2
  // argument of second setw should be no. of characters of largest i*i + 2

  int cw1 = number_of_digits(b) + 2;  // column width 1
  int cw2 = number_of_digits(b*b) + 2;  // column width 2

  for(int i=a; i<b; ++i) { 
    cout << setw(cw1) << i << setw(cw2) << i*i << endl;
  }
}

void q04() {
  cout << "Please enter the boundaries of an asymmetric range of doubles: " << endl;
  double a, b;
  cin >> a >> b;

  if(b < a) {
    cout << "End double must be larger than initial double." << endl;
    return;
  }

  cout << "Please enter an increment double: " << endl;
  double i;
  cin >> i;

  cout << "Please enter the required number of decimal places: " << endl;
  int dps;
  cin >> dps;

  const int gap = 2;

  // argument of first setw should be no. of characters of b + 4
  // argument of second setw should be no. of characters of b*b + 4

  int p1 = number_of_digits(b) + dps;  // precision column 1 
  int p2 = number_of_digits(b*b) + dps;  // precision column 2

  while(a<b) {
    streamsize prec = cout.precision(); // previous stream precision
    cout << setw(p1 + 1 + gap) << setprecision(p1) << a // set width to precision + 1 for decimal point + gap spaces
         << setw(p2 + 1 + gap) << setprecision(p2) << a*a 
         << setprecision(prec) << endl;
    a += i;
  }
}

int main() {
  q04();
  return 0;
}