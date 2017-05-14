#include "field.hpp"
#include "examplecheckbox.hpp"

using namespace std;
using namespace genv;

void Field::beolvas()
{
    ifstream befajl("fajl.txt");
    befajl.open();


    for(int i=0; i<9; i++)
    {
            for(int j=0; j<9; j++)
            {
                if((i==3 || i==6 )&& (j==3 || j==6))
                {
                    ExampleCheckBox* ec =new ExampleCheckBox(i*30+2,j*30+2,30,30,szam);
                    w.push_back(ec);
                }
                else if(j==3 || j==6)
                {
                    ExampleCheckBox* ec =new ExampleCheckBox(i*30,j*30+2,30,30,szam);
                    w.push_back(ec);
                }
                else if(i==3 || i==6)
                {
                    ExampleCheckBox* ec =new ExampleCheckBox(i*30+2,j*30,30,30,szam);
                    w.push_back(ec);
                }
                else
                {
                    ExampleCheckBox* ec =new ExampleCheckBox(i*30,j*30,30,30,szam);
                    w.push_back(ec);
                }
            }
    }
}

void Field::event_loop()
{
    gout.open(272,272);
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
        gout<<refresh;
    }

}
