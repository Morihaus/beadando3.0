#ifndef FIELD_HPP_INCLUDED
#define FIELD_HPP_INCLUDED

#include <vector>

using namespace std;

class Field
{
protected:
    vector<Widget*> w;

public:
    void beolvas();
    void event_loop();
    void handle();
    void vege();
};


#endif // FIELD_HPP_INCLUDED
