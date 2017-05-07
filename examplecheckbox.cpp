#include "examplecheckbox.hpp"
#include "graphics.hpp"
#include "string"

using namespace genv;
using namespace std;

const int XX=600;
const int YY=300;

ExampleCheckBox::ExampleCheckBox(int x, int y, int sx, int sy,int szam)
    : Widget(x,y,sx,sy,szam)
{
    ido1=0;
    ido2=0;
}

void ExampleCheckBox::draw() const
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-2, _size_y-4);
    gout << color(255,255,255);
    gout << move_to(_x+8, _y+20) << text(_szam)<<refresh;
}

void ExampleCheckBox::handle(event ev)
{
    gin.timer(500);
    if (ev.type==ev_key && ev.keycode>=1 && ev.keycode<=9)
    {
        _szam=ev.keycode;
    }
    if(ev.type==ev_key && ev.keycode==key_backspace )
    {
        _szam.
    }
    if(ev.type==ev_timer)
    {
        if(ido1<=ev.time)
        {
            gout<<move_to(_x+_size_x-7,_y+7)<<color(0,0,0)<<box(2,_size_y-12);
            ido1=500+ev.time;
        }
        if(ido2<=ev.time)
        {
            gout<<move_to(_x+_size_x-7,_y+7)<<color(255,255,255)<<box(2,_size_y-12);
            ido2=800+ev.time;
        }
    }
}
