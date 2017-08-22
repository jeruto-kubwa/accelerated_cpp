#ifndef GUARD_grammar_h
#define GUARD_grammar_h

#include <vector>
#include <string>
#include <map>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, std::vector<Rule> > Grammar;  

Grammar read_grammar(std::istream& in);

std::vector<std::string> gen_sentence(const Grammar& g); 

bool bracketed(const std::string& s);

void gen_aux(const Grammar& g, const std::string word, 
             std::vector<std::string>& ret);

int nrand(int n);

#endif 