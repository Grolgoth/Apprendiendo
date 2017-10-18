#ifndef CLICK_H
#define CLICK_H


class Click
{
    public:
        Click(int x, int y);
        ~Click();
        int getX();
        int getY();
    protected:
    private:
        int mouseX;
        int mouseY;
};

#endif // CLICK_H
