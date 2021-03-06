#ifndef IOFUNCTIONS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <windows.h>
#include "stringfunctions.h"
#define IOFUNCTIONS_H_INCLUDED

std::string encrypt(std::string name);
std::vector<std::string> storeSavegames(std::string path);
std::string decrypt(std::string name);
std::string getSaveGame(std::string savegame);
std::string getBinaryFile(std::string file);
void writeNewSaveGame(std::string path, std::string filename, std::string toWrite);
void saveGame(std::string path, std::string filename, std::string toWrite);
#endif // IOFUNCTIONS_H_INCLUDED
