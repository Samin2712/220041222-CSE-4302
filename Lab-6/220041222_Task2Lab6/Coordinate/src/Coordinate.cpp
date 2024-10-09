#include "Coordinate.h"
#include<cmath>
#include<iostream>
#include <cstdlib>
#include <ctime>
#include<algorithm>
using namespace std;
Coordinate:: Coordinate() :abscissa(0.0),ordinate(0.0){}
Coordinate:: Coordinate(float x,float y):abscissa(x),ordinate(y){}
void Coordinate::display() const
{
   cout<<"("<<abscissa<<", "<< ordinate << ")" <<endl;
}
float Coordinate::operator-(const Coordinate& c) const
{
    return sqrt(pow(c.abscissa-abscissa,2)+pow(c.ordinate-ordinate,2));
}
float Coordinate::getDistance() const
{
    return sqrt(pow(abscissa,2)+pow(ordinate,2));
}
void Coordinate::move_x(float val)
{
    abscissa+=val;
}
void Coordinate::move_y(float val)
{
    ordinate += val;
}
void Coordinate::move(float x_val,float y_val)
{
    abscissa +=x_val;
    ordinate +=y_val;
}
bool Coordinate::operator>(const Coordinate& c) const
{
    return this->getDistance()>c.getDistance();
}
bool Coordinate::operator<(const Coordinate& c) const
{
    return this->getDistance()<c.getDistance();
}
bool Coordinate::operator>=(const Coordinate& c) const
{
    return this->getDistance()>=c.getDistance();
}

bool Coordinate::operator<=(const Coordinate& c) const
{
    return this->getDistance()<=c.getDistance();
}

bool Coordinate::operator==(const Coordinate& c) const
{
    return this->getDistance()==c.getDistance();
}

bool Coordinate::operator!=(const Coordinate& c) const
{
    return this->getDistance()!=c.getDistance();
}
void randomAssignment(Coordinate c[],int size)
{
    srand(static_cast<unsigned>(time(0)));

    for (int i=0;i<size;++i) {
        float x=static_cast<float>(rand()%200-100);
        float y=static_cast<float>(rand()%200-100);
        c[i]=Coordinate(x,y);
    }
}
void sort(Coordinate c[],int size)
{
    for (int i=0;i<size-1;++i)
    {
        for (int j=i+1;j<size;++j)
        {
            if (c[i]>c[j])
            {
                swap(c[i],c[j]);
            }
        }
    }
}
