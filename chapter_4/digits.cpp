#include <math.h>

int number_of_digits(int i) 
{
  int digits = 0;
  while(i/10 != 0) {
    i /= 10;
    digits++;
  }
  return digits;
}

int number_of_digits(double d) 
{
  double a = log10(d);
  return (int) a + 1;
}