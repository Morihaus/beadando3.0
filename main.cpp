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
    while(gin >> ev )
    {
        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for (size_t i=0; i<widgets.size(); i++)
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
            }
        }
       for (size_t i=0; i<widgets.size(); i++)
        {
            widgets[i]->draw();
        }
        if (focus!=-1)
        {
            widgets[focus]->handle(ev);
        }
        gout << refresh;
    }
}

int main()
{
    int szam=0;
    gin.timer(40);
    gout.open(600,300);
    vector<Widget*> w;
    ExampleCheckBox* ec= new ExampleCheckBox(5,5,20,20,szam);
    w.push_back(ec);
    event_loop(w);
    return 0;
}
