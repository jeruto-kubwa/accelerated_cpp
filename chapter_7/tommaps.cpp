#include <map>
#include <string>
#include <vector>

using namespace std;

// Compair two pair<string, int> by int value
bool compare(const pair<string, int>& x, const pair<string, int>& y) 
{
  return x.second < y.second;
}

// Return a sorted vector<pair<string, int> > corresponding to the
// elements of a map<string, int> (sorted by the int values)
vector<pair<string, int> > 
  sort_freq_map(const map<string, int>& sort_map, 
                bool pred(const pair<string, int>&,
                             const pair<string, int>&) = compare) 
{
  vector<pair<string, int> > ret;

  for(map<string, int>::const_iterator i = sort_map.begin();
      i != sort_map.end(); ++i) {
    ret.push_back(make_pair(i->first, i->second));
  }

  sort(ret.begin(), ret.end(), pred);
  return ret;
}

// Return a map of keys grouped by their frequency
map<int, vector<string> > keys_by_freq(const map<string, int>& freq_map) 
{
  map<int, vector<string> > ret; 

  for(map<string, int>::const_iterator i = freq_map.begin(); 
      i != freq_map.end(); ++i) {
    ret[i->second].push_back(i->first);
  } 
  return ret;
}