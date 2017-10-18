#include "keyevent.h"

keyEvent::keyEvent(std::string key, bool down) {
    this->key = key;
    this->down = down;
    repeat = false;
}

keyEvent::~keyEvent() {

}

void keyEvent::setRepeat (bool state) {
    repeat = state;
}

bool keyEvent::getRepeat() {
    return repeat;
}

std::string keyEvent::getKey() {
    return key;
}

bool keyEvent::getDown() {
    return down;
}
