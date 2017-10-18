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
    backGround = SDL_CreateRGBSurface(SDL_SWSURFACE,view->WINW,view->WINH,32,0xff000000,0x00ff0000,0x0000ff00,0x000000ff);
    SDL_Surface* tempSurf = load_image(view->getFilepath() + "img\\backgrounds\\strookje.bmp");
    SDL_Rect R;R.x=view->WINW-tempSurf->w; R.y=view->WINH-tempSurf->h; R.h=tempSurf->h; R.w=tempSurf->w;
    SDL_BlitSurface(tempSurf, NULL, backGround, &R);
    if (saveGames.size() > 4) {
        int arrowButtonH = getImageDimension(view->getFilepath() + "img/scrollArrDown.bmp", false);
        buttons.push_back(button(view->WINW-tempSurf->w, view->WINH-arrowButtonH, view, font,
            "NOTEXT" + view->getFilepath() +"img/scrollArrDown.bmp#downarrow", "", "", true));
        buttons.push_back(button(view->WINW-tempSurf->w, view->WINH-tempSurf->h, view, font,
            "NOTEXT" + view->getFilepath() +"img/scrollArrUp.bmp#uparrow", "", "", true));
    }
    SDL_FreeSurface(tempSurf);
    if (saveGames.empty()) {
        SDL_Color color = createColor(160, 80, 4, 255);
        tempSurf = TTF_RenderText_Solid(font, "No ya hay juegos!", color);
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
