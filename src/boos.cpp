#include "boos.h"
#include <f.h>

using namespace std;

boos::~boos()
{
    cout <<"farewell"<<endl;
}

void boos::angry(f* f){cout<<"angry enzo"<<endl;
        f->shout();
        cout<<"en nu?"<<endl;
};
