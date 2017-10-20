#include "level.h"
#include "gamedelegator.h"

Level::Level() {
    //ctor
}

Level::~Level() {
    if (backGround != nullptr)
        SDL_FreeSurface(backGround);
     clearButtons();
}

void Level::show(View* view, event* Event) {
    if (backGround != nullptr)
        SDL_BlitSurface(backGround, NULL, view->getTarget(), NULL);
    Click* click = nullptr;
    std::vector<button>* buttons = getButtons();
    if (Event->eventtype == Event->CLICK)
            click = Event->getClick();
    for (unsigned int i=0; i<buttons->size(); i++) {
        SDL_Rect R = buttons->operator[](i).getRect();
        R.y += viewOffset;
        if (Event->eventtype == Event->CLICK) {
            if (buttons->operator[](i).clicked(click->getX(), click->getY())) {
                SDL_BlitSurface(buttons->operator[](i).getSurface(true), NULL, view->getTarget() ,&R);
                continue;
            }
        }
        SDL_BlitSurface(buttons->operator[](i).getSurface(false), NULL, view->getTarget() ,&R);
    }
}

std::vector<button>* Level::getButtons() {
    return &buttons;
}

button* Level::checkButtons(int x, int y){
    for (unsigned int i=0; i<buttons.size(); i++)
        if (buttons[i].clicked(x, y))
            return &(buttons[i]);
    return nullptr;
}

void Level::handleButtons(View* view, event* Event, gameDelegator* gameDelegator) {
button* Button = nullptr;
    if (Event->eventtype == Event->CLICK)
        Button = checkButtons(Event->getClick()->getX(), Event->getClick()->getY());
    if (Button != nullptr)
        buttonClicked(view, Event, gameDelegator, Button);
}

void Level::setViewOffset(int offset) {
    viewOffset = offset;
}

void Level::scrollBackground(View* view, bool withTextBox) {
    if (backGround != nullptr)
        SDL_FreeSurface(backGround);
    if (!withTextBox) {
        backGround = SDL_CreateRGBSurface(SDL_SWSURFACE,view->WINW,view->WINH,32,0xff000000,0x00ff0000,0x0000ff00,0x000000ff);
        SDL_Surface* tempSurf = load_image(view->getFilepath() + "img\\backgrounds\\strookje.bmp");
        SDL_Rect R;R.x=view->WINW-tempSurf->w; R.y=view->WINH-tempSurf->h; R.h=tempSurf->h; R.w=tempSurf->w;
        SDL_BlitSurface(tempSurf, NULL, backGround, &R);
        int arrowButtonH = getImageDimension(view->getFilepath() + "img/scrollArrDown.bmp", false);
        buttons.push_back(button(view->WINW-tempSurf->w, view->WINH-arrowButtonH, view, nullptr,
            "NOTEXT" + view->getFilepath() +"img/scrollArrDown.bmp#downarrow", "", "", true));
        buttons.push_back(button(view->WINW-tempSurf->w, view->WINH-tempSurf->h, view, nullptr,
            "NOTEXT" + view->getFilepath() +"img/scrollArrUp.bmp#uparrow", "", "", true));
        SDL_FreeSurface(tempSurf);
    }
    else {
        backGround = SDL_CreateRGBSurface(SDL_SWSURFACE,view->WINW,view->WINH,32,0xff000000,0x00ff0000,0x0000ff00,0x000000ff);
        SDL_Surface* tempSurf = load_image(view->getFilepath() + "img\\backgrounds\\strookjeSmall.bmp");
        SDL_Rect R;R.x=view->WINW-tempSurf->w; R.y=0; R.h=tempSurf->h; R.w=tempSurf->w;
        SDL_BlitSurface(tempSurf, NULL, backGround, &R);
        int arrowButtonH = getImageDimension(view->getFilepath() + "img/scrollArrDown.bmp", false);
        buttons.push_back(button(view->WINW-tempSurf->w, view->WINH-arrowButtonH, view, nullptr,
            "NOTEXT" + view->getFilepath() +"img/scrollArrDown.bmp#downarrow", "", "", true));
        buttons.push_back(button(view->WINW-tempSurf->w, 0, view, nullptr,
            "NOTEXT" + view->getFilepath() +"img/scrollArrUp.bmp#uparrow", "", "", true));
        SDL_FreeSurface(tempSurf);
    }
}

void Level::clearButtons() {
    for (unsigned int i=0; i<buttons.size(); i++)
        buttons[i].clearSurfaces();
    buttons.clear();
}
