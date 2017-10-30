#ifndef STRINGFUNCTIONS_H_INCLUDED
#include <iostream>
#include <vector>
#define STRINGFUNCTIONS_H_INCLUDED

int indexOf(std::string toSearch, std::string snippet);
bool stringContains(std::string toSearch, std::string snippet);
template <typename T>
bool vectorContains(std::vector<T> vect, T element) {
    for (unsigned int i = 0; i<vect.size(); i++)
        if (vect[i] == element)
            return true;
    return false;
}
std::string replaze(std::string targetString, std::string targetText, std::string replaceText, bool all);
std::string subString(std::string target, int beginIndex, int endIndex);
bool toBool(std::string target);
#endif // STRINGFUNCTIONS_H_INCLUDED
