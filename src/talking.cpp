#include "talking.h"
#include "SDLfunctions.h"

std::vector<int> checkNewlines(std::vector<int>newlines, std::string message, int characters) {
    newlines.clear();
    char a;
    for(unsigned int i=0; i<message.size(); i++) {
        a = message[i];
        if (a == '\n')
            newlines.push_back(i);
    }
    return newlines;
}

int linebreak(std::vector<int>newlines, int position, int characters) {
    for (unsigned int i=0; i<newlines.size(); i++)
        if (newlines[i] > position && newlines[i] < position + characters)
            return newlines[i] - position;
    return characters;
}

SDL_Surface* talking(std::string message, unsigned int characters, TTF_Font* A, SDL_Color C, bool self, std::string imagepath, int WINW, int height)
{
    SDL_Surface* LI = NULL;
    SDL_Surface* temp = NULL;
    if (characters == 0) // impossible!
        return LI;
    if (message.length() > characters)
    {
        temp = SDL_CreateRGBSurface(SDL_SWSURFACE,WINW,height,32,0xff000000,0x00ff0000,0x0000ff00,0x000000ff);
        std::string frag;
        std::vector<int>newlines;
        newlines = checkNewlines(newlines, message, characters);
        unsigned int i = characters;
        int cnt = 0;
        int spacecnt = 0;
        while (message.length()>i-characters)
        {
            int earlyCut = linebreak(newlines, i-characters, characters);
            bool clean = false; // this is a bool that indicates whether the current chop in message is 'clean' eg on a space and not in the middle of a word
                                // should the latter be the case we will try to adjust the size of frag a bit back or forth so no half words are formed.
            frag = message.substr(i-characters, earlyCut);
            if (frag[frag.size()-1] == ' ' || message[i - characters + earlyCut] == ' ' || message.length() <= i || frag[frag.size()-1] == '\n'
                || message[i - characters + earlyCut] == '\n')
            {
                clean = true;
                if (message[i - characters + earlyCut] == ' ')
                    i++;
            }
            else
            {
                spacecnt = 0;
                int el = 4;
                if (characters <= 4)
                    el = characters; // we look back if there is a space, but we shouldn't look further than characters.
                for (int a = 1; a < el; a++)
                {
                    spacecnt ++;
                    if (message[i - characters + earlyCut - a -1] == ' ')
                    {
                        clean = true;
                        break;
                    }
                }
                if (clean)
                {
                    std::string onzin;
                    i -= spacecnt;
                    for (unsigned int a = 0; a < characters - spacecnt; a++)
                        onzin += frag[a];
                    frag = onzin;
                }
            }
            if (!clean)
            {
                spacecnt = 0;
                int el = 3;
                unsigned int poep = message[i - characters + earlyCut - 1] + el; // unsigned vs signed bullshit
                if (poep >= message.size())
                    el = message.size() - i - 1; // we are checking if anywhere in the near future there will be a space but we don't want to check further than the end of message
                for (int a = 0; a < el; a++)
                {
                    spacecnt ++;
                    if (message[i - characters + earlyCut + a] == ' ')
                    {
                        clean = true;
                        break;
                    }
                }
                if (clean)
                {
                    for (int a = 0; a < spacecnt; a++)
                        frag = frag + message[i - characters + earlyCut + a];
                    i += spacecnt;
                }
            }
            if (! clean)   // if both forward and backward there are no nearby spaces we go back all the way until we find one!
            {
                spacecnt = 0;
                int el = characters -1;
                for (int a = 1; a < el; a++)
                {
                    spacecnt ++;
                    if (message[i - characters + earlyCut - a - 1] == ' ')
                    {
                        clean = true;
                        break;
                    }
                }
                if (clean)
                {
                    std::string onzin;
                    i -= spacecnt;
                    for (unsigned int a = 0; a < characters - spacecnt; a++)
                        onzin += frag[a];
                    frag = onzin;
                }
            }
            if (!clean)
                spacecnt = 0;
            i = i + earlyCut;
            LI = TTF_RenderText_Solid(A, frag.c_str(), C);
            if (LI->w > temp->w)
                temp->w = LI->w;
            apply_surface(0, cnt * TTF_FontLineSkip(A), LI, temp);
            if (cnt == 0)
                temp->w = LI->w;
            SDL_FreeSurface(LI);
            cnt ++;
        }
        if (self)
            return temp;
        else
        {
            SDL_Surface* temps;
            SDL_Surface* temps2 = SDL_CreateRGBSurface(SDL_SWSURFACE,WINW,height,32,0xff000000,0x00ff0000,0x0000ff00,0x000000ff);
            SDL_Rect offset;
            SDL_Rect arwclip;
            arwclip.x = 0; arwclip.y = 0; arwclip.w = characters*7 + characters/2; arwclip.h = cnt + 3;
            temps = load_image(imagepath); offset.x = 117; offset.y =59;
            SDL_BlitSurface(temps, &arwclip,temps2,&offset); SDL_FreeSurface(temps);
            apply_surface(120,60,temp,temps2); SDL_FreeSurface(temp);
            return temps2;
        }
    }
    else
    {
        LI = TTF_RenderText_Solid(A, message.c_str(), C);
        if (self)
            return LI;
        else
        {
            SDL_Surface* temps;
            SDL_Surface* temps2 = SDL_CreateRGBSurface(SDL_SWSURFACE,WINW,height,32,0xff000000,0x00ff0000,0x0000ff00,0x000000ff);
            SDL_Rect offset;
            SDL_Rect arwclip;
            arwclip.x = 0; arwclip.y = 0; arwclip.w = characters*6 + characters/2; arwclip.h = 19;
            temps = load_image(imagepath); offset.x = 147; offset.y =59;
            SDL_BlitSurface(temps, &arwclip,temps2,&offset); SDL_FreeSurface(temps);
            apply_surface(150,60,LI,temps2); SDL_FreeSurface(LI);
            return temps2;
        }
    }
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* arwclip)
{
    //Make a temporary rectangle to hold the offsets on the screen
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, arwclip, destination, &offset );
}
