#include "button.h"

button::button(int Xoffst, int Yoffst, View* view, TTF_Font* Font, std::string text, std::string bmp, bool scrollable, std::string textBmp, bool justText,
               int r, int g, int b, int a) {
    font = Font;
    color = createColor(r, g, b, a);
    this->scrollable = scrollable;
    bool hasPressed = false;
    if (textBmp != "") {
        pressed = load_image(replaze(textBmp, "unpr", "pressed", false));
        if (pressed != nullptr) {
            hasPressed = true;
        }
        unPressed = load_image(textBmp);
        if (hasPressed)
            pressed = load_image(replaze(textBmp, "unpr", "pressed", false));
    }
    else if(!stringContains(text,"NOTEXT")){
        extralines = getlines(text, 14);
        unPressed = talking(text, 14, font, color, true, "", view->WINW, view->WINH);
        pressed = talking(text, 14, font, brightColor(color), true, "", view->WINW, view->WINH);
    }
    else {
        if (bmp != "")
            pressed = load_image(bmp);
        text = replaze(text, "NOTEXT", "", false);
        unPressed=load_image(subString(text, 0, indexOf(text, "#")));
        text = subString(text, indexOf(text, "#") + 1, text.size());
        w = unPressed->w;
        h = unPressed->h;
    }
    if (!justText) {
        pressed = assembleSurface(bmp, true, pressed, view);
        unPressed = assembleSurface(bmp, false, unPressed, view);
    }
    name = text;
    determineOffsets(Xoffst, Yoffst, view);
}

button::button(bool rememberMe, int Xoffst, int Yoffst, View* view, TTF_Font* Font,
       std::string text, std::string bmp, bool scrollable, std::string textBMP) {
    this->rememberMe = rememberMe;
    font = Font;
    color = createColor(0, 0, 0, 255);
    this->scrollable = scrollable;
    bool hasPressed = false;
    if (textBMP != "") {
        pressed = load_image(replaze(textBMP, "unpr", "pressed", false));
        if (pressed != nullptr) {
            hasPressed = true;
        }
        unPressed = load_image(textBMP);
        if (hasPressed)
            pressed = load_image(replaze(textBMP, "unpr", "pressed", false));
    }
    else {
        extralines = getlines(text, 14);
        unPressed = talking(text, 14, font, color, true, "", view->WINW, view->WINH);
        pressed = talking(text, 14, font, brightColor(color), true, "", view->WINW, view->WINH);
    }
    pressed = assembleSurface(bmp, true, pressed, view);
    unPressed = assembleSurface(bmp, false, unPressed, view);
    name = text;
    determineOffsets(Xoffst, Yoffst, view);
}

button::~button()
{

}

button::button(const button& other)
{
    pressed = other.pressed;
    unPressed = other.unPressed;
    x = other.x;
    y = other.y;
    w = other.w;
    h = other.h;
    color = other.color;
    font = other.font;
    name = other.name;
    scrollable = other.scrollable;
    wasclicked = other.wasclicked;
    rememberMe = other.rememberMe;
}
std::string button::getName(){
    return name;
}
bool button::clicked(int mx, int my, int Yoffst) {
    if (scrollable) {
        if ((mx >= x && mx <= x + w) && (my >= y + Yoffst && my <= y + Yoffst + h)) {
                if (rememberMe)
                    wasclicked = !wasclicked;
            return true;
        }
    }
    else {
        if ((mx >= x && mx <= x + w) && (my >= y  && my <= y + h)) {
            if (rememberMe)
                    wasclicked = !wasclicked;
            return true;
        }
    }
    return false;
}
SDL_Surface* button::getSurface(bool pressed) {
    if (pressed && this->pressed != nullptr)
        return this->pressed;
    else
        return unPressed;
}
SDL_Rect button::getRect() {
    SDL_Rect R;
    R.x = x;
    R.y = y;
    R.h = h;
    R.w = w;
    return R;
}
void assembleSingleSurfaceOnTarget(std::string img, SDL_Surface* tex, int Xoffst, int w, int h) {
    SDL_Surface* addition = nullptr;
    SDL_Rect R;
    R.x = Xoffst;
    R.y = 0;
    R.h = h;
    R.w = w;
    addition = load_image(img);
    SDL_BlitSurface(addition, NULL, tex, &R);
    SDL_FreeSurface(addition);
}
void assemble(std::string left, std::string middle, std::string right, SDL_Surface* tex, int w, int bw, int mw, int bh) {
    assembleSingleSurfaceOnTarget(left, tex, 0, bw, bh);
    int counter = 0;
    for (int i = w; i > 0; i -= mw) {
        assembleSingleSurfaceOnTarget(middle, tex, mw * counter + bw, mw, bh);
        counter ++;
    }
    assembleSingleSurfaceOnTarget(right, tex, mw* counter + bw, bw, bh);
}
SDL_Surface* button::assembleSurface(std::string bmp, bool pressed, SDL_Surface* dims, View* view) {
    SDL_Surface* surfLoaded = nullptr;
    std::string left = bmp;
    std::string middle = replaze(bmp, "LB.bmp", "MB.bmp", false);
    std::string right = replaze(bmp, "LB.bmp", "RB.bmp", false);
    int width, height, fullwidth;
    int borderWidth, middleWidth, borderHeight;
    if (!pressed) {
        left = replaze(bmp, "LB.bmp", "LUB.bmp", false);
        middle = replaze(bmp, "LB.bmp", "MUB.bmp", false);
        right = replaze(bmp, "LB.bmp", "RUB.bmp", false);
    }
    width = dims->w;
    height = dims->h;
    borderWidth = getImageDimension(left, true);
    borderHeight = getImageDimension(left, false);
    int textYoffset = 2070 / height + extralines * (8 - height/15);
    middleWidth = getImageDimension(middle, true);
    fullwidth = 2 * borderWidth;
    for (int i = width; i > 0; i -= middleWidth)
        fullwidth += middleWidth;
    surfLoaded = SDL_CreateRGBSurface(SDL_SWSURFACE,fullwidth,borderHeight,32,0xff000000,0x00ff0000,0x0000ff00,0x000000ff);
    assemble(left, middle, right, surfLoaded, width, borderWidth, middleWidth, borderHeight);
    SDL_Rect R{x=borderWidth, y=textYoffset, w=width, h = height};
    SDL_BlitSurface(dims, NULL, surfLoaded, &R);
    SDL_FreeSurface(dims);
    w = surfLoaded->w;
    h = surfLoaded->h;
    return surfLoaded;
}
bool button::getWasclicked() {
    return wasclicked;
}
bool button::getScrollable() {
    return scrollable;
}
void button::determineOffsets(int Xoffst, int Yoffst, View* view) {
    x = Xoffst;
    y = Yoffst;
    if (Xoffst < 0)
        x = (view->WINW - unPressed->w) / 2 + Xoffst;
    if (Yoffst < 0)
        y = (view->WINH - unPressed->h) / 2 + Yoffst;
}
void button::setWasclicked(bool state) {
    wasclicked = state;
}
void button::clearSurfaces() {
    SDL_FreeSurface(pressed);
    SDL_FreeSurface(unPressed);
}
