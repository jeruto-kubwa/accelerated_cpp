#include <vector>
#include <list>
#include <string>
#include <map>
#include <iostream>
#include <cstdlib>

#include "../chapter_5/split.h"

using namespace std;

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, std::vector<Rule> > Grammar;  

// Read in the grammar rules a table
Grammar read_grammar(istream& in) 
{
  string line;
  Grammar ret;

  while(getline(in, line)) {
    vector<string> entry = split(line);

    if(!entry.empty())
      ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
  }
  return ret;
}

// Is the given string bracketed?
bool bracketed(const string& s) {
  return s.size() > 1 && s[0] == '<' && s[s.size()-1] == '>';
}


// Generate a random number in the range 0->n
int nrand(int n)
{
  if(n <= 0 || n > RAND_MAX)
    throw domain_error("Number is out of range.");

  const int bucket_size = RAND_MAX / n;
  int r;

  do r = rand() / bucket_size;
  while(r >= n);

  return r;
}

// // Expand the input string (word) given as the second argument
// void gen_aux(const Grammar& g, const string& word, list<string>& ret)
// {
//   // first check if word is not bracketed, then append word
//   if(!bracketed(word)) {
//     ret.push_back(word);
//   } else {
//     // locate the rule that corresponds to word
//     map<string, Rule_collection>::const_iterator rule_it =
//       g.find(word);

//     if(rule_it == g.end())
//       throw logic_error("No rule found for that word.");

//     // fetch the set of possible rules 
//     const Rule_collection c = rule_it->second;
    
//     // from which we select one at random 
//     const Rule r = c[nrand(c.size())];

//     // recursively expand the selected rule
//     for(vector<string>::const_iterator i = r.begin();
//         i != r.end(); ++i) {
//       gen_aux(g, *i, ret);
//     }
//   }
// }

// // Generate a sentence given a grammar rule 
// list<string> gen_sentence(const Grammar& g) 
// {
//   list<string> ret;
//   gen_aux(g, "<sentence>", ret);
//   return ret;
// }


// Below is a different implementation using two vectors and 
// no recursive calls (q 7-6). One vector to hold the sentence 
// and one vector used as a stack for the rules

// Expand the input string (word) given as the second argument
void gen_aux(const  Grammar&         g, 
             const  string&          token,
                    vector<string>&  sentence,
                    vector<string>&  token_stack)
{
  // first check if token is not bracketed, then append token
  if(!bracketed(token)) {
    sentence.push_back(token);
  } else {
    // locate the rule that corresponds to token
    map<string, Rule_collection>::const_iterator rule_it =
      g.find(token);

    if(rule_it == g.end())
      throw logic_error("No rule found for that token.");

    // fetch the set of possible rules 
    const Rule_collection c = rule_it->second;
    
    // from which we select one at random 
    const Rule r = c[nrand(c.size())];

    // add the tokens in to the token stack in reverse order
    for(Rule::const_reverse_iterator i = r.rbegin(); 
        i != r.rend(); ++i) {
      token_stack.push_back(*i);
    }
  }
}

// Generate a sentence given a grammar rule 
vector<string> gen_sentence(const Grammar& g) 
{
  vector<string> sentence;
  vector<string> token_stack;
  token_stack.push_back("<sentence>");

  while(!token_stack.empty()) {
    string token = token_stack.back();
    token_stack.pop_back();
    gen_aux(g, token, sentence, token_stack);
  }
  return sentence;
}
