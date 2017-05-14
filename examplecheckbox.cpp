#include "examplecheckbox.hpp"
#include "graphics.hpp"
#include "string"

using namespace genv;
using namespace std;


ExampleCheckBox::ExampleCheckBox(int x, int y, int sx, int sy,char szam)
    : Widget(x,y,sx,sy,szam)
{
    ido1=0;
    ido2=0;
}

void ExampleCheckBox::draw() const
{
    gout << move_to(_x, _y) << color(0,0,0) << box(_size_x+2, _size_y);
    gout << move_to(_x+2, _y+2) << color(255,255,255) << box(_size_x-2, _size_y-2);
    gout << color(0,0,255);
    gout << move_to(_x+12, _y+20) << text(_szam);
}

void ExampleCheckBox::handle(event ev)
{
    gin.timer(500);
    if (ev.type==ev_key && ev.keycode>='1' && ev.keycode<='9')
    {
        _szam=ev.keycode;
    }
    else if(ev.type==ev_key && ev.keycode==key_backspace)
    {
        _szam=NULL;
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
