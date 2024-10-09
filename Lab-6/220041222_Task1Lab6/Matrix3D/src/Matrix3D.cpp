#include "Matrix3D.h"
#include<iostream>
using namespace std;
Matrix3D::Matrix3D(const double mat[3][3],int inc):increment(inc>0?inc:1),count(0)
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            Matrix[i][j]=mat[i][j];
        }
    }
}
double Matrix3D::det() const
{
    return Matrix[0][0] * (Matrix[1][1] * Matrix[2][2] - Matrix[1][2] * Matrix[2][1])
             - Matrix[0][1] * (Matrix[1][0] * Matrix[2][2] - Matrix[1][2] * Matrix[2][0])
             + Matrix[0][2] * (Matrix[1][0] * Matrix[2][1] - Matrix[1][1] * Matrix[2][0]);
}
Matrix3D Matrix3D::inverse() const
{
    double determinant=det();
    if (determinant==0)
    {
        cout<<"Matrix is not invertible."<<endl;
        return *this;
    }
    double invMatrix[3][3];
    invMatrix[0][0] = (Matrix[1][1] * Matrix[2][2] - Matrix[1][2] * Matrix[2][1]) / determinant;
    invMatrix[0][1] = (Matrix[0][2] * Matrix[2][1] - Matrix[0][1] * Matrix[2][2]) / determinant;
    invMatrix[0][2] = (Matrix[0][1] * Matrix[1][2] - Matrix[0][2] * Matrix[1][1]) / determinant;

    invMatrix[1][0] = (Matrix[1][2] * Matrix[2][0] - Matrix[1][0] * Matrix[2][2]) / determinant;
    invMatrix[1][1] = (Matrix[0][0] * Matrix[2][2] - Matrix[0][2] * Matrix[2][0]) / determinant;
    invMatrix[1][2] = (Matrix[0][2] * Matrix[1][0] - Matrix[0][0] * Matrix[1][2]) / determinant;

    invMatrix[2][0] = (Matrix[1][0] * Matrix[2][1] - Matrix[1][1] * Matrix[2][0]) / determinant;
    invMatrix[2][1] = (Matrix[0][1] * Matrix[2][0] - Matrix[0][0] * Matrix[2][1]) / determinant;
    invMatrix[2][2] = (Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0]) / determinant;

    return Matrix3D(invMatrix);
}

void Matrix3D::getMatrix() const
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout<<Matrix[i][j]<< " ";
        }
        cout<<endl;
    }
}
void Matrix3D::setIncrement(int val)
{
    if (count==0&&val>0)increment=val;
    else if (val < 0) cout << "Cannot assign negative value to increment. Keeping previous value.\n";
    else cout << "Cannot set increment value as count is non-zero.\n";
}
void Matrix3D::Increment()
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            Matrix[i][j]+=increment;
        }
    }
}
Matrix3D Matrix3D::operator+(const Matrix3D &other) const
{
   double res[3][3];
   for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            res[i][j]=Matrix[i][j]+other.Matrix[i][j];
        }
    }
    return Matrix3D(res);
}
Matrix3D Matrix3D::operator-(const Matrix3D &other) const
{
   double res[3][3];
   for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            res[i][j]=Matrix[i][j]+other.Matrix[i][j];
        }
    }
    return Matrix3D(res);
}

Matrix3D Matrix3D::operator*(const Matrix3D &other) const
{
   double res[3][3];
   for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            res[i][j]=Matrix[i][j]+other.Matrix[i][j];
        }
    }
    return Matrix3D(res);
}
bool Matrix3D::operator>(const Matrix3D &other) const {return det()>other.det();}
bool Matrix3D::operator<(const Matrix3D &other) const {return det()<other.det();}
bool Matrix3D::operator>=(const Matrix3D &other) const {return det()>=other.det();}
bool Matrix3D::operator<=(const Matrix3D &other) const {return det()<=other.det();}
bool Matrix3D::operator==(const Matrix3D &other) const {return det()==other.det();}
bool Matrix3D::operator!=(const Matrix3D &other) const {return det()!=other.det();}
