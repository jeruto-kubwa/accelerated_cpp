#include <iostream>
using namespace std;

void ex01() {
  cout << "Please enter name: " << endl;
  string name;
  cin >> name;
  cout << "Hi there, " << name << "!" << endl;

}

void ex02() {
  cout << "Please enter first name: " << endl;
  string name;
  cin >> name;

  const string greeting = "Hello, " + name + "!";

  const string spaces(greeting.size(), ' ');
  const string second = "* " + spaces + " *";

  const string first(second.size(), '*');

  cout << endl;
  cout << first << endl;
  cout << second << endl;
  cout << "* " << greeting << " *" << endl;
  cout << second << endl;
  cout << first << endl;
}

void q04() {
  { 
    const std::string s = "a string"; std::cout << s << std::endl;
    { 
      const std::string s = "another string"; std::cout << s << std::endl;
    };;;;;;;;;;;;;;;  // All null statements
  }
}

void q05() {
  { 
    std::string s = "a string"; // scope of s is this code block and all children code blocks
    { 
      std::string x = s + ", really"; std::cout << s << std::endl; // scope of x is this code block
      std::cout << x << std::endl;
    } 
  }
}

void q06() {
  std::cout << "What is your name? "; std::string name;
  std::cin >> name;
  std::cout << "Hello, " << name
  << std::endl << "And what is yours? "; std::cin >> name;
  std::cout << "Hello, " << name
  << "; nice to meet you too!" << std::endl;
}



int main() {
  q06();  
  return 0;
}
