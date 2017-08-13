#include <algorithm> // to get the declaration of sort
#include <stdexcept> // to get the declaration of domain_error
#include <vector> // to get the declaration of vector

using std::vector;      using std::domain_error;

// return the median value of a vector<double>
// note calling this function copies the entire argument vector 
double median(vector<double> vec) {   
  typedef vector<double>::size_type vec_sz;
  vec_sz size = vec.size();

  if(size == 0)
    throw domain_error("median of an empty vector");

  sort(vec.begin(), vec.end()); // sort in nondecreasing order

  vec_sz mid = size/2;
  
  return (size % 2 == 0) ?  (vec[mid] + vec[mid-1]) / 2 
                                  : vec[mid];
}

double mean(vector<double> vec) {
  double sum = 0;
  for(vector<double>::size_type i=0; i<vec.size(); ++i) {
    sum += vec[i];
  }
  return sum / vec.size();
}
