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

// Compares the elements in the range [first1,last1)
//  with those in the range beginning at 
// first2, and returns true if all of the elements in both ranges match.

template<class In>
bool equal_tom(In begin1, In end1, In begin2)
{
  while(begin1 != end1) {
    if(*begin1++ != *begin2++) 
      return false;
  }
  return true;
}

// Copies the elements in the range [first,last) 
// to the range beginning at 
// result, except those elements for which pred returns true.

template<class In, class Out, class Predicate>
Out remove_copy_if_tom(In begin, In end, Out result, Predicate pred)
{
  for( ; begin != end; begin++) {
    if(!pred(*begin))
      *result++ = *begin;
  }
  return result;
}

template<class In, class Out, class Operation>
Out transform_tom(In begin, In end, Out result, Operation op)
{
  while(begin != end) {
    *result++ = op(*begin++);
  }
  return result;
}

template<class For, class X>
X accumulate_tom(For begin, For end, X x)
{
  while(begin != end) {
    x += *begin++;
  }
  return x;
}

#endif