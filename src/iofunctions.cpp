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
        name[i] = -1* name[i] + 50 -i%2;
    }
    return name;
}

std::string reAssemble(std::string name, std::string append, std::string endSyntax) {
    name = subString(name, 0, indexOf(name, endSyntax));
    name += append;
    name += endSyntax;
    return name;
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
