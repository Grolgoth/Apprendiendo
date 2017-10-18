#include "SDLfunctions.h"

SDL_Texture* createTextureFromImage(std::string img, SDL_Renderer* renderer) {
    SDL_Surface* loaded = load_image(img);
    if (loaded == nullptr)
        return nullptr;
    SDL_Texture* returntarget = nullptr;
    returntarget = SDL_CreateTextureFromSurface(renderer, loaded);
    SDL_FreeSurface(loaded);
    return returntarget;
}
SDL_Surface* load_image(std::string filename) {
      //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = nullptr;

    //Load the image
    loadedImage = SDL_LoadBMP( filename.c_str() );

    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
        {// map the colorkey
        Uint32 colorkey = SDL_MapRGB( loadedImage->format, 0, 0xFF, 0xFF );
        // make it transparent
        SDL_SetColorKey( loadedImage, SDL_TRUE, colorkey );
        }
    // something went wrong
    else
    {
        std::ofstream out("fout.txt");
        out << filename << std::endl;
        out.close();
    }

    //Return the optimized image
    return loadedImage;
}
SDL_Surface* fontToSurface(TTF_Font* font, std::string text, SDL_Color C) {
    return TTF_RenderText_Solid(font, text.c_str(), C);
}
SDL_Color createColor(int r, int g, int b, int a) {
    SDL_Color C;
    C.r = r;
    C.b = b;
    C.g = g;
    C.a = a;
    return C;
}
int testBrightening(int test, int add) {
    if (test + add < 255)
        test += add;
    else
        test = 255;
    return test;
}
SDL_Color brightColor(SDL_Color target) {
    target.r = testBrightening(target.r, (255 - target.r) / 3 *(target.r / (target.r + target.g + target.b + 1)));
    target.g = testBrightening(target.g, (255 - target.g) / 3 *(target.g / (target.r + target.g + target.b + 1)));
    target.b = testBrightening(target.b, (255 - target.b) / 3 *(target.b / (target.r + target.g + target.b + 1)));
    target.a = testBrightening(target.a, 100);
    return target;
}
void cleanSurfaces(std::vector<SDL_Surface*>surfaces) {
    for (unsigned int i=0; i<surfaces.size(); i++)
        SDL_FreeSurface(surfaces[i]);
}
int getImageDimension(std::string source, bool width) {
    SDL_Surface* loaded = load_image(source);
    int w = loaded->w;
    int h = loaded->h;
    SDL_FreeSurface(loaded);
    if (width)
        return w;
    return h;
}
