#include<bits/stdc++.h>
using namespace std;
struct fraction
{
    int numerator;
    int denominator;
};
int main()
{
    fraction f,a,b;
   char s1,s2;
   cout<< "Enter First Fraction: ";
   cin>>a.numerator>>s1>>a.denominator;
   cout<< "Enter Second Fraction: ";
   cin>>b.numerator>>s2>>b.denominator;
   if(a.denominator==0||b.denominator==0) cout<< "Math Error"<<endl;
   else
   {
       f.numerator=(a.numerator*b.denominator)+(a.denominator*b.numerator);
       f.denominator=(a.denominator*b.denominator);
       if(f.denominator==f.numerator) cout<<"Sum: "<<f.numerator<<'/'<<f.denominator<<'='<<1<<endl;
       else cout<<"Sum: "<<f.numerator<<'/'<<f.denominator<<endl;
   }
}