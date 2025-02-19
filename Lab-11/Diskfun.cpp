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
            cout<< "\n Enter name: ";
            cin>>name;
            cout<< " Enter age: ";
            cin>>age;
        }
       void showdata()
       {
         cout<< "\n Name: "<<name<<endl;
         cout<< "\n Age: "<< age<<endl;
       }
};
int main()
{
    char c;
    people p;
    fstream f;
    f.open("GROUP.DAT",ios::app|ios::out|ios::in|ios::binary);
    do
    {
        cout<< "\n Enter person's data:";
        p.getdata();
        f.write(reinterpret_cast<char*>(&p),sizeof(p));
        cout<< "Enter another person (y/n)? ";
        cin>>c;
    }while(c=='y');
    f.seekg(0);
    f.read(reinterpret_cast<char*>(&p),sizeof(p));
    while(!f.eof())
    {
        cout<< "\nPerson:";
        p.showdata();
        f.read(reinterpret_cast<char*>(&p),sizeof(p));
    }
    cout<<endl;
}