#include "room.h"
#include "hablar.h"
#include "roomHandler.h"

room::room(std::string savegame, View* view, hablar* menu, std::string Name):location(savegame, view, menu, Name)
{
    //ctor
}

room::~room()
{
    //dtor
}

void room::buttonClicked(std::string buttonName, gameDelegator* gd) {

}

void room::handleEvent(event* Event, gameDelegator* gd) {
    if (textEventType == 2 ) //if we are waiting for a single button to be clicked
        return;
    settings();
    if (Event->eventtype == Event->KEYEVENT && Event->getKeyEvent()->getDown() && !gd->getTextRenderers()[0]->getRendering()) {
        if (Event->getKeyEvent()->getKey() == "enter") {
            textEventType = ienterPressed(this);
            if (textEventType == 0 || (textEventType == 1 && write == ""))
                gd->getTextRenderers()[0]->render(getResult(this), Event);
            else if(textEventType == 1 && write != "") {
                textEventType = checkAnswer(this, write, gd, Event);
                if (textEventType == 4) {
                    hablarSwap(getResult(this), gd);
                    return;
                }
                write = "";
            }
        }
        else if(textEventType == 1) {
            if (Event->getKeyEvent()->getKey() == "backspace") {
                if (write.size() == 1)
                    write = "";
                else
                    write = subString(write, 0 , write.size() - 1);
            }
            else
                write += written(Event->getKeyEvent()->getKey());
            gd->getTextRenderers()[0]->writing(write);
        }
    }
}
