#include "hablarnew.h"
#include "gamedelegator.h"

hablarNew::hablarNew(View* view, TTF_Font* font) {
    texts[0] = "Pues&.&.&. quieres hablar?? Primero tienes que decirme su nombre. Escribe tu nombre por favor.";
}

hablarNew::~hablarNew()
{
    //dtor
}

void hablarNew::checkEvents(View* view, event* Event, gameDelegator* gameDelegator) {
    handleButtons(view, Event, gameDelegator);
    if (texts[0] != "") {
        gameDelegator->getTextRenderers()[0]->render(texts[0]);
        texts[0] = "";
    }
}
void hablarNew::buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button) {

}
