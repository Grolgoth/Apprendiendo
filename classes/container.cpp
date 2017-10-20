#include "container.h"

container::container(View* view) {
    //Inlezen uit file
    initFonts(view->getFilepath());
    initRenderers(view);
    delegator = new lvlDelegator(view, &fonts, this);
}

container::~container() {
    delete delegator;
    for (unsigned int i=0; i<fonts.size(); i++)
        TTF_CloseFont(fonts[i]);
    fonts.clear();
    for (unsigned int i=0; i<textRenderers.size(); i++)
        delete textRenderers[i];
    textRenderers.clear();
}

std::vector<textRenderer*> container::getTextRenderers() {
    return textRenderers;
}
event* container::getEvent() {
    return &Event;
}
int container::getMx() {
    return mx;
}
int container::getMy() {
    return my;
}
void container::setMx(int x) {
    mx = x;
}
void container::setMy(int y) {
    my = y;
}
gameDelegator* container::getDelegator() {
    return delegator;
}
void container::setSaveFile(std::string savefile) {
    saveFile = savefile;
}
void container::initFonts(std::string filepath) {
    fonts.push_back(TTF_OpenFont((filepath + "\\fonts\\CR.ttf").c_str(), 75));
    fonts.push_back(TTF_OpenFont((filepath + "\\fonts\\BOP.ttf").c_str(), 35));
    fonts.push_back(TTF_OpenFont((filepath + "\\fonts\\CR.ttf").c_str(), 34));
    fonts.push_back(TTF_OpenFont((filepath + "\\fonts\\CR.ttf").c_str(), 28));
    fonts.push_back(TTF_OpenFont((filepath + "\\fonts\\CR.ttf").c_str(), 24));
}
void container::initRenderers(View* view) {
    textRenderers.push_back(new textRenderer(view, fonts[1]));
}
