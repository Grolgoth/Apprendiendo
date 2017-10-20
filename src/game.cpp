#include "Game.h"

void run() {
    View current;
    container bin(&current);
    if(current.hale)
        loop(&current, &bin);
    else
        std::cerr << "FALLA LA INICIALIZACIÓN DE SDL" << std::endl;
}

void loop(View* view, container* bin) {
    bin->getDelegator()->delegate(view, bin);
    while(1) {
        if(SDL_PollEvent(view->getEvent()) || bin->getEvent()->eventtype == bin->getEvent()->QUIT
                || bin->getEvent()->eventtype == bin->getEvent()->SPECIAL) {
            if (bin->getEvent()->eventtype == bin->getEvent()->KEYEVENT)
                bin->getEvent()->getKeyEvent()->setRepeat(true);
            if (view->getEvent()->type == SDL_QUIT || bin->getEvent()->eventtype == bin->getEvent()->QUIT) {
                break;
            }
            else if (view->getEvent()->type == SDL_MOUSEBUTTONDOWN && view->getEvent()->button.button == SDL_BUTTON_LEFT) {
                    bin->getEvent()->setClick(bin->getMx(), bin->getMy());
            }
            else if (view->getEvent()->type == SDL_MOUSEBUTTONDOWN && view->getEvent()->button.button == SDL_BUTTON_RIGHT) {
                    bin->getEvent()->setClick(bin->getMx(), bin->getMy(), false);
            }
            else if (view->getEvent()->type == SDL_MOUSEBUTTONUP)
                    bin->getEvent()->eventtype = bin->getEvent()->NOTHING;
            else if (view->getEvent()->type == SDL_MOUSEMOTION) {
                bin->getEvent()->eventtype = bin->getEvent()->MOUSEMOTION;
                bin->setMx(view->getEvent()->motion.x);
                bin->setMy(view->getEvent()->motion.y);
            }
            else if (view->getEvent()->type == SDL_KEYDOWN)
                bin->getEvent()->setKeyEvent(whichkey(view->getEvent()->key.keysym.sym), true);
            else if (view->getEvent()->type == SDL_KEYUP)
                bin->getEvent()->setKeyEvent(whichkey(view->getEvent()->key.keysym.sym), false);
            else if (bin->getEvent()->eventtype != bin->getEvent()->SPECIAL)
                continue;
            bin->getDelegator()->delegate(view, bin);
        }
        if (bin->getEvent()->eventtype != bin->getEvent()->SPECIAL)
            SDL_Delay(12);
    }
}
