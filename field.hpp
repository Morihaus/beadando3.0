#ifndef FIELD_HPP_INCLUDED
#define FIELD_HPP_INCLUDED

#include "examplecheckbox.hpp"
#include <vector>

using namespace std;

class Field
{
private:
    vector<ExampleCheckBox*> w;
public:
    void beolvas();
    void event_loop();
    void ellenoriz();
    //void vege();
};


#endif // FIELD_HPP_INCLUDED
