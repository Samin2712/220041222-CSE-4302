#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class people
{
    protected:
       char name[80];
       short age;
    public:
       void getdata()
       {
         cout<< "Enter name: ";
         cin>>name;
         cout<< "Enter age: ";
         cin>>age;
       }
};
int main()
{
    people p;
    p.getdata();
    ofstream ot("PEOPLE.DAT",ios::binary);
    ot.write(reinterpret_cast<char*>(&p),sizeof(p));
    
}