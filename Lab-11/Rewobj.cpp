#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class people
{
    protected:
       char name[40];
       short age;
    public:
        void getdata(void)
        {
            cout<< "\n Enter name: ";
            cin>>name;
            cout<< " Enter age: ";
            cin>>age;
        }
       void showdata(void)
       {
         cout<< "Name: "<<name<<endl;
         cout<< "Age: "<< age<<endl;
       }
       void diskIN(int);
       void diskOut();
       static int diskcount();
};
void people::diskIN(int x)
{
    ifstream infile;                           
    infile.open("PERSFILE.DAT",ios::binary); 
    infile.seekg(x*sizeof(people));
    infile.read( (char*)this,sizeof(*this));
}
void people::diskOut()
{
    ofstream outfile;                           
    outfile.open("PERSFILE.DAT",ios::app|ios::binary); 
    outfile.write((char*)this,sizeof(*this));
}
int people::diskcount()
{
    ifstream infile;
    infile.open("PERSFILE.DAT",ios::binary);
    infile.seekg(0,ios::end);
    return (int)infile.tellg()/sizeof(people); 
}
int main()
{
    people p;
    char c;
    do
    {
        cout<< "Enter data for person:";
        p.getdata();
        p.diskOut();
        cout << "Do another (y/n)? ";
        cin>>c;
    }while(c=='y');
    int n=people::diskcount();
    cout<< "There are"<<n<< "persons in file"<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<"\nPerson "<<j;
        p.diskIN(j);
        p.showdata();
    }
    cout<<endl;
}