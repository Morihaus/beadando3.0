#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "string"

using namespace std;

class ExampleCheckBox : public Widget
{
public:
    int ido1,ido2;
    ExampleCheckBox(int x, int y, int sx, int sy, char szam);
    virtual void draw() const;
    virtual void handle(genv::event ev);
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
