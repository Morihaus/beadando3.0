#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include "string"

using namespace std;

class Widget
{
protected:
    int _x, _y, _size_x, _size_y, _szam;
public:
    Widget(int x, int y, int sx, int sy, char szam);
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void draw() const;
    virtual void handle(genv::event ev);
};


#endif // WIDGETS_HPP_INCLUDED
