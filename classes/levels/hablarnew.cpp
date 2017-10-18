#include "hablarnew.h"
#include "gamedelegator.h"

hablarNew::hablarNew(View* view, TTF_Font* font) {
    step = 0;
    texts[0] = "Pues&.&.&. quieres hablar?? Primero tienes que decirme su nombre. Escribe tu nombre por favor.\n";
    texts[1] = "Que? !Es un nombre tan largo! Ya no puedo recordar. Dime otra vez por favor.\n";
    texts[2] = "Eso es su nombre?&& Hmm.&.&.& Supongo que lo suficiente. Pues,&& Dime algo sobre de ti.\n";
}

hablarNew::~hablarNew()
{
    //dtor
}
void hablarNew::checkName(std::string name) {
    if (name.size() > 0 && name.size() < 40)
        step++;
    else {
        p.name = "";
        step = 1;
    }

}
void hablarNew::checkEvents(View* view, event* Event, gameDelegator* gameDelegator) {
    handleButtons(view, Event, gameDelegator);
    if (step == 0) {
        gameDelegator->getTextRenderers()[0]->render(texts[0]);
        step ++;
    }
    if (step == 1 && !gameDelegator->getTextRenderers()[0]->getRendering())
        step ++;
    if (step == 3) {
        gameDelegator->getTextRenderers()[0]->render(texts[2]);
        step ++;
    }
    if (Event->eventtype == Event->KEYEVENT) {
        if (Event->getKeyEvent()->getRepeat() && keyrepeatdelay < 1) {
            keyrepeatdelay ++;
            return;
        }
        keyrepeatdelay = 0;
        if (step == 2 && Event->getKeyEvent()->getDown() && keyCheck(Event->getKeyEvent()->getKey(), std::vector<std::string>{"enter", "backspace"})) {
            if (Event->getKeyEvent()->getKey() == "enter") {
                checkName(p.name);
                if (step == 1)
                    gameDelegator->getTextRenderers()[0]->render(texts[1]);
            }
            else if (p.name.size() > 0) {
                p.name = p.name.substr(0, p.name.size() - 1);
                gameDelegator->getTextRenderers()[0]->writing(p.name);
            }
        }
        else if (step == 2 && Event->getKeyEvent()->getDown()) {
            p.name += written(Event->getKeyEvent()->getKey());
            gameDelegator->getTextRenderers()[0]->writing(p.name);
        }
    }
}
void hablarNew::buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button) {
    Event->eventtype = Event->SPECIAL;
}
