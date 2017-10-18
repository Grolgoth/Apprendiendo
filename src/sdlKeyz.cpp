#include "sdlKeyz.h"

std::string whichkey(SDL_Keycode key) {
    bool caps = false;
    SDL_Keymod a = SDL_GetModState();
    if(a == KMOD_CAPS)
        caps = true;
    switch(key) {
    case SDLK_0:return "0";
    case SDLK_1:return "1";
    case SDLK_2:return "2";
    case SDLK_3:return "3";
    case SDLK_4:return "4";
    case SDLK_5:return "5";
    case SDLK_6:return "6";
    case SDLK_7:return "7";
    case SDLK_8:return "8";
    case SDLK_9:return "9";
    case SDLK_a:if(!caps)return "a"; return"A";
    case SDLK_b:if(!caps)return "b"; return"B";
    case SDLK_c:if(!caps)return "c"; return"C";
    case SDLK_d:if(!caps)return "d"; return"D";
    case SDLK_e:if(!caps)return "e"; return"E";
    case SDLK_f:if(!caps)return "f"; return"F";
    case SDLK_g:if(!caps)return "g"; return"G";
    case SDLK_h:if(!caps)return "h"; return"H";
    case SDLK_i:if(!caps)return "i"; return"I";
    case SDLK_j:if(!caps)return "j"; return"J";
    case SDLK_k:if(!caps)return "k"; return"K";
    case SDLK_l:if(!caps)return "l"; return"L";
    case SDLK_m:if(!caps)return "m"; return"M";
    case SDLK_n:if(!caps)return "n"; return"N";
    case SDLK_o:if(!caps)return "o"; return"O";
    case SDLK_p:if(!caps)return "p"; return"P";
    case SDLK_q:if(!caps)return "q"; return"Q";
    case SDLK_r:if(!caps)return "r"; return"R";
    case SDLK_s:if(!caps)return "s"; return"S";
    case SDLK_t:if(!caps)return "t"; return"T";
    case SDLK_u:if(!caps)return "u"; return"U";
    case SDLK_v:if(!caps)return "v"; return"V";
    case SDLK_w:if(!caps)return "w"; return"W";
    case SDLK_x:if(!caps)return "x"; return"X";
    case SDLK_y:if(!caps)return "y"; return"Y";
    case SDLK_z:if(!caps)return "z"; return"Z";
    case SDLK_UP:return "up";
    case SDLK_DOWN:return "down";
    case SDLK_RIGHT:return "right";
    case SDLK_LEFT:return "left";
    case SDLK_LSHIFT:
    case SDLK_RSHIFT:return "shift";
    case SDLK_RETURN:return "enter";
    case SDLK_ESCAPE:return "esc";
    case SDLK_RALT:
    case SDLK_LALT:return "alt";
    case SDLK_RCTRL:
    case SDLK_LCTRL:return "ctrl";
    case SDLK_SPACE:return "space";
    case SDLK_BACKSPACE:return "backspace";
    case SDLK_COMMA:return ",";
    case SDLK_PERIOD:return ".";
    case SDLK_SLASH:return "/";
    case SDLK_BACKSLASH:return "\\";
    case SDLK_QUOTE:return "'";
    case SDLK_RIGHTBRACKET:return "]";
    case SDLK_LEFTBRACKET:return "[";
    case SDLK_TAB:return "tab";
    case SDLK_PLUS:
    case SDLK_EQUALS:return "=";
    case SDLK_COLON:
    case SDLK_SEMICOLON:return";";
    case SDLK_MINUS:
    case SDLK_UNDERSCORE:return"-";
    default: return "";
   }
}
std::string written(std::string key) {
    if (key == "space")
        return " ";
    else if (key == "enter")
        return "\n";
    else if (key == "tab")
        return "    ";
    else if (key == "backspace" || key == "shift" || key == "alt" || key == "ctrl" || key == "esc" || key == "up"
             || key == "down" || key == "right" || key == "left")
        return "";
    return key;
}
bool keyCheck(std::string key, std::vector<std::string> keys) {
    for(unsigned int i=0; i<keys.size(); i++)
        if(key == keys[i])
            return true;
    return false;
}
