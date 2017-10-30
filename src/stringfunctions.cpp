#include "stringfunctions.h"

int indexOf(std::string toSearch, std::string snippet) {
    for (unsigned int i=0; i<toSearch.size(); i++) {
        for (unsigned int j=0; j<snippet.size(); j++) {
            if (toSearch[i + j] != snippet[j])
                break;
            if (j == snippet.size() - 1)
                return i;
        }
    }
    return -1;
}

bool stringContains(std::string toSearch, std::string snippet) {
    if (indexOf(toSearch, snippet) < 0)
        return false;
    return true;
}

std::string replaze(std::string targetString, std::string targetText, std::string replaceText, bool all) {
    if (!stringContains(targetString, targetText))
        return targetString;
    std::string newString = "";
    int firstIndex = indexOf(targetString, targetText);
    for (int i=0; i<firstIndex; i++)
        newString += targetString[i];
    newString += replaceText;
    for(unsigned int i=firstIndex + targetText.size(); i<targetString.size(); i++)
            newString += targetString[i];
    while (all && stringContains(newString, targetText))
        newString = replaze(newString, targetText, replaceText, false);
    return newString;
}

std::string subString(std::string target, int beginIndex, int endIndex) {
    if (endIndex <= beginIndex || (unsigned)endIndex > target.size())
        endIndex = target.size();
    std::string buffer = "";
    for (int i=beginIndex; i<endIndex; i++)
        buffer += target[i];
    return buffer;
}

bool toBool(std::string target) {
    if (target != "true")
        return false;
    return true;
}
