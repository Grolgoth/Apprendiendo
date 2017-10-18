#include "gamedelegator.h"
#include "container.h"

gameDelegator::gameDelegator() {
    //ctor
}

gameDelegator::~gameDelegator() {
    //dtor
}

std::vector<TTF_Font*> gameDelegator::getFonts() {
    return fonts;
}
std::vector<textRenderer*> gameDelegator::getTextRenderers() {
    return textRenderers;
}
void checkRenderers(View* view, textRenderer* renderer, container* bin) {
    if (renderer->getRendering()) {
        if (bin->getEvent()->eventtype == bin->getEvent()->KEYEVENT && keyCheck(bin->getEvent()->getKeyEvent()->getKey(),
            std::vector<std::string>{"space", "enter"}) && bin->getEvent()->getKeyEvent()->getDown())
            renderer->renderstep(true);
        else
            renderer->renderstep(false);
        bin->getEvent()->eventtype = bin->getEvent()->SPECIAL;
    }
    if (!renderer->getNext())
            apply_surface(0,300,renderer->getCurrent(),view->getTarget());
}
void gameDelegator::handleRenderers(View* view, std::vector<textRenderer*> renderers, container* bin) {
    for (unsigned int i=0; i<renderers.size(); i++) {
        if (renderers[i]->getRendering() || !renderers[i]->getNext()) {
            checkRenderers(view, renderers[i], bin);
            break;
        }
    }
}
lvlDelegator::lvlDelegator(View* view, std::vector<TTF_Font*>* vectptrfonts, container* bin) {
    fonts = *vectptrfonts;
    standard = new hablarMain(view, fonts[0]);
    textRenderers = bin ->getTextRenderers();
}

lvlDelegator::~lvlDelegator() {
    delete standard;
}

void lvlDelegator::delegate(View* view, container* bin) {
    standard->show(view, bin->getEvent());
    standard->checkEvents(view, bin->getEvent(), this);
    handleRenderers(view, bin->getTextRenderers(), bin);
    view->render();
}

void lvlDelegator::setStandard(Level* lvl) {
    delete standard;
    standard = lvl;
}

Level* lvlDelegator::getStandard() {
    return standard;
}
