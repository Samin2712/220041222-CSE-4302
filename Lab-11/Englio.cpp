#include<iostream>
using namespace std;
class Distance
{
    private:
      int feet;
      float inches;
    public:
      Distance():feet(0),inches(0.0){}
      Distance(int ft,float in):feet(ft),inches(in){}
      friend istream& operator>>(istream&s,Distance& d);
      friend ostream&operator<<(ostream& s,Distance& d);
};
istream& operator>>(istream&s,Distance& d)
{
    cout<<"Enter feet: ";
    s>>d.feet;
    cout<<"Enter inches: ";
    s>>d.inches; 
    return s;
}
ostream& operator << (ostream& s, Distance& d)
 {                                            
    s << d.feet << "-" << d.inches <<endl;
    return s;                                  
 }    
int main()
{
    Distance d1,d2;
    Distance d3(11, 6.25);
    cout<< "Enter two distance value: ";
    cin>>d1>>d2;
    cout<<endl;
    cout<<"Dist1="<<d1<<endl;
    cout<<"Dist2="<<d2<<endl;
    cout<<"Dist3="<<d3<<endl;
}