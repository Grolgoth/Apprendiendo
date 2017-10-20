#ifndef STRINGFUNCTIONS_H_INCLUDED
#include <iostream>
#define STRINGFUNCTIONS_H_INCLUDED

int indexOf(std::string toSearch, std::string snippet);
bool stringContains(std::string toSearch, std::string snippet);
std::string replaze(std::string targetString, std::string targetText, std::string replaceText, bool all);
std::string subString(std::string target, int beginIndex, int endIndex);
#endif // STRINGFUNCTIONS_H_INCLUDED
