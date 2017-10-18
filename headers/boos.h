#ifndef BOOS_H
#include <iostream>
#define BOOS_H

class f;

class boos {
public:
    boos(std::string text) {
        message = text;
    };
    ~boos();
    void angry(f* f);
    std::string message;
};

#endif // BOOS_H
