#ifndef GAMEDELEGATOR_H
#include "SDL.h"
#include "SDL_ttf.h"
#include "View.h"
#include "level.h"
#include "hablarmain.h"
#include "View.h"
#include <vector>
#include <textrenderer.h>
#define GAMEDELEGATOR_H

class container;

class gameDelegator {
    public:
        gameDelegator();
        virtual ~gameDelegator();
        virtual void delegate(View* view, container* bin) = 0;
        virtual Level* getStandard() = 0;
        virtual void setStandard(Level* lvl) = 0;
        std::vector<TTF_Font*> getFonts();
        std::vector<textRenderer*> getTextRenderers();
    protected:
        void handleRenderers(View* view, std::vector<textRenderer*> renderers, container* bin);
        std::vector<TTF_Font*> fonts;
        std::vector<textRenderer*> textRenderers;
    private:
};

class lvlDelegator : public gameDelegator {
    public:
        lvlDelegator(View* view, std::vector<TTF_Font*>* vectptrfonts, container* bin);
        ~lvlDelegator();
        virtual void delegate(View* view, container* bin);
        virtual Level* getStandard();
        virtual void setStandard(Level* lvl);
    protected:
    private:
        Level* standard;
};

#endif // GAMEDELEGATOR_H
