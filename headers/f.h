#ifndef F_H
#define F_H

class boos;

class f {
public:
    f(boos* h) {
        Boos = h;
    }
    ~f();
    void shout();
    boos* Boos;
};

#endif // F_H
