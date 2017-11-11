#include "savestructs.h"
#include "room.h"
#include "hablar.h"
#include "location.h"

using namespace std;

vector<string> getElements(string savegame, string element) {
    vector<string> result;
    string game = getSaveGame(savegame);
    string sub = subString(game, indexOf(game, "<" + element + ">") + 2 + element.length(), indexOf(game, "</" + element + ">"));
    game = "";
    for (unsigned int i=0; i<sub.length(); i++) {
        bool continues = true;
        if (sub[i] == '<' && sub[i + 1] != '/' && !(sub[i+1] == '\n' || sub[i+1] == '<')) {
            for (unsigned int h=i+1; continues; h++) {
                if (sub[h] == '>') {
                    continues = false;
                    result.push_back(game);
                    game  = "";
                    continue;
                }
                game += sub[h];
            }
        }
        else if (sub[i] == '>' && !(sub[i+1] == '\n' || sub[i+1] == '<' || i + 1 >= sub.size())) {
            for (unsigned int h=i+1; continues; h++) {
                if (sub[h] == '<') {
                    continues = false;
                    result.push_back(game);
                    game  = "";
                    continue;
                }
                game += sub[h];
            }
        }
    }
    return result;
}

void singleElement(personality* p, string element, string value) {
    if (element == "noMorning")
        p->noMorning = true;
    else if (element == "Name")
        p->name = value;
    else if (element == "Gender")
        p->gender = value;
    else if (element == "Hobbies") {
        for (unsigned int i = 0; i<value.length(); i++)
            p->hobbies[i] = value[i];
    }
    else if (element == "Funny")
        p->funny = true;
    else if (element == "Arrogant")
        p->arrogant = true;
    else if (element == "SocietyModerateRooted")
        p->societyModerateRooted = true;
    else if (element == "SocietyRooted")
        p->societyRooted = true;
    else if (element == "FreeThinking")
        p->freeThinking = true;
    else if (element == "Career")
        p->carrier = true;
    else if (element == "Curious")
        p->curious = true;
    else if (element == "Aggressive")
        p->aggressive = true;
    else if (element == "Loyal")
        p->loyal = true;
    else if (element == "Love")
        p->love = true;
    else if (element == "Asshole")
        p->asshole = true;
    else if (element == "Brave")
        p->brave = true;
    else if (element == "Content")
        p->content = true;
    else if (element == "Chaotic")
        p->chaotic = true;
    else if (element == "Democrat")
        p->democrat = true;
    else if (element == "Dogooder")
        p->doGooder = true;
    else if (element == "Humble")
        p->humble = true;
    else if (element == "Intelligent")
        p->intelligent = true;
    else if (element == "Nice")
        p->nice = true;
    else if (element == "Optimistic")
        p->optimistic = true;
    else if (element == "Realistic")
        p->realistic = true;
    else if (element == "Shy")
        p->shy = true;
    else if (element == "Patient")
        p->patient = true;
    else if (element == "Sportive")
        p->sportive = true;
    else if (element == "Talksalot")
        p->talksalot = true;
    else if (element == "Stubborn")
        p->stubborn = true;
}
string SingleElement(vector<string> elements, string element) {
    for (unsigned int i = 0; i<elements.size() - 1; i+=2) {
        if (element == elements[i]) {
            return elements[i + 1];
        }
    }
    return "";
}

void fromSave(string savegame, personality* p) {
    vector<string> elements = getElements(savegame, "Personality");
    for (unsigned int i = 0; i<elements.size() - 1; i+=2)
        singleElement(p, elements[i], elements[i+1]);
}

location* locationFromSave(string savegame, View* view, hablar* menu) {
    string game = getSaveGame(savegame);
    string loc = subString(game, indexOf(game, "<Location>") + 10, indexOf(game, "</Location>"));
    if (loc == "Room") {
        return new room(savegame, view, menu, "Un Cuarto");
    }
    return nullptr;
}

void addElement(string savegame, string name, string content) {
    string game = getSaveGame(savegame);
    string game1 = subString(game, 0, indexOf(game, "</Save>"));
    game1 += "\n<" + name + ">" + content + "</" + name + ">" + "</Save>";
    ofstream out(savegame);
    out.unsetf(ios_base::skipws);
    out << encrypt(game1);
    out.close();
}

void setElement(string savegame, string name, string element, string state) {
    string game = getSaveGame(savegame);
    string cadre = subString(game, indexOf(game, "<" + name + ">") + 2 + name.length(), indexOf(game, "</" + name + ">"));
    string newcadre = replaze(cadre,
        subString(cadre, indexOf(cadre, "<" + element + ">"), indexOf(cadre, "</" + element + ">") + 3 + element.length())
        , "<" + element + ">" + state + "</" + element + ">", false);
    game = replaze(game, cadre, newcadre, false);
    ofstream out(savegame);
    out.unsetf(ios_base::skipws);
    out << encrypt(game);
    out.close();
}
