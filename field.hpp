#ifndef FIELD_HPP_INCLUDED
#define FIELD_HPP_INCLUDED

#include <vector>

using namespace std;

class Field
{
public:
    Field();
    vector<Widget*> w;
    void beolvas();
    void event_loop();
    //void handle();
    //void vege();
};


#endif // FIELD_HPP_INCLUDED
