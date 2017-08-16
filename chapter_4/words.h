#ifndef GUARD_words_h
#define GUARD_words_h

#include <vector>
#include <string>
#include <istream>

std::istream& read_words(std::istream&, std::vector<std::string>&);
void count_words(std::vector<std::string>, 
                 std::vector<std::string>&,
                 std::vector<int>&);
void display_words(const std::vector<std::string>&);
void display_word_counts(const std::vector<std::string>&, const std::vector<int>&); 

#endif
