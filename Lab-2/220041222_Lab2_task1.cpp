#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a,b,c,d,t1,t2;
   char s1,s2;
   cout<< "Enter First Fraction: ";
   cin>>a>>s1>>b;
   cout<< "Enter Second Fraction: ";
   cin>>c>>s2>>d;
   if(b==0||d==0) cout<< "Math Error"<<endl;
   else
   {
       t1=(a*d)+(b*c);
       t2=(b*d);
       if(t1==t2) cout<<"Sum: "<<t1<<'/'<<t2<<"="<<1<<endl;
       else cout<<"Sum: "<<t1<<'/'<<t2<<endl;
   }
}