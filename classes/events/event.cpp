#include "event.h"

event::event() {
    clickobj = nullptr;
    keyevent = nullptr;
}

event::~event() {
    delete clickobj;
    delete keyevent;
    keysDown.clear();
}

void event::setClick(int x, int y, bool left){
    delete clickobj;
    clickobj = new Click(x, y);
    eventtype = CLICK;
    if (!left)
        eventtype = RCLICK;
}
void event::setKeyEvent(std::string key, bool down) {
    if (down && keyIsInKeysDown(key))
        return;
    delete keyevent;
    keyevent = new keyEvent(key, down);
    eventtype = KEYEVENT;
    if (down) {
        keysDown.push_back(key);
        checkKeySequences();
    }
    else
        removeKeyFromKeysDown(key);
}
void event::removeKeyFromKeysDown(std::string key) {
    for(unsigned int i = 0; i < keysDown.size(); i ++)
        if (keysDown[i] == key)
            keysDown.erase(keysDown.begin() + i);
}
void event::checkKeySequences() {
    if (keysDown.size() == 2 && keysDown[0] == "shift" && keyevent->getKey() == keysDown[1])
        shiftKeySequence(keysDown[1]);
}
void event::shiftKeySequence(std::string secondKey) {
    if (secondKey == "1") {delete keyevent;keyevent = new keyEvent("!", true);}
    if (secondKey == "2") {delete keyevent;keyevent = new keyEvent("@", true);}
    if (secondKey == "3") {delete keyevent;keyevent = new keyEvent("#", true);}
    if (secondKey == "4") {delete keyevent;keyevent = new keyEvent("$", true);}
    if (secondKey == "5") {delete keyevent;keyevent = new keyEvent("%", true);}
    if (secondKey == "6") {delete keyevent;keyevent = new keyEvent("^", true);}
    if (secondKey == "7") {delete keyevent;keyevent = new keyEvent("&", true);}
    if (secondKey == "8") {delete keyevent;keyevent = new keyEvent("*", true);}
    if (secondKey == "9") {delete keyevent;keyevent = new keyEvent("(", true);}
    if (secondKey == "0") {delete keyevent;keyevent = new keyEvent(")", true);}
    if (secondKey == "-") {delete keyevent;keyevent = new keyEvent("_", true);}
    if (secondKey == "=") {delete keyevent;keyevent = new keyEvent("+", true);}
    if (secondKey == "[") {delete keyevent;keyevent = new keyEvent("{", true);}
    if (secondKey == "]") {delete keyevent;keyevent = new keyEvent("}", true);}
    if (secondKey == "\\") {delete keyevent;keyevent = new keyEvent("|", true);}
    if (secondKey == ";") {delete keyevent;keyevent = new keyEvent(":", true);}
    if (secondKey == "'") {delete keyevent;keyevent = new keyEvent("\"", true);}
    if (secondKey == ",") {delete keyevent;keyevent = new keyEvent("<", true);}
    if (secondKey == ".") {delete keyevent;keyevent = new keyEvent(">", true);}
    if (secondKey == "/") {delete keyevent;keyevent = new keyEvent("?", true);}
}
bool event::keyIsInKeysDown(std::string key) {
    for(unsigned int i=0; i<keysDown.size(); i++)
        if (keysDown[i] == key)
            return true;
    return false;
}
keyEvent* event::getKeyEvent() {
    return keyevent;
}
Click* event::getClick() {
    return clickobj;
}
std::vector<std::string> event::getKeysDown() {
    return keysDown;
}
