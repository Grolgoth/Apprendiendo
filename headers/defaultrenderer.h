#ifndef DEFAULTRENDERER_H
#include "textrenderer.h"
#define DEFAULTRENDERER_H


class defaultRenderer : public textRenderer
{
    public:
        defaultRenderer(View* view);
        ~defaultRenderer();
    protected:
    private:
};

#endif // DEFAULTRENDERER_H
