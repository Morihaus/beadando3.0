#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include <vector>

using namespace std;
using namespace genv;

void event_loop(vector<Widget*>& widgets)
{
    event ev;
    int focus = -1;
    while(gin >> ev)
    {
        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for (int i=0; i<widgets.size(); i++)
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
            }
        }
        for (int i=0; i<widgets.size(); i++)
        {
            widgets[i]->draw();
        }
        if (focus!=-1)
        {
            widgets[focus]->handle(ev);
        }
    }
}

int main()
{
    char szam=NULL;
    gin.timer(40);
    gout.open(600,300);
    vector<Widget*> w;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            ExampleCheckBox* ec =new ExampleCheckBox(0,0,i*30,j*30,szam);
            w.push_back(ec);
        }
    }

    event_loop(w);
    return 0;
}
