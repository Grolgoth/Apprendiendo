#include "textrenderer.h"

textRenderer::textRenderer(View* view, TTF_Font* Font)
{
    color.r=123; color.g=78; color.b=80; color.a=255;
    WINW = view->WINW;
    WINH = view->WINH;
    backGround = load_image(view->getFilepath() + "img\\backgrounds\\defbackground.bmp");
    rendering = false;
    refreshCurrent();
    font = Font;
}

textRenderer::~textRenderer()
{
    SDL_FreeSurface(backGround);
    if (current != nullptr)
        SDL_FreeSurface(current);
}
SDL_Surface* textRenderer::getCurrent() {
    return current;
}
void textRenderer::refreshCurrent() {
    if (current != nullptr)
        SDL_FreeSurface(current);
    current = SDL_CreateRGBSurface(SDL_SWSURFACE,WINW,WINH,32,0xff000000,0x00ff0000,0x0000ff00,0x000000ff);
    SDL_BlitSurface(backGround, NULL, current, NULL);
}
void textRenderer::render(std::string text, event* Event) {
    Event->eventtype = Event->SPECIAL;
    rendered = "";
    rendering = true;
    next = false;
    toRender = text;
}
void textRenderer::renderstep(bool all) {
    if (toRender.size() == 0) {
        rendering = false;
        return;
    }
    refreshCurrent();
    std::string now;
    int bigDelay = 0;
    if (!all) {
        if(toRender[0] != '&') {
            now = rendered + toRender[0];
            rendered = now;
        }
        else {
            bigDelay = 100;
            now = rendered;
        }
        toRender = toRender.substr(1, toRender.size());
    }
    else {
        now = rendered + replaze(toRender, "&", "", true);
        rendered = now;
        rendering = false;
    }
    SDL_Surface* text = talking(now, 55, font, color, true, "", WINW, WINH);
    apply_surface(50, 40, text, current);
    SDL_FreeSurface(text);
    SDL_Delay(delay + bigDelay);
}
void textRenderer::writing(std::string text) {
    refreshCurrent();
    SDL_Surface* texts = talking(rendered + text, 55, font, color, true, "", WINW, WINH);
    apply_surface(50, 40, texts, current);
    SDL_FreeSurface(texts);
}
bool textRenderer::getRendering() {
    return rendering;
}
bool textRenderer::getNext() {
    return next;
}

void textRenderer::setNext(bool state) {
    next = state;
}
