#ifndef HABLARNEW_DIALOG_H_INCLUDED
#include <iostream>
#include <vector>
#define HABLARNEW_DIALOG_H_INCLUDED

std::string getResponse(int step, std::string* variableNames = nullptr);
std::vector<std::string> getButtonNames(int step, std::string* variableNames = nullptr);

#endif // HABLARNEW_DIALOG_H_INCLUDED
