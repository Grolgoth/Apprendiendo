#include "click.h"

Click::Click(int x, int y) {
    mouseX = x;
    mouseY = y;
}

Click::~Click() {

}

int Click::getX() {
    return mouseX;
}

int Click::getY() {
    return mouseY;
}
