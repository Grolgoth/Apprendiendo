#ifndef ROOMHANDLER_H_INCLUDED
#include "room.h"
#define ROOMHANDLER_H_INCLUDED

int ienterPressed(room* Room);
std::string getResult(room* Room);
int checkAnswer(room* Room, std::string write, gameDelegator* gd, event* Event);
#endif // ROOMHANDLER_H_INCLUDED
