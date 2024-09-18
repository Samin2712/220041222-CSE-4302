#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class RationalNumber
{
    private:
        int numerator;
        int denominator;
    public:
        void assign(int nm,int dm)
        {
            if(denominator==0) cerr<< "You can not assign 0 as denominator."<<endl;
            numerator=nm;
            denominator=dm;
        }
        double convert()
        {
           double x=(numerator*1.0/denominator*1.0);
           return x;
        }
        void invert()
        {
            if(numerator==0) cout<< "You can not assign 0 as denominator"<<endl;
            else
            {
                swap(numerator,denominator);
            }
        }
        void print()
        {
            cout<< "Result is: "<<numerator<<"/"<<denominator<<endl;
        }
};
int main()
{
    RationalNumber num;
    num.assign(5,6);
    num.print();
    cout<<num.convert()<<endl;
    num.invert();
    num.print();
    cout<<num.convert()<<endl;
}