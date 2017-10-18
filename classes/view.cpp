#include "View.h"

View::View() {
    hale = init();
}

View::~View() {
    SDL_FreeSurface(target);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();
}

View::View(const View& other) {

}

SDL_Window* View::getWindow() {
    return window;
}

SDL_Renderer* View::getRenderer() {
    return renderer;
}

SDL_Event* View::getEvent() {
    return &event;
}
SDL_Surface* View::getTarget() {
    return target;
}
std::string View::getFilepath() {
    return filepath;
}
void View::setFilepath() {
    char t[MAX_PATH];
    GetModuleFileName(NULL,t,sizeof(t));
    filepath = t;
    int o = filepath.size();
    for (int i=0; i<o; i++)
        if (filepath[i] == 'b' && filepath[i+1] == 'i' && filepath[i+2] == 'n')
            filepath.erase(i,i+o);
}
void View::render() {
    SDL_RenderClear(renderer);
    SDL_Texture* screen = SDL_CreateTextureFromSurface(renderer, target);
    SDL_RenderCopy(renderer, screen, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(screen);
    SDL_FreeSurface(target);
    target = SDL_CreateRGBSurface(SDL_SWSURFACE,WINW,WINH,32,0xff000000,0x00ff0000,0x0000ff00,0x000000ff);
}
bool View::init() {
    if(SDL_Init(SDL_INIT_EVERYTHING))
        return false;
    TTF_Init();
    window = SDL_CreateWindow("Pues, quieres hablar¿", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINW, WINH, SDL_WINDOW_RESIZABLE);
    if (window == nullptr)
        return false;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr)
        return false;
    target = SDL_CreateRGBSurface(SDL_SWSURFACE,WINW,WINH,32,0xff000000,0x00ff0000,0x0000ff00,0x000000ff);
    setFilepath();
    if (filepath == "")
        return false;
    return true;
}
