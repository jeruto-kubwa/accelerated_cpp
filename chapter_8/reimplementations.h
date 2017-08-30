/*
  This file contains some standard library generic functions 
  written again by me (for learning purposes). 
*/ 

#ifndef GUARD_reimplementations_h
#define GUARD_reimplementations_h

#include <algorithm>

template<class T>
T max_tom(const T& left, const T& right) 
{
  return left > right ? left : right;
}

// sequential write only access  (Input iterator)
template<class In, class X> 
In find_tom(In begin, In end, const X& x)
{
  while(begin != end && *begin != x) {
    ++begin;
  }
  return begin;
}

// sequential write only access (Output iterator)
template<class In, class Out>
Out copy_tom(In begin, In end, Out dest)
{
  while(begin != end) {
    *dest++ = *begin++;
  }
  return dest;
}

// sequential read-write access (Forward iterator)
template<class For, class X>
void replace_tom(For begin, For end, const X& x, const X& y)
{
  while(begin != end) {
    if(*begin == x)
      *begin = y;
    ++begin;
  }
}

// reversible access (Bidirectional iterator)
template<class Bi>
void reverse_tom(Bi begin, Bi end)
{
  while(begin != end) {
    --end;
    if(begin != end)
      std::swap(*begin++, *end);
  }
}

// random access (Random access iterator)
template<class Ran, class X>
bool binary_search_tom(Ran begin, Ran end, const X& x)
{
  while(begin != end) {
    Ran mid = begin + (end - begin) / 2;
    if(*mid > x)
      end = mid;
    else if(*mid < x)
      begin = mid + 1 ;
    else 
      return true; // then x is found
  }
  return false;
}

#endif