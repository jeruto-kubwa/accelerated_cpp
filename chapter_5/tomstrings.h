#ifndef GUARD_median_h
#define GUARD_median_h

#include <vector>
#include <string>

std::string::size_type width(const std::vector<std::string>&);

std::vector<std::string> frame(const std::vector<std::string>&);

void display_picture(const std::vector<std::string>&);

void print_string_vector(const std::vector<std::string>&);

std::vector<std::string> vcat(const std::vector<std::string>&, const std::vector<std::string>&);

std::vector<std::string> hcat(const std::vector<std::string>&, const std::vector<std::string>&);

std::istream& read_picture(std::istream&, std::vector<std::string>&);

std::string joinv(const std::vector<std::string>&);

std::vector<std::string> center(const std::vector<std::string>&);

bool is_palindrome(const std::string&);

bool contains_character(const std::string&, char);

bool has_ascender_or_descender(const std::string&);

#endif