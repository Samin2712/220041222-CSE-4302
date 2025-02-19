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
         cout<< "Name: "<<name<<endl;
         cout<< "Age: "<< age<<endl;
       }
};
int main()
{
    people p;
    ifstream in;
    in.open("GROUP.DAT",ios::app|ios::out|ios::in|ios::binary);
    in.seekg(0,ios::end);
    int end_p=in.tellg();
    int n=end_p/sizeof(p);
    cout << "\nThere are "<<n<<" persons in file"; 
   cout<< "Enter person number: ";
   cin>>n;
   int position=(n-1)*sizeof(p); 
   in.seekg(position);
   in.read(reinterpret_cast<char*>(&p),sizeof(p));
   p.showdata();
   cout<<endl;
}