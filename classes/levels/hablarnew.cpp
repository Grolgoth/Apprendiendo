#include "hablarnew.h"
#include "gamedelegator.h"

hablarNew::hablarNew(View* view, TTF_Font* font) {
    step = 0;
    backGround = SDL_CreateRGBSurface(SDL_SWSURFACE,view->WINW,view->WINH,32,0xff000000,0x00ff0000,0x0000ff00,0x000000ff);
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
        gameDelegator->getTextRenderers()[0]->render(getResponse(0, nullptr));
        step ++;
    }
    if (step == 1 && !gameDelegator->getTextRenderers()[0]->getRendering())
        step ++;
    if (step == 3) {
        gameDelegator->getTextRenderers()[0]->render(getResponse(2, nullptr));
        step ++;
    }
    if (step == 4 && !gameDelegator->getTextRenderers()[0]->getRendering())
        step4(view, gameDelegator);
    if (step == 6)
        step6(view, gameDelegator);
    if (Event->eventtype == Event->KEYEVENT) {
        if (Event->getKeyEvent()->getRepeat() && keyrepeatdelay < 1) {
            keyrepeatdelay ++;
            return;
        }
        keyrepeatdelay = 0;
        if(step == 2 && Event->getKeyEvent()->getDown())
            step2(Event, gameDelegator);
        if (step == 7 && Event->getKeyEvent()->getKey() == "enter")
            step7(gameDelegator);
    }
}
void hablarNew::buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button) {
    Event->eventtype = Event->SPECIAL;
    if (step == 5)
        step5(Button);
}
void hablarNew::step2(event* Event, gameDelegator* gd) {
    if (keyCheck(Event->getKeyEvent()->getKey(), std::vector<std::string>{"enter", "backspace"})) {
            if (Event->getKeyEvent()->getKey() == "enter") {
                checkName(p.name);
                if (step == 1) {
                    gd->getTextRenderers()[0]->render(getResponse(1, nullptr));
                    Event->eventtype = Event->SPECIAL;
                }
            }
            else if (p.name.size() > 0) {
                p.name = p.name.substr(0, p.name.size() - 1);
                gd->getTextRenderers()[0]->writing(p.name);
            }
    }
    else if (step == 2 && Event->getKeyEvent()->getDown()) {
        p.name += written(Event->getKeyEvent()->getKey());
        gd->getTextRenderers()[0]->writing(p.name);
    }
}
void hablarNew::step4(View* view, gameDelegator* gd) {
    SDL_Color color = createColor(160, 80, 4, 255);
    SDL_Surface* tempSurf = TTF_RenderText_Solid(gd->getFonts()[0], "Yo soy...", color);
    SDL_Rect R2; R2.x=(view->WINW-tempSurf->w)/2; R2.y = 2;
    SDL_BlitSurface(tempSurf, NULL, backGround, &R2);
    SDL_FreeSurface(tempSurf);
    buttons.push_back(button(0, 100, view, gd->getFonts()[2], "Un Hombre", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(250, 100, view, gd->getFonts()[2], "Una Mujer", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(500, 100, view, gd->getFonts()[2], "¡No creas que puedes categorizarme!", view->getFilepath() + "img/LB.bmp"));
    step ++;
}
void hablarNew::step5(button* Button) {
    if (Button->getName() == "Un Hombre")
            p.gender = "M";
        else if (Button->getName() == "Una Mujer")
            p.gender = "F";
        else
            p.gender = "N";
    step ++;
}
void hablarNew::step6(View* view, gameDelegator* gd) {
    clearButtons();
    SDL_FreeSurface(backGround);
    backGround = nullptr;
    scrollBackground(view, true);
    std::string variableNames[2] = {p.name, p.gender};
    gd->getTextRenderers()[0]->render(getResponse(6, variableNames));
    std::vector<std::string> buttonNames = getButtonNames(6, variableNames);
    buttons.push_back(button(true, 10, 10, view, gd->getFonts()[2], buttonNames[0], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 160, view, gd->getFonts()[4], buttonNames[1], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 310, view, gd->getFonts()[4], buttonNames[2], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 460, view, gd->getFonts()[2], buttonNames[3], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 10, view, gd->getFonts()[2], buttonNames[4], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 160, view, gd->getFonts()[2], buttonNames[5], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 310, view, gd->getFonts()[2], buttonNames[6], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 460, view, gd->getFonts()[2], buttonNames[7], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 610, view, gd->getFonts()[2], buttonNames[8], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 610, view, gd->getFonts()[2], buttonNames[9], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 760, view, gd->getFonts()[2], buttonNames[10], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 760, view, gd->getFonts()[2], buttonNames[11], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 910, view, gd->getFonts()[2], buttonNames[12], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 910, view, gd->getFonts()[2], buttonNames[13], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, -1, 1060, view, gd->getFonts()[4], buttonNames[14], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 1210, view, gd->getFonts()[4], buttonNames[15], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 1210, view, gd->getFonts()[2], buttonNames[16], view->getFilepath() + "img/LB.bmp"));
    step ++;
}
void hablarNew::step7(gameDelegator* gd) {
    std::vector<std::string> traits;
    for (unsigned int i=0; i<buttons.size(); i++)
        if(buttons[i].getWasclicked())
            traits.push_back(buttons[i].getName());
    if (traits.size() > 12)
        gd->getTextRenderers()[0]->render(getResponse(7, &p.gender));
    else if (traits.size() < 4) {
        std::string number = "" + traits.size();
        gd->getTextRenderers()[0]->render(getResponse(8, &number));
    }
    else {
        clearButtons();
        step ++;
    }
}
