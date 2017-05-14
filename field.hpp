#ifndef FIELD_HPP_INCLUDED
#define FIELD_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>

using namespace std;

class Field
{
public:
    vector<Widget*> w;
    void beolvas();
    void event_loop();
    //void handle();
    //void vege();
};


#endif // FIELD_HPP_INCLUDED
