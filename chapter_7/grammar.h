#ifndef GUARD_grammar_h
#define GUARD_grammar_h

#include <vector>
#include <list>
#include <string>
#include <map>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, std::vector<Rule> > Grammar;  

Grammar read_grammar(std::istream& in);

//std::list<std::string> gen_sentence(const Grammar& g); 

std::vector<std::string> gen_sentence(const Grammar& g); 

bool bracketed(const std::string& s);

// void gen_aux(const Grammar& g, const std::string word, 
//              std::list<std::string>& ret);

void gen_aux(const  Grammar&                   g, 
             const  std::string&               token,
                    std::vector<std::string>&  sentence,
                    std::vector<std::string>&  token_stack);

int nrand(int n);

#endif 