#include <iostream>
#include "Matrix3D.h"
#include <stdexcept>
using namespace std;

int main()
{
    double a[3][3]={{1,6,4},{2,1,4},{5,2,1}};
    double b[3][3]={{4,7,9},{1,6,2},{3,6,9}};
    Matrix3D mt1(a);
    Matrix3D mt2(b);
    cout<<mt1.det()<<endl;
    Matrix3D inv_mt1=mt1.inverse();
    inv_mt1.getMatrix();
    Matrix3D mt3=mt1+mt2;
    mt3.getMatrix();
    return 0;
}
