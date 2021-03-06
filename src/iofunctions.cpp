#include "iofunctions.h"

std::string encrypt(std::string name)
{
    for (unsigned int i = 0; i < name.size(); i++)
    {
        name[i] = 50 - name[i] + i%2;
    }
    return name;
}

std::string decrypt(std::string name) {
    for (unsigned int i = 0; i < name.size(); i++)
    {
        name[i] = -1* name[i] + 50 +i%2;
    }
    return name;
}

std::string reAssemble(std::string name, std::string append, std::string endSyntax) {
    name = subString(name, 0, indexOf(name, endSyntax));
    name += append;
    name += endSyntax;
    return name;
}

void saveGame(std::string path, std::string filename, std::string toWrite) {
    std::ofstream out(path + filename);
    out << encrypt(toWrite);
    out.close();
}

void writeNewSaveGame(std::string path, std::string filename, std::string toWrite) {
    if (!storeSavegames(path).empty() && vectorContains(storeSavegames(path), filename)) {
        for (int i = 0; true; i++) {
            filename = reAssemble(filename, "" + i, subString(filename, indexOf(filename, "."), 0));
            if (!vectorContains(storeSavegames(path), filename))
                break;
        }
    }
    std::ofstream out(path + "/" + filename);
    out << encrypt(toWrite);
    out.close();
}

std::string getSaveGame(std::string savegame) {
    std::string result = "";
    std::ifstream in(savegame);
    char c;
    while (in >> c)
        result += c;
    in.close();
    return decrypt(result);
}

char strToChar(const char* str) {
    char parsed = 0;
    for (int i = 0; i < 8; i++) {
        if (str[i] == '1') {
            parsed |= 1 << (7 - i);
        }
    }
    return parsed;
}

std::string getBinaryFile(std::string file) {
    std::ifstream in(file);
    in.unsetf(std::ios_base::skipws);
    std::string File = "";
    std::string buffer = "";
    char c;
    while (in >> c) {
        if (c != '\n' && c != ' ')
            buffer += c;
        else {
            File += strToChar(buffer.c_str());
            buffer = "";
        }
    }
    in.close();
    return File;
}

std::vector<std::string> storeSavegames(std::string path) {
    std::vector<std::string> saveGames;
    std::string arg = "cd " + path + " && java SaveFiles " + path;
    system(arg.c_str());
    std::ifstream in(path + "save\\savegames.txt");
    char a;
    std::string buffer = "";
    while(in >> a) {
        buffer += a;
        if(a == '\n') {
            saveGames.push_back(buffer);
            buffer = "";
        }
    }
    if (! stringContains(buffer, "Nosavegamesfound."))
        saveGames.push_back(buffer);
    else
        saveGames.clear();
    in.close();
    arg = replaze(arg, "java SaveFiles " + path, "del savegames.txt", false);
    system(arg.c_str());
    return saveGames;
}
