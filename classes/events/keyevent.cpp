#include "keyevent.h"

keyEvent::keyEvent(std::string key, bool down) {
    this->key = key;
    this->down = down;
}

keyEvent::~keyEvent() {

}

std::string keyEvent::getKey() {
    return key;
}

bool keyEvent::getDown() {
    return down;
}
