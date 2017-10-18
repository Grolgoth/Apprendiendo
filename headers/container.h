#ifndef CONTAINER_H
#include "event.h"
#include "textrenderer.h"
#include "gamedelegator.h"
#include "hablarmain.h"
#define CONTAINER_H


class container
{
    public:
        container(View* view);
        ~container();
        event* getEvent();
        int getMx();
        int getMy();
        void setMx(int x);
        void setMy(int y);
        gameDelegator* getDelegator();
        std::vector<textRenderer*> getTextRenderers();
        void setSaveFile(std::string savefile);
    protected:
    private:
        std::vector<textRenderer*> textRenderers;
        void initRenderers(View* view);
        void initFonts(std::string filepath);
        std::vector<TTF_Font*> fonts;
        int mx;
        int my;
        gameDelegator* delegator;
        event Event;
        std::string saveFile;
};

#endif // CONTAINER_H
