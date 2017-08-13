#include <iostream> 
#include <string>
using namespace std;

void ex01() {
  // ask for the person's name
  std::cout << "Please enter your first name: ";
  
  //Read the name 
  std::string name; 
  std::cin >> name;
  
  // build the message that we intend to write
  const std::string greeting = "Hello, " + name + "!";

  int vertical_pad; //Number of vertical padding spaces
  int horizontal_pad; //Number of horizontal padding spaces
  
  // ask for the required vertical and horizontal padding ammount in spaces
  cout << "Please enter the ammount of vertical padding: ";
  cin >> vertical_pad;

  cout << "Please enter the ammount of horizontal padding: ";
  cin >> horizontal_pad;

  const int rows = 2 * vertical_pad + 3; //Number of rows
  const string::size_type cols = greeting.size() + 2 * horizontal_pad + 2; //Number of columns

  // construct string objects for padding whitespace
  string above_white_space(cols-2, ' ');
  string side_white_space(horizontal_pad, ' ');

  //New line to seperate output from input
  cout << endl; 

  for(int r = 0; r != rows; ++r) {
    string::size_type c = 0;
    
    while(c != cols) {

      //First check if we are at begining point for greeting 
      if(r == vertical_pad + 1 and c == horizontal_pad + 1) { 
        cout << greeting;
        c += greeting.size();
      }  else {
        // are we on the border?
        if(r == 0 || r == rows - 1 ||
           c == 0 || c == cols -1){
          cout << '*';
          ++c;
        } else {
          // are we on the greeting line? 
          if(r == vertical_pad + 1) {
            cout << side_white_space;
            c += side_white_space.size();
          } else {
            cout << above_white_space;
            c += above_white_space.size();
          }
        }
      }
    }//while loop
    cout << endl;
  }//for loop
}

// below two functions are for q05

void print_a_rectangle() { // print a rectangle 

  int w, h;
  
  cout << "Please provide rectangle width: " << endl;
  cin >> w;

  cout << "Please provide rectangle height: " << endl;
  cin >> h;

  // there are two types of line to print 

  string top_or_bottom_row(w, '*');
  
  string spaces(w-2, ' ');
  string middle_row = '*' + spaces + '*';

  for(int r = 0; r!=h; ++r) {
    if(r == 0 || r == h-1)
      cout << top_or_bottom_row << endl;
    else 
      cout << middle_row << endl;
  }
}

//     *    1    : 0
//    * *    2 : 1        1 + 2n   n = count-2  so we have 1 + 2* count - 4
//   *   *    3 : 3
//  *     *    4 : 5 
// * * * * *    5

void print_a_triangle() { // print a triangle
  int h;
  cout << "Please provide triangle height in rows: " << endl;
  cin >> h;

  for(int i=0; i<h; ++i){ // print the base 
    cout << "* "; 
  }
  cout << endl;

  int count = h-1; 
  while(count > 1) { 

    string side_space(h - count, ' '); // white space either side of triangle body
    cout << side_space << '*'; // print space on lhs 

    string mid_space(1 + 2* count - 4, ' ');
    cout << mid_space;

    cout << '*' << side_space << endl; // print space on rhs and new line
    --count;
  }

  string side_space(h - count, ' ');
  cout << side_space << '*' << side_space << endl;  // print the peak 
}

void q06() {
  int i = 1;
  int product = 1;
  while (i < 10) {
    product *= i;
    i += 1;
  }
  cout << product << endl;
}

void q08() {
  cout << "Provide two integers: " << endl;
  int a, b;
  cin >> a >> b;

  if (a > b) 
    cout << a << " is greater than " << b << endl;  
  else if (a == b)
    cout << a << " is equal to " << b << endl;
  else 
    cout << b << " is greater than " << a << endl;  
}


int main() {
  q10();  
  return 0;
}
