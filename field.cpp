#include "field.hpp"
#include "examplecheckbox.hpp"
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

using namespace std;
using namespace genv;

void Field::beolvas()
{
    ifstream befajl("fajl.txt");
    char szam;
    string seged;
    char palyak[5][81];
    srand(time(NULL));
    int randomsor=rand() % 5;

    while(!befajl.eof())
    {
        getline(befajl,seged,' ');
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<81; j++)
            {
                if(seged[j]!=0)
                {
                    palyak[i][j]=seged[j];
                }
            }
        }
    }

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if((i==3 || i==6 )&& (j==3 || j==6))
            {
                ExampleCheckBox* ec =new ExampleCheckBox(i*30+2,j*30+2,30,30,' ');
                w.push_back(ec);
            }
            else if(j==3 || j==6)
            {
                ExampleCheckBox* ec =new ExampleCheckBox(i*30,j*30+2,30,30,' ');
                w.push_back(ec);
            }
            else if(i==3 || i==6)
            {
                ExampleCheckBox* ec =new ExampleCheckBox(i*30+2,j*30,30,30,' ');
                w.push_back(ec);
            }
            else
            {
                ExampleCheckBox* ec =new ExampleCheckBox(i*30,j*30,30,30,' ');
                w.push_back(ec);
            }
        }
    }

    for(int k=0; k<81; k++)
    {
        if(palyak[randomsor][k]!=0)
        {
            w[k]->set_szam(palyak[randomsor][k]);
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
            for (int i=0; i<w.size(); i++)
            {
                if (w[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
            }
        }
        for (int i=0; i<w.size(); i++)
        {
            w[i]->draw();
        }
        if (focus!=-1)
        {
            w[focus]->handle(ev);
        }
        gout<<refresh;
    }

    /*void Field::ellenoriz()
    {
        if()
        {

        }


    }*/

}
