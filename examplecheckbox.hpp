#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "string"

using namespace std;

class ExampleCheckBox : public Widget
{
protected:
    int ido1,ido2;
public:
    ExampleCheckBox(int x, int y, int sx, int sy, int szam);
    virtual void draw() const;
    virtual void handle(genv::event ev);
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
