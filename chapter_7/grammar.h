#ifndef GUARD_grammar_h
#define GUARD_grammar_h

#include <list>
#include <string>
#include <map>

typedef std::list<std::string> Rule;
typedef std::list<Rule> Rule_collection;
typedef std::map<std::string, std::list<Rule> > Grammar;  

Grammar read_grammar(std::istream& in);

std::list<std::string> gen_sentence(const Grammar& g); 

bool bracketed(const std::string& s);

void gen_aux(const Grammar& g, const std::string word, 
             std::list<std::string>& ret);

int nrand(int n);

#endif 