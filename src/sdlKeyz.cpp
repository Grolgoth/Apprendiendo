#include "sdlKeyz.h"

std::string whichkey(SDL_Keycode key) {
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
    case SDLK_a:return "a";
    case SDLK_b:return "b";
    case SDLK_c:return "c";
    case SDLK_d:return "d";
    case SDLK_e:return "e";
    case SDLK_f:return "f";
    case SDLK_g:return "g";
    case SDLK_h:return "h";
    case SDLK_i:return "i";
    case SDLK_j:return "j";
    case SDLK_k:return "k";
    case SDLK_l:return "l";
    case SDLK_m:return "m";
    case SDLK_n:return "n";
    case SDLK_o:return "o";
    case SDLK_p:return "p";
    case SDLK_q:return "q";
    case SDLK_r:return "r";
    case SDLK_s:return "s";
    case SDLK_t:return "t";
    case SDLK_u:return "u";
    case SDLK_v:return "v";
    case SDLK_w:return "w";
    case SDLK_x:return "x";
    case SDLK_y:return "y";
    case SDLK_z:return "z";
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
    default: return "ERROR";
   }
}
