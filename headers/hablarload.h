#ifndef HABLARLOAD_H
#include "level.h"
#define HABLARLOAD_H


class hablarLoad : public Level
{
    public:
        hablarLoad(View* view, TTF_Font* font);
        ~hablarLoad();
        virtual void checkEvents(View* view, event* Event, gameDelegator* gameDelegator);
        virtual void buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button);
    protected:
    private:
        void makeButtons(View* view, TTF_Font* font);
        void storeSavegames(View* view);
        std::vector<std::string>saveGames;
};

#endif // HABLARLOAD_H
