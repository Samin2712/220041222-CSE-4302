#include <iostream>
#include "Coordinate.h"
using namespace std;

int main()
{
     const int sz=10;
     Coordinate coord[sz];
     randomAssignment(coord,sz);
     sort(coord, sz);
     for (int i=0;i<sz;++i)
     {
        coord[i].display();
     }
     Coordinate a(2.0,3.0);
     Coordinate b(5.0,4.0);
     a.display();
     b.display();
     int dis=a-b;
     cout<<dis<<endl;
    return 0;
}
