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
       void showdata()
       {
         cout<< "Name: "<<name<<endl;
         cout<< "Age: "<< age<<endl;
       }
};
int main()
{
    people p;
    ifstream in("PEOPLE.DAT",ios::binary);
    in.read(reinterpret_cast<char*>(&p),sizeof(p));
    p.showdata();
    
}