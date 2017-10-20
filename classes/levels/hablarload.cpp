#include "hablarload.h"
#include "gamedelegator.h"
#include "hablarmain.h"

void hablarLoad::storeSavegames(View* view) {
    std::string arg = "cd " + view->getFilepath() + "save && java SaveFiles " + view->getFilepath() + "save";
    system(arg.c_str());
    std::ifstream in(view->getFilepath() + "save\\savegames.txt");
    char a;
    std::string buffer = "";
    while(in >> a) {
        buffer += a;
        if(a == '\n') {
            saveGames.push_back(buffer);
            buffer = "";
        }
    }
    if (! stringContains(buffer, "Nosavegamesfound."))
        saveGames.push_back(buffer);
    else
        saveGames.clear();
    in.close();
    arg = replaze(arg, "java SaveFiles " + view->getFilepath() + "save", "del savegames.txt", false);
    system(arg.c_str());
}

void hablarLoad::makeButtons(View* view, TTF_Font* font) {
    for (unsigned int i=0; i<saveGames.size(); i++)
        buttons.push_back(button(-80, 50 + 150* i + viewOffset, view, font, replaze(saveGames[i],".save", "", false), view->getFilepath() + "img/LB.bmp"));
}

hablarLoad::hablarLoad(View* view, TTF_Font* font) {
    storeSavegames(view);
    if (saveGames.size() > 4)
        scrollBackground(view, false);
    if (saveGames.empty()) {
        SDL_Color color = createColor(160, 80, 4, 255);
        SDL_Surface* tempSurf = TTF_RenderText_Solid(font, "No ya hay juegos!", color);
        SDL_Rect R2; R2.x=(view->WINW-tempSurf->w)/2; R2.y = 200; R2.w=tempSurf->w; R2.h=tempSurf->h;
        SDL_BlitSurface(tempSurf, NULL, backGround, &R2);
        SDL_FreeSurface(tempSurf);
    }
    makeButtons(view, font);
    buttons.push_back(button(0, 470, view, font, "Vuelva", view->getFilepath() + "img/LB.bmp"));
}

hablarLoad::~hablarLoad()
{
    //dtor
}
void hablarLoad::buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button) {
    Event->eventtype = Event->SPECIAL;
    if (Button->getName() == "Dejar")
        Event->eventtype = Event->QUIT;
    else if (Button->getName() == "Vuelva") {
        gameDelegator->setStandard(new hablarMain(view, gameDelegator->getFonts()[0]));
        return;
    }
}

void hablarLoad::checkEvents(View* view, event* Event, gameDelegator* gameDelegator) {
    handleButtons(view, Event, gameDelegator);
}
