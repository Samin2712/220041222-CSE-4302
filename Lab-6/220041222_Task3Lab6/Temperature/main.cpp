#include <iostream>
#include "Temperature.h"
using namespace std;

int main()
{
    Celsius cel(25.0);
    cel.display();
    Fahrenheit c_to_far=cel;
    c_to_far.display();
    Fahrenheit far(98.0);
    far.display();
    Celsius far_to_cel=far;
    far_to_cel.display();
    return 0;
}
