#ifndef FIELD_HPP_INCLUDED
#define FIELD_HPP_INCLUDED

#include "examplecheckbox.hpp"
#include <vector>

using namespace std;

class Field
{
protected:
    vector<Widget*> w;

public:
    field(int xx,int yy);
    void beolvas();
    void event_loop();
    void handle();
    void vege();
};


#endif // FIELD_HPP_INCLUDED
